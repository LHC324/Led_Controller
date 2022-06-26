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

void setup_scr_Screen_Brightness(lv_ui *ui)
{

	// Write codes Screen_Brightness
	ui->Screen_Brightness = lv_obj_create(NULL);

	// Write style state: LV_STATE_DEFAULT for style_screen_brightness_main_main_default
	static lv_style_t style_screen_brightness_main_main_default;
	if (style_screen_brightness_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_brightness_main_main_default);
	else
		lv_style_init(&style_screen_brightness_main_main_default);
	lv_style_set_bg_color(&style_screen_brightness_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_brightness_main_main_default, 0);
	lv_obj_add_style(ui->Screen_Brightness, &style_screen_brightness_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Screen_Brightness_cont_1
	ui->Screen_Brightness_cont_1 = lv_obj_create(ui->Screen_Brightness);
	lv_obj_set_pos(ui->Screen_Brightness_cont_1, 0, 0);
	lv_obj_set_size(ui->Screen_Brightness_cont_1, 480, 320);

	// Write style state: LV_STATE_DEFAULT for style_screen_brightness_cont_1_main_main_default
	static lv_style_t style_screen_brightness_cont_1_main_main_default;
	if (style_screen_brightness_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_brightness_cont_1_main_main_default);
	else
		lv_style_init(&style_screen_brightness_cont_1_main_main_default);
	lv_style_set_radius(&style_screen_brightness_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_brightness_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_screen_brightness_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_screen_brightness_cont_1_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_screen_brightness_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_screen_brightness_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_screen_brightness_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_brightness_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_screen_brightness_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_brightness_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_brightness_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_brightness_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->Screen_Brightness_cont_1, &style_screen_brightness_cont_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Screen_Brightness_label_2
	ui->Screen_Brightness_label_2 = lv_label_create(ui->Screen_Brightness);
	lv_obj_set_pos(ui->Screen_Brightness_label_2, 150, 20);
	lv_obj_set_size(ui->Screen_Brightness_label_2, 180, 20);
	lv_label_set_text(ui->Screen_Brightness_label_2, "Brightness");
	lv_label_set_long_mode(ui->Screen_Brightness_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->Screen_Brightness_label_2, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_screen_brightness_label_2_main_main_default
	static lv_style_t style_screen_brightness_label_2_main_main_default;
	if (style_screen_brightness_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_brightness_label_2_main_main_default);
	else
		lv_style_init(&style_screen_brightness_label_2_main_main_default);
	lv_style_set_radius(&style_screen_brightness_label_2_main_main_default, 10);
	lv_style_set_bg_color(&style_screen_brightness_label_2_main_main_default, lv_color_make(0xd3, 0xf6, 0x23));
	lv_style_set_bg_grad_color(&style_screen_brightness_label_2_main_main_default, lv_color_make(0xf6, 0x23, 0x23));
	lv_style_set_bg_grad_dir(&style_screen_brightness_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_brightness_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_brightness_label_2_main_main_default, lv_color_make(0xe8, 0x11, 0x52));
	lv_style_set_text_font(&style_screen_brightness_label_2_main_main_default, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_brightness_label_2_main_main_default, 1);
	lv_style_set_pad_left(&style_screen_brightness_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_brightness_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_brightness_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_brightness_label_2_main_main_default, 0);
	lv_obj_add_style(ui->Screen_Brightness_label_2, &style_screen_brightness_label_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Screen_Brightness_slider_1
	ui->Screen_Brightness_slider_1 = lv_slider_create(ui->Screen_Brightness);
	lv_obj_set_pos(ui->Screen_Brightness_slider_1, 140, 140);
	lv_obj_set_size(ui->Screen_Brightness_slider_1, 200, 10);

	// Write style state: LV_STATE_DEFAULT for style_screen_brightness_slider_1_main_main_default
	static lv_style_t style_screen_brightness_slider_1_main_main_default;
	if (style_screen_brightness_slider_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_brightness_slider_1_main_main_default);
	else
		lv_style_init(&style_screen_brightness_slider_1_main_main_default);
	lv_style_set_radius(&style_screen_brightness_slider_1_main_main_default, 50);
	lv_style_set_bg_color(&style_screen_brightness_slider_1_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_screen_brightness_slider_1_main_main_default, lv_color_make(0x90, 0x94, 0x98));
	lv_style_set_bg_grad_dir(&style_screen_brightness_slider_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_brightness_slider_1_main_main_default, 100);
	lv_style_set_outline_color(&style_screen_brightness_slider_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_screen_brightness_slider_1_main_main_default, 0);
	lv_style_set_outline_opa(&style_screen_brightness_slider_1_main_main_default, 255);
	lv_style_set_pad_left(&style_screen_brightness_slider_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_brightness_slider_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_brightness_slider_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_brightness_slider_1_main_main_default, 0);
	lv_obj_add_style(ui->Screen_Brightness_slider_1, &style_screen_brightness_slider_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_screen_brightness_slider_1_main_indicator_default
	static lv_style_t style_screen_brightness_slider_1_main_indicator_default;
	if (style_screen_brightness_slider_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_screen_brightness_slider_1_main_indicator_default);
	else
		lv_style_init(&style_screen_brightness_slider_1_main_indicator_default);
	lv_style_set_radius(&style_screen_brightness_slider_1_main_indicator_default, 50);
	lv_style_set_bg_color(&style_screen_brightness_slider_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_brightness_slider_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_brightness_slider_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_brightness_slider_1_main_indicator_default, 255);
	lv_obj_add_style(ui->Screen_Brightness_slider_1, &style_screen_brightness_slider_1_main_indicator_default, LV_PART_INDICATOR | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_screen_brightness_slider_1_main_knob_default
	static lv_style_t style_screen_brightness_slider_1_main_knob_default;
	if (style_screen_brightness_slider_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_screen_brightness_slider_1_main_knob_default);
	else
		lv_style_init(&style_screen_brightness_slider_1_main_knob_default);
	lv_style_set_radius(&style_screen_brightness_slider_1_main_knob_default, 50);
	lv_style_set_bg_color(&style_screen_brightness_slider_1_main_knob_default, lv_color_make(0xd4, 0xce, 0xce));
	lv_style_set_bg_grad_color(&style_screen_brightness_slider_1_main_knob_default, lv_color_make(0xc2, 0xd1, 0xe0));
	lv_style_set_bg_grad_dir(&style_screen_brightness_slider_1_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_brightness_slider_1_main_knob_default, 255);
	lv_obj_add_style(ui->Screen_Brightness_slider_1, &style_screen_brightness_slider_1_main_knob_default, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_slider_set_range(ui->Screen_Brightness_slider_1, 0, 100);
	// lv_slider_set_value(ui->Screen_Brightness_slider_1, 50, false);
	lv_slider_set_value(ui->Screen_Brightness_slider_1, (int32_t)guser.brightness, false);

	// Write codes Screen_Brightness_btn_1
	ui->Screen_Brightness_btn_1 = lv_btn_create(ui->Screen_Brightness);
	lv_obj_set_pos(ui->Screen_Brightness_btn_1, 435, 275);
	lv_obj_set_size(ui->Screen_Brightness_btn_1, 42, 42);

	// Write style state: LV_STATE_DEFAULT for style_screen_brightness_btn_1_main_main_default
	static lv_style_t style_screen_brightness_btn_1_main_main_default;
	if (style_screen_brightness_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_brightness_btn_1_main_main_default);
	else
		lv_style_init(&style_screen_brightness_btn_1_main_main_default);
	lv_style_set_radius(&style_screen_brightness_btn_1_main_main_default, 100);
	lv_style_set_bg_color(&style_screen_brightness_btn_1_main_main_default, lv_color_make(0x07, 0xcf, 0x68));
	lv_style_set_bg_grad_color(&style_screen_brightness_btn_1_main_main_default, lv_color_make(0x06, 0xf4, 0xe4));
	lv_style_set_bg_grad_dir(&style_screen_brightness_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_brightness_btn_1_main_main_default, 48);
	lv_style_set_shadow_color(&style_screen_brightness_btn_1_main_main_default, lv_color_make(0xff, 0x00, 0x00));
	lv_style_set_shadow_opa(&style_screen_brightness_btn_1_main_main_default, 216);
	lv_style_set_border_color(&style_screen_brightness_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_screen_brightness_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_brightness_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->Screen_Brightness_btn_1, &style_screen_brightness_btn_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Screen_Brightness_btn_1_label = lv_label_create(ui->Screen_Brightness_btn_1);
	lv_label_set_text(ui->Screen_Brightness_btn_1_label, "Exit");
	lv_obj_set_style_text_color(ui->Screen_Brightness_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Screen_Brightness_btn_1_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Screen_Brightness_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Screen_Brightness_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes Screen_Brightness_label_3
	ui->Screen_Brightness_label_3 = lv_label_create(ui->Screen_Brightness);
	lv_obj_set_pos(ui->Screen_Brightness_label_3, 200, 161);
	lv_obj_set_size(ui->Screen_Brightness_label_3, 80, 20);
	// lv_label_set_text(ui->Screen_Brightness_label_3, "50%");
	/*初始化屏幕亮度初值*/
	sprintf((char *)guser.temp_data, "%d", guser.brightness);
	lv_label_set_text_fmt(ui->Screen_Brightness_label_3, "%s%%", guser.temp_data);
	lv_label_set_long_mode(ui->Screen_Brightness_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->Screen_Brightness_label_3, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_screen_brightness_label_3_main_main_default
	static lv_style_t style_screen_brightness_label_3_main_main_default;
	if (style_screen_brightness_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_brightness_label_3_main_main_default);
	else
		lv_style_init(&style_screen_brightness_label_3_main_main_default);
	lv_style_set_radius(&style_screen_brightness_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_brightness_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_brightness_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_brightness_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_brightness_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_screen_brightness_label_3_main_main_default, lv_color_make(0xfc, 0xfc, 0xfc));
	lv_style_set_text_font(&style_screen_brightness_label_3_main_main_default, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_brightness_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_brightness_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_brightness_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_brightness_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_brightness_label_3_main_main_default, 0);
	lv_obj_add_style(ui->Screen_Brightness_label_3, &style_screen_brightness_label_3_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Init events for screen
	events_init_Screen_Brightness(ui);

	lv_group_t *group = lv_group_create();
	lv_indev_set_group(indev_encoder[0], group);
	lv_group_add_obj(group, ui->Screen_Brightness_slider_1);
	lv_group_set_editing(group, true);

	lv_group_t *group1 = lv_group_create();
	lv_indev_set_group(indev_encoder[2], group1);
	lv_group_add_obj(group1, ui->Screen_Brightness_btn_1);
}
