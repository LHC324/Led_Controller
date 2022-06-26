#ifndef __EC11_H__
#define __EC11_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "main.h"

    typedef enum
    {
        DownAndReverse = -2,
        Reverse = -1,
        None = 0,
        Down = 1,
        Forward = 2,
        DownAndForward = 3,
        Up,
    } Ec1x_EventType;

    typedef struct
    {
        GPIO_TypeDef *pGPIOx;
        uint16_t Pin;
    } Ec1x_Pin;

    typedef struct
    {
        Ec1x_Pin A, B, Key;
        IRQn_Type IRQn;
        bool First_Flag, BFlag;
        // void (*Ec1x_Event)(void *);
    } Ec1x;

    typedef struct EC1x_Type
    {
        uint8_t Id;
        Ec1x_EventType Option;
    } Ec1x_Type;

    extern Ec1x_Type Read_Ec1x(void);
    // extern Ec1x_Type Check_Ec1x_Press(void);
    extern Ec1x_Type Check_Ec1x_Press(uint8_t site);

#ifdef __cplusplus
}
#endif
#endif /*__EC11_H__ */
