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

void setup_scr_Timer(lv_ui *ui)
{

	// Write codes Timer
	ui->Timer = lv_obj_create(NULL);

	// Write style state: LV_STATE_DEFAULT for style_timer_main_main_default
	static lv_style_t style_timer_main_main_default;
	if (style_timer_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_timer_main_main_default);
	else
		lv_style_init(&style_timer_main_main_default);
	lv_style_set_bg_color(&style_timer_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_timer_main_main_default, 0);
	lv_obj_add_style(ui->Timer, &style_timer_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Timer_cont_1
	ui->Timer_cont_1 = lv_obj_create(ui->Timer);
	lv_obj_set_pos(ui->Timer_cont_1, 0, 0);
	lv_obj_set_size(ui->Timer_cont_1, 480, 320);

	// Write style state: LV_STATE_DEFAULT for style_timer_cont_1_main_main_default
	static lv_style_t style_timer_cont_1_main_main_default;
	if (style_timer_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_timer_cont_1_main_main_default);
	else
		lv_style_init(&style_timer_cont_1_main_main_default);
	lv_style_set_radius(&style_timer_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_timer_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_timer_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_timer_cont_1_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_timer_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_timer_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_timer_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_timer_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_timer_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_timer_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_timer_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_timer_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->Timer_cont_1, &style_timer_cont_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Timer_label
	ui->Timer_label = lv_label_create(ui->Timer);
	lv_obj_set_pos(ui->Timer_label, 150, 20);
	lv_obj_set_size(ui->Timer_label, 180, 20);
	lv_label_set_text(ui->Timer_label, "Timer");
	lv_label_set_long_mode(ui->Timer_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->Timer_label, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_timer_label_main_main_default
	static lv_style_t style_timer_label_main_main_default;
	if (style_timer_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_timer_label_main_main_default);
	else
		lv_style_init(&style_timer_label_main_main_default);
	lv_style_set_radius(&style_timer_label_main_main_default, 10);
	lv_style_set_bg_color(&style_timer_label_main_main_default, lv_color_make(0xd3, 0xf6, 0x23));
	lv_style_set_bg_grad_color(&style_timer_label_main_main_default, lv_color_make(0xf6, 0x23, 0x23));
	lv_style_set_bg_grad_dir(&style_timer_label_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_timer_label_main_main_default, 0);
	lv_style_set_text_color(&style_timer_label_main_main_default, lv_color_make(0x0d, 0xd9, 0xd5));
	lv_style_set_text_font(&style_timer_label_main_main_default, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_timer_label_main_main_default, 1);
	lv_style_set_pad_left(&style_timer_label_main_main_default, 0);
	lv_style_set_pad_right(&style_timer_label_main_main_default, 0);
	lv_style_set_pad_top(&style_timer_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_timer_label_main_main_default, 0);
	lv_obj_add_style(ui->Timer_label, &style_timer_label_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Timer_btn_1
	ui->Timer_btn_1 = lv_btn_create(ui->Timer);
	lv_obj_set_pos(ui->Timer_btn_1, 5, 275);
	lv_obj_set_size(ui->Timer_btn_1, 42, 42);

	// Write style state: LV_STATE_DEFAULT for style_timer_btn_1_main_main_default
	static lv_style_t style_timer_btn_1_main_main_default;
	if (style_timer_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_timer_btn_1_main_main_default);
	else
		lv_style_init(&style_timer_btn_1_main_main_default);
	lv_style_set_radius(&style_timer_btn_1_main_main_default, 40);
	lv_style_set_bg_color(&style_timer_btn_1_main_main_default, lv_color_make(0x07, 0xcf, 0x68));
	lv_style_set_bg_grad_color(&style_timer_btn_1_main_main_default, lv_color_make(0x06, 0xf4, 0xe4));
	lv_style_set_bg_grad_dir(&style_timer_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_timer_btn_1_main_main_default, 51);
	lv_style_set_shadow_color(&style_timer_btn_1_main_main_default, lv_color_make(0x34, 0xf4, 0x97));
	lv_style_set_shadow_opa(&style_timer_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_timer_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_timer_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_timer_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->Timer_btn_1, &style_timer_btn_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Timer_btn_1_label = lv_label_create(ui->Timer_btn_1);
	lv_label_set_text(ui->Timer_btn_1_label, "R");
	lv_obj_set_style_text_color(ui->Timer_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Timer_btn_1_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Timer_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Timer_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes Timer_btn_2
	ui->Timer_btn_2 = lv_btn_create(ui->Timer);
	lv_obj_set_pos(ui->Timer_btn_2, 435, 275);
	lv_obj_set_size(ui->Timer_btn_2, 42, 42);

	// Write style state: LV_STATE_DEFAULT for style_timer_btn_2_main_main_default
	static lv_style_t style_timer_btn_2_main_main_default;
	if (style_timer_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_timer_btn_2_main_main_default);
	else
		lv_style_init(&style_timer_btn_2_main_main_default);
	lv_style_set_radius(&style_timer_btn_2_main_main_default, 100);
	lv_style_set_bg_color(&style_timer_btn_2_main_main_default, lv_color_make(0x07, 0xcf, 0x68));
	lv_style_set_bg_grad_color(&style_timer_btn_2_main_main_default, lv_color_make(0x06, 0xf4, 0xe4));
	lv_style_set_bg_grad_dir(&style_timer_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_timer_btn_2_main_main_default, 48);
	lv_style_set_shadow_color(&style_timer_btn_2_main_main_default, lv_color_make(0xff, 0x00, 0x00));
	lv_style_set_shadow_opa(&style_timer_btn_2_main_main_default, 216);
	lv_style_set_border_color(&style_timer_btn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_timer_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_timer_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->Timer_btn_2, &style_timer_btn_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Timer_btn_2_label = lv_label_create(ui->Timer_btn_2);
	lv_label_set_text(ui->Timer_btn_2_label, "Exit");
	lv_obj_set_style_text_color(ui->Timer_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Timer_btn_2_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Timer_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Timer_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes Timer_btn_3
	ui->Timer_btn_3 = lv_btn_create(ui->Timer);
	lv_obj_set_pos(ui->Timer_btn_3, 165, 133);
	lv_obj_set_size(ui->Timer_btn_3, 150, 30);

	// Write style state: LV_STATE_DEFAULT for style_timer_btn_3_main_main_default
	static lv_style_t style_timer_btn_3_main_main_default;
	if (style_timer_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_timer_btn_3_main_main_default);
	else
		lv_style_init(&style_timer_btn_3_main_main_default);
	lv_style_set_radius(&style_timer_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_timer_btn_3_main_main_default, lv_color_make(0xed, 0xed, 0xed));
	lv_style_set_bg_grad_color(&style_timer_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_timer_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_timer_btn_3_main_main_default, 49);
	lv_style_set_shadow_color(&style_timer_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_timer_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_timer_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_timer_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_timer_btn_3_main_main_default, 0);
	lv_obj_add_style(ui->Timer_btn_3, &style_timer_btn_3_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Timer_btn_3_label = lv_label_create(ui->Timer_btn_3);
	// lv_label_set_text(ui->Timer_btn_3_label, "0000.0S");
	sprintf((char *)guser.temp_data, "%.1f", guser.timer_counts);
	lv_label_set_text_fmt(ui->Timer_btn_3_label, "%sS", guser.temp_data);
	lv_obj_set_style_text_color(ui->Timer_btn_3_label, lv_color_make(0x0d, 0xd9, 0xd5), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Timer_btn_3_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Timer_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Timer_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	// Init events for screen
	events_init_Timer(ui);

	lv_group_t *group = lv_group_create();
	lv_indev_set_group(indev_encoder[0], group);
	lv_group_add_obj(group, ui->Timer_btn_1);
	lv_group_set_editing(group, true);

	lv_group_t *group1 = lv_group_create();
	lv_indev_set_group(indev_encoder[1], group1);
	lv_group_add_obj(group1, ui->Timer_btn_2);
	lv_group_set_editing(group1, true);

	lv_group_t *group2 = lv_group_create();
	lv_indev_set_group(indev_encoder[2], group2);
	lv_group_add_obj(group2, ui->Timer_btn_3);
	lv_group_set_editing(group2, true);
}
