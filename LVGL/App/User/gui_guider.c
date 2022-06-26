/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"

User_Info guser = {
    .Ws281x_Cmyk = {
        .C.C = 0,
        .C.M = 0,
        .C.Y = 0,
        .C.K = 100,
    },
    .timer_counts = 0,
    .test_flag = false,
    .system_start = false,
    .buzzer_switch = false,
    // .ptarget = NULL,
    .brightness = 50,
};

lv_ui guider_ui;

void setup_ui(lv_ui *ui)
{
    setup_scr_Main(ui);
    lv_scr_load(ui->Main);
}

void clock_count(int *hour, int *min, int *sec)
{
    if (*sec < 60)
    {
        /* code */
        (*sec)++;
    }
    else
    {
        *sec = 1;
    }

    if (*sec == 60)
    {
        /* code */
        if (*min < 60)
        {
            (*min)++;
        }
        else
        {
            *min = 1;
        }
    }

    if (*min % 12 == 0 && *sec == 60)
    {
        /* code */
        if (*hour < 60)
        {
            /* code */
            (*hour)++;
        }
        else
        {
            *hour = 1;
        }
    }
}
