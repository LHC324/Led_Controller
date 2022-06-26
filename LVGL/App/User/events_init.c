/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "tim.h"
#include "Flash.h"

#define CMYK_COLOR_MAX 100U
#define CMYK_COLOR_MIN 0U
#define LONG_PRESS_VALUE 5U
#define COUNTS_MAX 9999.9F
#define COUNTS_MIN 0.0F
#define TIMER_STEP1 10.0F
#define TIMER_STEP2 1.0F
#define TIMER_STEP3 0.1F

extern void Debug(const char *format, ...);

/**/

void events_init(lv_ui *ui)
{
}

static void Main_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!lv_obj_is_valid(guider_ui.Menue))
			setup_scr_Menue(&guider_ui);
		lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Menue, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
	}
	break;
	default:
		break;
	}
}

void events_init_Main(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Main_btn_1, Main_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void Menue_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!lv_obj_is_valid(guider_ui.CMYK_Revise))
			setup_scr_CMYK_Revise(&guider_ui);
		lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.CMYK_Revise, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
	}
	break;
	default:
		break;
	}
}

static void Menue_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!lv_obj_is_valid(guider_ui.Timer))
			setup_scr_Timer(&guider_ui);
		lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Timer, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
	}
	break;
	default:
		break;
	}
}

static void Menue_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!lv_obj_is_valid(guider_ui.Calendar))
			setup_scr_Calendar(&guider_ui);
		lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Calendar, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
	}
	break;
	default:
		break;
	}
}

static void Menue_btn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!lv_obj_is_valid(guider_ui.Screen_Brightness))
			setup_scr_Screen_Brightness(&guider_ui);
		lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Screen_Brightness, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
	}
	break;
	default:
		break;
	}
}

static void Menue_btn_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!lv_obj_is_valid(guider_ui.Buzzer))
			setup_scr_Buzzer(&guider_ui);
		lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Buzzer, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
	}
	break;
	default:
		break;
	}
}

static void Menue_btn_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!lv_obj_is_valid(guider_ui.Main))
			setup_scr_Main(&guider_ui);
		lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Main, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
	}
	break;
	default:
		break;
	}
}

void events_init_Menue(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Menue_btn_1, Menue_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Menue_btn_2, Menue_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Menue_btn_3, Menue_btn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Menue_btn_4, Menue_btn_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Menue_btn_5, Menue_btn_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Menue_btn_6, Menue_btn_6_event_handler, LV_EVENT_ALL, NULL);
}

// static void CMYK_Revise_btn_event_handler(lv_event_t *e)
// {
// 	lv_ui *ui = (lv_ui *)e->user_data;
// 	if (!ui)
// 		return;
// 	uint32_t id = (e->current_target == ui->CMYK_Revise_btn_1) ? 1 : (e->current_target == ui->CMYK_Revise_btn_2) ? 2
// 																 : (e->current_target == ui->CMYK_Revise_btn_3)	  ? 3
// 																 : (e->current_target == ui->CMYK_Revise_btn_4)	  ? 4
// 																 : (e->current_target == ui->CMYK_Revise_btn_5)	  ? 5
// 																												  : 0;

// 	lv_event_code_t code = lv_event_get_code(e);
// 	uint8_t *pvalue = NULL;
// 	lv_obj_t *pobj = NULL;
// 	//	static bool editing = false;
// 	switch (id)
// 	{
// 	case 1:
// 	{
// 		switch (code)
// 		{
// 		case LV_EVENT_PRESSED:
// 		{
// 			if (!lv_obj_is_valid(ui->Menue))
// 				setup_scr_Menue(ui);
// 			lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
// 			if (d->prev_scr == NULL && d->scr_to_load == NULL)
// 				lv_scr_load_anim(ui->Menue, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
// 			guser.test_flag = false;
// 			/*参数保存到falsh*/
// 			FLASH_Write(SAVE_PARAM_FLASH_ADDR, (uint32_t *)&guser, sizeof(guser));
// 		}
// 		break;
// 		default:
// 			break;
// 		}
// 	}
// 	break;
// 	case 2:
// 	{
// 		pvalue = &guser.Ws281x_Cmyk.C.C;
// 		pobj = ui->CMYK_Revise_btn_2_label;
// 	}
// 	break;
// 	case 3:
// 	{
// 		pvalue = &guser.Ws281x_Cmyk.C.M;
// 		pobj = ui->CMYK_Revise_btn_3_label;
// 	}
// 	break;
// 	case 4:
// 	{
// 		pvalue = &guser.Ws281x_Cmyk.C.Y;
// 		pobj = ui->CMYK_Revise_btn_4_label;
// 	}
// 	break;
// 	case 5:
// 	{
// 		pvalue = &guser.Ws281x_Cmyk.C.K;
// 		pobj = ui->CMYK_Revise_btn_5_label;
// 	}
// 	break;
// 	default:
// 		break;
// 	}

// 	if ((!pvalue) || (!pobj))
// 		return;

// 	lv_group_t *group = lv_obj_get_group(e->current_target);
// 	switch (code)
// 	{
// 		// lv_indev_get_key(lv_indev_get_act());
// 		// 		// lv_indev_data_t data;
// 		// 		/*Read the data*/
// 		// 		// _lv_indev_read(lv_indev_get_act(), &data);
// 	case LV_EVENT_PRESSED:
// 	{
// 		if (group)
// 		{
// 			// editing ^= true;
// 			// lv_group_set_editing(group, editing);
// 			lv_group_set_editing(group, true);
// 		}
// 	}
// 	break;
// 	case LV_EVENT_LONG_PRESSED:
// 	{
// 		if (group)
// 		{
// 			lv_group_set_editing(group, false);
// 			// if (e->current_target->styles->style)
// 			// 	lv_style_init(e->current_target->styles->style);
// 		}
// 	}
// 	break;
// 	case LV_EVENT_KEY:
// 	{
// 		switch (lv_indev_get_act()->proc.types.keypad.last_key)
// 		{
// 		case LV_KEY_RIGHT:
// 		{
// 			if ((*pvalue) < CMYK_COLOR_MAX)
// 			{
// 				(*pvalue)++;
// 			}
// 		}
// 		break;
// 		case LV_KEY_LEFT:
// 		{
// 			if ((*pvalue))
// 			{
// 				(*pvalue)--;
// 			}
// 		}
// 		break;
// 		default:
// 			break;
// 		}
// 		/*实时输出当前颜色*/
// 		guser.test_flag = true;
// 		// Ws281x->WS281x_CmykToRgb(Ws281x, guser.Ws281x_Cmyk, 0);
// 		lv_label_set_text_fmt(pobj, "%d", *pvalue);
// #if defined(USING_DEBUG)
// 		Debug("CMYK_Revise_btn_2_event_code = %d.\r\n", lv_indev_get_act()->proc.types.keypad.last_key);
// #endif
// 	}
// 	break;
// 	default:
// 		break;
// 	}
// }

static void CMYK_Revise_btn_event_handler(lv_event_t *e)
{
	lv_ui *ui = (lv_ui *)e->user_data;
	if (!ui)
		return;
	uint32_t id = (e->current_target == ui->CMYK_Revise_btn_1) ? 1 : (e->current_target == ui->CMYK_Revise_btn_2) ? 2
																 : (e->current_target == ui->CMYK_Revise_btn_3)	  ? 3
																 : (e->current_target == ui->CMYK_Revise_btn_4)	  ? 4
																 : (e->current_target == ui->CMYK_Revise_btn_5)	  ? 5
																												  : 0;

	lv_event_code_t code = lv_event_get_code(e);
	/*确认操作设备0时记录聚焦对象*/
	bool sure_flag = (lv_indev_get_act() == indev_encoder[0]);

	switch (id)
	{
	case 1:
	{
		switch (code)
		{
		case LV_EVENT_PRESSED:
		{
			if (!lv_obj_is_valid(ui->Menue))
				setup_scr_Menue(ui);
			lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
			if (d->prev_scr == NULL && d->scr_to_load == NULL)
				lv_scr_load_anim(ui->Menue, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
			guser.test_flag = false;
			/*参数保存到falsh*/
			FLASH_Write(SAVE_PARAM_FLASH_ADDR, (uint32_t *)&guser, sizeof(guser));
			guser.focus_obj.ptarget = NULL;
			guser.focus_obj.pvalue = NULL;
		}
		break;
		default:
			break;
		}
	}
	break;
	case 2:
	{
		if (sure_flag)
		{
			guser.focus_obj.ptarget = ui->CMYK_Revise_btn_2_label;
			guser.focus_obj.pvalue = &guser.Ws281x_Cmyk.C.C;
		}
	}
	break;
	case 3:
	{

		if (sure_flag)
		{
			guser.focus_obj.ptarget = ui->CMYK_Revise_btn_3_label;
			guser.focus_obj.pvalue = &guser.Ws281x_Cmyk.C.M;
		}
	}
	break;
	case 4:
	{
		if (sure_flag)
		{
			guser.focus_obj.ptarget = ui->CMYK_Revise_btn_4_label;
			guser.focus_obj.pvalue = &guser.Ws281x_Cmyk.C.Y;
		}
	}
	break;
	case 5:
	{
		if (sure_flag)
		{
			guser.focus_obj.ptarget = ui->CMYK_Revise_btn_5_label;
			guser.focus_obj.pvalue = &guser.Ws281x_Cmyk.C.K;
		}
	}
	break;
	default:
		break;
	}

	if ((!guser.focus_obj.pvalue) || (!guser.focus_obj.ptarget) ||
		(lv_indev_get_act() != indev_encoder[1]))
		return;

	// lv_group_t *group = lv_obj_get_group(e->current_target);
	switch (code)
	{
		// lv_indev_get_key(lv_indev_get_act());
		// 		// lv_indev_data_t data;
		// 		/*Read the data*/
		// _lv_indev_read(lv_indev_get_act(), &data);
	case LV_EVENT_PRESSED:
	{
		// if (group)
		// {
		// 	// editing ^= true;
		// 	// lv_group_set_editing(group, editing);
		// 	lv_group_set_editing(group, true);
		// }
	}
	break;
	case LV_EVENT_LONG_PRESSED:
	{
		// if (group)
		// {
		// 	lv_group_set_editing(group, false);
		// 	// if (e->current_target->styles->style)
		// 	// 	lv_style_init(e->current_target->styles->style);
		// }
	}
	break;
	case LV_EVENT_KEY:
	{
		switch (lv_indev_get_act()->proc.types.keypad.last_key)
		{
		case LV_KEY_RIGHT:
		{
			if ((*guser.focus_obj.pvalue) < CMYK_COLOR_MAX)
			{
				(*guser.focus_obj.pvalue)++;
			}
		}
		break;
		case LV_KEY_LEFT:
		{
			if ((*guser.focus_obj.pvalue))
			{
				(*guser.focus_obj.pvalue)--;
			}
		}
		break;
		default:
			break;
		}
		/*实时输出当前颜色*/
		guser.test_flag = true;
		// Ws281x->WS281x_CmykToRgb(Ws281x, guser.Ws281x_Cmyk, 0);
		// lv_label_set_text_fmt(pobj, "%d", *pvalue);
		lv_label_set_text_fmt(guser.focus_obj.ptarget, "%d", *guser.focus_obj.pvalue);
#if defined(USING_DEBUG)
		Debug("CMYK_Revise_btn_2_event_code = %d.\r\n", lv_indev_get_act()->proc.types.keypad.last_key);
#endif
	}
	break;
	default:
		break;
	}
}

void events_init_CMYK_Revise(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->CMYK_Revise_btn_1, CMYK_Revise_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->CMYK_Revise_btn_2, CMYK_Revise_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->CMYK_Revise_btn_3, CMYK_Revise_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->CMYK_Revise_btn_4, CMYK_Revise_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->CMYK_Revise_btn_5, CMYK_Revise_btn_event_handler, LV_EVENT_ALL, ui);
}

static void Timer_btn_event_handler(lv_event_t *e)
{
	lv_ui *ui = (lv_ui *)e->user_data;
	if (!ui)
		return;
	uint32_t id = (e->current_target == ui->Timer_btn_1) ? 1 : (e->current_target == ui->Timer_btn_2) ? 2
														   : (e->current_target == ui->Timer_btn_3)	  ? 3
																									  : 0;

	lv_event_code_t code = lv_event_get_code(e);
	lv_group_t *group = lv_obj_get_group(e->current_target);
	// static bool editing[] = {false, false, false};
	if (!group)
		return;

	switch (id)
	{
	case 1:
	{
		switch (code)
		{
			/*手动触发的实时刷新事件*/
		case LV_EVENT_VALUE_CHANGED:
		{
			float *pdata = (float *)lv_event_get_param(e);
			sprintf((char *)guser.temp_data, "%.1f", *pdata);
			lv_label_set_text_fmt(ui->Timer_btn_3_label, "%sS", guser.temp_data);
		}
		break;
		case LV_EVENT_PRESSED:
		{
			// editing[0] ^= true;
			// lv_group_set_editing(group, editing[0]);
			if (guser.timer_counts)
			{
				lv_label_set_text(ui->Timer_btn_1_label, "S");
				/*设置CCR寄存器*/
				__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 0);
				if (++guser.counter >= 2U)
				{
					guser.system_start = true;
				}
			}
		}
		break;
		case LV_EVENT_LONG_PRESSED:
		{
			// lv_label_set_text(ui->Timer_btn_1_label, "Stop");
			// guser.system_start = false;
			// lv_label_set_text(ui->Timer_btn_1_label, "S");
			// if (++guser.counter >= 2U)
			// {
			// 	/*设置CCR寄存器*/
			// 	__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 0);
			// 	guser.system_start = true;
			// }
		}
		break;
		case LV_EVENT_KEY:
		{
			switch (lv_indev_get_act()->proc.types.keypad.last_key)
			{
			case LV_KEY_RIGHT:
			{
				if (guser.timer_counts + TIMER_STEP1 < COUNTS_MAX)
				{
					guser.timer_counts += TIMER_STEP1;
				}
			}
			break;
			case LV_KEY_LEFT:
			{
				if (guser.timer_counts - TIMER_STEP1 >= COUNTS_MIN)
				{
					guser.timer_counts -= TIMER_STEP1;
				}
			}
			break;
			default:
				break;
			}
		}
		break;
		default:
			break;
		}
	}
	break;
	case 2:
	{
		switch (code)
		{
			/*手动触发的实时刷新事件*/
		case LV_EVENT_VALUE_CHANGED:
		{
			lv_label_set_text(guider_ui.Timer_btn_1_label, "R");
		}
		break;
		case LV_EVENT_PRESSED:
		{
			// editing[1] ^= true;
			// lv_group_set_editing(group, editing[1]);
		}
		break;
		case LV_EVENT_KEY:
		{
			switch (lv_indev_get_act()->proc.types.keypad.last_key)
			{
			case LV_KEY_RIGHT:
			{
				if (guser.timer_counts + TIMER_STEP2 < COUNTS_MAX)
				{
					guser.timer_counts += TIMER_STEP2;
				}
			}
			break;
			case LV_KEY_LEFT:
			{
				if (guser.timer_counts - TIMER_STEP2 >= COUNTS_MIN)
				{
					guser.timer_counts -= TIMER_STEP2;
				}
			}
			break;
			default:
				break;
			}
		}
		break;
		default:
			break;
		}
	}
	break;
	case 3:
	{
		switch (code)
		{
		case LV_EVENT_PRESSED:
		{
			// lv_group_set_editing(group, editing[2]);
			if (!lv_obj_is_valid(ui->Menue))
				setup_scr_Menue(ui);
			lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
			if (d->prev_scr == NULL && d->scr_to_load == NULL)
				lv_scr_load_anim(ui->Menue, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
			/*打开屏幕背光*/
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, guser.brightness);
			/*清空次数*/
			guser.counter = 0;
			guser.system_start = false;
			/*强制退出，清空计数值*/
			guser.timer_counts = 0;
			/*参数保存到falsh*/
			FLASH_Write(SAVE_PARAM_FLASH_ADDR, (uint32_t *)&guser, sizeof(guser));
		}
		break;
		case LV_EVENT_LONG_PRESSED:
		{
			// if (!lv_obj_is_valid(ui->Menue))
			// 	setup_scr_Menue(ui);
			// lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
			// if (d->prev_scr == NULL && d->scr_to_load == NULL)
			// 	lv_scr_load_anim(ui->Menue, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
			// /*打开屏幕背光*/
			// __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, guser.brightness);
			// /*清空次数*/
			// guser.counter = 0;
			// guser.system_start = false;
			// /*强制退出，清空计数值*/
			// guser.timer_counts = 0;
			// /*参数保存到falsh*/
			// FLASH_Write(SAVE_PARAM_FLASH_ADDR, (uint32_t *)&guser, sizeof(guser));
		}
		break;
		case LV_EVENT_KEY:
		{
			switch (lv_indev_get_act()->proc.types.keypad.last_key)
			{
				/*编码器3极性与1、2相反*/
			case LV_KEY_LEFT:
			{
				if (guser.timer_counts + TIMER_STEP3 < COUNTS_MAX)
				{
					guser.timer_counts += TIMER_STEP3;
				}
			}
			break;
			case LV_KEY_RIGHT:
			{
				if (guser.timer_counts - TIMER_STEP3 >= COUNTS_MIN)
				{
					guser.timer_counts -= TIMER_STEP3;
				}
			}
			break;
			default:
				break;
			}
		}
		break;
		default:
			break;
		}
	}
	break;
	default:
		break;
	}
	sprintf((char *)guser.temp_data, "%.1f", guser.timer_counts);
	lv_label_set_text_fmt(ui->Timer_btn_3_label, "%sS", guser.temp_data);
}

void events_init_Timer(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Timer_btn_1, Timer_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Timer_btn_2, Timer_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Timer_btn_3, Timer_btn_event_handler, LV_EVENT_ALL, ui);
}

static void Calendar_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!lv_obj_is_valid(guider_ui.Menue))
			setup_scr_Menue(&guider_ui);
		lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Menue, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
	}
	break;
	default:
		break;
	}
}

void events_init_Calendar(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Calendar_btn_1, Calendar_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void Screen_Brightness_slider_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		guser.brightness = lv_slider_get_value(guider_ui.Screen_Brightness_slider_1);
		sprintf((char *)guser.temp_data, "%d", guser.brightness);
		lv_label_set_text_fmt(guider_ui.Screen_Brightness_label_3, "%s%%", guser.temp_data);
		/*设置CCR寄存器*/
		__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, guser.brightness);
	}
	break;
	default:
		break;
	}
#if defined(USING_DEBUG)
	Debug("slider_1 event_code = %d.\r\n", code);
#endif
}

static void Screen_Brightness_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!lv_obj_is_valid(guider_ui.Menue))
			setup_scr_Menue(&guider_ui);
		lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Menue, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
		/*参数保存到falsh*/
		FLASH_Write(SAVE_PARAM_FLASH_ADDR, (uint32_t *)&guser, sizeof(guser));
	}
	break;
	default:
		break;
	}
}

void events_init_Screen_Brightness(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Screen_Brightness_slider_1, Screen_Brightness_slider_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Screen_Brightness_btn_1, Screen_Brightness_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void Buzzer_sw_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *obj = lv_event_get_target(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		guser.buzzer_switch = lv_obj_has_state(obj, LV_STATE_CHECKED); //? true : false;
#if defined(USING_DEBUG)
		Debug("switch_state = %d.\r\n", guser.buzzer_switch);
#endif
	}
	break;
	default:
		break;
	}
}

static void Buzzer_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!lv_obj_is_valid(guider_ui.Menue))
			setup_scr_Menue(&guider_ui);
		lv_disp_t *d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Menue, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
		/*参数保存到falsh*/
		FLASH_Write(SAVE_PARAM_FLASH_ADDR, (uint32_t *)&guser, sizeof(guser));
	}
	break;
	default:
		break;
	}
}

static void Buzzer_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		if (!guser.buzzer_switch)
		{
			guser.buzzer_switch = true;
			lv_obj_add_state(guider_ui.Buzzer_sw_1, LV_STATE_CHECKED);
		}
		else
		{
			guser.buzzer_switch = false;
			lv_obj_clear_state(guider_ui.Buzzer_sw_1, LV_STATE_CHECKED);
		}
#if defined(USING_DEBUG)
		Debug("switch_state = %d.\r\n", guser.buzzer_switch);
#endif
	}
	break;
	default:
		break;
	}
}

void events_init_Buzzer(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Buzzer_sw_1, Buzzer_sw_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Buzzer_btn_1, Buzzer_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Buzzer_btn_2, Buzzer_btn_2_event_handler, LV_EVENT_ALL, NULL);
}
