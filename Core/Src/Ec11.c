#include "Ec11.h"
#include "cmsis_os.h"

extern osMessageQId Ecode_QueueHandle;
extern void Debug(const char *format, ...);
/*定义Ec11事件组*/
Ec1x Ec11_Events[] = {
    {.A.pGPIOx = EC11_A1_GPIO_Port, .A.Pin = EC11_A1_Pin, .B.pGPIOx = EC11_B1_GPIO_Port, .B.Pin = EC11_B1_Pin, .Key.pGPIOx = EC11_KEY1_GPIO_Port, .Key.Pin = EC11_KEY1_Pin, .IRQn = EC11_A1_EXTI_IRQn, .First_Flag = false, .BFlag = false},
    {.A.pGPIOx = EC11_A2_GPIO_Port, .A.Pin = EC11_A2_Pin, .B.pGPIOx = EC11_B2_GPIO_Port, .B.Pin = EC11_B2_Pin, .Key.pGPIOx = EC11_KEY2_GPIO_Port, .Key.Pin = EC11_KEY2_Pin, .IRQn = EC11_A2_EXTI_IRQn, .First_Flag = false, .BFlag = false},
    {.A.pGPIOx = EC11_A3_GPIO_Port, .A.Pin = EC11_A3_Pin, .B.pGPIOx = EC11_B3_GPIO_Port, .B.Pin = EC11_B3_Pin, .Key.pGPIOx = EC11_KEY3_GPIO_Port, .Key.Pin = EC11_KEY3_Pin, .IRQn = EC11_A3_EXTI_IRQn, .First_Flag = false, .BFlag = false},
};

/**
 * @brief  EXTI line detection callbacks.
 * @param  GPIO_Pin Specifies the pins connected EXTI line
 * @retval None
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    /* Post the pin. */
    osMessagePut(Ecode_QueueHandle, GPIO_Pin, 0);
}

/**
 * @brief  获取Ec1x事件类型
 * @note   AB同电平，正转；AB异电平，反转[此事件下降沿触发]
 * @param  None
 * @return Ec1x对象事件类型
 */
#define Get_PinState(__site, __s) \
    (Ec11_Events[__site].__s.pGPIOx->IDR & Ec11_Events[__site].__s.Pin)
#define Get_First_Flag(__site) \
    (Ec11_Events[__site].First_Flag)
#define Get_BFlag(__site) \
    (Ec11_Events[__site].BFlag)
Ec1x_Type Read_Ec1x(void)
{
    Ec1x_Type ec11_type = {
        .Id = 0xFF,
        .Option = None,
    };
    osEvent event = osMessageGet(Ecode_QueueHandle, 10);
    if (event.status == osEventMessage)
    {
#if defined(USING_DEBUG)
        // Debug("osOK!\r\n");
#endif
        for (uint16_t num = 0; num < sizeof(Ec11_Events) / sizeof(Ec1x); num++)
        {
            if (event.value.v == Ec11_Events[num].A.Pin)
            {
                if ((!Get_PinState(num, A)) && (!Get_First_Flag(num)))
                {
                    Get_First_Flag(num) = true, Get_BFlag(num) = false;
                    if (Get_PinState(num, B))
                    {
                        Get_BFlag(num) = true;
                    }
                }
                /*检测A相是上升沿*/
                if ((Get_First_Flag(num)) && Get_PinState(num, A))
                {
                    Get_First_Flag(num) = false;
                    /*先检测是否按下*/
                    if (!Get_PinState(num, Key))
                    {
                        ec11_type.Option = Down;
                    }
                    /*检测到AB反向*/
                    if ((!Get_PinState(num, B)) && (Get_BFlag(num)))
                    {
                        ec11_type.Option = (Ec1x_EventType)(Reverse - ec11_type.Option);
                    }
                    else if (Get_PinState(num, B) && (!Get_BFlag(num)))
                    {
                        ec11_type.Option += Forward;
                    }
                    if ((ec11_type.Option != None) && (ec11_type.Option != Down))
                        // ec11_type.Id = num + 1U;
                        ec11_type.Id = num;
                }
                break;
            }
            /*仅仅处理按键部分*/
            // else
            // {
            //     if (event.value.v == Ec11_Events[num].Key.Pin)
            //     {
            //         // ec11_type.Id = num + 1U;
            //         ec11_type.Id = num;
            //         ec11_type.Option = Down;
            //         break;
            //     }
            // }
        }
    }
    else
    {
        for (uint16_t num = 0; num < sizeof(Ec11_Events) / sizeof(Ec1x); num++)
        {
            if (!Get_PinState(num, Key))
            {
                ec11_type.Id = num;
                ec11_type.Option = Down;
            }
            // else
            // {
            //     ec11_type.Id = num;
            //     ec11_type.Option = Up;
            // }
        }
    }

    return ec11_type;
}

/**
 * @brief  获取Ec1x事件类型
 * @note   AB同电平，正转；AB异电平，反转[此事件下降沿触发]
 * @param  None
 * @return Ec1x对象事件类型
 */
Ec1x_Type Check_Ec1x_Press(uint8_t site)
{
    Ec1x_Type ec11_type = {
        .Id = 0xFF,
        .Option = None,
    };
    if (site < sizeof(Ec11_Events) / sizeof(Ec1x))
    {
        if (!Get_PinState(site, Key))
        {
            ec11_type.Id = site;
            ec11_type.Option = Down;
        }
    }
    return ec11_type;
}
