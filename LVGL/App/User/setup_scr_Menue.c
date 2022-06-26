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

void setup_scr_Menue(lv_ui *ui)
{

	// Write codes Menue
	ui->Menue = lv_obj_create(NULL);

	// Write style state: LV_STATE_DEFAULT for style_menue_main_main_default
	static lv_style_t style_menue_main_main_default;
	if (style_menue_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menue_main_main_default);
	else
		lv_style_init(&style_menue_main_main_default);
	lv_style_set_bg_color(&style_menue_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_menue_main_main_default, 0);
	lv_obj_add_style(ui->Menue, &style_menue_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Menue_cont_1
	ui->Menue_cont_1 = lv_obj_create(ui->Menue);
	lv_obj_set_pos(ui->Menue_cont_1, 0, 0);
	lv_obj_set_size(ui->Menue_cont_1, 480, 320);

	// Write style state: LV_STATE_DEFAULT for style_menue_cont_1_main_main_default
	static lv_style_t style_menue_cont_1_main_main_default;
	if (style_menue_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menue_cont_1_main_main_default);
	else
		lv_style_init(&style_menue_cont_1_main_main_default);
	lv_style_set_radius(&style_menue_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_menue_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_menue_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_menue_cont_1_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_menue_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_menue_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_menue_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_menue_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_menue_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_menue_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_menue_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_menue_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->Menue_cont_1, &style_menue_cont_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes Menue_btn_1
	ui->Menue_btn_1 = lv_btn_create(ui->Menue);
	lv_obj_set_pos(ui->Menue_btn_1, 150, 30);
	lv_obj_set_size(ui->Menue_btn_1, 180, 29);

	// Write style state: LV_STATE_DEFAULT for style_menue_btn_1_main_main_default
	static lv_style_t style_menue_btn_1_main_main_default;
	if (style_menue_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menue_btn_1_main_main_default);
	else
		lv_style_init(&style_menue_btn_1_main_main_default);
	lv_style_set_radius(&style_menue_btn_1_main_main_default, 10);
	lv_style_set_bg_color(&style_menue_btn_1_main_main_default, lv_color_make(0xcf, 0x07, 0xbe));
	lv_style_set_bg_grad_color(&style_menue_btn_1_main_main_default, lv_color_make(0x06, 0xf4, 0xe4));
	lv_style_set_bg_grad_dir(&style_menue_btn_1_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_menue_btn_1_main_main_default, 31);
	lv_style_set_shadow_color(&style_menue_btn_1_main_main_default, lv_color_make(0xc8, 0x27, 0xd3));
	lv_style_set_shadow_opa(&style_menue_btn_1_main_main_default, 255);
	lv_style_set_border_color(&style_menue_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_menue_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_menue_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->Menue_btn_1, &style_menue_btn_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Menue_btn_1_label = lv_label_create(ui->Menue_btn_1);
	lv_label_set_text(ui->Menue_btn_1_label, "CMYK settings");
	lv_obj_set_style_text_color(ui->Menue_btn_1_label, lv_color_make(0xff, 0x05, 0xea), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menue_btn_1_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Menue_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Menue_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes Menue_btn_2
	ui->Menue_btn_2 = lv_btn_create(ui->Menue);
	lv_obj_set_pos(ui->Menue_btn_2, 150, 80);
	lv_obj_set_size(ui->Menue_btn_2, 180, 30);

	// Write style state: LV_STATE_DEFAULT for style_menue_btn_2_main_main_default
	static lv_style_t style_menue_btn_2_main_main_default;
	if (style_menue_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menue_btn_2_main_main_default);
	else
		lv_style_init(&style_menue_btn_2_main_main_default);
	lv_style_set_radius(&style_menue_btn_2_main_main_default, 10);
	lv_style_set_bg_color(&style_menue_btn_2_main_main_default, lv_color_make(0x07, 0xa7, 0xcf));
	lv_style_set_bg_grad_color(&style_menue_btn_2_main_main_default, lv_color_make(0x06, 0xf4, 0x36));
	lv_style_set_bg_grad_dir(&style_menue_btn_2_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_menue_btn_2_main_main_default, 17);
	lv_style_set_shadow_color(&style_menue_btn_2_main_main_default, lv_color_make(0x15, 0xce, 0xd1));
	lv_style_set_shadow_opa(&style_menue_btn_2_main_main_default, 255);
	lv_style_set_border_color(&style_menue_btn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_menue_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_menue_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->Menue_btn_2, &style_menue_btn_2_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Menue_btn_2_label = lv_label_create(ui->Menue_btn_2);
	lv_label_set_text(ui->Menue_btn_2_label, "Timer");
	lv_obj_set_style_text_color(ui->Menue_btn_2_label, lv_color_make(0x0d, 0xd9, 0xd5), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menue_btn_2_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Menue_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Menue_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes Menue_btn_3
	ui->Menue_btn_3 = lv_btn_create(ui->Menue);
	lv_obj_set_pos(ui->Menue_btn_3, 150, 134);
	lv_obj_set_size(ui->Menue_btn_3, 180, 30);

	// Write style state: LV_STATE_DEFAULT for style_menue_btn_3_main_main_default
	static lv_style_t style_menue_btn_3_main_main_default;
	if (style_menue_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menue_btn_3_main_main_default);
	else
		lv_style_init(&style_menue_btn_3_main_main_default);
	lv_style_set_radius(&style_menue_btn_3_main_main_default, 10);
	lv_style_set_bg_color(&style_menue_btn_3_main_main_default, lv_color_make(0x0e, 0xec, 0x15));
	lv_style_set_bg_grad_color(&style_menue_btn_3_main_main_default, lv_color_make(0xf4, 0x4d, 0x06));
	lv_style_set_bg_grad_dir(&style_menue_btn_3_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_menue_btn_3_main_main_default, 47);
	lv_style_set_shadow_color(&style_menue_btn_3_main_main_default, lv_color_make(0xdf, 0xc3, 0x11));
	lv_style_set_shadow_opa(&style_menue_btn_3_main_main_default, 255);
	lv_style_set_border_color(&style_menue_btn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_menue_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_menue_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->Menue_btn_3, &style_menue_btn_3_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Menue_btn_3_label = lv_label_create(ui->Menue_btn_3);
	lv_label_set_text(ui->Menue_btn_3_label, "Calendar");
	lv_obj_set_style_text_color(ui->Menue_btn_3_label, lv_color_make(0xe7, 0xcb, 0x13), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menue_btn_3_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Menue_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Menue_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes Menue_btn_4
	ui->Menue_btn_4 = lv_btn_create(ui->Menue);
	lv_obj_set_pos(ui->Menue_btn_4, 150, 187);
	lv_obj_set_size(ui->Menue_btn_4, 180, 30);

	// Write style state: LV_STATE_DEFAULT for style_menue_btn_4_main_main_default
	static lv_style_t style_menue_btn_4_main_main_default;
	if (style_menue_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menue_btn_4_main_main_default);
	else
		lv_style_init(&style_menue_btn_4_main_main_default);
	lv_style_set_radius(&style_menue_btn_4_main_main_default, 10);
	lv_style_set_bg_color(&style_menue_btn_4_main_main_default, lv_color_make(0xb8, 0x32, 0x05));
	lv_style_set_bg_grad_color(&style_menue_btn_4_main_main_default, lv_color_make(0x05, 0xff, 0xb8));
	lv_style_set_bg_grad_dir(&style_menue_btn_4_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_menue_btn_4_main_main_default, 50);
	lv_style_set_shadow_color(&style_menue_btn_4_main_main_default, lv_color_make(0xe8, 0x11, 0x52));
	lv_style_set_shadow_opa(&style_menue_btn_4_main_main_default, 255);
	lv_style_set_border_color(&style_menue_btn_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_menue_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_menue_btn_4_main_main_default, 255);
	lv_obj_add_style(ui->Menue_btn_4, &style_menue_btn_4_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Menue_btn_4_label = lv_label_create(ui->Menue_btn_4);
	lv_label_set_text(ui->Menue_btn_4_label, "Screen Brightness");
	lv_obj_set_style_text_color(ui->Menue_btn_4_label, lv_color_make(0xe8, 0x11, 0x52), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menue_btn_4_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Menue_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Menue_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes Menue_btn_5
	ui->Menue_btn_5 = lv_btn_create(ui->Menue);
	lv_obj_set_pos(ui->Menue_btn_5, 150, 240);
	lv_obj_set_size(ui->Menue_btn_5, 180, 30);

	// Write style state: LV_STATE_DEFAULT for style_menue_btn_5_main_main_default
	static lv_style_t style_menue_btn_5_main_main_default;
	if (style_menue_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menue_btn_5_main_main_default);
	else
		lv_style_init(&style_menue_btn_5_main_main_default);
	lv_style_set_radius(&style_menue_btn_5_main_main_default, 10);
	lv_style_set_bg_color(&style_menue_btn_5_main_main_default, lv_color_make(0xb8, 0x32, 0x05));
	lv_style_set_bg_grad_color(&style_menue_btn_5_main_main_default, lv_color_make(0x05, 0xff, 0xb8));
	lv_style_set_bg_grad_dir(&style_menue_btn_5_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_menue_btn_5_main_main_default, 53);
	lv_style_set_shadow_color(&style_menue_btn_5_main_main_default, lv_color_make(0x00, 0xff, 0x7b));
	lv_style_set_shadow_opa(&style_menue_btn_5_main_main_default, 255);
	lv_style_set_border_color(&style_menue_btn_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_menue_btn_5_main_main_default, 0);
	lv_style_set_border_opa(&style_menue_btn_5_main_main_default, 255);
	lv_obj_add_style(ui->Menue_btn_5, &style_menue_btn_5_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Menue_btn_5_label = lv_label_create(ui->Menue_btn_5);
	lv_label_set_text(ui->Menue_btn_5_label, "Buzzer");
	lv_obj_set_style_text_color(ui->Menue_btn_5_label, lv_color_make(0x00, 0xf5, 0x49), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menue_btn_5_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Menue_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Menue_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	// Write codes Menue_btn_6
	ui->Menue_btn_6 = lv_btn_create(ui->Menue);
	lv_obj_set_pos(ui->Menue_btn_6, 435, 275);
	lv_obj_set_size(ui->Menue_btn_6, 42, 42);

	// Write style state: LV_STATE_DEFAULT for style_menue_btn_6_main_main_default
	static lv_style_t style_menue_btn_6_main_main_default;
	if (style_menue_btn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_menue_btn_6_main_main_default);
	else
		lv_style_init(&style_menue_btn_6_main_main_default);
	lv_style_set_radius(&style_menue_btn_6_main_main_default, 100);
	lv_style_set_bg_color(&style_menue_btn_6_main_main_default, lv_color_make(0x07, 0xcf, 0x68));
	lv_style_set_bg_grad_color(&style_menue_btn_6_main_main_default, lv_color_make(0x06, 0xf4, 0xe4));
	lv_style_set_bg_grad_dir(&style_menue_btn_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menue_btn_6_main_main_default, 48);
	lv_style_set_shadow_color(&style_menue_btn_6_main_main_default, lv_color_make(0xff, 0x00, 0x00));
	lv_style_set_shadow_opa(&style_menue_btn_6_main_main_default, 216);
	lv_style_set_border_color(&style_menue_btn_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_menue_btn_6_main_main_default, 0);
	lv_style_set_border_opa(&style_menue_btn_6_main_main_default, 255);
	lv_obj_add_style(ui->Menue_btn_6, &style_menue_btn_6_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	ui->Menue_btn_6_label = lv_label_create(ui->Menue_btn_6);
	lv_label_set_text(ui->Menue_btn_6_label, "Exit");
	lv_obj_set_style_text_color(ui->Menue_btn_6_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menue_btn_6_label, &lv_font_montserrat_18, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->Menue_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Menue_btn_6_label, LV_ALIGN_CENTER, 0, 0);

	// Init events for screen
	events_init_Menue(ui);

	/**/
	lv_group_t *group = lv_group_create();
	lv_indev_set_group(indev_encoder[1], group);
	lv_group_add_obj(group, ui->Menue_btn_1);
	lv_group_add_obj(group, ui->Menue_btn_2);
	lv_group_add_obj(group, ui->Menue_btn_3);
	lv_group_add_obj(group, ui->Menue_btn_4);
	lv_group_add_obj(group, ui->Menue_btn_5);
	lv_group_t *group1 = lv_group_create();
	lv_indev_set_group(indev_encoder[2], group1);
	lv_group_add_obj(group1, ui->Menue_btn_6);
}
