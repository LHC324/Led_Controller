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

static int Main_analog_clock_1_hour_value = (3 * 5) + (20 / 12);
static int Main_analog_clock_1_min_value = 20;
static int Main_analog_clock_1_sec_value = 50;
void Main_analog_clock_1_timer(lv_timer_t *timer)
{
	clock_count(&Main_analog_clock_1_hour_value, &Main_analog_clock_1_min_value, &Main_analog_clock_1_sec_value);
	if (lv_obj_is_valid(guider_ui.Main_analog_clock_1))
	{
		lv_meter_set_indicator_value(guider_ui.Main_analog_clock_1, guider_ui.Main_analog_clock_1_indic_hour, Main_analog_clock_1_hour_value);
		lv_meter_set_indicator_value(guider_ui.Main_analog_clock_1, guider_ui.Main_analog_clock_1_indic_min, Main_analog_clock_1_min_value);
		lv_meter_set_indicator_value(guider_ui.Main_analog_clock_1, guider_ui.Main_analog_clock_1_indic_sec, Main_analog_clock_1_sec_value);
	}
}

void setup_scr_Main(lv_ui *ui)
{

	// Write codes Main
	ui->Main = lv_obj_create(NULL);

	// Write style state: LV_STATE_DEFAULT for style_main_main_main_default
	static lv_style_t style_main_main_main_default;
	if (style_main_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_main_main_default);
	else
		lv_style_init(&style_main_main_main_default);
	lv_style_set_bg_color(&style_main_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_main_main_main_default, 0);
	lv_obj_add_style(ui->Main, &style_main_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Main_cont_1
	ui->Main_cont_1 = lv_obj_create(ui->Main);
	lv_obj_set_pos(ui->Main_cont_1, 0, 0);
	lv_obj_set_size(ui->Main_cont_1, 480, 320);

	// Write style state: LV_STATE_DEFAULT for style_main_cont_1_main_main_default
	static lv_style_t style_main_cont_1_main_main_default;
	if (style_main_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_cont_1_main_main_default);
	else
		lv_style_init(&style_main_cont_1_main_main_default);
	lv_style_set_radius(&style_main_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_main_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_main_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_main_cont_1_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_main_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_main_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_main_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_main_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_main_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_main_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_main_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_main_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->Main_cont_1, &style_main_cont_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Main_btn_1
	ui->Main_btn_1 = lv_btn_create(ui->Main);
	lv_obj_set_pos(ui->Main_btn_1, 5, 275);
	lv_obj_set_size(ui->Main_btn_1, 42, 42);

	// Write style state: LV_STATE_DEFAULT for style_main_btn_1_main_main_default
	static lv_style_t style_main_btn_1_main_main_default;
	if (style_main_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_btn_1_main_main_default);
	else
		lv_style_init(&style_main_btn_1_main_main_default);
	lv_style_set_radius(&style_main_btn_1_main_main_default, 100);
	lv_style_set_bg_color(&style_main_btn_1_main_main_default, lv_color_make(0x07, 0xcf, 0xae));
	lv_style_set_bg_grad_color(&style_main_btn_1_main_main_default, lv_color_make(0x06, 0xf4, 0xe4));
	lv_style_set_bg_grad_dir(&style_main_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_main_btn_1_main_main_default, 48);
	lv_style_set_shadow_color(&style_main_btn_1_main_main_default, lv_color_make(0xf7, 0xb6, 0x02));
	lv_style_set_shadow_opa(&style_main_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_main_btn_1_main_main_default, lv_color_make(0xf7, 0xb6, 0x02));
	lv_style_set_border_width(&style_main_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_main_btn_1_main_main_default, 0);
	lv_obj_add_style(ui->Main_btn_1, &style_main_btn_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Main_btn_1_label = lv_label_create(ui->Main_btn_1);
	lv_label_set_text(ui->Main_btn_1_label, "M");
	lv_obj_set_style_text_color(ui->Main_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Main_btn_1_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Main_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Main_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes Main_label_1
	ui->Main_label_1 = lv_label_create(ui->Main);
	lv_obj_set_pos(ui->Main_label_1, 150, 20);
	lv_obj_set_size(ui->Main_label_1, 180, 20);
	lv_label_set_text(ui->Main_label_1, "Led Controller");
	lv_label_set_long_mode(ui->Main_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->Main_label_1, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_main_label_1_main_main_default
	static lv_style_t style_main_label_1_main_main_default;
	if (style_main_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_label_1_main_main_default);
	else
		lv_style_init(&style_main_label_1_main_main_default);
	lv_style_set_radius(&style_main_label_1_main_main_default, 10);
	lv_style_set_bg_color(&style_main_label_1_main_main_default, lv_color_make(0xfa, 0xfa, 0xfa));
	lv_style_set_bg_grad_color(&style_main_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_main_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_main_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_main_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_main_label_1_main_main_default, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_main_label_1_main_main_default, 1);
	lv_style_set_pad_left(&style_main_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_main_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_main_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_main_label_1_main_main_default, 0);
	lv_obj_add_style(ui->Main_label_1, &style_main_label_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	static bool Main_analog_clock_1_timer_enabled = false;

	// Write codes Main_analog_clock_1
	ui->Main_analog_clock_1 = lv_meter_create(ui->Main);
	lv_obj_set_pos(ui->Main_analog_clock_1, 160, 88);
	lv_obj_set_size(ui->Main_analog_clock_1, 160, 160);

	// create hour scale
	lv_meter_scale_t *Main_analog_clock_1_scale_hour = lv_meter_add_scale(ui->Main_analog_clock_1);
	lv_meter_set_scale_ticks(ui->Main_analog_clock_1, Main_analog_clock_1_scale_hour, 12, 0, 0, lv_palette_main(LV_PALETTE_GREY));
	lv_meter_set_scale_major_ticks(ui->Main_analog_clock_1, Main_analog_clock_1_scale_hour, 1, 2, 10, lv_color_make(0xf7, 0xf7, 0xf7), 10);
	lv_meter_set_scale_range(ui->Main_analog_clock_1, Main_analog_clock_1_scale_hour, 1, 12, 330, 300);

	// create min scale
	lv_meter_scale_t *Main_analog_clock_1_scale_min = lv_meter_add_scale(ui->Main_analog_clock_1);
	lv_meter_set_scale_ticks(ui->Main_analog_clock_1, Main_analog_clock_1_scale_min, 61, 2, 5, lv_color_make(0x80, 0x4d, 0x3c));
	lv_meter_set_scale_range(ui->Main_analog_clock_1, Main_analog_clock_1_scale_min, 0, 60, 360, 270);
	ui->Main_analog_clock_1_indic_hour = lv_meter_add_needle_line(ui->Main_analog_clock_1, Main_analog_clock_1_scale_min, 2, lv_color_make(0x00, 0xff, 0x00), -40);
	lv_meter_set_indicator_value(ui->Main_analog_clock_1, ui->Main_analog_clock_1_indic_hour, Main_analog_clock_1_hour_value);
	ui->Main_analog_clock_1_indic_min = lv_meter_add_needle_line(ui->Main_analog_clock_1, Main_analog_clock_1_scale_min, 2, lv_color_make(0xE1, 0xFF, 0x00), -30);
	lv_meter_set_indicator_value(ui->Main_analog_clock_1, ui->Main_analog_clock_1_indic_min, Main_analog_clock_1_min_value);
	ui->Main_analog_clock_1_indic_sec = lv_meter_add_needle_line(ui->Main_analog_clock_1, Main_analog_clock_1_scale_min, 2, lv_color_make(0xee, 0x00, 0xff), -10);
	lv_meter_set_indicator_value(ui->Main_analog_clock_1, ui->Main_analog_clock_1_indic_sec, Main_analog_clock_1_sec_value);

	// create timer
	if (!Main_analog_clock_1_timer_enabled)
	{
		lv_timer_create(Main_analog_clock_1_timer, 1000, NULL);
		Main_analog_clock_1_timer_enabled = true;
	}
	// Write style state: LV_STATE_DEFAULT for style_main_analog_clock_1_main_main_default
	static lv_style_t style_main_analog_clock_1_main_main_default;
	if (style_main_analog_clock_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_analog_clock_1_main_main_default);
	else
		lv_style_init(&style_main_analog_clock_1_main_main_default);
	lv_style_set_bg_color(&style_main_analog_clock_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_main_analog_clock_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_main_analog_clock_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_main_analog_clock_1_main_main_default, 255);
	lv_obj_add_style(ui->Main_analog_clock_1, &style_main_analog_clock_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for style_main_analog_clock_1_main_ticks_default
	static lv_style_t style_main_analog_clock_1_main_ticks_default;
	if (style_main_analog_clock_1_main_ticks_default.prop_cnt > 1)
		lv_style_reset(&style_main_analog_clock_1_main_ticks_default);
	else
		lv_style_init(&style_main_analog_clock_1_main_ticks_default);
	lv_style_set_text_color(&style_main_analog_clock_1_main_ticks_default, lv_color_make(0xde, 0x91, 0x91));
	lv_style_set_text_font(&style_main_analog_clock_1_main_ticks_default, &lv_font_montserrat_12);
	lv_obj_add_style(ui->Main_analog_clock_1, &style_main_analog_clock_1_main_ticks_default, LV_PART_TICKS | LV_STATE_DEFAULT);

	// Init events for screen
	events_init_Main(ui);
	lv_group_t *group = lv_group_create();
	lv_indev_set_group(indev_encoder[0], group);
	lv_group_add_obj(group, ui->Main_btn_1);
}
