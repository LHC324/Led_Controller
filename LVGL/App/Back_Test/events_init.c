/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"


void events_init(lv_ui *ui)
{
}

static void screen_sw2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		bool sw_state;
		sw_state = lv_obj_has_state(guider_ui.screen_sw2, LV_STATE_CHECKED);
		if (!sw_state) {
			lv_obj_add_flag(guider_ui.screen_ddlist1, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(guider_ui.screen_roller1, LV_OBJ_FLAG_HIDDEN);
			} else {
			lv_obj_add_flag(guider_ui.screen_roller1, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(guider_ui.screen_ddlist1, LV_OBJ_FLAG_HIDDEN);
		}
	}
		break;
	default:
		break;
	}
}

void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_sw2, screen_sw2_event_handler, LV_EVENT_ALL, NULL);
}
