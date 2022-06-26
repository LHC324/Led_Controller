/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "tim.h"
#include "usart.h"
#include "Lcd.h"
#include "picture.h"
#include "ws2812.h"
#include "Ec11.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_guider.h"
#include "events_init.h"
//#include "lv_examples.h"
//#include "lv_demo_benchmark.h"
#include "Flash.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
bool g_OsRun = false;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId cmykHandle;
osThreadId lcdHandle;
osThreadId EcodingHandle;
osMessageQId Ecode_QueueHandle;
osTimerId counterHandle;
osTimerId ReportHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
#if LV_USE_LOG
void my_log_cb(const char *buf)
{
  extern uint8_t CDC_Transmit_FS(uint8_t * Buf, uint16_t Len);
  CDC_Transmit_FS((uint8_t *)buf, strlen(buf));
}
#endif
/* USER CODE END FunctionPrototypes */

void Cmyk_Task(void const *argument);
void Lcd_Task(void const *argument);
void Ecoding_Task(void const *argument);
void Counter_Callback(void const *argument);
void Report_Callback(void const *argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize);

/* GetTimerTaskMemory prototype (linked to static allocation support) */
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize);

/* Hook prototypes */
void vApplicationTickHook(void);
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);
void vApplicationMallocFailedHook(void);

/* USER CODE BEGIN 3 */
__weak void vApplicationTickHook(void)
{
  /* This function will be called by each tick interrupt if
  configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h. User code can be
  added here, but the tick hook is called from an interrupt context, so
  code must not attempt to block, and only the interrupt safe FreeRTOS API
  functions can be used (those that end in FromISR()). */
  /*Lvgl heartbeat*/
#if (!LV_TICK_CUSTOM)
  lv_tick_inc(1);
#endif
#if defined(USING_DEBUG)
  // Debug("note: time slice trigger.\r\n");
#endif
}
/* USER CODE END 3 */

/* USER CODE BEGIN 4 */
__weak void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
/* Run time stack overflow checking is performed if
configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
called if a stack overflow is detected. */
#if defined(USING_DEBUG)
  Debug("Error: Task %s is Stack Overflow!\r\n", *pcTaskName);
#endif
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
__weak void vApplicationMallocFailedHook(void)
{
/* vApplicationMallocFailedHook() will only be called if
configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
function that will get called if a call to pvPortMalloc() fails.
pvPortMalloc() is called internally by the kernel whenever a task, queue,
timer or semaphore is created. It is also called by various parts of the
demo application. If heap_1.c or heap_2.c are used, then the size of the
heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
to query the size of free heap space that remains (although it does not
provide information on how the remaining heap might be fragmented). */
#if defined(USING_DEBUG)
  Debug("Error: memory allocation failed !\r\n");
#endif
}
/* USER CODE END 5 */

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/* USER CODE BEGIN GET_TIMER_TASK_MEMORY */
static StaticTask_t xTimerTaskTCBBuffer;
static StackType_t xTimerStack[configTIMER_TASK_STACK_DEPTH];

void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize)
{
  *ppxTimerTaskTCBBuffer = &xTimerTaskTCBBuffer;
  *ppxTimerTaskStackBuffer = &xTimerStack[0];
  *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
  /* place for user code */
}
/* USER CODE END GET_TIMER_TASK_MEMORY */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void)
{
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* definition and creation of counter */
  osTimerDef(counter, Counter_Callback);
  counterHandle = osTimerCreate(osTimer(counter), osTimerPeriodic, NULL);

  /* definition and creation of Report */
  osTimerDef(Report, Report_Callback);
  ReportHandle = osTimerCreate(osTimer(Report), osTimerPeriodic, NULL);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  // extern TIM_HandleTypeDef htim2;
  // HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  // static uint16_t pulse[] = {
  //     0,
  //     60,
  //     80,
  //     0,
  //     40,
  //     30,
  // };
  // HAL_TIM_PWM_Start_DMA(&htim5, TIM_CHANNEL_1, (uint32_t *)pulse, sizeof(pulse));
  osTimerStart(counterHandle, 200U);
  osTimerStart(ReportHandle, 1000U);
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of Ecode_Queue */
  osMessageQDef(Ecode_Queue, 16, uint16_t);
  Ecode_QueueHandle = osMessageCreate(osMessageQ(Ecode_Queue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of cmyk */
  osThreadDef(cmyk, Cmyk_Task, osPriorityNormal, 0, 512);
  cmykHandle = osThreadCreate(osThread(cmyk), NULL);

  /* definition and creation of lcd */
  osThreadDef(lcd, Lcd_Task, osPriorityHigh, 0, 2048);
  lcdHandle = osThreadCreate(osThread(lcd), NULL);

  /* definition and creation of Ecoding */
  osThreadDef(Ecoding, Ecoding_Task, osPriorityRealtime, 0, 1024);
  EcodingHandle = osThreadCreate(osThread(Ecoding), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  //   MX_USB_DEVICE_Init();
  //   MX_LCD_Init();
  //   MX_WS281x_Init();
  //   /*Initialize littleVGL*/
  //   lv_init();
  //   /*lvgl display interface initialization, placed after lv_init()*/
  //   lv_port_disp_init();
  //   /*lvgl input interface initialization, placed after lv_init()*/
  //   lv_port_indev_init();
  // #if LV_USE_LOG
  //   /*Registered user log output*/
  //   lv_log_register_print_cb(my_log_cb);
  // #endif
  //   /*Create a GUI-Guider app */
  //   setup_ui(&guider_ui);
  if ((guser.save_flag == 0x5AA5) || (guser.save_flag == 0xFFFF))
  {
    guser.save_flag = 0xA55A;
    FLASH_Write(SAVE_PARAM_FLASH_ADDR, (uint32_t *)&guser, sizeof(guser));
  }
  else
  {
    // FLASH_Write(SAVE_PARAM_FLASH_ADDR, (uint32_t *)&guser, sizeof(guser));
    FLASH_Read(SAVE_PARAM_FLASH_ADDR, &guser, sizeof(guser));
  }
  __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, guser.brightness);
  /* USER CODE END RTOS_THREADS */
}

/* USER CODE BEGIN Header_Cmyk_Task */
/**
 * @brief  Function implementing the cmyk thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_Cmyk_Task */
void Cmyk_Task(void const *argument)
{
  //   /* init code for USB_DEVICE */
  //   MX_USB_DEVICE_Init();
  //   /* USER CODE BEGIN Cmyk_Task */
  //   g_OsRun = true;
  //   MX_LCD_Init();
  //   MX_WS281x_Init();
  //   /*Initialize littleVGL*/
  //   lv_init();
  //   /*lvgl display interface initialization, placed after lv_init()*/
  //   lv_port_disp_init();
  //   /*lvgl input interface initialization, placed after lv_init()*/
  //   lv_port_indev_init();
  // #if LV_USE_LOG
  //   /*Registered user log output*/
  //   lv_log_register_print_cb(my_log_cb);
  // #endif
  //   /*Create a GUI-Guider app */
  //   setup_ui(&guider_ui);
  // _lv_group_init();
  //  taskENTER_CRITICAL();
  //  lv_example_anim_1();
  //  taskEXIT_CRITICAL();
  // lv_demo_benchmark();
  CMYK cmyk = {
      .C.C = 0,
      .C.M = 0,
      .C.Y = 0,
      .C.K = 100,
  };
  /*Continuously calling lv_label_set_text will cause memory overflow*/
  // bool first_flag = false;
  /* Infinite loop */
  for (;;)
  {
#if defined(USING_DEBUG)
    // Debug("Cmyk_Task is running!\r\n");
    // //	  osDelay(10);
    // Debug("hello world!\r\n");
#endif
    if (Ws281x)
    {
      // Ws281x->WS281x_Test(Ws281x);
      // lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
      while (guser.test_flag)
      {
        Ws281x->WS281x_CmykToRgb(Ws281x, guser.Ws281x_Cmyk, 1000);
      }
      if ((guser.system_start == true) && ((guser.timer_counts - 1.0F) >= 0))
      {
        guser.timer_counts--;
        if (guser.timer_counts < 1.0F)
        {
          guser.timer_counts = 0;
        }
        if (lv_scr_act() == guider_ui.Timer)
          lv_event_send(guider_ui.Timer_btn_1, LV_EVENT_VALUE_CHANGED, &guser.timer_counts);
        // first_flag = false;
        Ws281x->WS281x_CmykToRgb(Ws281x, guser.Ws281x_Cmyk, 1000 - 200);
        if (guser.buzzer_switch)
        {
          // osTimerStart(counterHandle, 200U);
          // HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin);
          HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET);
          osDelay(200);
          HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
        }
        else
        {
          // osTimerStop(counterHandle);
          HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
        }
      }
      else
      {
        guser.system_start = false;
        // if ((d->prev_scr == guider_ui.Timer) && guider_ui.Timer_btn_1_label)
        // if (guider_ui.Timer_btn_1_label && !first_flag)
        // {
        //   first_flag = true;
        //   lv_label_set_text(guider_ui.Timer_btn_1_label, "R");
        // }
        if (lv_scr_act() == guider_ui.Timer)
          lv_event_send(guider_ui.Timer_btn_2, LV_EVENT_VALUE_CHANGED, NULL);
        Ws281x->WS281x_CmykToRgb(Ws281x, cmyk, 1000);
      }
    }
    // osDelay(1000);
  }
  /* USER CODE END Cmyk_Task */
}

/* USER CODE BEGIN Header_Lcd_Task */
/**
 * @brief Function implementing the lcd thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_Lcd_Task */
void Lcd_Task(void const *argument)
{
  /* USER CODE BEGIN Lcd_Task */
  /* Infinite loop */
  for (;;)
  {
    lv_task_handler();
#if defined(USING_DEBUG)
    // Debug("Lcd_Task is Running!\r\n");
#endif
    osDelay(10);
  }
  /* USER CODE END Lcd_Task */
}

/* USER CODE BEGIN Header_Ecoding_Task */
/**
 * @brief Function implementing the Ecoding thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_Ecoding_Task */
void Ecoding_Task(void const *argument)
{
  /* USER CODE BEGIN Ecoding_Task */
  // static uint8_t counts = 0;
  // static int value = 0;
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN Cmyk_Task */
  g_OsRun = true;
  MX_LCD_Init();
  MX_WS281x_Init();
  /*Initialize littleVGL*/
  lv_init();
  /*lvgl display interface initialization, placed after lv_init()*/
  lv_port_disp_init();
  /*lvgl input interface initialization, placed after lv_init()*/
  lv_port_indev_init();
#if LV_USE_LOG
  /*Registered user log output*/
  lv_log_register_print_cb(my_log_cb);
#endif
  /*Create a GUI-Guider app */
  setup_ui(&guider_ui);
  /* Infinite loop */
  for (;;)
  {
    Ec1x_Type type = Read_Ec1x();
    extern void encoder_handler(Ec1x_Type * ptype);

    encoder_handler(&type);
    // HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET);
    // guser.buzzer_start = true;
    // osTimerStart(counterHandle, 100);
    // osTimerStart(counterHandle, 100U);
    //     if ((type.Id != 0xFF) && (type.Option != None))
    //     {
    // #if defined(USING_DEBUG)
    // Debug("id = %d, type = %d\r\n", type.Id, type.Option);
    //       // Debug("id = %d, type = %d\r\n", type.Id, value / 20);
    // #endif
    //     }
    // Debug("hello world!\r\n");
  }
  /* USER CODE END Ecoding_Task */
}

/* Counter_Callback function */
void Counter_Callback(void const *argument)
{
  /* USER CODE BEGIN Counter_Callback */
  // extern void Lcd_test(void);
  // Lcd_test();
  // static RGB888 rgb = {.Color = 0x00FFFFFF};

  // //  rgb.C.R ? (rgb.C.G ? (rgb.C.B ? (rgb.C.B--) : (rgb.C.B = 0xFF, rgb.C.G--)) : (rgb.C.G = 0xFF, rgb.C.R--)) : (rgb.C.R = rgb.C.G = rgb.C.B = 0xFF);
  // rgb.C.R ? (rgb.C.G ? (rgb.C.B ? (rgb.C.B -= 51U) : (rgb.C.B = 0xFF, rgb.C.G -= 51U)) : (rgb.C.G = 0xFF, rgb.C.R -= 51U)) : (rgb.C.R = rgb.C.G = rgb.C.B = 0xFF);
  // if (Lcd)
  // {
  //   Lcd->Region.Color = (uint16_t)RGB888_TO_RGB565(rgb.Color);
  //   Lcd->LCD_Test(Lcd);
  // }

  // Lcd->Region.X.start = 0;
  // Lcd->Region.X.end = 99;
  // Lcd->Region.X.len = 100;
  // Lcd->Region.Y.start = 0;
  // Lcd->Region.Y.end = 99;
  // Lcd->Region.Y.len = 100;
  // Lcd->LCD_DisPicture(Lcd, gImage_Pic);

#if defined(USING_DEBUG)
  // Debug("Color is 0x%x.\r\n", rgb.Color);
#endif
  // HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin);
  // osTimerStop(counterHandle);
  /* USER CODE END Counter_Callback */
}

/* Report_Callback function */
void Report_Callback(void const *argument)
{
  /* USER CODE BEGIN Report_Callback */
  // if (Ws281x)
  // {
  //   Ws281x->WS281x_Test(Ws281x);
  // }
  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
#if defined(USING_DEBUG)
  // Debug("Report callback.\r\n");
#endif
  /* USER CODE END Report_Callback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
