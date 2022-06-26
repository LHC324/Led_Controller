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

void setup_scr_Buzzer(lv_ui *ui)
{

	// Write codes Buzzer
	ui->Buzzer = lv_obj_create(NULL);

	// Write style state: LV_STATE_DEFAULT for style_buzzer_main_main_default
	static lv_style_t style_buzzer_main_main_default;
	if (style_buzzer_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_buzzer_main_main_default);
	else
		lv_style_init(&style_buzzer_main_main_default);
	lv_style_set_bg_color(&style_buzzer_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_buzzer_main_main_default, 0);
	lv_obj_add_style(ui->Buzzer, &style_buzzer_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Buzzer_cont_1
	ui->Buzzer_cont_1 = lv_obj_create(ui->Buzzer);
	lv_obj_set_pos(ui->Buzzer_cont_1, 0, 0);
	lv_obj_set_size(ui->Buzzer_cont_1, 480, 320);

	// Write style state: LV_STATE_DEFAULT for style_buzzer_cont_1_main_main_default
	static lv_style_t style_buzzer_cont_1_main_main_default;
	if (style_buzzer_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_buzzer_cont_1_main_main_default);
	else
		lv_style_init(&style_buzzer_cont_1_main_main_default);
	lv_style_set_radius(&style_buzzer_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_buzzer_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_buzzer_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_buzzer_cont_1_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_buzzer_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_buzzer_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_buzzer_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_buzzer_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_buzzer_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_buzzer_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_buzzer_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_buzzer_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->Buzzer_cont_1, &style_buzzer_cont_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Buzzer_label_1
	ui->Buzzer_label_1 = lv_label_create(ui->Buzzer);
	lv_obj_set_pos(ui->Buzzer_label_1, 149, 20);
	lv_obj_set_size(ui->Buzzer_label_1, 180, 20);
	lv_label_set_text(ui->Buzzer_label_1, "Buzzer");
	lv_label_set_long_mode(ui->Buzzer_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->Buzzer_label_1, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_buzzer_label_1_main_main_default
	static lv_style_t style_buzzer_label_1_main_main_default;
	if (style_buzzer_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_buzzer_label_1_main_main_default);
	else
		lv_style_init(&style_buzzer_label_1_main_main_default);
	lv_style_set_radius(&style_buzzer_label_1_main_main_default, 10);
	lv_style_set_bg_color(&style_buzzer_label_1_main_main_default, lv_color_make(0xd3, 0xf6, 0x23));
	lv_style_set_bg_grad_color(&style_buzzer_label_1_main_main_default, lv_color_make(0xf6, 0x23, 0x23));
	lv_style_set_bg_grad_dir(&style_buzzer_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_buzzer_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_buzzer_label_1_main_main_default, lv_color_make(0x00, 0xf5, 0x49));
	lv_style_set_text_font(&style_buzzer_label_1_main_main_default, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_buzzer_label_1_main_main_default, 1);
	lv_style_set_pad_left(&style_buzzer_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_buzzer_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_buzzer_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_buzzer_label_1_main_main_default, 0);
	lv_obj_add_style(ui->Buzzer_label_1, &style_buzzer_label_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Buzzer_sw_1
	ui->Buzzer_sw_1 = lv_switch_create(ui->Buzzer);
	lv_obj_set_pos(ui->Buzzer_sw_1, 215, 145);
	lv_obj_set_size(ui->Buzzer_sw_1, 50, 25);

	// Write style state: LV_STATE_DEFAULT for style_buzzer_sw_1_main_main_default
	static lv_style_t style_buzzer_sw_1_main_main_default;
	if (style_buzzer_sw_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_buzzer_sw_1_main_main_default);
	else
		lv_style_init(&style_buzzer_sw_1_main_main_default);
	lv_style_set_radius(&style_buzzer_sw_1_main_main_default, 100);
	lv_style_set_bg_color(&style_buzzer_sw_1_main_main_default, lv_color_make(0x52, 0x51, 0x52));
	lv_style_set_bg_grad_color(&style_buzzer_sw_1_main_main_default, lv_color_make(0x58, 0x51, 0x58));
	lv_style_set_bg_grad_dir(&style_buzzer_sw_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_buzzer_sw_1_main_main_default, 255);
	lv_obj_add_style(ui->Buzzer_sw_1, &style_buzzer_sw_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_CHECKED for style_buzzer_sw_1_main_indicator_checked
	static lv_style_t style_buzzer_sw_1_main_indicator_checked;
	if (style_buzzer_sw_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_buzzer_sw_1_main_indicator_checked);
	else
		lv_style_init(&style_buzzer_sw_1_main_indicator_checked);
	lv_style_set_radius(&style_buzzer_sw_1_main_indicator_checked, 100);
	lv_style_set_bg_color(&style_buzzer_sw_1_main_indicator_checked, lv_color_make(0x23, 0xf6, 0x89));
	lv_style_set_bg_grad_color(&style_buzzer_sw_1_main_indicator_checked, lv_color_make(0x23, 0xf6, 0x74));
	lv_style_set_bg_grad_dir(&style_buzzer_sw_1_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_buzzer_sw_1_main_indicator_checked, 255);
	lv_obj_add_style(ui->Buzzer_sw_1, &style_buzzer_sw_1_main_indicator_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

	// Write style state: LV_STATE_DEFAULT for style_buzzer_sw_1_main_knob_default
	static lv_style_t style_buzzer_sw_1_main_knob_default;
	if (style_buzzer_sw_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_buzzer_sw_1_main_knob_default);
	else
		lv_style_init(&style_buzzer_sw_1_main_knob_default);
	lv_style_set_radius(&style_buzzer_sw_1_main_knob_default, 100);
	lv_style_set_bg_color(&style_buzzer_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_buzzer_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_buzzer_sw_1_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_buzzer_sw_1_main_knob_default, 255);
	lv_obj_add_style(ui->Buzzer_sw_1, &style_buzzer_sw_1_main_knob_default, LV_PART_KNOB | LV_STATE_DEFAULT);

	// Write codes Buzzer_btn_2
	ui->Buzzer_btn_2 = lv_btn_create(ui->Buzzer);
	lv_obj_set_pos(ui->Buzzer_btn_2, 435, 275);
	lv_obj_set_size(ui->Buzzer_btn_2, 42, 42);

	// Write style state: LV_STATE_DEFAULT for style_buzzer_btn_2_main_main_default
	static lv_style_t style_buzzer_btn_2_main_main_default;
	if (style_buzzer_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_buzzer_btn_2_main_main_default);
	else
		lv_style_init(&style_buzzer_btn_2_main_main_default);
	lv_style_set_radius(&style_buzzer_btn_2_main_main_default, 100);
	lv_style_set_bg_color(&style_buzzer_btn_2_main_main_default, lv_color_make(0x07, 0xcf, 0x68));
	lv_style_set_bg_grad_color(&style_buzzer_btn_2_main_main_default, lv_color_make(0x06, 0xf4, 0xe4));
	lv_style_set_bg_grad_dir(&style_buzzer_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_buzzer_btn_2_main_main_default, 48);
	lv_style_set_shadow_color(&style_buzzer_btn_2_main_main_default, lv_color_make(0xff, 0x00, 0x00));
	lv_style_set_shadow_opa(&style_buzzer_btn_2_main_main_default, 216);
	lv_style_set_border_color(&style_buzzer_btn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_buzzer_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_buzzer_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->Buzzer_btn_2, &style_buzzer_btn_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Buzzer_btn_2_label = lv_label_create(ui->Buzzer_btn_2);
	lv_label_set_text(ui->Buzzer_btn_2_label, "Exit");
	lv_obj_set_style_text_color(ui->Buzzer_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Buzzer_btn_2_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Buzzer_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Buzzer_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes Buzzer_btn_1
	ui->Buzzer_btn_1 = lv_btn_create(ui->Buzzer);
	lv_obj_set_pos(ui->Buzzer_btn_1, 5, 275);
	lv_obj_set_size(ui->Buzzer_btn_1, 42, 42);

	// Write style state: LV_STATE_DEFAULT for style_buzzer_btn_1_main_main_default
	static lv_style_t style_buzzer_btn_1_main_main_default;
	if (style_buzzer_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_buzzer_btn_1_main_main_default);
	else
		lv_style_init(&style_buzzer_btn_1_main_main_default);
	lv_style_set_radius(&style_buzzer_btn_1_main_main_default, 100);
	lv_style_set_bg_color(&style_buzzer_btn_1_main_main_default, lv_color_make(0x07, 0xcf, 0x68));
	lv_style_set_bg_grad_color(&style_buzzer_btn_1_main_main_default, lv_color_make(0x06, 0xf4, 0xe4));
	lv_style_set_bg_grad_dir(&style_buzzer_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_buzzer_btn_1_main_main_default, 51);
	lv_style_set_shadow_color(&style_buzzer_btn_1_main_main_default, lv_color_make(0x34, 0xf4, 0x97));
	lv_style_set_shadow_opa(&style_buzzer_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_buzzer_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_buzzer_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_buzzer_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->Buzzer_btn_1, &style_buzzer_btn_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Buzzer_btn_1_label = lv_label_create(ui->Buzzer_btn_1);
	lv_label_set_text(ui->Buzzer_btn_1_label, "Sw");
	lv_obj_set_style_text_color(ui->Buzzer_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Buzzer_btn_1_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Buzzer_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Buzzer_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	if (guser.buzzer_switch)
	{
		lv_obj_add_state(guider_ui.Buzzer_sw_1, LV_STATE_CHECKED);
	}
	else
	{
		lv_obj_clear_state(guider_ui.Buzzer_sw_1, LV_STATE_CHECKED);
	}

	// Init events for screen
	events_init_Buzzer(ui);

	lv_group_t *group = lv_group_create();
	lv_indev_set_group(indev_encoder[0], group);
	lv_group_add_obj(group, ui->Buzzer_btn_2);
	lv_group_set_editing(group, false);

	lv_group_t *group1 = lv_group_create();
	lv_indev_set_group(indev_encoder[2], group1);
	lv_group_add_obj(group1, ui->Buzzer_btn_1);
	lv_group_set_editing(group1, false);
}
