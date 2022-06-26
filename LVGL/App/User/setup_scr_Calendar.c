/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

static void Calendar_calendar_1draw_part_begin_event_cb(lv_event_t *e)
{
	lv_obj_t *obj = lv_event_get_target(e);
	lv_obj_draw_part_dsc_t *dsc = lv_event_get_param(e);
	if (dsc->part == LV_PART_ITEMS)
	{
		if (dsc->id < 7)
		{
			dsc->label_dsc->color = lv_color_make(0xff, 0xff, 0xff);
			dsc->label_dsc->font = &lv_font_montserrat_12;
		}
		else if (lv_btnmatrix_has_btn_ctrl(obj, dsc->id, LV_BTNMATRIX_CTRL_DISABLED))
		{
			dsc->rect_dsc->bg_color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad_color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad_dir = LV_GRAD_DIR_VER;
			dsc->rect_dsc->bg_opa = 94;
			dsc->label_dsc->color = lv_color_make(0xA9, 0xA2, 0xA2);
			dsc->label_dsc->font = &lv_font_montserrat_12;
		}
		if (lv_btnmatrix_has_btn_ctrl(obj, dsc->id, LV_BTNMATRIX_CTRL_CUSTOM_1))
		{
			dsc->rect_dsc->bg_color = lv_color_make(0x01, 0xf9, 0x3f);
			dsc->rect_dsc->bg_grad_color = lv_color_make(0xbe, 0xc5, 0x9b);
			dsc->rect_dsc->bg_grad_dir = LV_GRAD_DIR_VER;
			dsc->rect_dsc->bg_opa = 159;
			dsc->rect_dsc->border_color = lv_color_make(0xff, 0xff, 0xff);
			dsc->rect_dsc->border_width = 1;
			dsc->label_dsc->color = lv_color_make(0xff, 0xff, 0xff);
			dsc->label_dsc->font = &lv_font_montserrat_12;
		}
		if (lv_btnmatrix_has_btn_ctrl(obj, dsc->id, LV_BTNMATRIX_CTRL_CUSTOM_2))
		{
			dsc->rect_dsc->bg_color = lv_color_make(0xff, 0xff, 0xff);
			dsc->rect_dsc->bg_grad_color = lv_color_make(0x25, 0x97, 0xf4);
			dsc->rect_dsc->bg_grad_dir = LV_GRAD_DIR_VER;
			dsc->rect_dsc->bg_opa = 0;
			dsc->label_dsc->color = lv_color_make(0xff, 0xff, 0xff);
			dsc->label_dsc->font = &lv_font_montserrat_12;
		}
	}
}

void setup_scr_Calendar(lv_ui *ui)
{

	// Write codes Calendar
	ui->Calendar = lv_obj_create(NULL);

	// Write style state: LV_STATE_DEFAULT for style_calendar_main_main_default
	static lv_style_t style_calendar_main_main_default;
	if (style_calendar_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_calendar_main_main_default);
	else
		lv_style_init(&style_calendar_main_main_default);
	lv_style_set_bg_color(&style_calendar_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_calendar_main_main_default, 0);
	lv_obj_add_style(ui->Calendar, &style_calendar_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Calendar_cont_1
	ui->Calendar_cont_1 = lv_obj_create(ui->Calendar);
	lv_obj_set_pos(ui->Calendar_cont_1, 0, 0);
	lv_obj_set_size(ui->Calendar_cont_1, 480, 320);

	// Write style state: LV_STATE_DEFAULT for style_calendar_cont_1_main_main_default
	static lv_style_t style_calendar_cont_1_main_main_default;
	if (style_calendar_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_calendar_cont_1_main_main_default);
	else
		lv_style_init(&style_calendar_cont_1_main_main_default);
	lv_style_set_radius(&style_calendar_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_calendar_cont_1_main_main_default, lv_color_make(0x01, 0x04, 0x09));
	lv_style_set_bg_grad_color(&style_calendar_cont_1_main_main_default, lv_color_make(0x1b, 0x29, 0x33));
	lv_style_set_bg_grad_dir(&style_calendar_cont_1_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_calendar_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_calendar_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_calendar_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_calendar_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_calendar_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_calendar_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_calendar_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_calendar_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->Calendar_cont_1, &style_calendar_cont_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Calendar_label_1
	ui->Calendar_label_1 = lv_label_create(ui->Calendar);
	lv_obj_set_pos(ui->Calendar_label_1, 150, 20);
	lv_obj_set_size(ui->Calendar_label_1, 180, 20);
	lv_label_set_text(ui->Calendar_label_1, "Calendar");
	lv_label_set_long_mode(ui->Calendar_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->Calendar_label_1, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_calendar_label_1_main_main_default
	static lv_style_t style_calendar_label_1_main_main_default;
	if (style_calendar_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_calendar_label_1_main_main_default);
	else
		lv_style_init(&style_calendar_label_1_main_main_default);
	lv_style_set_radius(&style_calendar_label_1_main_main_default, 10);
	lv_style_set_bg_color(&style_calendar_label_1_main_main_default, lv_color_make(0xd3, 0xf6, 0x23));
	lv_style_set_bg_grad_color(&style_calendar_label_1_main_main_default, lv_color_make(0xf6, 0x23, 0x23));
	lv_style_set_bg_grad_dir(&style_calendar_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_calendar_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_calendar_label_1_main_main_default, lv_color_make(0xe7, 0xcb, 0x13));
	lv_style_set_text_font(&style_calendar_label_1_main_main_default, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_calendar_label_1_main_main_default, 1);
	lv_style_set_pad_left(&style_calendar_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_calendar_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_calendar_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_calendar_label_1_main_main_default, 0);
	lv_obj_add_style(ui->Calendar_label_1, &style_calendar_label_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Calendar_calendar_1
	ui->Calendar_calendar_1 = lv_calendar_create(ui->Calendar);
	lv_obj_set_pos(ui->Calendar_calendar_1, 100, 95);
	lv_obj_set_size(ui->Calendar_calendar_1, 280, 210);
	today.year = 2022;
	today.month = 7;
	today.day = 1;
	lv_calendar_set_today_date(ui->Calendar_calendar_1, today.year, today.month, today.day);
	lv_calendar_set_showed_date(ui->Calendar_calendar_1, today.year, today.month);
	highlihted_days[0].year = 2022;
	highlihted_days[0].month = 7;
	highlihted_days[0].day = 14;
	lv_calendar_set_highlighted_dates(ui->Calendar_calendar_1, highlihted_days, 1);
	lv_obj_t *Calendar_calendar_1_header = lv_calendar_header_arrow_create(ui->Calendar, ui->Calendar_calendar_1, 25);
	lv_obj_add_event_cb(ui->Calendar_calendar_1, Calendar_calendar_1draw_part_begin_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);

	// Write style state: LV_STATE_DEFAULT for style_calendar_calendar_1_main_main_default
	static lv_style_t style_calendar_calendar_1_main_main_default;
	if (style_calendar_calendar_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_calendar_calendar_1_main_main_default);
	else
		lv_style_init(&style_calendar_calendar_1_main_main_default);
	lv_style_set_bg_color(&style_calendar_calendar_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_calendar_calendar_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_calendar_calendar_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_calendar_calendar_1_main_main_default, 0);
	lv_style_set_border_color(&style_calendar_calendar_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_calendar_calendar_1_main_main_default, 2);
	lv_obj_add_style(ui->Calendar_calendar_1, &style_calendar_calendar_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_calendar_calendar_1_main_items_default
	static lv_style_t style_calendar_calendar_1_main_items_default;
	if (style_calendar_calendar_1_main_items_default.prop_cnt > 1)
		lv_style_reset(&style_calendar_calendar_1_main_items_default);
	else
		lv_style_init(&style_calendar_calendar_1_main_items_default);
	lv_style_set_bg_color(&style_calendar_calendar_1_main_items_default, lv_color_make(0x2f, 0x86, 0x8e));
	lv_style_set_bg_grad_color(&style_calendar_calendar_1_main_items_default, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_calendar_calendar_1_main_items_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_calendar_calendar_1_main_items_default, 0);
	lv_style_set_border_color(&style_calendar_calendar_1_main_items_default, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_calendar_calendar_1_main_items_default, 1);
	lv_style_set_text_color(&style_calendar_calendar_1_main_items_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_calendar_calendar_1_main_items_default, &lv_font_montserrat_12);
	lv_obj_add_style(ui->Calendar_calendar_1, &style_calendar_calendar_1_main_items_default, LV_PART_ITEMS | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_calendar_calendar_1_extra_header_main_default
	static lv_style_t style_calendar_calendar_1_extra_header_main_default;
	if (style_calendar_calendar_1_extra_header_main_default.prop_cnt > 1)
		lv_style_reset(&style_calendar_calendar_1_extra_header_main_default);
	else
		lv_style_init(&style_calendar_calendar_1_extra_header_main_default);
	lv_style_set_bg_color(&style_calendar_calendar_1_extra_header_main_default, lv_color_make(0xf2, 0xd3, 0x07));
	lv_style_set_bg_grad_color(&style_calendar_calendar_1_extra_header_main_default, lv_color_make(0xee, 0xc0, 0x1b));
	lv_style_set_bg_grad_dir(&style_calendar_calendar_1_extra_header_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_calendar_calendar_1_extra_header_main_default, 175);
	lv_style_set_text_color(&style_calendar_calendar_1_extra_header_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_calendar_calendar_1_extra_header_main_default, &lv_font_montserrat_12);
	lv_obj_add_style(Calendar_calendar_1_header, &style_calendar_calendar_1_extra_header_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Calendar_btn_1
	ui->Calendar_btn_1 = lv_btn_create(ui->Calendar);
	lv_obj_set_pos(ui->Calendar_btn_1, 435, 275);
	lv_obj_set_size(ui->Calendar_btn_1, 42, 42);

	// Write style state: LV_STATE_DEFAULT for style_calendar_btn_1_main_main_default
	static lv_style_t style_calendar_btn_1_main_main_default;
	if (style_calendar_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_calendar_btn_1_main_main_default);
	else
		lv_style_init(&style_calendar_btn_1_main_main_default);
	lv_style_set_radius(&style_calendar_btn_1_main_main_default, 100);
	lv_style_set_bg_color(&style_calendar_btn_1_main_main_default, lv_color_make(0x07, 0xcf, 0x68));
	lv_style_set_bg_grad_color(&style_calendar_btn_1_main_main_default, lv_color_make(0x06, 0xf4, 0xe4));
	lv_style_set_bg_grad_dir(&style_calendar_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_calendar_btn_1_main_main_default, 48);
	lv_style_set_shadow_color(&style_calendar_btn_1_main_main_default, lv_color_make(0xff, 0x00, 0x00));
	lv_style_set_shadow_opa(&style_calendar_btn_1_main_main_default, 216);
	lv_style_set_border_color(&style_calendar_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_calendar_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_calendar_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->Calendar_btn_1, &style_calendar_btn_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Calendar_btn_1_label = lv_label_create(ui->Calendar_btn_1);
	lv_label_set_text(ui->Calendar_btn_1_label, "Exit");
	lv_obj_set_style_text_color(ui->Calendar_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Calendar_btn_1_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Calendar_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Calendar_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	// Init events for screen
	events_init_Calendar(ui);

	lv_group_t *group2 = lv_group_create();
	lv_indev_set_group(indev_encoder[2], group2);
	lv_group_add_obj(group2, ui->Calendar_btn_1);
	lv_group_set_editing(group2, false);
}
