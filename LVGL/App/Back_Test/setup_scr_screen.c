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

static void _screen_ddlist1_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_screen_ddlist1_extra_list_selected_default
	static lv_style_t style_screen_ddlist1_extra_list_selected_default;
	if (style_screen_ddlist1_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist1_extra_list_selected_default);
	else
		lv_style_init(&style_screen_ddlist1_extra_list_selected_default);
	lv_style_set_radius(&style_screen_ddlist1_extra_list_selected_default, 3);
	lv_style_set_bg_color(&style_screen_ddlist1_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_screen_ddlist1_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_screen_ddlist1_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_ddlist1_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_screen_ddlist1_extra_list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_screen_ddlist1_extra_list_selected_default, 1);
	lv_style_set_text_color(&style_screen_ddlist1_extra_list_selected_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_ddlist1_extra_list_selected_default, &lv_font_arial_12);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_screen_ddlist1_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_ddlist1_extra_list_main_default
	static lv_style_t style_screen_ddlist1_extra_list_main_default;
	if (style_screen_ddlist1_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist1_extra_list_main_default);
	else
		lv_style_init(&style_screen_ddlist1_extra_list_main_default);
	lv_style_set_radius(&style_screen_ddlist1_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_screen_ddlist1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_ddlist1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_ddlist1_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_ddlist1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_ddlist1_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_screen_ddlist1_extra_list_main_default, 1);
	lv_style_set_text_color(&style_screen_ddlist1_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_ddlist1_extra_list_main_default, &lv_font_arial_12);
	lv_style_set_max_height(&style_screen_ddlist1_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_screen_ddlist1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_ddlist1_extra_list_scrollbar_default
	static lv_style_t style_screen_ddlist1_extra_list_scrollbar_default;
	if (style_screen_ddlist1_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist1_extra_list_scrollbar_default);
	else
		lv_style_init(&style_screen_ddlist1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_screen_ddlist1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_screen_ddlist1_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_grad_color(&style_screen_ddlist1_extra_list_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_ddlist1_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_ddlist1_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_screen_ddlist1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}

void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen_main_main_default
	static lv_style_t style_screen_main_main_default;
	if (style_screen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_main_main_default);
	else
		lv_style_init(&style_screen_main_main_default);
	lv_style_set_bg_color(&style_screen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_main_main_default, 0);
	lv_obj_add_style(ui->screen, &style_screen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ddlist1
	ui->screen_ddlist1 = lv_dropdown_create(ui->screen);
	lv_obj_set_pos(ui->screen_ddlist1, 260, 35);
	lv_obj_set_width(ui->screen_ddlist1, 130);
	lv_dropdown_set_options(ui->screen_ddlist1, "list1\nlist2\nlist3");
	lv_obj_add_event_cb(ui->screen_ddlist1, _screen_ddlist1_event_cb, LV_EVENT_READY, NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen_ddlist1_main_main_default
	static lv_style_t style_screen_ddlist1_main_main_default;
	if (style_screen_ddlist1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_ddlist1_main_main_default);
	else
		lv_style_init(&style_screen_ddlist1_main_main_default);
	lv_style_set_radius(&style_screen_ddlist1_main_main_default, 3);
	lv_style_set_bg_color(&style_screen_ddlist1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_ddlist1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_ddlist1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_ddlist1_main_main_default, 255);
	lv_style_set_border_color(&style_screen_ddlist1_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_screen_ddlist1_main_main_default, 1);
	lv_style_set_text_color(&style_screen_ddlist1_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_ddlist1_main_main_default, &lv_font_arial_12);
	lv_style_set_text_line_space(&style_screen_ddlist1_main_main_default, 20);
	lv_obj_add_style(ui->screen_ddlist1, &style_screen_ddlist1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_roller1
	ui->screen_roller1 = lv_roller_create(ui->screen);
	lv_obj_set_pos(ui->screen_roller1, 90, 35);

	//Write style state: LV_STATE_DEFAULT for style_screen_roller1_main_main_default
	static lv_style_t style_screen_roller1_main_main_default;
	if (style_screen_roller1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_roller1_main_main_default);
	else
		lv_style_init(&style_screen_roller1_main_main_default);
	lv_style_set_radius(&style_screen_roller1_main_main_default, 5);
	lv_style_set_bg_color(&style_screen_roller1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_roller1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_roller1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_roller1_main_main_default, 255);
	lv_style_set_border_color(&style_screen_roller1_main_main_default, lv_color_make(0xdf, 0xe7, 0xed));
	lv_style_set_border_width(&style_screen_roller1_main_main_default, 1);
	lv_style_set_text_color(&style_screen_roller1_main_main_default, lv_color_make(0x33, 0x33, 0x33));
	lv_obj_add_style(ui->screen_roller1, &style_screen_roller1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen_roller1_main_selected_default
	static lv_style_t style_screen_roller1_main_selected_default;
	if (style_screen_roller1_main_selected_default.prop_cnt > 1)
		lv_style_reset(&style_screen_roller1_main_selected_default);
	else
		lv_style_init(&style_screen_roller1_main_selected_default);
	lv_style_set_bg_color(&style_screen_roller1_main_selected_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_roller1_main_selected_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_roller1_main_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_roller1_main_selected_default, 255);
	lv_style_set_text_color(&style_screen_roller1_main_selected_default, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_obj_add_style(ui->screen_roller1, &style_screen_roller1_main_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->screen_roller1,"1\n2\n3\n4\n5",LV_ROLLER_MODE_INFINITE);
	lv_obj_set_style_text_font(ui->screen_roller1, &lv_font_arial_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_roller1, &lv_font_arial_12, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->screen_roller1, &lv_font_arial_12, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_visible_row_count(ui->screen_roller1,5);

	//Write codes screen_sw2
	ui->screen_sw2 = lv_switch_create(ui->screen);
	lv_obj_set_pos(ui->screen_sw2, 195, 238);
	lv_obj_set_size(ui->screen_sw2, 40, 23);

	//Write style state: LV_STATE_DEFAULT for style_screen_sw2_main_main_default
	static lv_style_t style_screen_sw2_main_main_default;
	if (style_screen_sw2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_sw2_main_main_default);
	else
		lv_style_init(&style_screen_sw2_main_main_default);
	lv_style_set_radius(&style_screen_sw2_main_main_default, 100);
	lv_style_set_bg_color(&style_screen_sw2_main_main_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_color(&style_screen_sw2_main_main_default, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_bg_grad_dir(&style_screen_sw2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw2_main_main_default, 255);
	lv_obj_add_style(ui->screen_sw2, &style_screen_sw2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_screen_sw2_main_indicator_checked
	static lv_style_t style_screen_sw2_main_indicator_checked;
	if (style_screen_sw2_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_screen_sw2_main_indicator_checked);
	else
		lv_style_init(&style_screen_sw2_main_indicator_checked);
	lv_style_set_radius(&style_screen_sw2_main_indicator_checked, 100);
	lv_style_set_bg_color(&style_screen_sw2_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_sw2_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_sw2_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw2_main_indicator_checked, 255);
	lv_obj_add_style(ui->screen_sw2, &style_screen_sw2_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_screen_sw2_main_knob_default
	static lv_style_t style_screen_sw2_main_knob_default;
	if (style_screen_sw2_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_screen_sw2_main_knob_default);
	else
		lv_style_init(&style_screen_sw2_main_knob_default);
	lv_style_set_radius(&style_screen_sw2_main_knob_default, 100);
	lv_style_set_bg_color(&style_screen_sw2_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_sw2_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_sw2_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_sw2_main_knob_default, 255);
	lv_obj_add_style(ui->screen_sw2, &style_screen_sw2_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_label3
	ui->screen_label3 = lv_label_create(ui->screen);
	lv_obj_set_pos(ui->screen_label3, 65, 241);
	lv_obj_set_size(ui->screen_label3, 100, 23);
	lv_label_set_text(ui->screen_label3, "roller");
	lv_label_set_long_mode(ui->screen_label3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_label3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_label3_main_main_default
	static lv_style_t style_screen_label3_main_main_default;
	if (style_screen_label3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label3_main_main_default);
	else
		lv_style_init(&style_screen_label3_main_main_default);
	lv_style_set_radius(&style_screen_label3_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label3_main_main_default, &lv_font_arial_12);
	lv_style_set_text_letter_space(&style_screen_label3_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_label3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label3_main_main_default, 0);
	lv_obj_add_style(ui->screen_label3, &style_screen_label3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label4
	ui->screen_label4 = lv_label_create(ui->screen);
	lv_obj_set_pos(ui->screen_label4, 261, 241);
	lv_obj_set_size(ui->screen_label4, 100, 23);
	lv_label_set_text(ui->screen_label4, "select");
	lv_label_set_long_mode(ui->screen_label4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen_label4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen_label4_main_main_default
	static lv_style_t style_screen_label4_main_main_default;
	if (style_screen_label4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label4_main_main_default);
	else
		lv_style_init(&style_screen_label4_main_main_default);
	lv_style_set_radius(&style_screen_label4_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label4_main_main_default, 0);
	lv_style_set_text_color(&style_screen_label4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label4_main_main_default, &lv_font_arial_12);
	lv_style_set_text_letter_space(&style_screen_label4_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_label4_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label4_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_label4_main_main_default, 0);
	lv_obj_add_style(ui->screen_label4, &style_screen_label4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_screen(ui);
}