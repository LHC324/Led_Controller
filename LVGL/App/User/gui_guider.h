/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
#include "guider_fonts.h"
#include "lv_port_indev.h"
#include "ws2812.h"

#define SAVE_PARAM_FLASH_ADDR 0x08060000

	typedef struct
	{
		lv_obj_t *Main;
		lv_obj_t *Main_cont_1;
		lv_obj_t *Main_btn_1;
		lv_obj_t *Main_btn_1_label;
		lv_obj_t *Main_label_1;
		lv_obj_t *Main_analog_clock_1;
		lv_meter_indicator_t *Main_analog_clock_1_indic_hour;
		lv_meter_indicator_t *Main_analog_clock_1_indic_min;
		lv_meter_indicator_t *Main_analog_clock_1_indic_sec;
		lv_obj_t *Menue;
		lv_obj_t *Menue_cont_1;
		lv_obj_t *Menue_btn_1;
		lv_obj_t *Menue_btn_1_label;
		lv_obj_t *Menue_btn_2;
		lv_obj_t *Menue_btn_2_label;
		lv_obj_t *Menue_btn_3;
		lv_obj_t *Menue_btn_3_label;
		lv_obj_t *Menue_btn_4;
		lv_obj_t *Menue_btn_4_label;
		lv_obj_t *Menue_btn_5;
		lv_obj_t *Menue_btn_5_label;
		lv_obj_t *Menue_btn_6;
		lv_obj_t *Menue_btn_6_label;

		lv_obj_t *CMYK_Revise;
		lv_obj_t *CMYK_Revise_cont_1;
		lv_obj_t *CMYK_Revise_label_1;
		lv_obj_t *CMYK_Revise_label_2;
		lv_obj_t *CMYK_Revise_label_3;
		lv_obj_t *CMYK_Revise_label_4;
		lv_obj_t *CMYK_Revise_label_5;
		lv_obj_t *CMYK_Revise_btn_1;
		lv_obj_t *CMYK_Revise_btn_1_label;
		lv_obj_t *CMYK_Revise_btn_2;
		lv_obj_t *CMYK_Revise_btn_2_label;
		lv_obj_t *CMYK_Revise_btn_3;
		lv_obj_t *CMYK_Revise_btn_3_label;
		lv_obj_t *CMYK_Revise_btn_4;
		lv_obj_t *CMYK_Revise_btn_4_label;
		lv_obj_t *CMYK_Revise_btn_5;
		lv_obj_t *CMYK_Revise_btn_5_label;

		lv_obj_t *Timer;
		lv_obj_t *Timer_cont_1;
		lv_obj_t *Timer_label;
		lv_obj_t *Timer_btn_1;
		lv_obj_t *Timer_btn_1_label;
		lv_obj_t *Timer_btn_2;
		lv_obj_t *Timer_btn_2_label;
		lv_obj_t *Timer_btn_3;
		lv_obj_t *Timer_btn_3_label;

		lv_obj_t *Calendar;
		lv_obj_t *Calendar_cont_1;
		lv_obj_t *Calendar_label_1;
		lv_obj_t *Calendar_calendar_1;
		lv_obj_t *Calendar_btn_1;
		lv_obj_t *Calendar_btn_1_label;
		lv_obj_t *Screen_Brightness;
		lv_obj_t *Screen_Brightness_cont_1;
		lv_obj_t *Screen_Brightness_label_2;
		lv_obj_t *Screen_Brightness_slider_1;
		lv_obj_t *Screen_Brightness_btn_1;
		lv_obj_t *Screen_Brightness_btn_1_label;
		lv_obj_t *Screen_Brightness_label_3;
		lv_obj_t *Buzzer;
		lv_obj_t *Buzzer_cont_1;
		lv_obj_t *Buzzer_label_1;
		lv_obj_t *Buzzer_sw_1;
		lv_obj_t *Buzzer_btn_1;
		lv_obj_t *Buzzer_btn_1_label;
		lv_obj_t *Buzzer_btn_2;
		lv_obj_t *Buzzer_btn_2_label;
	} lv_ui;

	typedef struct
	{
		CMYK Ws281x_Cmyk;
		float timer_counts;
		bool test_flag;
		bool system_start;
		bool buzzer_switch;
		// bool buzzer_start;
		uint32_t brightness;
		uint8_t temp_data[8U];
		uint16_t counter;
		struct
		{
			struct _lv_obj_t *ptarget;
			uint8_t *pvalue;
		} focus_obj;

		uint16_t save_flag;
	} User_Info __attribute__((aligned(4)));
	extern User_Info guser;

	void setup_ui(lv_ui *ui);
	extern lv_ui guider_ui;
	// extern lv_indev_t *indev_encoder;
	extern lv_indev_t *indev_encoder[DEVICES_MAX];
	void setup_scr_Main(lv_ui *ui);
	void clock_count(int *hour, int *min, int *sec);
	void setup_scr_Menue(lv_ui *ui);
	void setup_scr_CMYK_Revise(lv_ui *ui);
	void setup_scr_Timer(lv_ui *ui);
	void setup_scr_Calendar(lv_ui *ui);
	static lv_calendar_date_t today;
	static lv_calendar_date_t highlihted_days[1];
	void setup_scr_Screen_Brightness(lv_ui *ui);
	void setup_scr_Buzzer(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif
