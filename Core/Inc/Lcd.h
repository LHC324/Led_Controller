#ifndef __LCD_H__
#define __LCD_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "main.h"

#define LCD_HEIGHT 480U
#define LCD_WIDTH 320U

#define WHITE 0xFFFF
#define BLACK 0x0000
#define BLUE 0x001F
#define BRED 0XF81F
#define GRED 0XFFE0
#define GBLUE 0X07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define GREEN 0x07E0
#define CYAN 0x7FFF
#define YELLOW 0xFFE0
#define BROWN 0XBC40 //棕色
#define BRRED 0XFC07 //棕红色
#define GRAY 0X8430  //灰色

#define RGB888_TO_RGB565(__color) \
    ((((__color) >> 19U) & 0x1f) << 11U) | ((((__color) >> 10U) & 0x3f) << 5U) | (((__color) >> 3U) & 0x1f)

    typedef union
    {
        uint16_t Color;
        struct
        {
            uint8_t R : 5;
            uint8_t G : 6;
            uint8_t B : 5;
        } C;
    } RGB565;

    typedef union
    {
        uint32_t Color;
        struct
        {
            uint8_t R;
            uint8_t G;
            uint8_t B;
        } C;
    } RGB888;

    typedef enum
    {
        Cmd = 0x00,
        Data,
    } Lcd_Option;

    typedef enum
    {
        Single = 0x00,
        Circle,
    } Lcd_WriteType;

    typedef enum
    {
        Horizontal = 0x00,
        Vertical,
    } Lcd_Direction;

    typedef struct Lcd
    {
        uint16_t start;
        uint16_t end;
        uint16_t len;
    } Lcd_site;

    typedef struct Lcd_HandleTypeDef *pLcd;
    typedef struct
    {
        GPIO_TypeDef *pGPIOx;
        uint16_t Pin;
    } Lcd_Pin;

    typedef struct
    {
        SPI_HandleTypeDef *hspi;
        DMA_HandleTypeDef *dspi;
        uint32_t timeout;
        Lcd_Pin Rs, Cs;
    } Lcd_Spi;

    typedef struct
    {
        Lcd_site X, Y;
        uint16_t Color;
    } Lcd_Area;

    typedef struct
    {
        uint16_t Height;
        uint16_t Width;
        Lcd_Direction Direction;
    } Lcd_Size;

    typedef struct Lcd_HandleTypeDef
    {
        Lcd_Spi Spi;
        Lcd_Area Region;
        Lcd_Size Size;
        void (*LCD_Write)(pLcd, Lcd_Option, uint8_t);
        void (*LCD_WriteDma)(pLcd, uint8_t const *, uint32_t);
        void (*LCD_WriteDatas)(pLcd, uint8_t *, uint8_t);
        void (*LCD_WriteBlock)(pLcd);
        void (*LCD_WriteColor)(pLcd, uint16_t *, Lcd_WriteType);
        void (*LCD_WritePixel)(pLcd);
        void (*LCD_Clrear)(pLcd, uint16_t);
        void (*LCD_DisPicture)(pLcd, uint8_t const *);
        void (*LCD_Test)(pLcd);
    } LCD __attribute__((aligned(4)));

    extern void MX_LCD_Init(void);
    extern pLcd Lcd;

#ifdef __cplusplus
}
#endif
#endif /*__ LCD_H__ */
