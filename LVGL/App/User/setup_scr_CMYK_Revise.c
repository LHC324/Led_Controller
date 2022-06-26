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

void setup_scr_CMYK_Revise(lv_ui *ui)
{

	// Write codes CMYK_Revise
	ui->CMYK_Revise = lv_obj_create(NULL);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_main_main_default
	static lv_style_t style_cmyk_revise_main_main_default;
	if (style_cmyk_revise_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_main_main_default);
	lv_style_set_bg_color(&style_cmyk_revise_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_cmyk_revise_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise, &style_cmyk_revise_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes CMYK_Revise_cont_1
	ui->CMYK_Revise_cont_1 = lv_obj_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_cont_1, 0, 0);
	lv_obj_set_size(ui->CMYK_Revise_cont_1, 480, 320);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_cont_1_main_main_default
	static lv_style_t style_cmyk_revise_cont_1_main_main_default;
	if (style_cmyk_revise_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_cont_1_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_cont_1_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_cmyk_revise_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_cmyk_revise_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_cont_1_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_cmyk_revise_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_cmyk_revise_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_cmyk_revise_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_cmyk_revise_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_cmyk_revise_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_cmyk_revise_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_cmyk_revise_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_cmyk_revise_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise_cont_1, &style_cmyk_revise_cont_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes CMYK_Revise_label_1
	ui->CMYK_Revise_label_1 = lv_label_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_label_1, 0, 140);
	lv_obj_set_size(ui->CMYK_Revise_label_1, 50, 20);
	lv_label_set_text(ui->CMYK_Revise_label_1, "C:");
	lv_label_set_long_mode(ui->CMYK_Revise_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->CMYK_Revise_label_1, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_label_1_main_main_default
	static lv_style_t style_cmyk_revise_label_1_main_main_default;
	if (style_cmyk_revise_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_label_1_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_label_1_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_cmyk_revise_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_cmyk_revise_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cmyk_revise_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_cmyk_revise_label_1_main_main_default, lv_color_make(0xfa, 0xfa, 0xfa));
	lv_style_set_text_font(&style_cmyk_revise_label_1_main_main_default, &lv_font_Acme_Regular_22);
	lv_style_set_text_letter_space(&style_cmyk_revise_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_cmyk_revise_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_cmyk_revise_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_cmyk_revise_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_cmyk_revise_label_1_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise_label_1, &style_cmyk_revise_label_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes CMYK_Revise_label_2
	ui->CMYK_Revise_label_2 = lv_label_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_label_2, 120, 140);
	lv_obj_set_size(ui->CMYK_Revise_label_2, 50, 20);
	lv_label_set_text(ui->CMYK_Revise_label_2, "M:");
	lv_label_set_long_mode(ui->CMYK_Revise_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->CMYK_Revise_label_2, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_label_2_main_main_default
	static lv_style_t style_cmyk_revise_label_2_main_main_default;
	if (style_cmyk_revise_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_label_2_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_label_2_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_cmyk_revise_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_cmyk_revise_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cmyk_revise_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_cmyk_revise_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_cmyk_revise_label_2_main_main_default, &lv_font_Acme_Regular_22);
	lv_style_set_text_letter_space(&style_cmyk_revise_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_cmyk_revise_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_cmyk_revise_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_cmyk_revise_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_cmyk_revise_label_2_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise_label_2, &style_cmyk_revise_label_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes CMYK_Revise_label_3
	ui->CMYK_Revise_label_3 = lv_label_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_label_3, 250, 140);
	lv_obj_set_size(ui->CMYK_Revise_label_3, 50, 20);
	lv_label_set_text(ui->CMYK_Revise_label_3, "Y:");
	lv_label_set_long_mode(ui->CMYK_Revise_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->CMYK_Revise_label_3, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_label_3_main_main_default
	static lv_style_t style_cmyk_revise_label_3_main_main_default;
	if (style_cmyk_revise_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_label_3_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_label_3_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_cmyk_revise_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_cmyk_revise_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cmyk_revise_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_cmyk_revise_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_cmyk_revise_label_3_main_main_default, &lv_font_Acme_Regular_22);
	lv_style_set_text_letter_space(&style_cmyk_revise_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_cmyk_revise_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_cmyk_revise_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_cmyk_revise_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_cmyk_revise_label_3_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise_label_3, &style_cmyk_revise_label_3_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes CMYK_Revise_label_4
	ui->CMYK_Revise_label_4 = lv_label_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_label_4, 375, 140);
	lv_obj_set_size(ui->CMYK_Revise_label_4, 50, 20);
	lv_label_set_text(ui->CMYK_Revise_label_4, "K:");
	lv_label_set_long_mode(ui->CMYK_Revise_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->CMYK_Revise_label_4, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_label_4_main_main_default
	static lv_style_t style_cmyk_revise_label_4_main_main_default;
	if (style_cmyk_revise_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_label_4_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_label_4_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_cmyk_revise_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_cmyk_revise_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cmyk_revise_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_cmyk_revise_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_cmyk_revise_label_4_main_main_default, &lv_font_Acme_Regular_22);
	lv_style_set_text_letter_space(&style_cmyk_revise_label_4_main_main_default, 2);
	lv_style_set_pad_left(&style_cmyk_revise_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_cmyk_revise_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_cmyk_revise_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_cmyk_revise_label_4_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise_label_4, &style_cmyk_revise_label_4_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes CMYK_Revise_label_5
	ui->CMYK_Revise_label_5 = lv_label_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_label_5, 150, 20);
	lv_obj_set_size(ui->CMYK_Revise_label_5, 180, 20);
	lv_label_set_text(ui->CMYK_Revise_label_5, "CMYK Revise");
	lv_label_set_long_mode(ui->CMYK_Revise_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->CMYK_Revise_label_5, LV_TEXT_ALIGN_CENTER, 0);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_label_5_main_main_default
	static lv_style_t style_cmyk_revise_label_5_main_main_default;
	if (style_cmyk_revise_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_label_5_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_label_5_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_label_5_main_main_default, 10);
	lv_style_set_bg_color(&style_cmyk_revise_label_5_main_main_default, lv_color_make(0xd3, 0xf6, 0x23));
	lv_style_set_bg_grad_color(&style_cmyk_revise_label_5_main_main_default, lv_color_make(0xf6, 0x23, 0x23));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cmyk_revise_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_cmyk_revise_label_5_main_main_default, lv_color_make(0xc8, 0x27, 0xd2));
	lv_style_set_text_font(&style_cmyk_revise_label_5_main_main_default, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_cmyk_revise_label_5_main_main_default, 1);
	lv_style_set_pad_left(&style_cmyk_revise_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_cmyk_revise_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_cmyk_revise_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_cmyk_revise_label_5_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise_label_5, &style_cmyk_revise_label_5_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes CMYK_Revise_btn_1
	ui->CMYK_Revise_btn_1 = lv_btn_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_btn_1, 435, 275);
	lv_obj_set_size(ui->CMYK_Revise_btn_1, 42, 42);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_btn_1_main_main_default
	static lv_style_t style_cmyk_revise_btn_1_main_main_default;
	if (style_cmyk_revise_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_btn_1_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_btn_1_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_btn_1_main_main_default, 102);
	lv_style_set_bg_color(&style_cmyk_revise_btn_1_main_main_default, lv_color_make(0x07, 0xcf, 0x68));
	lv_style_set_bg_grad_color(&style_cmyk_revise_btn_1_main_main_default, lv_color_make(0x06, 0xf4, 0xe4));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cmyk_revise_btn_1_main_main_default, 48);
	lv_style_set_shadow_color(&style_cmyk_revise_btn_1_main_main_default, lv_color_make(0xff, 0x00, 0x00));
	lv_style_set_shadow_opa(&style_cmyk_revise_btn_1_main_main_default, 216);
	lv_style_set_border_color(&style_cmyk_revise_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_cmyk_revise_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_cmyk_revise_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->CMYK_Revise_btn_1, &style_cmyk_revise_btn_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->CMYK_Revise_btn_1_label = lv_label_create(ui->CMYK_Revise_btn_1);
	lv_label_set_text(ui->CMYK_Revise_btn_1_label, "Exit");
	lv_obj_set_style_text_color(ui->CMYK_Revise_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CMYK_Revise_btn_1_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->CMYK_Revise_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->CMYK_Revise_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes CMYK_Revise_btn_2
	ui->CMYK_Revise_btn_2 = lv_btn_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_btn_2, 40, 141);
	lv_obj_set_size(ui->CMYK_Revise_btn_2, 60, 20);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_btn_2_main_main_default
	static lv_style_t style_cmyk_revise_btn_2_main_main_default;
	if (style_cmyk_revise_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_btn_2_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_btn_2_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_cmyk_revise_btn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_cmyk_revise_btn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cmyk_revise_btn_2_main_main_default, 57);
	lv_style_set_shadow_color(&style_cmyk_revise_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_cmyk_revise_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_cmyk_revise_btn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_cmyk_revise_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_cmyk_revise_btn_2_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise_btn_2, &style_cmyk_revise_btn_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_PRESSED for style_cmyk_revise_btn_2_main_main_pressed
	// static lv_style_t style_cmyk_revise_btn_2_main_main_pressed;
	// if (style_cmyk_revise_btn_2_main_main_pressed.prop_cnt > 1)
	// 	lv_style_reset(&style_cmyk_revise_btn_2_main_main_pressed);
	// else
	// 	lv_style_init(&style_cmyk_revise_btn_2_main_main_pressed);
	// lv_style_set_radius(&style_cmyk_revise_btn_2_main_main_pressed, 5);
	// lv_style_set_bg_color(&style_cmyk_revise_btn_2_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_color(&style_cmyk_revise_btn_2_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_dir(&style_cmyk_revise_btn_2_main_main_pressed, LV_GRAD_DIR_VER);
	// lv_style_set_bg_opa(&style_cmyk_revise_btn_2_main_main_pressed, 255);
	// lv_style_set_shadow_color(&style_cmyk_revise_btn_2_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_shadow_opa(&style_cmyk_revise_btn_2_main_main_pressed, 0);
	// lv_style_set_border_color(&style_cmyk_revise_btn_2_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_border_width(&style_cmyk_revise_btn_2_main_main_pressed, 0);
	// lv_style_set_border_opa(&style_cmyk_revise_btn_2_main_main_pressed, 0);
	// lv_obj_add_style(ui->CMYK_Revise_btn_2, &style_cmyk_revise_btn_2_main_main_pressed, LV_PART_MAIN | LV_STATE_PRESSED);
	ui->CMYK_Revise_btn_2_label = lv_label_create(ui->CMYK_Revise_btn_2);
	// lv_label_set_text(ui->CMYK_Revise_btn_2_label, "100");
	lv_label_set_text_fmt(ui->CMYK_Revise_btn_2_label, "%d", guser.Ws281x_Cmyk.C.C);
	lv_obj_set_style_text_color(ui->CMYK_Revise_btn_2_label, lv_color_make(0x00, 0xc3, 0xf1), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CMYK_Revise_btn_2_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->CMYK_Revise_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->CMYK_Revise_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes CMYK_Revise_btn_3
	ui->CMYK_Revise_btn_3 = lv_btn_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_btn_3, 159, 141);
	lv_obj_set_size(ui->CMYK_Revise_btn_3, 60, 20);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_btn_3_main_main_default
	static lv_style_t style_cmyk_revise_btn_3_main_main_default;
	if (style_cmyk_revise_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_btn_3_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_btn_3_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_cmyk_revise_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_cmyk_revise_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cmyk_revise_btn_3_main_main_default, 40);
	lv_style_set_shadow_color(&style_cmyk_revise_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_cmyk_revise_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_cmyk_revise_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_cmyk_revise_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_cmyk_revise_btn_3_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise_btn_3, &style_cmyk_revise_btn_3_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->CMYK_Revise_btn_3_label = lv_label_create(ui->CMYK_Revise_btn_3);
	// lv_label_set_text(ui->CMYK_Revise_btn_3_label, "100");
	lv_label_set_text_fmt(ui->CMYK_Revise_btn_3_label, "%d", guser.Ws281x_Cmyk.C.M);
	lv_obj_set_style_text_color(ui->CMYK_Revise_btn_3_label, lv_color_make(0xff, 0x7a, 0x7a), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CMYK_Revise_btn_3_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->CMYK_Revise_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->CMYK_Revise_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes CMYK_Revise_btn_4
	ui->CMYK_Revise_btn_4 = lv_btn_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_btn_4, 288, 141);
	lv_obj_set_size(ui->CMYK_Revise_btn_4, 60, 20);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_btn_4_main_main_default
	static lv_style_t style_cmyk_revise_btn_4_main_main_default;
	if (style_cmyk_revise_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_btn_4_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_btn_4_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_btn_4_main_main_default, 5);
	lv_style_set_bg_color(&style_cmyk_revise_btn_4_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_cmyk_revise_btn_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_btn_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cmyk_revise_btn_4_main_main_default, 35);
	lv_style_set_shadow_color(&style_cmyk_revise_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_cmyk_revise_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_cmyk_revise_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_cmyk_revise_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_cmyk_revise_btn_4_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise_btn_4, &style_cmyk_revise_btn_4_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->CMYK_Revise_btn_4_label = lv_label_create(ui->CMYK_Revise_btn_4);
	// lv_label_set_text(ui->CMYK_Revise_btn_4_label, "100");
	lv_label_set_text_fmt(ui->CMYK_Revise_btn_4_label, "%d", guser.Ws281x_Cmyk.C.Y);
	lv_obj_set_style_text_color(ui->CMYK_Revise_btn_4_label, lv_color_make(0xfb, 0xff, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CMYK_Revise_btn_4_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->CMYK_Revise_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->CMYK_Revise_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes CMYK_Revise_btn_5
	ui->CMYK_Revise_btn_5 = lv_btn_create(ui->CMYK_Revise);
	lv_obj_set_pos(ui->CMYK_Revise_btn_5, 411, 141);
	lv_obj_set_size(ui->CMYK_Revise_btn_5, 60, 20);

	// Write style state: LV_STATE_DEFAULT for style_cmyk_revise_btn_5_main_main_default
	static lv_style_t style_cmyk_revise_btn_5_main_main_default;
	if (style_cmyk_revise_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cmyk_revise_btn_5_main_main_default);
	else
		lv_style_init(&style_cmyk_revise_btn_5_main_main_default);
	lv_style_set_radius(&style_cmyk_revise_btn_5_main_main_default, 5);
	lv_style_set_bg_color(&style_cmyk_revise_btn_5_main_main_default, lv_color_make(0xfc, 0xfc, 0xfc));
	lv_style_set_bg_grad_color(&style_cmyk_revise_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_cmyk_revise_btn_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cmyk_revise_btn_5_main_main_default, 55);
	lv_style_set_shadow_color(&style_cmyk_revise_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_cmyk_revise_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_cmyk_revise_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_cmyk_revise_btn_5_main_main_default, 0);
	lv_style_set_border_opa(&style_cmyk_revise_btn_5_main_main_default, 0);
	lv_obj_add_style(ui->CMYK_Revise_btn_5, &style_cmyk_revise_btn_5_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->CMYK_Revise_btn_5_label = lv_label_create(ui->CMYK_Revise_btn_5);
	// lv_label_set_text(ui->CMYK_Revise_btn_5_label, "100");
	lv_label_set_text_fmt(ui->CMYK_Revise_btn_5_label, "%d", guser.Ws281x_Cmyk.C.K);
	lv_obj_set_style_text_color(ui->CMYK_Revise_btn_5_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->CMYK_Revise_btn_5_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->CMYK_Revise_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->CMYK_Revise_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	// Init events for screen
	events_init_CMYK_Revise(ui);
	lv_group_t *group = lv_group_create();
	lv_indev_set_group(indev_encoder[0], group);
	lv_group_add_obj(group, ui->CMYK_Revise_btn_2);
	lv_group_add_obj(group, ui->CMYK_Revise_btn_3);
	lv_group_add_obj(group, ui->CMYK_Revise_btn_4);
	lv_group_add_obj(group, ui->CMYK_Revise_btn_5);
	lv_group_set_editing(group, false);

	lv_group_t *group1 = lv_group_create();
	lv_indev_set_group(indev_encoder[1], group1);
	lv_group_add_obj(group1, ui->CMYK_Revise_btn_5);
	lv_group_add_obj(group1, ui->CMYK_Revise_btn_4);
	lv_group_add_obj(group1, ui->CMYK_Revise_btn_3);
	lv_group_add_obj(group1, ui->CMYK_Revise_btn_2);
	lv_group_set_editing(group1, true);

	lv_group_t *group2 = lv_group_create();
	lv_indev_set_group(indev_encoder[2], group2);
	lv_group_add_obj(group2, ui->CMYK_Revise_btn_1);
	lv_group_set_editing(group2, false);
}
