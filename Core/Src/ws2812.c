#include "ws2812.h"
#include "Lcd.h"
#include "cmsis_os.h"
#include "tim.h"

#define FUNC_DELAY vTaskDelay
/*创建WS281x对象*/
pWs281x Ws281x;

#define COLOR_TYPE RGB888

/*静态函数声明*/
static void WS281x_CloseAll(pWs281x ws281x);
static void WS281x_Transmit(pWs281x ws281x, WS281x_BUF_TYPE *pbuf, uint32_t size);
static void WS281x_SetPixeColor(pWs281x ws281x, uint8_t site, uint32_t grb);
static void WS281x_ColorWipe(pWs281x ws281x, uint32_t grb, uint16_t wait);
static uint32_t WS281x_Wheel(pWs281x ws281x, uint8_t wheelPos);
static void WS281x_Rainbow(pWs281x ws281x, uint8_t wait);
static void WS281x_RainbowCycle(pWs281x ws281x, uint8_t wait);
static void WS281x_TheaterChase(pWs281x ws281x, uint32_t grb, uint8_t wait);
static void WS281x_TheaterChaseRainbow(pWs281x ws281x, uint8_t wait);
static void WS281x_RgbToCmyk(pWs281x ws281x, COLOR_TYPE rgb, uint16_t wait);
static void WS281x_CmykToRgb(pWs281x ws281x, CMYK cmyk, uint16_t wait);
static void W281x_Test(pWs281x ws281x);
/**
 * @brief  创建WS2812对象
 * @param  lcd   屏幕对象
 * @param  slcd  屏幕引用对象
 * @return None
 */
static void Creat_WS281x_Object(pWs281x *ws281x, Ws281x_Pwm *pwm, uint16_t size)
{
  (*ws281x) = (pWs281x)USERMALLOC(sizeof(WS281X));
#if defined(USING_DEBUG)
  // Debug("*lcd = %p\r\n", *lcd);
#endif
  if ((*ws281x) && (pwm))
  {
    (*ws281x)->Region.Light_Num = size;
    (*ws281x)->Region.Total_Size = size * GRB;
    WS281X_TYPE pBuf = (WS281X_TYPE)USERMALLOC(size * GRB * sizeof(WS281x_BUF_TYPE));
    if (pBuf)
    {
      (*ws281x)->Region.pBuf = pBuf;
    }
    else
    {
      USERFREE(pBuf);
    }
    (*ws281x)->Pwm.htim = pwm->htim;
    (*ws281x)->Pwm.hdma = pwm->hdma;
    (*ws281x)->Pwm.channel = pwm->channel;
    (*ws281x)->Pwm.timeout = pwm->timeout;
    (*ws281x)->WS281x_DelayMs = FUNC_DELAY;
    (*ws281x)->WS281x_CloseAll = WS281x_CloseAll;
    (*ws281x)->WS281x_Transmit = WS281x_Transmit;
    (*ws281x)->WS281x_SetPixeColor = WS281x_SetPixeColor;
    (*ws281x)->WS281x_ColorWipe = WS281x_ColorWipe;
    (*ws281x)->WS281x_Wheel = WS281x_Wheel;
    (*ws281x)->WS281x_Rainbow = WS281x_Rainbow;
    (*ws281x)->WS281x_RainbowCycle = WS281x_RainbowCycle;
    (*ws281x)->WS281x_TheaterChase = WS281x_TheaterChase;
    (*ws281x)->WS281x_TheaterChaseRainbow = WS281x_TheaterChaseRainbow;
    (*ws281x)->WS281x_RgbToCmyk = WS281x_RgbToCmyk;
    (*ws281x)->WS281x_CmykToRgb = WS281x_CmykToRgb;
    (*ws281x)->WS281x_Test = W281x_Test;
  }
  else
  {
    USERFREE(*ws281x);
  }
}

/**
 * @brief  初始化WS2812
 * @param  None
 * @return None
 */
void MX_WS281x_Init(void)
{
  extern DMA_HandleTypeDef hdma_tim2_ch1;
  Ws281x_Pwm pwm = {
      .htim = &htim2,
      .hdma = &hdma_tim2_ch1,
      .channel = TIM_CHANNEL_1,
      .timeout = 0x1000,
  };
  // Ws281x_Area area = {
  //   .Light_Num = PIXEL_NUM,
  //   .pBuf = NULL,
  // };

  Creat_WS281x_Object(&Ws281x, &pwm, PIXEL_NUM);
}

/**
 * @brief  关闭WS281x灯珠显示
 * @param  ws281x  WS281x对象
 * @return None
 */
static void WS281x_CloseAll(pWs281x ws281x)
{
  if ((ws281x->Region.pBuf) && (ws281x->Region.Light_Num))
  {
    memset(ws281x->Region.pBuf, WS_LOW, ws281x->Region.Total_Size * sizeof(WS281x_BUF_TYPE));
  }
  ws281x->WS281x_Transmit(ws281x, (WS281x_BUF_TYPE *)ws281x->Region.pBuf, ws281x->Region.Total_Size);
}

/**
 * @brief  创建WS2812对象
 * @param  ws281x ws281x对象
 * @param  pbuf   数据指针
 * @param  size   数据长度
 * @return None
 */
static void WS281x_Transmit(pWs281x ws281x, WS281x_BUF_TYPE *pbuf, uint32_t size)
{
  HAL_TIM_PWM_Start_DMA(ws281x->Pwm.htim, ws281x->Pwm.channel, (uint32_t *)pbuf, size);
  /* 判断上次DMA有没有传输完成 */
  // while (HAL_DMA_GetState(ws281x->Pwm.hdma) != HAL_DMA_STATE_READY)
  //   ;
  // HAL_TIM_PWM_Stop_DMA(ws281x->Pwm.htim, ws281x->Pwm.channel);
}

/*获得Ws281x类型颜色值*/
#define Get_Ws281xColor(__R, __G, __B) \
  ((uint32_t)((__G) << 16U | (__R) << 8U | (__B)))

/**
 * @brief  WS2812设置灯珠颜色(32bit模式/24bit模式)
 * @param  ws281x ws281x对象
 * @param  site   ws281x灯珠位置
 * @param  grb    grb颜色值
 * @note   可使用RGB888共用体
 * @return None
 */
static void WS281x_SetPixeColor(pWs281x ws281x, uint8_t site, uint32_t grb)
{
  // COLOR_TYPE *prgb = (COLOR_TYPE *)rgb;
  if ((ws281x->Region.pBuf) && (site < ws281x->Region.Light_Num))
  {
    for (uint8_t i = 0; i < GRB - 1U; i++)
    {
      ws281x->Region.pBuf[site][i] = ((grb << i) & 0x800000) ? WS_HIGH : WS_LOW;
    }
    /*未知原因：防止DMA传输过程中数据个数错误，导致的波形错误*/
    ws281x->Region.pBuf[site][GRB - 1U] = 0;
  }
}

/**
 * @brief  WS2812设置灯珠颜色(32bit模式/24bit模式)
 * @note   Fill the dots one after the other with a color.
 * @param  ws281x ws281x对象
 * @param  wait   等待时间
 * @return None
 */
static void WS281x_ColorWipe(pWs281x ws281x, uint32_t grb, uint16_t wait)
{
  for (uint16_t pixe = 0; pixe < PIXEL_NUM; pixe++)
  {
    ws281x->WS281x_SetPixeColor(ws281x, pixe, grb);
  }
  ws281x->WS281x_Transmit(ws281x, (WS281x_BUF_TYPE *)ws281x->Region.pBuf, ws281x->Region.Total_Size);
  ws281x->WS281x_DelayMs(wait);
}

/**
 * @brief  WS2812输入一个8bit颜色值产生32bit颜色
 * @note   Input a value 0 to 255 to get a color value.
 *         The colours are a transition r - g - b - back to r.
 * @param  ws281x ws281x对象
 *
 * @return 32bit颜色值
 */
static uint32_t WS281x_Wheel(pWs281x ws281x, uint8_t wheelPos)
{
  wheelPos = 0xFF - wheelPos;
  if (wheelPos < 85)
  {
    return Get_Ws281xColor(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  if (wheelPos < 170)
  {
    wheelPos -= 85;
    return Get_Ws281xColor(0, wheelPos * 3, 255 - wheelPos * 3);
  }
  wheelPos -= 170;
  return Get_Ws281xColor(wheelPos * 3, 255 - wheelPos * 3, 0);
}

/**
 * @brief  WS2812设置灯珠颜色(32bit模式/24bit模式)
 * @param  ws281x ws281x对象
 * @param  wait   等待时间
 * @return None
 */
static void WS281x_Rainbow(pWs281x ws281x, uint8_t wait)
{
  for (uint16_t i = 0; i < 0x400; i++)
  {
    for (uint8_t pixe = 0; pixe < PIXEL_NUM; pixe++)
    {
      ws281x->WS281x_SetPixeColor(ws281x, pixe, ws281x->WS281x_Wheel(ws281x, (i + pixe) & 0xFF));
    }
    ws281x->WS281x_Transmit(ws281x, (WS281x_BUF_TYPE *)ws281x->Region.pBuf, ws281x->Region.Total_Size);
    ws281x->WS281x_DelayMs(wait);
  }
}

/**
 * @brief  WS2812设置灯珠颜色(32bit模式/24bit模式)
 * @note   Slightly different, this makes the rainbow equally distributed throughout
 * @param  ws281x ws281x对象
 * @param  wait   等待时间
 * @return None
 */
static void WS281x_RainbowCycle(pWs281x ws281x, uint8_t wait)
{
  for (uint16_t i = 0; i < 256 * 5; i++)
  { /*5 cycles of all colors on wheel*/
    for (uint16_t pixe = 0; pixe < PIXEL_NUM; pixe++)
    {
      ws281x->WS281x_SetPixeColor(ws281x, i, ws281x->WS281x_Wheel(ws281x, ((i * 256 / PIXEL_NUM) + i) & 0xFF));
    }
    ws281x->WS281x_Transmit(ws281x, (WS281x_BUF_TYPE *)ws281x->Region.pBuf, ws281x->Region.Total_Size);
    ws281x->WS281x_DelayMs(wait);
  }
}

/**
 * @brief  WS2812设置灯珠颜色(32bit模式/24bit模式)
 * @note   Theatre-style crawling lights.
 * @param  ws281x ws281x对象
 * @param  wait   等待时间
 * @return None
 */
static void WS281x_TheaterChase(pWs281x ws281x, uint32_t grb, uint8_t wait)
{
  for (int j = 0; j < 10; j++)
  { /*do 10 cycles of chasing*/
    for (int q = 0; q < 3; q++)
    {
      for (uint16_t pixe = 0; pixe < PIXEL_NUM; pixe += 3)
      {
        /*turn every third pixel on*/
        ws281x->WS281x_SetPixeColor(ws281x, pixe + q, grb);
      }
      ws281x->WS281x_Transmit(ws281x, (WS281x_BUF_TYPE *)ws281x->Region.pBuf, ws281x->Region.Total_Size);

      ws281x->WS281x_DelayMs(wait);

      for (uint16_t i = 0; i < PIXEL_NUM; i = i + 3)
      {
        /*turn every third pixel off*/
        ws281x->WS281x_SetPixeColor(ws281x, i + q, 0);
      }
    }
  }
}

/**
 * @brief  WS2812设置灯珠颜色(32bit模式/24bit模式)
 * @note   Theatre-style crawling lights with rainbow effect.
 * @param  ws281x ws281x对象
 * @param  wait   等待时间
 * @return None
 */
static void WS281x_TheaterChaseRainbow(pWs281x ws281x, uint8_t wait)
{
  for (int j = 0; j < 256; j++)
  { // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++)
    {
      for (uint16_t pixe = 0; pixe < PIXEL_NUM; pixe += 3)
      {
        /*turn every third pixel on*/
        ws281x->WS281x_SetPixeColor(ws281x, pixe + q, ws281x->WS281x_Wheel(ws281x, (pixe + j) % 0xFF));
      }
      ws281x->WS281x_Transmit(ws281x, (WS281x_BUF_TYPE *)ws281x->Region.pBuf, ws281x->Region.Total_Size);

      ws281x->WS281x_DelayMs(wait);

      for (uint16_t i = 0; i < PIXEL_NUM; i = i + 3)
      {
        /*turn every third pixel off*/
        ws281x->WS281x_SetPixeColor(ws281x, i + q, 0);
      }
    }
  }
}

/**
 * @brief  WS2812的RGB转CMY模式
 * @note   None
 * @param  ws281x ws281x对象
 * @param  wait   等待时间
 * @return None
 */
static void WS281x_RgbToCmyk(pWs281x ws281x, COLOR_TYPE rgb, uint16_t wait)
{
#define CMYK_MAX 100.0F
#define P 2.55F
  CMYK cmyk = {
      .C.K = (uint8_t)(min(min((0xFF - rgb.C.R), (0xFF - rgb.C.G)), (0xFF - rgb.C.B)) / 2.55),
  };
  uint8_t gap = CMYK_MAX - cmyk.C.K;

  if (!gap)
    gap = 1U;

  cmyk.C.C = (uint8_t)(((CMYK_MAX - (rgb.C.R / P) - cmyk.C.K) / gap) * CMYK_MAX);
  cmyk.C.M = (uint8_t)(((CMYK_MAX - (rgb.C.G / P) - cmyk.C.K) / gap) * CMYK_MAX);
  cmyk.C.Y = (uint8_t)(((CMYK_MAX - (rgb.C.B / P) - cmyk.C.K) / gap) * CMYK_MAX);

  ws281x->WS281x_ColorWipe(ws281x, cmyk.Color, wait);
}

/**
 * @brief  WS2812的CMY转RGB模式
 * @note   None
 * @param  ws281x ws281x对象
 * @param  wait   等待时间
 * @return None
 */
static void WS281x_CmykToRgb(pWs281x ws281x, CMYK cmyk, uint16_t wait)
{
  COLOR_TYPE rgb = {
      .C.R = (uint8_t)(0xFF * (CMYK_MAX - (float)cmyk.C.C) * (CMYK_MAX - (float)cmyk.C.K) / 10000.0F),
      .C.G = (uint8_t)(0xFF * (CMYK_MAX - (float)cmyk.C.M) * (CMYK_MAX - (float)cmyk.C.K) / 10000.0F),
      .C.B = (uint8_t)(0xFF * (CMYK_MAX - (float)cmyk.C.Y) * (CMYK_MAX - (float)cmyk.C.K) / 10000.0F),
  };
#if defined(USING_DEBUG)
  // extern void Debug(const char *format, ...);
  // Debug("R = %d, G = %d, B= %d.\r\n", rgb.C.R, rgb.C.G, rgb.C.B);
#endif
  ws281x->WS281x_ColorWipe(ws281x, Get_Ws281xColor(rgb.C.R, rgb.C.G, rgb.C.B), wait);
}

// uint32_t pulse[] = {
//     10,
//     20,
//     30,
//     40,
//     50,
//     60,
//     90,
//     0,
// };

/**
 * @brief  WS2812测试函数
 * @param  ws281x ws281x对象
 * @return None
 */
static void W281x_Test(pWs281x ws281x)
{
#define WAIT_TIMES 0x0A
#if (WAIT_TIMES > 0xFF)
#define WAIT_TIMES 0xFF
#endif

  // ws281x->WS281x_Rainbow(ws281x, WAIT_TIMES);
  // ws281x->WS281x_RainbowCycle(ws281x, WAIT_TIMES);
  // ws281x->WS281x_TheaterChase(ws281x, 0x00FF00, WAIT_TIMES);
  // ws281x->WS281x_TheaterChaseRainbow(ws281x, WAIT_TIMES);
  CMYK cmyk = {
      .C.C = 0,
      .C.M = 6,
      .C.Y = 14,
      .C.K = 19,
  };
  ws281x->WS281x_CmykToRgb(ws281x, cmyk, 0xFF);

  // HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_1, (uint32_t *)pulse, sizeof(pulse) / sizeof(uint32_t));
  // HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  //  for (uint16_t i = 0; i < sizeof(pulse); i++)
  // {
  //    HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_1);
  //    __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_1, (uint32_t)pulse[i]);
  //   HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
  //  }
  //   HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_1);
}

/**
 * @brief  pwm的DMA传输完成回调函数
 * @param  htim 定时器句柄
 * @return None
 */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
  // HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_1);
}
