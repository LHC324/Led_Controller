#ifndef __WS2812_H__
#define __WS2812_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "main.h"
#include "Lcd.h"

#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#define PIXEL_NUM 64U
#define GRB 25U
#define WS281x_BUF_TYPE uint32_t
    typedef WS281x_BUF_TYPE (*WS281X_TYPE)[GRB];
#define COLOR_TYPE RGB888

#define WS_HIGH 70U
#define WS_LOW 30U

    typedef union
    {
        uint32_t Color;
        struct
        {
            uint8_t C;
            uint8_t M;
            uint8_t Y;
            uint8_t K;
        } C;
    } CMYK;

    typedef struct Ws2812x_HandleTypeDef *pWs281x;

    typedef enum
    {
        RGB_32 = 0x00,
        RGB_24,
    } Color_Mode;

    typedef struct
    {
        TIM_HandleTypeDef *htim;
        DMA_HandleTypeDef *hdma;
        uint32_t channel;
        uint32_t timeout;
    } Ws281x_Pwm;
    typedef struct
    {
        uint16_t Light_Num;
        WS281x_BUF_TYPE (*pBuf)[GRB];
        uint32_t Total_Size;
    } Ws281x_Area;
    typedef struct Ws2812x_HandleTypeDef
    {

        Ws281x_Pwm Pwm;
        Ws281x_Area Region;
        void (*WS281x_CloseAll)(pWs281x);
        void (*WS281x_Transmit)(pWs281x, WS281x_BUF_TYPE *, uint32_t);
        void (*WS281x_SetPixeColor)(pWs281x, uint8_t, uint32_t);
        void (*WS281x_ColorWipe)(pWs281x, uint32_t, uint16_t);
        uint32_t (*WS281x_Wheel)(pWs281x, uint8_t);
        void (*WS281x_Rainbow)(pWs281x, uint8_t);
        void (*WS281x_RainbowCycle)(pWs281x, uint8_t);
        void (*WS281x_TheaterChase)(pWs281x, uint32_t, uint8_t);
        void (*WS281x_TheaterChaseRainbow)(pWs281x, uint8_t);
        void (*WS281x_RgbToCmyk)(pWs281x, COLOR_TYPE, uint16_t);
        void (*WS281x_CmykToRgb)(pWs281x, CMYK, uint16_t);
        void (*WS281x_Test)(pWs281x);
        void (*WS281x_DelayMs)(uint32_t);
    } WS281X __attribute__((aligned(4)));
    extern pWs281x Ws281x;

    extern void MX_WS281x_Init(void);

#ifdef __cplusplus
}
#endif
#endif /*__WS2812_H__ */
