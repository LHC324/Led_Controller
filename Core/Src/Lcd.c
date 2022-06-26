#include "Lcd.h"
#include "cmsis_os.h"
#include "spi.h"
#include "usart.h"

/*定义LCD对象*/
pLcd Lcd;

extern DMA_HandleTypeDef hdma_spi3_tx;

/*静态函数声明*/
static void Lcd_Write(pLcd lcd, Lcd_Option type, uint8_t Data);
static void Lcd_WriteDma(pLcd lcd, uint8_t const *pbuf, uint32_t size);
static void Lcd_WriteDatas(pLcd lcd, uint8_t *pdata, uint8_t len);
static void Lcd_WriteBlock(pLcd lcd);
static void Lcd_WriteColor(pLcd lcd, uint16_t *pcolor, Lcd_WriteType type);
static void Lcd_WritePixel(pLcd lcd);
static void Lcd_Clear(pLcd lcd, uint16_t color);
static void Lcd_DisPicture(pLcd lcd, uint8_t const *pimg);
static void Lcd_init(pLcd lcd, uint16_t color);
static void Lcd_Test(pLcd lcd);

/**
 * @brief  创建LCD对象
 * @param  lcd   屏幕对象
 * @param  slcd  屏幕引用对象
 * @return None
 */
static void Creat_LcdObject(pLcd *lcd, Lcd_Spi *pspi, Lcd_Size *psize)
{
    (*lcd) = (pLcd)USERMALLOC(sizeof(LCD));
#if defined(USING_DEBUG)
    // Debug("*lcd = %p\r\n", *lcd);
#endif
    if ((*lcd) && (pspi) && (psize))
    {
        (*lcd)->LCD_Write = Lcd_Write;
        (*lcd)->LCD_WriteDma = Lcd_WriteDma;
        (*lcd)->LCD_WriteDatas = Lcd_WriteDatas;
        (*lcd)->LCD_WriteBlock = Lcd_WriteBlock;
        (*lcd)->LCD_WriteColor = Lcd_WriteColor;
        (*lcd)->LCD_WritePixel = Lcd_WritePixel;
        (*lcd)->LCD_Clrear = Lcd_Clear;
        (*lcd)->LCD_DisPicture = Lcd_DisPicture;
        (*lcd)->LCD_Test = Lcd_Test;
        (*lcd)->Size.Direction = psize->Direction;
        if ((*lcd)->Size.Direction == Horizontal)
        {
            (*lcd)->Size.Height = psize->Height;
            (*lcd)->Size.Width = psize->Width;
        }
        else
        {
            (*lcd)->Size.Height = psize->Width;
            (*lcd)->Size.Width = psize->Height;
        }
        (*lcd)->Spi.hspi = pspi->hspi;
        (*lcd)->Spi.dspi = pspi->dspi;
        (*lcd)->Spi.timeout = pspi->timeout;
        (*lcd)->Spi.Rs = pspi->Rs;
        (*lcd)->Spi.Cs = pspi->Cs;
        // (*lcd)->Spi = *pspi;
    }
    else
    {
        USERFREE(*lcd);
    }
}

/**
 * @brief  销毁LCD对象
 * @param  lcd   屏幕对象
 * @return None
 */
void Free_LcdObject(pLcd *lcd)
{
    USERFREE(*lcd);
}
/**
 * @brief  LCD初始化
 * @param  None
 * @return None
 */
void MX_LCD_Init(void)
{
    Lcd_Spi spi = {
        .hspi = &hspi3,
        .dspi = &hdma_spi3_tx,
        .timeout = 0x100,
        .Rs = {.pGPIOx = SPI3_RS_GPIO_Port, .Pin = SPI3_RS_Pin},
        .Cs = {.pGPIOx = SPI3_NSS_GPIO_Port, .Pin = SPI3_NSS_Pin},
    };
    Lcd_Size size = {
        .Height = LCD_HEIGHT,
        .Width = LCD_WIDTH,
        .Direction = Horizontal,
        // .Direction = Vertical,
    };
    Creat_LcdObject(&Lcd, &spi, &size);
    Lcd_init(Lcd, GBLUE);
}

#define LCD_Writes(__obj, __data, __size)              \
    (do {                                              \
        Lcd_Option type;                               \
        for (uint8_t i = 0; i < (__size); i++)         \
        {                                              \
            type = !i ? Cmd : Data;                    \
            (__obj)->LCD_Write(lcd, Cmd, (__data)[i]); \
        }                                              \
    } while (0);)

/**
 * @brief  对LCD屏幕写数据/命令
 * @param  lcd   屏幕对象
 * @param  type  操作类型
 * @param  Data  目标数据
 * @return None
 */
static void Lcd_Write(pLcd lcd, Lcd_Option type, uint8_t Data)
{
    GPIO_PinState PinState = (type == Cmd) ? GPIO_PIN_RESET : GPIO_PIN_SET;

#if defined(USING_DEBUG)
    // Debug("Data is 0x%x .\r\n", Data);
#endif
    HAL_GPIO_WritePin(lcd->Spi.Rs.pGPIOx, lcd->Spi.Rs.Pin, PinState);
    //    HAL_GPIO_WritePin(lcd->Spi.Cs.pGPIOx, lcd->Spi.Cs.Pin, GPIO_PIN_RESET);
    lcd->Spi.Cs.pGPIOx->BSRR = (uint32_t)lcd->Spi.Cs.Pin << 16U;
    HAL_SPI_Transmit(lcd->Spi.hspi, &Data, sizeof(Data), lcd->Spi.timeout);
    /* 判断上次DMA有没有传输完成 */
    // while(HAL_DMA_GetState(&hdma_spi3_tx) != HAL_DMA_STATE_READY);
    /* 发送一个(24bit)的 RGB 数据到 2812 */
    // HAL_SPI_Transmit_DMA(&hspi3, &Data, sizeof(Data));
    //    HAL_GPIO_WritePin(lcd->Spi.Cs.pGPIOx, lcd->Spi.Cs.Pin, GPIO_PIN_SET);
    //    HAL_GPIO_WritePin(lcd->Spi.Rs.pGPIOx, lcd->Spi.Rs.Pin, GPIO_PIN_SET);
    lcd->Spi.Cs.pGPIOx->BSRR = lcd->Spi.Cs.Pin;
    lcd->Spi.Rs.pGPIOx->BSRR = lcd->Spi.Rs.Pin;
}

/**
 * @brief  对LCD屏幕写数据/命令
 * @param  lcd   屏幕对象
 * @param  pbuf  数据指针
 * @return None
 */
static void Lcd_WriteDma(pLcd lcd, uint8_t const *pbuf, uint32_t size)
{
    if (pbuf)
    {
        lcd->Spi.Cs.pGPIOx->BSRR = (uint32_t)lcd->Spi.Cs.Pin << 16U;
        lcd->Spi.Rs.pGPIOx->BSRR = lcd->Spi.Rs.Pin;
        // lcd->Spi.hspi->State = HAL_SPI_STATE_READY;
        HAL_SPI_Transmit_DMA(lcd->Spi.hspi, (uint8_t *)pbuf, size);
        /* 判断上次DMA有没有传输完成 */
        while (HAL_DMA_GetState(lcd->Spi.dspi) != HAL_DMA_STATE_READY)
            ;
        lcd->Spi.Cs.pGPIOx->BSRR = lcd->Spi.Cs.Pin;
    }
}

/**
 * @brief  初始化LCD时写一条命令同时写多条数据
 * @param  lcd   屏幕对象
 * @param  pdata 数据指针
 * @param  len   数据长度
 * @return None
 */
static void Lcd_WriteDatas(pLcd lcd, uint8_t *pdata, uint8_t len)
{
    Lcd_Option type;
    for (uint8_t *p = pdata; p < pdata + len; p++)
    {
        type = (p == pdata) ? Cmd : Data;
        lcd->LCD_Write(lcd, type, *p);
    }
}

/**
 * @brief  LCD写矩形区域
 * @param  lcd   屏幕对象
 * @return None
 */
static void Lcd_WriteBlock(pLcd lcd)
{
    uint8_t data[] = {0x2A, lcd->Region.X.start >> 8U, lcd->Region.X.start, lcd->Region.X.end >> 8U, lcd->Region.X.end};

    lcd->LCD_WriteDatas(lcd, data, sizeof(data));

    uint8_t data1[] = {0x2B, lcd->Region.Y.start >> 8U, lcd->Region.Y.start, lcd->Region.Y.end >> 8U, lcd->Region.Y.end};
    lcd->LCD_WriteDatas(lcd, data1, sizeof(data1));

    lcd->LCD_Write(lcd, Cmd, 0x2C);
}

/**
 * @brief  LCD写颜色块
 * @param  lcd   屏幕对象
 * @return None
 */
static void Lcd_WriteColor(pLcd lcd, uint16_t *pcolor, Lcd_WriteType type)
{
#define PACKAGE_SIZE (10 * 1024U)
    uint32_t dma_size = (uint32_t)(lcd->Region.X.len * lcd->Region.Y.len * 2U);
    // uint32_t rem_size = dma_size;
    // uint32_t send_package = dma_size / PACKAGE_SIZE + !!(dma_size % PACKAGE_SIZE);
    // uint32_t send_package = (dma_size >= PACKAGE_SIZE) ? (dma_size + PACKAGE_SIZE - 1U) / PACKAGE_SIZE : 1;
    uint32_t real_size = 0;

    lcd->LCD_WriteBlock(lcd);
    // while (send_package--)
    while (dma_size)
    {
        real_size = (dma_size > PACKAGE_SIZE) ? PACKAGE_SIZE : dma_size;
        uint8_t *pbuf = (uint8_t *)USERMALLOC(real_size);
        if (pbuf)
        {
            /*申请内存150KB，太大无法满足*/
            for (uint8_t *p = pbuf; p < pbuf + real_size;)
            {
                *p++ = *pcolor >> 8U;
                *p++ = *pcolor;
                type == Circle ? pcolor++ : 0;
            }
            lcd->LCD_WriteDma(lcd, pbuf, real_size);
        }
        USERFREE(pbuf);
        dma_size -= real_size;
    }
}

/**
 * @brief  LCD填充像素
 * @param  lcd   屏幕对象
 * @return None
 */
static void Lcd_WritePixel(pLcd lcd)
{
    lcd->LCD_WriteBlock(lcd);
    lcd->LCD_Write(lcd, Data, lcd->Region.Color >> 8U);
    lcd->LCD_Write(lcd, Data, lcd->Region.Color);
}

/**
 * @brief  LCD清屏函数
 * @param  lcd   屏幕对象
 * @return None
 */
static void Lcd_Clear(pLcd lcd, uint16_t color)
{
    lcd->Region.Color = color;
    lcd->Region.X.start = 0;
    lcd->Region.Y.start = 0;
    lcd->Region.X.end = lcd->Size.Height - 1U;
    lcd->Region.Y.end = lcd->Size.Width - 1U;
    lcd->Region.X.len = lcd->Size.Height;
    lcd->Region.Y.len = lcd->Size.Width;
    lcd->LCD_WriteColor(lcd, &lcd->Region.Color, Single);
}

/**
 * @brief  LCD显示图片
 * @param  lcd   屏幕对象
 * @return None
 */
static void Lcd_DisPicture(pLcd lcd, uint8_t const *pimg)
{
    uint32_t dma_size = (uint32_t)(lcd->Region.X.len * lcd->Region.Y.len * 2U);
    // uint8_t *pbuf = (uint8_t *)USERMALLOC(dma_size);
    if (pimg)
    {
        /*放置图片位置*/
        lcd->LCD_WriteBlock(lcd);

        lcd->LCD_WriteDma(lcd, pimg, dma_size);

        // lcd->Spi.Cs.pGPIOx->BSRR = (uint32_t)lcd->Spi.Cs.Pin << 16U;
        // lcd->Spi.Rs.pGPIOx->BSRR = lcd->Spi.Rs.Pin;
        // // lcd->Spi.hspi->State = HAL_SPI_STATE_READY;
        // HAL_SPI_Transmit_DMA(lcd->Spi.hspi, (uint8_t *)pimg, dma_size);
        // /* 判断上次DMA有没有传输完成 */
        // while (HAL_DMA_GetState(lcd->Spi.dspi) != HAL_DMA_STATE_READY)
        //     ;
        // lcd->Spi.Cs.pGPIOx->BSRR = lcd->Spi.Cs.Pin;
        /*使用DMA传输速度是普通spi的10倍多*/
        // for (uint32_t i = 0; i < dma_size; i++)
        // {
        //     Lcd_Write(lcd, Data, pimg[i]);
        // }
    }

    // USERFREE(pbuf);
}

/**
 * @brief  初始化LCD对象
 * @param  lcd   屏幕对象
 * @param  color 清屏颜色
 * @return None
 */
static void Lcd_init(pLcd lcd, uint16_t color)
{
#define A "\xF0\x5A\x5A"
    Lcd_WriteDatas(lcd, A, sizeof(A) - 1U);
#define B "\xF1\x5A\x5A"
    Lcd_WriteDatas(lcd, B, sizeof(B) - 1U);
#define C "\xF2\x3B\x33\x03\x0C\x08\x08\x08\x00\x08\x08\x00\x00\x00\x00\x33\x0c\x08\x0c\x08"
    Lcd_WriteDatas(lcd, C, sizeof(C) - 1U);
#define D "\xF4\x07\x00\x00\x00\x00\x00\x00\x00\x04\x70\x03\x04\x70\x03"
    Lcd_WriteDatas(lcd, D, sizeof(D) - 1U);
#define E "\xF5\x00\x46\x70\x00\x00\x02\x00\x00\x00\x00\x46\x70"
    Lcd_WriteDatas(lcd, E, sizeof(E) - 1U);
#define F "\xF6\x03\x00\x08\x03\x03\x00\x03\x00"
    Lcd_WriteDatas(lcd, F, sizeof(F) - 1U);
#define G "\xF7\x48\x80\x10\x02\x00"
    Lcd_WriteDatas(lcd, G, sizeof(G) - 1U);
#define H "\xF8\x11\x00"
    Lcd_WriteDatas(lcd, H, sizeof(H) - 1U);
#define I "\xF9\x14"
    Lcd_WriteDatas(lcd, I, sizeof(I) - 1U);
#define J "\xFA\x33\x07\x04\x1A\x18\x1C\x24\x1D\x26\x28\x2F\x2E\x00\x00\x00\x00"
    Lcd_WriteDatas(lcd, J, sizeof(J) - 1U);
#define K "\xFB\x33\x03\x00\x2E\x2F\x28\x26\x1D\x24\x1C\x18\x1A\x04\x00\x00\x00"
    Lcd_WriteDatas(lcd, K, sizeof(K) - 1U);
#define I1 "\xF9\x12"
    Lcd_WriteDatas(lcd, I1, sizeof(I1) - 1U);
#define J1 "\xFA\x36\x07\x04\x1C\x1C\x23\x28\x1C\x25\x26\x2E\x2B\x00\x00\x00\x00"
    Lcd_WriteDatas(lcd, J1, sizeof(J1) - 1U);
#define K1 "\xFB\x33\x06\x00\x2B\x2E\x26\x25\x1C\x28\x23\x1C\x1C\x04\x00\x00\x00"
    Lcd_WriteDatas(lcd, K1, sizeof(K1) - 1U);
#define I2 "\xF9\x11"
    Lcd_WriteDatas(lcd, I2, sizeof(I2) - 1U);
#define J2 "\xFA\x33\x07\x04\x30\x32\x34\x35\x11\x1D\x20\x28\x20\x00\x00\x00\x00"
    Lcd_WriteDatas(lcd, J2, sizeof(J2) - 1U);
#define K2 "\xFB\x33\x03\x00\x20\x28\x20\x1D\x11\x35\x34\x32\x30\x04\x00\x00\x00"
    Lcd_WriteDatas(lcd, K2, sizeof(K2) - 1U);
#define L "\x44\x00\x01"
    Lcd_WriteDatas(lcd, L, sizeof(L) - 1U);
#define M "\x2A\x00\x00\x01\x3F"
    Lcd_WriteDatas(lcd, M, sizeof(M) - 1U);
#define N "\x2B\x00\x00\x01\xDF"
    Lcd_WriteDatas(lcd, N, sizeof(N) - 1U);
#define O "\x36\x00"
    Lcd_WriteDatas(lcd, O, sizeof(O) - 1U);
#define P "\x3A\x55"
    Lcd_WriteDatas(lcd, P, sizeof(P) - 1U);
#define Q "\x11"
    Lcd_WriteDatas(lcd, Q, sizeof(Q) - 1U);
    HAL_Delay(120);
#define R "\x29"
    Lcd_WriteDatas(lcd, R, sizeof(R) - 1U);
#define S "\x2C"
    Lcd_WriteDatas(lcd, S, sizeof(S) - 1U);
    if (lcd->Size.Direction == Horizontal)
    {
#define T "\x36\x60"
        Lcd_WriteDatas(lcd, T, sizeof(T) - 1U);
    }
    else
    {
#define T1 "\x36\xC0"
        Lcd_WriteDatas(lcd, T1, sizeof(T1) - 1U);
    }
    HAL_Delay(10);
    lcd->LCD_Clrear(lcd, color);
}

/**
 * @brief  LCD测试函数
 * @param  lcd   屏幕对象
 * @return None
 */
static void Lcd_Test(pLcd lcd)
{
    // static uint16_t color = 0x00;

    // lcd->Region.Color = color++;
    // lcd->Region.X.start = 0;
    // lcd->Region.X.end = 479;
    // lcd->Region.Y.start = 0;
    // lcd->Region.Y.end = 319;
    // lcd->Region.X.len = 480;
    // lcd->Region.Y.len = 320;

    // lcd->Region.X.start = 109;
    // lcd->Region.Y.start = 189;
    // lcd->Region.X.end = 209;
    // lcd->Region.Y.end = 289;

    // lcd->Region.X.len = 100;
    // lcd->Region.Y.len = 100;

    // lcd->Region.X.start = (lcd->Size.Height - lcd->Region.X.len) / 2U - 1U;
    // lcd->Region.Y.start = (lcd->Size.Width - lcd->Region.Y.len) / 2U - 1U;
    // lcd->Region.X.end = lcd->Region.X.start + lcd->Region.X.len;
    // lcd->Region.Y.end = lcd->Region.Y.start + lcd->Region.Y.len;
    // lcd->LCD_WriteColor(lcd);

    lcd->LCD_Clrear(lcd, lcd->Region.Color);
}
