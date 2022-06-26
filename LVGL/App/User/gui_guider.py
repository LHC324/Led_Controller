# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=480,h=320)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(480*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 480
disp_drv.ver_res = 320
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.add_flag(lv.obj.FLAG.HIDDEN)


Main = lv.obj()
# create style style_main_main_main_default
style_main_main_main_default = lv.style_t()
style_main_main_main_default.init()
style_main_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_main_main_main_default.set_bg_opa(0)

# add style for Main
Main.add_style(style_main_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Main_cont_1 = lv.obj(Main)
Main_cont_1.set_pos(0,0)
Main_cont_1.set_size(480,320)
# create style style_main_cont_1_main_main_default
style_main_cont_1_main_main_default = lv.style_t()
style_main_cont_1_main_main_default.init()
style_main_cont_1_main_main_default.set_radius(0)
style_main_cont_1_main_main_default.set_bg_color(lv.color_make(0x01,0x04,0x09))
style_main_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x1b,0x29,0x3b))
style_main_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_main_cont_1_main_main_default.set_bg_opa(255)
style_main_cont_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_main_cont_1_main_main_default.set_border_width(0)
style_main_cont_1_main_main_default.set_border_opa(255)
style_main_cont_1_main_main_default.set_pad_left(0)
style_main_cont_1_main_main_default.set_pad_right(0)
style_main_cont_1_main_main_default.set_pad_top(0)
style_main_cont_1_main_main_default.set_pad_bottom(0)

# add style for Main_cont_1
Main_cont_1.add_style(style_main_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Main_btn_1 = lv.btn(Main)
Main_btn_1.set_pos(3,280)
Main_btn_1.set_size(80,40)
Main_btn_1_label = lv.label(Main_btn_1)
Main_btn_1_label.set_text("Menue")
Main_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
Main_btn_1_label.align(lv.ALIGN.CENTER,0,0)
Main_btn_1_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    Main_btn_1_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Main_btn_1_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Main_btn_1_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_main_btn_1_main_main_default
style_main_btn_1_main_main_default = lv.style_t()
style_main_btn_1_main_main_default.init()
style_main_btn_1_main_main_default.set_radius(10)
style_main_btn_1_main_main_default.set_bg_color(lv.color_make(0x07,0xcf,0xae))
style_main_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_main_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_main_btn_1_main_main_default.set_bg_opa(48)
style_main_btn_1_main_main_default.set_shadow_color(lv.color_make(0xf7,0xb6,0x02))
style_main_btn_1_main_main_default.set_shadow_opa(255)
style_main_btn_1_main_main_default.set_border_color(lv.color_make(0xf7,0xb6,0x02))
style_main_btn_1_main_main_default.set_border_width(0)
style_main_btn_1_main_main_default.set_border_opa(0)

# add style for Main_btn_1
Main_btn_1.add_style(style_main_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Main_label_1 = lv.label(Main)
Main_label_1.set_pos(150,20)
Main_label_1.set_size(180,20)
Main_label_1.set_text("Led Controller")
Main_label_1.set_long_mode(lv.label.LONG.WRAP)
Main_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_main_label_1_main_main_default
style_main_label_1_main_main_default = lv.style_t()
style_main_label_1_main_main_default.init()
style_main_label_1_main_main_default.set_radius(10)
style_main_label_1_main_main_default.set_bg_color(lv.color_make(0xfa,0xfa,0xfa))
style_main_label_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_main_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_main_label_1_main_main_default.set_bg_opa(0)
style_main_label_1_main_main_default.set_text_color(lv.color_make(0xfa,0xfa,0xfa))
try:
    style_main_label_1_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_main_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_main_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_main_label_1_main_main_default.set_text_letter_space(1)
style_main_label_1_main_main_default.set_pad_left(0)
style_main_label_1_main_main_default.set_pad_right(0)
style_main_label_1_main_main_default.set_pad_top(0)
style_main_label_1_main_main_default.set_pad_bottom(0)

# add style for Main_label_1
Main_label_1.add_style(style_main_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Main_analog_clock_1 = lv.meter(Main)

Main_analog_clock_1_scale_hour = Main_analog_clock_1.add_scale()
Main_analog_clock_1.set_scale_ticks(Main_analog_clock_1_scale_hour, 12, 0, 0, lv.palette_main(lv.PALETTE.GREY))
Main_analog_clock_1.set_scale_major_ticks(Main_analog_clock_1_scale_hour, 1, 2, 10,
	lv.color_make(0xff, 0xff, 0xff), 10)
Main_analog_clock_1.set_scale_range(Main_analog_clock_1_scale_hour, 1, 12, 330, 300)

Main_analog_clock_1_scale_min = Main_analog_clock_1.add_scale()
Main_analog_clock_1.set_scale_ticks(Main_analog_clock_1_scale_min, 61, 2, 5,
	lv.color_make(0xe1, 0xd1, 0xd1))
Main_analog_clock_1.set_scale_range(Main_analog_clock_1_scale_min, 0, 60, 360, 270)


Main_analog_clock_1_indic_hour = Main_analog_clock_1.add_needle_line(Main_analog_clock_1_scale_min, 2,
    lv.color_make(0x00, 0xff, 0x00),
    -40)


if Main_analog_clock_1_indic_hour:
    Main_analog_clock_1.set_indicator_value(Main_analog_clock_1_indic_hour, 3 *5 + 20 //12)



Main_analog_clock_1_indic_min = Main_analog_clock_1.add_needle_line(Main_analog_clock_1_scale_min, 2,
    lv.color_make(0xE1, 0xFF, 0x00),
    -30)


if Main_analog_clock_1_indic_min:
    Main_analog_clock_1.set_indicator_value(Main_analog_clock_1_indic_min, 20)



Main_analog_clock_1_indic_sec = Main_analog_clock_1.add_needle_line(Main_analog_clock_1_scale_min, 2,
    lv.color_make(0x66, 0x00, 0xFF),
    -10)


if Main_analog_clock_1_indic_sec:
    Main_analog_clock_1.set_indicator_value(Main_analog_clock_1_indic_sec, 50)

class Main_analog_clock_1_timerClass():
    def __init__(self):
        self.hour = 3 *5 + 20 //12
        self.minute = 20
        self.second = 50
        
    def count(self, timer):
        if self.second < 60:
            self.second += 1
        else:
            self.second = 1

        if self.second == 60:
            if self.minute < 60:
                self.minute += 1
            else:
                self.minute = 1

        if self.second == 60 and self.minute % 12 == 0:
            if self.hour < 60:
                self.hour += 1
            else:
                self.hour = 1

        Main_analog_clock_1.set_indicator_value(Main_analog_clock_1_indic_hour, self.hour)
        Main_analog_clock_1.set_indicator_value(Main_analog_clock_1_indic_min, self.minute)
        Main_analog_clock_1.set_indicator_value(Main_analog_clock_1_indic_sec, self.second)

Main_analog_clock_1_timerInstance = Main_analog_clock_1_timerClass()

Main_analog_clock_1_timer = lv.timer_create_basic()
Main_analog_clock_1_timer.set_period(1000)
Main_analog_clock_1_timer.set_cb(lambda src: Main_analog_clock_1_timerInstance.count(Main_analog_clock_1_timer))
Main_analog_clock_1.set_pos(165,90)
Main_analog_clock_1.set_size(150,150)
# create style style_main_analog_clock_1_main_main_default
style_main_analog_clock_1_main_main_default = lv.style_t()
style_main_analog_clock_1_main_main_default.init()
style_main_analog_clock_1_main_main_default.set_bg_color(lv.color_make(0x0c,0x04,0x04))
style_main_analog_clock_1_main_main_default.set_bg_grad_color(lv.color_make(0x07,0x03,0x03))
style_main_analog_clock_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_main_analog_clock_1_main_main_default.set_bg_opa(255)

# add style for Main_analog_clock_1
Main_analog_clock_1.add_style(style_main_analog_clock_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_main_analog_clock_1_main_ticks_default
style_main_analog_clock_1_main_ticks_default = lv.style_t()
style_main_analog_clock_1_main_ticks_default.init()
style_main_analog_clock_1_main_ticks_default.set_text_color(lv.color_make(0xe2,0x8d,0x8d))
try:
    style_main_analog_clock_1_main_ticks_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_main_analog_clock_1_main_ticks_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_main_analog_clock_1_main_ticks_default.set_text_font(lv.font_montserrat_16)

# add style for Main_analog_clock_1
Main_analog_clock_1.add_style(style_main_analog_clock_1_main_ticks_default, lv.PART.TICKS|lv.STATE.DEFAULT)

Menue = lv.obj()
# create style style_menue_main_main_default
style_menue_main_main_default = lv.style_t()
style_menue_main_main_default.init()
style_menue_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_menue_main_main_default.set_bg_opa(0)

# add style for Menue
Menue.add_style(style_menue_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Menue_cont_1 = lv.obj(Menue)
Menue_cont_1.set_pos(0,0)
Menue_cont_1.set_size(480,320)
# create style style_menue_cont_1_main_main_default
style_menue_cont_1_main_main_default = lv.style_t()
style_menue_cont_1_main_main_default.init()
style_menue_cont_1_main_main_default.set_radius(0)
style_menue_cont_1_main_main_default.set_bg_color(lv.color_make(0x01,0x04,0x09))
style_menue_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x1b,0x29,0x3b))
style_menue_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_menue_cont_1_main_main_default.set_bg_opa(255)
style_menue_cont_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_menue_cont_1_main_main_default.set_border_width(0)
style_menue_cont_1_main_main_default.set_border_opa(255)
style_menue_cont_1_main_main_default.set_pad_left(0)
style_menue_cont_1_main_main_default.set_pad_right(0)
style_menue_cont_1_main_main_default.set_pad_top(0)
style_menue_cont_1_main_main_default.set_pad_bottom(0)

# add style for Menue_cont_1
Menue_cont_1.add_style(style_menue_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Menue_btn_1 = lv.btn(Menue)
Menue_btn_1.set_pos(150,30)
Menue_btn_1.set_size(180,29)
Menue_btn_1_label = lv.label(Menue_btn_1)
Menue_btn_1_label.set_text("CMYK settings")
Menue_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
Menue_btn_1_label.align(lv.ALIGN.CENTER,0,0)
Menue_btn_1_label.set_style_text_color(lv.color_make(0xc8,0x27,0xd2), lv.STATE.DEFAULT)
try:
    Menue_btn_1_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Menue_btn_1_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Menue_btn_1_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_menue_btn_1_main_main_default
style_menue_btn_1_main_main_default = lv.style_t()
style_menue_btn_1_main_main_default.init()
style_menue_btn_1_main_main_default.set_radius(10)
style_menue_btn_1_main_main_default.set_bg_color(lv.color_make(0xcf,0x07,0xbe))
style_menue_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_menue_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_menue_btn_1_main_main_default.set_bg_opa(31)
style_menue_btn_1_main_main_default.set_shadow_color(lv.color_make(0xc8,0x27,0xd3))
style_menue_btn_1_main_main_default.set_shadow_opa(255)
style_menue_btn_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_menue_btn_1_main_main_default.set_border_width(0)
style_menue_btn_1_main_main_default.set_border_opa(255)

# add style for Menue_btn_1
Menue_btn_1.add_style(style_menue_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Menue_btn_2 = lv.btn(Menue)
Menue_btn_2.set_pos(150,80)
Menue_btn_2.set_size(180,30)
Menue_btn_2_label = lv.label(Menue_btn_2)
Menue_btn_2_label.set_text("Timer")
Menue_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
Menue_btn_2_label.align(lv.ALIGN.CENTER,0,0)
Menue_btn_2_label.set_style_text_color(lv.color_make(0x0d,0xd9,0xd5), lv.STATE.DEFAULT)
try:
    Menue_btn_2_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Menue_btn_2_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Menue_btn_2_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_menue_btn_2_main_main_default
style_menue_btn_2_main_main_default = lv.style_t()
style_menue_btn_2_main_main_default.init()
style_menue_btn_2_main_main_default.set_radius(10)
style_menue_btn_2_main_main_default.set_bg_color(lv.color_make(0x07,0xa7,0xcf))
style_menue_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0x36))
style_menue_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_menue_btn_2_main_main_default.set_bg_opa(17)
style_menue_btn_2_main_main_default.set_shadow_color(lv.color_make(0x15,0xce,0xd1))
style_menue_btn_2_main_main_default.set_shadow_opa(255)
style_menue_btn_2_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_menue_btn_2_main_main_default.set_border_width(0)
style_menue_btn_2_main_main_default.set_border_opa(255)

# add style for Menue_btn_2
Menue_btn_2.add_style(style_menue_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Menue_btn_3 = lv.btn(Menue)
Menue_btn_3.set_pos(150,134)
Menue_btn_3.set_size(180,30)
Menue_btn_3_label = lv.label(Menue_btn_3)
Menue_btn_3_label.set_text("Calendar")
Menue_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
Menue_btn_3_label.align(lv.ALIGN.CENTER,0,0)
Menue_btn_3_label.set_style_text_color(lv.color_make(0xe7,0xcb,0x13), lv.STATE.DEFAULT)
try:
    Menue_btn_3_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Menue_btn_3_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Menue_btn_3_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_menue_btn_3_main_main_default
style_menue_btn_3_main_main_default = lv.style_t()
style_menue_btn_3_main_main_default.init()
style_menue_btn_3_main_main_default.set_radius(10)
style_menue_btn_3_main_main_default.set_bg_color(lv.color_make(0x0e,0xec,0x15))
style_menue_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0xf4,0x4d,0x06))
style_menue_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_menue_btn_3_main_main_default.set_bg_opa(47)
style_menue_btn_3_main_main_default.set_shadow_color(lv.color_make(0xdf,0xc3,0x11))
style_menue_btn_3_main_main_default.set_shadow_opa(255)
style_menue_btn_3_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_menue_btn_3_main_main_default.set_border_width(0)
style_menue_btn_3_main_main_default.set_border_opa(255)

# add style for Menue_btn_3
Menue_btn_3.add_style(style_menue_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Menue_btn_4 = lv.btn(Menue)
Menue_btn_4.set_pos(150,187)
Menue_btn_4.set_size(180,30)
Menue_btn_4_label = lv.label(Menue_btn_4)
Menue_btn_4_label.set_text("Screen Brightness")
Menue_btn_4.set_style_pad_all(0, lv.STATE.DEFAULT)
Menue_btn_4_label.align(lv.ALIGN.CENTER,0,0)
Menue_btn_4_label.set_style_text_color(lv.color_make(0xe8,0x11,0x52), lv.STATE.DEFAULT)
try:
    Menue_btn_4_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Menue_btn_4_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Menue_btn_4_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_menue_btn_4_main_main_default
style_menue_btn_4_main_main_default = lv.style_t()
style_menue_btn_4_main_main_default.init()
style_menue_btn_4_main_main_default.set_radius(10)
style_menue_btn_4_main_main_default.set_bg_color(lv.color_make(0xb8,0x32,0x05))
style_menue_btn_4_main_main_default.set_bg_grad_color(lv.color_make(0x05,0xff,0xb8))
style_menue_btn_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_menue_btn_4_main_main_default.set_bg_opa(50)
style_menue_btn_4_main_main_default.set_shadow_color(lv.color_make(0xe8,0x11,0x52))
style_menue_btn_4_main_main_default.set_shadow_opa(255)
style_menue_btn_4_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_menue_btn_4_main_main_default.set_border_width(0)
style_menue_btn_4_main_main_default.set_border_opa(255)

# add style for Menue_btn_4
Menue_btn_4.add_style(style_menue_btn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Menue_btn_5 = lv.btn(Menue)
Menue_btn_5.set_pos(150,240)
Menue_btn_5.set_size(180,30)
Menue_btn_5_label = lv.label(Menue_btn_5)
Menue_btn_5_label.set_text("Buzzer")
Menue_btn_5.set_style_pad_all(0, lv.STATE.DEFAULT)
Menue_btn_5_label.align(lv.ALIGN.CENTER,0,0)
Menue_btn_5_label.set_style_text_color(lv.color_make(0x00,0xf5,0x49), lv.STATE.DEFAULT)
try:
    Menue_btn_5_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Menue_btn_5_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Menue_btn_5_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_menue_btn_5_main_main_default
style_menue_btn_5_main_main_default = lv.style_t()
style_menue_btn_5_main_main_default.init()
style_menue_btn_5_main_main_default.set_radius(10)
style_menue_btn_5_main_main_default.set_bg_color(lv.color_make(0xb8,0x32,0x05))
style_menue_btn_5_main_main_default.set_bg_grad_color(lv.color_make(0x05,0xff,0xb8))
style_menue_btn_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_menue_btn_5_main_main_default.set_bg_opa(53)
style_menue_btn_5_main_main_default.set_shadow_color(lv.color_make(0x00,0xff,0x7b))
style_menue_btn_5_main_main_default.set_shadow_opa(255)
style_menue_btn_5_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_menue_btn_5_main_main_default.set_border_width(0)
style_menue_btn_5_main_main_default.set_border_opa(255)

# add style for Menue_btn_5
Menue_btn_5.add_style(style_menue_btn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Menue_btn_6 = lv.btn(Menue)
Menue_btn_6.set_pos(3,280)
Menue_btn_6.set_size(80,40)
Menue_btn_6_label = lv.label(Menue_btn_6)
Menue_btn_6_label.set_text("Enter")
Menue_btn_6.set_style_pad_all(0, lv.STATE.DEFAULT)
Menue_btn_6_label.align(lv.ALIGN.CENTER,0,0)
Menue_btn_6_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    Menue_btn_6_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Menue_btn_6_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Menue_btn_6_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_menue_btn_6_main_main_default
style_menue_btn_6_main_main_default = lv.style_t()
style_menue_btn_6_main_main_default.init()
style_menue_btn_6_main_main_default.set_radius(8)
style_menue_btn_6_main_main_default.set_bg_color(lv.color_make(0x07,0xcf,0x68))
style_menue_btn_6_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_menue_btn_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_menue_btn_6_main_main_default.set_bg_opa(57)
style_menue_btn_6_main_main_default.set_shadow_color(lv.color_make(0x34,0xf4,0x97))
style_menue_btn_6_main_main_default.set_shadow_opa(255)
style_menue_btn_6_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_menue_btn_6_main_main_default.set_border_width(0)
style_menue_btn_6_main_main_default.set_border_opa(255)

# add style for Menue_btn_6
Menue_btn_6.add_style(style_menue_btn_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Menue_btn_7 = lv.btn(Menue)
Menue_btn_7.set_pos(397,280)
Menue_btn_7.set_size(80,40)
Menue_btn_7_label = lv.label(Menue_btn_7)
Menue_btn_7_label.set_text("Cancel")
Menue_btn_7.set_style_pad_all(0, lv.STATE.DEFAULT)
Menue_btn_7_label.align(lv.ALIGN.CENTER,0,0)
Menue_btn_7_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    Menue_btn_7_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Menue_btn_7_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Menue_btn_7_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_menue_btn_7_main_main_default
style_menue_btn_7_main_main_default = lv.style_t()
style_menue_btn_7_main_main_default.init()
style_menue_btn_7_main_main_default.set_radius(10)
style_menue_btn_7_main_main_default.set_bg_color(lv.color_make(0x07,0xcf,0x68))
style_menue_btn_7_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_menue_btn_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_menue_btn_7_main_main_default.set_bg_opa(48)
style_menue_btn_7_main_main_default.set_shadow_color(lv.color_make(0xff,0x00,0x00))
style_menue_btn_7_main_main_default.set_shadow_opa(216)
style_menue_btn_7_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_menue_btn_7_main_main_default.set_border_width(0)
style_menue_btn_7_main_main_default.set_border_opa(255)

# add style for Menue_btn_7
Menue_btn_7.add_style(style_menue_btn_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise = lv.obj()
# create style style_cmyk_revise_main_main_default
style_cmyk_revise_main_main_default = lv.style_t()
style_cmyk_revise_main_main_default.init()
style_cmyk_revise_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_cmyk_revise_main_main_default.set_bg_opa(0)

# add style for CMYK_Revise
CMYK_Revise.add_style(style_cmyk_revise_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_cont_1 = lv.obj(CMYK_Revise)
CMYK_Revise_cont_1.set_pos(0,0)
CMYK_Revise_cont_1.set_size(480,320)
# create style style_cmyk_revise_cont_1_main_main_default
style_cmyk_revise_cont_1_main_main_default = lv.style_t()
style_cmyk_revise_cont_1_main_main_default.init()
style_cmyk_revise_cont_1_main_main_default.set_radius(0)
style_cmyk_revise_cont_1_main_main_default.set_bg_color(lv.color_make(0x01,0x04,0x09))
style_cmyk_revise_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x1b,0x29,0x3b))
style_cmyk_revise_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_cmyk_revise_cont_1_main_main_default.set_bg_opa(255)
style_cmyk_revise_cont_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_cmyk_revise_cont_1_main_main_default.set_border_width(0)
style_cmyk_revise_cont_1_main_main_default.set_border_opa(255)
style_cmyk_revise_cont_1_main_main_default.set_pad_left(0)
style_cmyk_revise_cont_1_main_main_default.set_pad_right(0)
style_cmyk_revise_cont_1_main_main_default.set_pad_top(0)
style_cmyk_revise_cont_1_main_main_default.set_pad_bottom(0)

# add style for CMYK_Revise_cont_1
CMYK_Revise_cont_1.add_style(style_cmyk_revise_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_label_1 = lv.label(CMYK_Revise)
CMYK_Revise_label_1.set_pos(0,140)
CMYK_Revise_label_1.set_size(50,20)
CMYK_Revise_label_1.set_text("C:")
CMYK_Revise_label_1.set_long_mode(lv.label.LONG.WRAP)
CMYK_Revise_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_cmyk_revise_label_1_main_main_default
style_cmyk_revise_label_1_main_main_default = lv.style_t()
style_cmyk_revise_label_1_main_main_default.init()
style_cmyk_revise_label_1_main_main_default.set_radius(0)
style_cmyk_revise_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_label_1_main_main_default.set_bg_opa(0)
style_cmyk_revise_label_1_main_main_default.set_text_color(lv.color_make(0xfa,0xfa,0xfa))
try:
    style_cmyk_revise_label_1_main_main_default.set_text_font(lv.font_Acme_Regular_22)
except AttributeError:
    try:
        style_cmyk_revise_label_1_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_cmyk_revise_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_cmyk_revise_label_1_main_main_default.set_text_letter_space(2)
style_cmyk_revise_label_1_main_main_default.set_pad_left(0)
style_cmyk_revise_label_1_main_main_default.set_pad_right(0)
style_cmyk_revise_label_1_main_main_default.set_pad_top(0)
style_cmyk_revise_label_1_main_main_default.set_pad_bottom(0)

# add style for CMYK_Revise_label_1
CMYK_Revise_label_1.add_style(style_cmyk_revise_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_label_2 = lv.label(CMYK_Revise)
CMYK_Revise_label_2.set_pos(120,140)
CMYK_Revise_label_2.set_size(50,20)
CMYK_Revise_label_2.set_text("M:")
CMYK_Revise_label_2.set_long_mode(lv.label.LONG.WRAP)
CMYK_Revise_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_cmyk_revise_label_2_main_main_default
style_cmyk_revise_label_2_main_main_default = lv.style_t()
style_cmyk_revise_label_2_main_main_default.init()
style_cmyk_revise_label_2_main_main_default.set_radius(0)
style_cmyk_revise_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_label_2_main_main_default.set_bg_opa(0)
style_cmyk_revise_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_cmyk_revise_label_2_main_main_default.set_text_font(lv.font_Acme_Regular_22)
except AttributeError:
    try:
        style_cmyk_revise_label_2_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_cmyk_revise_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_cmyk_revise_label_2_main_main_default.set_text_letter_space(2)
style_cmyk_revise_label_2_main_main_default.set_pad_left(0)
style_cmyk_revise_label_2_main_main_default.set_pad_right(0)
style_cmyk_revise_label_2_main_main_default.set_pad_top(0)
style_cmyk_revise_label_2_main_main_default.set_pad_bottom(0)

# add style for CMYK_Revise_label_2
CMYK_Revise_label_2.add_style(style_cmyk_revise_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_label_3 = lv.label(CMYK_Revise)
CMYK_Revise_label_3.set_pos(250,140)
CMYK_Revise_label_3.set_size(50,20)
CMYK_Revise_label_3.set_text("Y:")
CMYK_Revise_label_3.set_long_mode(lv.label.LONG.WRAP)
CMYK_Revise_label_3.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_cmyk_revise_label_3_main_main_default
style_cmyk_revise_label_3_main_main_default = lv.style_t()
style_cmyk_revise_label_3_main_main_default.init()
style_cmyk_revise_label_3_main_main_default.set_radius(0)
style_cmyk_revise_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_label_3_main_main_default.set_bg_opa(0)
style_cmyk_revise_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_cmyk_revise_label_3_main_main_default.set_text_font(lv.font_Acme_Regular_22)
except AttributeError:
    try:
        style_cmyk_revise_label_3_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_cmyk_revise_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_cmyk_revise_label_3_main_main_default.set_text_letter_space(2)
style_cmyk_revise_label_3_main_main_default.set_pad_left(0)
style_cmyk_revise_label_3_main_main_default.set_pad_right(0)
style_cmyk_revise_label_3_main_main_default.set_pad_top(0)
style_cmyk_revise_label_3_main_main_default.set_pad_bottom(0)

# add style for CMYK_Revise_label_3
CMYK_Revise_label_3.add_style(style_cmyk_revise_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_label_4 = lv.label(CMYK_Revise)
CMYK_Revise_label_4.set_pos(375,140)
CMYK_Revise_label_4.set_size(50,20)
CMYK_Revise_label_4.set_text("K:")
CMYK_Revise_label_4.set_long_mode(lv.label.LONG.WRAP)
CMYK_Revise_label_4.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_cmyk_revise_label_4_main_main_default
style_cmyk_revise_label_4_main_main_default = lv.style_t()
style_cmyk_revise_label_4_main_main_default.init()
style_cmyk_revise_label_4_main_main_default.set_radius(0)
style_cmyk_revise_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_label_4_main_main_default.set_bg_opa(0)
style_cmyk_revise_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_cmyk_revise_label_4_main_main_default.set_text_font(lv.font_Acme_Regular_22)
except AttributeError:
    try:
        style_cmyk_revise_label_4_main_main_default.set_text_font(lv.font_montserrat_22)
    except AttributeError:
        style_cmyk_revise_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_cmyk_revise_label_4_main_main_default.set_text_letter_space(2)
style_cmyk_revise_label_4_main_main_default.set_pad_left(0)
style_cmyk_revise_label_4_main_main_default.set_pad_right(0)
style_cmyk_revise_label_4_main_main_default.set_pad_top(0)
style_cmyk_revise_label_4_main_main_default.set_pad_bottom(0)

# add style for CMYK_Revise_label_4
CMYK_Revise_label_4.add_style(style_cmyk_revise_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_label_5 = lv.label(CMYK_Revise)
CMYK_Revise_label_5.set_pos(150,20)
CMYK_Revise_label_5.set_size(180,20)
CMYK_Revise_label_5.set_text("CMYK Revise")
CMYK_Revise_label_5.set_long_mode(lv.label.LONG.WRAP)
CMYK_Revise_label_5.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_cmyk_revise_label_5_main_main_default
style_cmyk_revise_label_5_main_main_default = lv.style_t()
style_cmyk_revise_label_5_main_main_default.init()
style_cmyk_revise_label_5_main_main_default.set_radius(10)
style_cmyk_revise_label_5_main_main_default.set_bg_color(lv.color_make(0xd3,0xf6,0x23))
style_cmyk_revise_label_5_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0x23,0x23))
style_cmyk_revise_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_label_5_main_main_default.set_bg_opa(0)
style_cmyk_revise_label_5_main_main_default.set_text_color(lv.color_make(0xc8,0x27,0xd2))
try:
    style_cmyk_revise_label_5_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_cmyk_revise_label_5_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_cmyk_revise_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_cmyk_revise_label_5_main_main_default.set_text_letter_space(1)
style_cmyk_revise_label_5_main_main_default.set_pad_left(0)
style_cmyk_revise_label_5_main_main_default.set_pad_right(0)
style_cmyk_revise_label_5_main_main_default.set_pad_top(0)
style_cmyk_revise_label_5_main_main_default.set_pad_bottom(0)

# add style for CMYK_Revise_label_5
CMYK_Revise_label_5.add_style(style_cmyk_revise_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_label_6 = lv.label(CMYK_Revise)
CMYK_Revise_label_6.set_pos(16,141)
CMYK_Revise_label_6.set_size(100,20)
CMYK_Revise_label_6.set_text("100")
CMYK_Revise_label_6.set_long_mode(lv.label.LONG.WRAP)
CMYK_Revise_label_6.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_cmyk_revise_label_6_main_main_default
style_cmyk_revise_label_6_main_main_default = lv.style_t()
style_cmyk_revise_label_6_main_main_default.init()
style_cmyk_revise_label_6_main_main_default.set_radius(10)
style_cmyk_revise_label_6_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_cmyk_revise_label_6_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_cmyk_revise_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_label_6_main_main_default.set_bg_opa(0)
style_cmyk_revise_label_6_main_main_default.set_text_color(lv.color_make(0x09,0xc3,0xf1))
try:
    style_cmyk_revise_label_6_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_cmyk_revise_label_6_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_cmyk_revise_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_cmyk_revise_label_6_main_main_default.set_text_letter_space(1)
style_cmyk_revise_label_6_main_main_default.set_pad_left(0)
style_cmyk_revise_label_6_main_main_default.set_pad_right(0)
style_cmyk_revise_label_6_main_main_default.set_pad_top(0)
style_cmyk_revise_label_6_main_main_default.set_pad_bottom(0)

# add style for CMYK_Revise_label_6
CMYK_Revise_label_6.add_style(style_cmyk_revise_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_label_7 = lv.label(CMYK_Revise)
CMYK_Revise_label_7.set_pos(135,141)
CMYK_Revise_label_7.set_size(100,20)
CMYK_Revise_label_7.set_text("100")
CMYK_Revise_label_7.set_long_mode(lv.label.LONG.WRAP)
CMYK_Revise_label_7.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_cmyk_revise_label_7_main_main_default
style_cmyk_revise_label_7_main_main_default = lv.style_t()
style_cmyk_revise_label_7_main_main_default.init()
style_cmyk_revise_label_7_main_main_default.set_radius(0)
style_cmyk_revise_label_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_label_7_main_main_default.set_bg_opa(0)
style_cmyk_revise_label_7_main_main_default.set_text_color(lv.color_make(0xff,0x7a,0x7a))
try:
    style_cmyk_revise_label_7_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_cmyk_revise_label_7_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_cmyk_revise_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_cmyk_revise_label_7_main_main_default.set_text_letter_space(1)
style_cmyk_revise_label_7_main_main_default.set_pad_left(0)
style_cmyk_revise_label_7_main_main_default.set_pad_right(0)
style_cmyk_revise_label_7_main_main_default.set_pad_top(0)
style_cmyk_revise_label_7_main_main_default.set_pad_bottom(0)

# add style for CMYK_Revise_label_7
CMYK_Revise_label_7.add_style(style_cmyk_revise_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_label_8 = lv.label(CMYK_Revise)
CMYK_Revise_label_8.set_pos(261,141)
CMYK_Revise_label_8.set_size(100,20)
CMYK_Revise_label_8.set_text("100")
CMYK_Revise_label_8.set_long_mode(lv.label.LONG.WRAP)
CMYK_Revise_label_8.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_cmyk_revise_label_8_main_main_default
style_cmyk_revise_label_8_main_main_default = lv.style_t()
style_cmyk_revise_label_8_main_main_default.init()
style_cmyk_revise_label_8_main_main_default.set_radius(0)
style_cmyk_revise_label_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_cmyk_revise_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_label_8_main_main_default.set_bg_opa(0)
style_cmyk_revise_label_8_main_main_default.set_text_color(lv.color_make(0xfb,0xff,0x00))
try:
    style_cmyk_revise_label_8_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_cmyk_revise_label_8_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_cmyk_revise_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_cmyk_revise_label_8_main_main_default.set_text_letter_space(1)
style_cmyk_revise_label_8_main_main_default.set_pad_left(0)
style_cmyk_revise_label_8_main_main_default.set_pad_right(0)
style_cmyk_revise_label_8_main_main_default.set_pad_top(0)
style_cmyk_revise_label_8_main_main_default.set_pad_bottom(0)

# add style for CMYK_Revise_label_8
CMYK_Revise_label_8.add_style(style_cmyk_revise_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_label_9 = lv.label(CMYK_Revise)
CMYK_Revise_label_9.set_pos(390,141)
CMYK_Revise_label_9.set_size(89,20)
CMYK_Revise_label_9.set_text("100")
CMYK_Revise_label_9.set_long_mode(lv.label.LONG.WRAP)
CMYK_Revise_label_9.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_cmyk_revise_label_9_main_main_default
style_cmyk_revise_label_9_main_main_default = lv.style_t()
style_cmyk_revise_label_9_main_main_default.init()
style_cmyk_revise_label_9_main_main_default.set_radius(0)
style_cmyk_revise_label_9_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_cmyk_revise_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_cmyk_revise_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_label_9_main_main_default.set_bg_opa(0)
style_cmyk_revise_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_cmyk_revise_label_9_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_cmyk_revise_label_9_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_cmyk_revise_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_cmyk_revise_label_9_main_main_default.set_text_letter_space(1)
style_cmyk_revise_label_9_main_main_default.set_pad_left(0)
style_cmyk_revise_label_9_main_main_default.set_pad_right(0)
style_cmyk_revise_label_9_main_main_default.set_pad_top(0)
style_cmyk_revise_label_9_main_main_default.set_pad_bottom(0)

# add style for CMYK_Revise_label_9
CMYK_Revise_label_9.add_style(style_cmyk_revise_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_btn_1 = lv.btn(CMYK_Revise)
CMYK_Revise_btn_1.set_pos(3,280)
CMYK_Revise_btn_1.set_size(80,40)
CMYK_Revise_btn_1_label = lv.label(CMYK_Revise_btn_1)
CMYK_Revise_btn_1_label.set_text("Enter")
CMYK_Revise_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
CMYK_Revise_btn_1_label.align(lv.ALIGN.CENTER,0,0)
CMYK_Revise_btn_1_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    CMYK_Revise_btn_1_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        CMYK_Revise_btn_1_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        CMYK_Revise_btn_1_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_cmyk_revise_btn_1_main_main_default
style_cmyk_revise_btn_1_main_main_default = lv.style_t()
style_cmyk_revise_btn_1_main_main_default.init()
style_cmyk_revise_btn_1_main_main_default.set_radius(8)
style_cmyk_revise_btn_1_main_main_default.set_bg_color(lv.color_make(0x07,0xcf,0x68))
style_cmyk_revise_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_cmyk_revise_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_btn_1_main_main_default.set_bg_opa(51)
style_cmyk_revise_btn_1_main_main_default.set_shadow_color(lv.color_make(0x34,0xf4,0x97))
style_cmyk_revise_btn_1_main_main_default.set_shadow_opa(255)
style_cmyk_revise_btn_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_cmyk_revise_btn_1_main_main_default.set_border_width(0)
style_cmyk_revise_btn_1_main_main_default.set_border_opa(255)

# add style for CMYK_Revise_btn_1
CMYK_Revise_btn_1.add_style(style_cmyk_revise_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

CMYK_Revise_btn_2 = lv.btn(CMYK_Revise)
CMYK_Revise_btn_2.set_pos(397,280)
CMYK_Revise_btn_2.set_size(80,40)
CMYK_Revise_btn_2_label = lv.label(CMYK_Revise_btn_2)
CMYK_Revise_btn_2_label.set_text("Cancel")
CMYK_Revise_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
CMYK_Revise_btn_2_label.align(lv.ALIGN.CENTER,0,0)
CMYK_Revise_btn_2_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    CMYK_Revise_btn_2_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        CMYK_Revise_btn_2_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        CMYK_Revise_btn_2_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_cmyk_revise_btn_2_main_main_default
style_cmyk_revise_btn_2_main_main_default = lv.style_t()
style_cmyk_revise_btn_2_main_main_default.init()
style_cmyk_revise_btn_2_main_main_default.set_radius(10)
style_cmyk_revise_btn_2_main_main_default.set_bg_color(lv.color_make(0x07,0xcf,0x68))
style_cmyk_revise_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_cmyk_revise_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_cmyk_revise_btn_2_main_main_default.set_bg_opa(48)
style_cmyk_revise_btn_2_main_main_default.set_shadow_color(lv.color_make(0xff,0x00,0x00))
style_cmyk_revise_btn_2_main_main_default.set_shadow_opa(216)
style_cmyk_revise_btn_2_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_cmyk_revise_btn_2_main_main_default.set_border_width(0)
style_cmyk_revise_btn_2_main_main_default.set_border_opa(255)

# add style for CMYK_Revise_btn_2
CMYK_Revise_btn_2.add_style(style_cmyk_revise_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Timer = lv.obj()
# create style style_timer_main_main_default
style_timer_main_main_default = lv.style_t()
style_timer_main_main_default.init()
style_timer_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_timer_main_main_default.set_bg_opa(0)

# add style for Timer
Timer.add_style(style_timer_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Timer_cont_1 = lv.obj(Timer)
Timer_cont_1.set_pos(0,0)
Timer_cont_1.set_size(480,320)
# create style style_timer_cont_1_main_main_default
style_timer_cont_1_main_main_default = lv.style_t()
style_timer_cont_1_main_main_default.init()
style_timer_cont_1_main_main_default.set_radius(0)
style_timer_cont_1_main_main_default.set_bg_color(lv.color_make(0x01,0x04,0x09))
style_timer_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x1b,0x29,0x33))
style_timer_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_timer_cont_1_main_main_default.set_bg_opa(255)
style_timer_cont_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_timer_cont_1_main_main_default.set_border_width(0)
style_timer_cont_1_main_main_default.set_border_opa(255)
style_timer_cont_1_main_main_default.set_pad_left(0)
style_timer_cont_1_main_main_default.set_pad_right(0)
style_timer_cont_1_main_main_default.set_pad_top(0)
style_timer_cont_1_main_main_default.set_pad_bottom(0)

# add style for Timer_cont_1
Timer_cont_1.add_style(style_timer_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Timer_label = lv.label(Timer)
Timer_label.set_pos(150,20)
Timer_label.set_size(180,20)
Timer_label.set_text("Timer")
Timer_label.set_long_mode(lv.label.LONG.WRAP)
Timer_label.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_timer_label_main_main_default
style_timer_label_main_main_default = lv.style_t()
style_timer_label_main_main_default.init()
style_timer_label_main_main_default.set_radius(10)
style_timer_label_main_main_default.set_bg_color(lv.color_make(0xd3,0xf6,0x23))
style_timer_label_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0x23,0x23))
style_timer_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_timer_label_main_main_default.set_bg_opa(0)
style_timer_label_main_main_default.set_text_color(lv.color_make(0x0d,0xd9,0xd5))
try:
    style_timer_label_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_timer_label_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_timer_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_timer_label_main_main_default.set_text_letter_space(1)
style_timer_label_main_main_default.set_pad_left(0)
style_timer_label_main_main_default.set_pad_right(0)
style_timer_label_main_main_default.set_pad_top(0)
style_timer_label_main_main_default.set_pad_bottom(0)

# add style for Timer_label
Timer_label.add_style(style_timer_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Timer_label_1 = lv.label(Timer)
Timer_label_1.set_pos(190,138)
Timer_label_1.set_size(100,32)
Timer_label_1.set_text("0000.0S")
Timer_label_1.set_long_mode(lv.label.LONG.WRAP)
Timer_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_timer_label_1_main_main_default
style_timer_label_1_main_main_default = lv.style_t()
style_timer_label_1_main_main_default.init()
style_timer_label_1_main_main_default.set_radius(0)
style_timer_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_timer_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_timer_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_timer_label_1_main_main_default.set_bg_opa(0)
style_timer_label_1_main_main_default.set_text_color(lv.color_make(0x0d,0xd9,0xd5))
try:
    style_timer_label_1_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_timer_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_timer_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_timer_label_1_main_main_default.set_text_letter_space(2)
style_timer_label_1_main_main_default.set_pad_left(0)
style_timer_label_1_main_main_default.set_pad_right(0)
style_timer_label_1_main_main_default.set_pad_top(0)
style_timer_label_1_main_main_default.set_pad_bottom(0)

# add style for Timer_label_1
Timer_label_1.add_style(style_timer_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Timer_btn_1 = lv.btn(Timer)
Timer_btn_1.set_pos(3,280)
Timer_btn_1.set_size(80,40)
Timer_btn_1_label = lv.label(Timer_btn_1)
Timer_btn_1_label.set_text("Enter")
Timer_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
Timer_btn_1_label.align(lv.ALIGN.CENTER,0,0)
Timer_btn_1_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    Timer_btn_1_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Timer_btn_1_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Timer_btn_1_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_timer_btn_1_main_main_default
style_timer_btn_1_main_main_default = lv.style_t()
style_timer_btn_1_main_main_default.init()
style_timer_btn_1_main_main_default.set_radius(8)
style_timer_btn_1_main_main_default.set_bg_color(lv.color_make(0x07,0xcf,0x68))
style_timer_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_timer_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_timer_btn_1_main_main_default.set_bg_opa(51)
style_timer_btn_1_main_main_default.set_shadow_color(lv.color_make(0x34,0xf4,0x97))
style_timer_btn_1_main_main_default.set_shadow_opa(255)
style_timer_btn_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_timer_btn_1_main_main_default.set_border_width(0)
style_timer_btn_1_main_main_default.set_border_opa(255)

# add style for Timer_btn_1
Timer_btn_1.add_style(style_timer_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Timer_btn_2 = lv.btn(Timer)
Timer_btn_2.set_pos(397,280)
Timer_btn_2.set_size(80,40)
Timer_btn_2_label = lv.label(Timer_btn_2)
Timer_btn_2_label.set_text("Cancel")
Timer_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
Timer_btn_2_label.align(lv.ALIGN.CENTER,0,0)
Timer_btn_2_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    Timer_btn_2_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Timer_btn_2_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Timer_btn_2_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_timer_btn_2_main_main_default
style_timer_btn_2_main_main_default = lv.style_t()
style_timer_btn_2_main_main_default.init()
style_timer_btn_2_main_main_default.set_radius(10)
style_timer_btn_2_main_main_default.set_bg_color(lv.color_make(0x07,0xcf,0x68))
style_timer_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_timer_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_timer_btn_2_main_main_default.set_bg_opa(48)
style_timer_btn_2_main_main_default.set_shadow_color(lv.color_make(0xff,0x00,0x00))
style_timer_btn_2_main_main_default.set_shadow_opa(216)
style_timer_btn_2_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_timer_btn_2_main_main_default.set_border_width(0)
style_timer_btn_2_main_main_default.set_border_opa(255)

# add style for Timer_btn_2
Timer_btn_2.add_style(style_timer_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Calendar = lv.obj()
# create style style_calendar_main_main_default
style_calendar_main_main_default = lv.style_t()
style_calendar_main_main_default.init()
style_calendar_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_calendar_main_main_default.set_bg_opa(0)

# add style for Calendar
Calendar.add_style(style_calendar_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Calendar_cont_1 = lv.obj(Calendar)
Calendar_cont_1.set_pos(0,0)
Calendar_cont_1.set_size(480,320)
# create style style_calendar_cont_1_main_main_default
style_calendar_cont_1_main_main_default = lv.style_t()
style_calendar_cont_1_main_main_default.init()
style_calendar_cont_1_main_main_default.set_radius(0)
style_calendar_cont_1_main_main_default.set_bg_color(lv.color_make(0x01,0x04,0x09))
style_calendar_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x1b,0x29,0x33))
style_calendar_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_calendar_cont_1_main_main_default.set_bg_opa(255)
style_calendar_cont_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_calendar_cont_1_main_main_default.set_border_width(0)
style_calendar_cont_1_main_main_default.set_border_opa(255)
style_calendar_cont_1_main_main_default.set_pad_left(0)
style_calendar_cont_1_main_main_default.set_pad_right(0)
style_calendar_cont_1_main_main_default.set_pad_top(0)
style_calendar_cont_1_main_main_default.set_pad_bottom(0)

# add style for Calendar_cont_1
Calendar_cont_1.add_style(style_calendar_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Calendar_label_1 = lv.label(Calendar)
Calendar_label_1.set_pos(150,20)
Calendar_label_1.set_size(180,20)
Calendar_label_1.set_text("Calendar")
Calendar_label_1.set_long_mode(lv.label.LONG.WRAP)
Calendar_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_calendar_label_1_main_main_default
style_calendar_label_1_main_main_default = lv.style_t()
style_calendar_label_1_main_main_default.init()
style_calendar_label_1_main_main_default.set_radius(10)
style_calendar_label_1_main_main_default.set_bg_color(lv.color_make(0xd3,0xf6,0x23))
style_calendar_label_1_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0x23,0x23))
style_calendar_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_calendar_label_1_main_main_default.set_bg_opa(0)
style_calendar_label_1_main_main_default.set_text_color(lv.color_make(0xe7,0xcb,0x13))
try:
    style_calendar_label_1_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_calendar_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_calendar_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_calendar_label_1_main_main_default.set_text_letter_space(1)
style_calendar_label_1_main_main_default.set_pad_left(0)
style_calendar_label_1_main_main_default.set_pad_right(0)
style_calendar_label_1_main_main_default.set_pad_top(0)
style_calendar_label_1_main_main_default.set_pad_bottom(0)

# add style for Calendar_label_1
Calendar_label_1.add_style(style_calendar_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Calendar_calendar_1 = lv.calendar(Calendar)
Calendar_calendar_1.set_pos(100,95)
Calendar_calendar_1.set_size(280,210)
Calendar_calendar_1.set_today_date(time.localtime()[0], time.localtime()[1], time.localtime()[2])
Calendar_calendar_1.set_showed_date(time.localtime()[0], time.localtime()[1])
highlighted_days=[
    lv.calendar_date_t({'year':2020, 'month':5, 'day':14})
]
Calendar_calendar_1.set_highlighted_dates(highlighted_days, len(highlighted_days))
Calendar_calendar_1_header = lv.calendar_header_arrow(Calendar, Calendar_calendar_1, 25)
def style_calendar_calendar_1_extra_ctrl_day_names_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if dsc.id < 7:
        dsc.label_dsc.color = lv.color_make(0x0D,0x30,0x55)
        try:
            lv.font_montserrat_12
            dsc.label_dsc.font = lv.font_montserrat_12
        except AttributeError:
            try:
                lv.font_montserrat_13
                dsc.label_dsc.font = lv.font_montserrat_13
            except AttributeError:
                dsc.label_dsc.font = lv.font_montserrat_16

Calendar_calendar_1.add_event_cb(style_calendar_calendar_1_extra_ctrl_day_names_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_calendar_calendar_1_extra_ctrl_highlight_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.CUSTOM_2):
        dsc.rect_dsc.bg_color = lv.color_make(0x21,0x95,0xf6)
        dsc.rect_dsc.bg_grad_color = lv.color_make(0x21,0x95,0xf6)
        dsc.rect_dsc.bg_grad_dir = lv.GRAD_DIR.VER
        dsc.rect_dsc.bg_opa = 0
        dsc.label_dsc.color = lv.color_make(0x0D,0x30,0x55)
        try:
            lv.font_montserrat_12
            dsc.label_dsc.font = lv.font_montserrat_12
        except AttributeError:
            try:
                lv.font_montserrat_13
                dsc.label_dsc.font = lv.font_montserrat_13
            except AttributeError:
                dsc.label_dsc.font = lv.font_montserrat_16

Calendar_calendar_1.add_event_cb(style_calendar_calendar_1_extra_ctrl_highlight_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_calendar_calendar_1_extra_ctrl_today_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.CUSTOM_1):
        dsc.rect_dsc.bg_color = lv.color_make(0xb8,0xe2,0xe5)
        dsc.rect_dsc.bg_grad_color = lv.color_make(0x8c,0xd2,0xd9)
        dsc.rect_dsc.bg_grad_dir = lv.GRAD_DIR.HOR
        dsc.rect_dsc.bg_opa = 255
        dsc.rect_dsc.border_color = lv.color_make(0xc0,0xc0,0xc0)
        dsc.rect_dsc.border_width = 1
        dsc.label_dsc.color = lv.color_make(0x0D,0x30,0x55)
        try:
            lv.font_montserrat_12
            dsc.label_dsc.font = lv.font_montserrat_12
        except AttributeError:
            try:
                lv.font_montserrat_13
                dsc.label_dsc.font = lv.font_montserrat_13
            except AttributeError:
                dsc.label_dsc.font = lv.font_montserrat_16

Calendar_calendar_1.add_event_cb(style_calendar_calendar_1_extra_ctrl_today_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_calendar_calendar_1_extra_ctrl_other_month_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if dsc.id >= 7 and obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.DISABLED):
        dsc.rect_dsc.bg_color = lv.color_make(0x01,0xa2,0xb1)
        dsc.rect_dsc.bg_grad_color = lv.color_make(0x01,0xa2,0xb1)
        dsc.rect_dsc.bg_grad_dir = lv.GRAD_DIR.VER
        dsc.rect_dsc.bg_opa = 0
        dsc.label_dsc.color = lv.color_make(0xA9,0xA2,0xA2)
        try:
            lv.font_montserrat_12
            dsc.label_dsc.font = lv.font_montserrat_12
        except AttributeError:
            try:
                lv.font_montserrat_13
                dsc.label_dsc.font = lv.font_montserrat_13
            except AttributeError:
                dsc.label_dsc.font = lv.font_montserrat_16

Calendar_calendar_1.add_event_cb(style_calendar_calendar_1_extra_ctrl_other_month_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

# create style style_calendar_calendar_1_extra_header_main_default
style_calendar_calendar_1_extra_header_main_default = lv.style_t()
style_calendar_calendar_1_extra_header_main_default.init()
style_calendar_calendar_1_extra_header_main_default.set_bg_color(lv.color_make(0xe7,0xcb,0x13))
style_calendar_calendar_1_extra_header_main_default.set_bg_grad_color(lv.color_make(0x1b,0x16,0x04))
style_calendar_calendar_1_extra_header_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_calendar_calendar_1_extra_header_main_default.set_bg_opa(255)
style_calendar_calendar_1_extra_header_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_calendar_calendar_1_extra_header_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_calendar_calendar_1_extra_header_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_calendar_calendar_1_extra_header_main_default.set_text_font(lv.font_montserrat_16)

# add style for Calendar_calendar_1_header
Calendar_calendar_1_header.add_style(style_calendar_calendar_1_extra_header_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_calendar_calendar_1_main_main_default
style_calendar_calendar_1_main_main_default = lv.style_t()
style_calendar_calendar_1_main_main_default.init()
style_calendar_calendar_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_calendar_calendar_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_calendar_calendar_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_calendar_calendar_1_main_main_default.set_bg_opa(255)
style_calendar_calendar_1_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_calendar_calendar_1_main_main_default.set_border_width(1)

# add style for Calendar_calendar_1
Calendar_calendar_1.add_style(style_calendar_calendar_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_calendar_calendar_1_main_items_default
style_calendar_calendar_1_main_items_default = lv.style_t()
style_calendar_calendar_1_main_items_default.init()
style_calendar_calendar_1_main_items_default.set_bg_color(lv.color_make(0x01,0xa2,0xb1))
style_calendar_calendar_1_main_items_default.set_bg_grad_color(lv.color_make(0x01,0xa2,0xb1))
style_calendar_calendar_1_main_items_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_calendar_calendar_1_main_items_default.set_bg_opa(0)
style_calendar_calendar_1_main_items_default.set_border_color(lv.color_make(0xc0,0xc0,0xc0))
style_calendar_calendar_1_main_items_default.set_border_width(1)
style_calendar_calendar_1_main_items_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_calendar_calendar_1_main_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_calendar_calendar_1_main_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_calendar_calendar_1_main_items_default.set_text_font(lv.font_montserrat_16)

# add style for Calendar_calendar_1
Calendar_calendar_1.add_style(style_calendar_calendar_1_main_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

Calendar_btn_1 = lv.btn(Calendar)
Calendar_btn_1.set_pos(397,280)
Calendar_btn_1.set_size(80,40)
Calendar_btn_1_label = lv.label(Calendar_btn_1)
Calendar_btn_1_label.set_text("Cancel")
Calendar_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
Calendar_btn_1_label.align(lv.ALIGN.CENTER,0,0)
Calendar_btn_1_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    Calendar_btn_1_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Calendar_btn_1_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Calendar_btn_1_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_calendar_btn_1_main_main_default
style_calendar_btn_1_main_main_default = lv.style_t()
style_calendar_btn_1_main_main_default.init()
style_calendar_btn_1_main_main_default.set_radius(10)
style_calendar_btn_1_main_main_default.set_bg_color(lv.color_make(0x07,0xcf,0x68))
style_calendar_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_calendar_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_calendar_btn_1_main_main_default.set_bg_opa(48)
style_calendar_btn_1_main_main_default.set_shadow_color(lv.color_make(0xff,0x00,0x00))
style_calendar_btn_1_main_main_default.set_shadow_opa(216)
style_calendar_btn_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_calendar_btn_1_main_main_default.set_border_width(0)
style_calendar_btn_1_main_main_default.set_border_opa(255)

# add style for Calendar_btn_1
Calendar_btn_1.add_style(style_calendar_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Screen_Brightness = lv.obj()
# create style style_screen_brightness_main_main_default
style_screen_brightness_main_main_default = lv.style_t()
style_screen_brightness_main_main_default.init()
style_screen_brightness_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_brightness_main_main_default.set_bg_opa(0)

# add style for Screen_Brightness
Screen_Brightness.add_style(style_screen_brightness_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Screen_Brightness_cont_1 = lv.obj(Screen_Brightness)
Screen_Brightness_cont_1.set_pos(0,0)
Screen_Brightness_cont_1.set_size(480,320)
# create style style_screen_brightness_cont_1_main_main_default
style_screen_brightness_cont_1_main_main_default = lv.style_t()
style_screen_brightness_cont_1_main_main_default.init()
style_screen_brightness_cont_1_main_main_default.set_radius(0)
style_screen_brightness_cont_1_main_main_default.set_bg_color(lv.color_make(0x01,0x04,0x09))
style_screen_brightness_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x1b,0x29,0x33))
style_screen_brightness_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_screen_brightness_cont_1_main_main_default.set_bg_opa(255)
style_screen_brightness_cont_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_screen_brightness_cont_1_main_main_default.set_border_width(0)
style_screen_brightness_cont_1_main_main_default.set_border_opa(255)
style_screen_brightness_cont_1_main_main_default.set_pad_left(0)
style_screen_brightness_cont_1_main_main_default.set_pad_right(0)
style_screen_brightness_cont_1_main_main_default.set_pad_top(0)
style_screen_brightness_cont_1_main_main_default.set_pad_bottom(0)

# add style for Screen_Brightness_cont_1
Screen_Brightness_cont_1.add_style(style_screen_brightness_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Screen_Brightness_label_2 = lv.label(Screen_Brightness)
Screen_Brightness_label_2.set_pos(150,20)
Screen_Brightness_label_2.set_size(180,20)
Screen_Brightness_label_2.set_text("Brightness")
Screen_Brightness_label_2.set_long_mode(lv.label.LONG.WRAP)
Screen_Brightness_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_brightness_label_2_main_main_default
style_screen_brightness_label_2_main_main_default = lv.style_t()
style_screen_brightness_label_2_main_main_default.init()
style_screen_brightness_label_2_main_main_default.set_radius(10)
style_screen_brightness_label_2_main_main_default.set_bg_color(lv.color_make(0xd3,0xf6,0x23))
style_screen_brightness_label_2_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0x23,0x23))
style_screen_brightness_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_brightness_label_2_main_main_default.set_bg_opa(0)
style_screen_brightness_label_2_main_main_default.set_text_color(lv.color_make(0xe8,0x11,0x52))
try:
    style_screen_brightness_label_2_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_screen_brightness_label_2_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_screen_brightness_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_brightness_label_2_main_main_default.set_text_letter_space(1)
style_screen_brightness_label_2_main_main_default.set_pad_left(0)
style_screen_brightness_label_2_main_main_default.set_pad_right(0)
style_screen_brightness_label_2_main_main_default.set_pad_top(0)
style_screen_brightness_label_2_main_main_default.set_pad_bottom(0)

# add style for Screen_Brightness_label_2
Screen_Brightness_label_2.add_style(style_screen_brightness_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Screen_Brightness_slider_1 = lv.slider(Screen_Brightness)
Screen_Brightness_slider_1.set_pos(140,140)
Screen_Brightness_slider_1.set_size(200,10)
Screen_Brightness_slider_1.set_range(0, 100)
Screen_Brightness_slider_1.set_value(50, False)

# create style style_screen_brightness_slider_1_main_main_default
style_screen_brightness_slider_1_main_main_default = lv.style_t()
style_screen_brightness_slider_1_main_main_default.init()
style_screen_brightness_slider_1_main_main_default.set_radius(50)
style_screen_brightness_slider_1_main_main_default.set_bg_color(lv.color_make(0xf5,0xf5,0xf5))
style_screen_brightness_slider_1_main_main_default.set_bg_grad_color(lv.color_make(0x90,0x94,0x98))
style_screen_brightness_slider_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_brightness_slider_1_main_main_default.set_bg_opa(100)
style_screen_brightness_slider_1_main_main_default.set_outline_color(lv.color_make(0x21,0x95,0xf6))
style_screen_brightness_slider_1_main_main_default.set_outline_width(0)
style_screen_brightness_slider_1_main_main_default.set_outline_opa(255)
style_screen_brightness_slider_1_main_main_default.set_pad_left(0)
style_screen_brightness_slider_1_main_main_default.set_pad_right(0)
style_screen_brightness_slider_1_main_main_default.set_pad_top(0)
style_screen_brightness_slider_1_main_main_default.set_pad_bottom(0)

# add style for Screen_Brightness_slider_1
Screen_Brightness_slider_1.add_style(style_screen_brightness_slider_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_brightness_slider_1_main_indicator_default
style_screen_brightness_slider_1_main_indicator_default = lv.style_t()
style_screen_brightness_slider_1_main_indicator_default.init()
style_screen_brightness_slider_1_main_indicator_default.set_radius(50)
style_screen_brightness_slider_1_main_indicator_default.set_bg_color(lv.color_make(0xf7,0x08,0x44))
style_screen_brightness_slider_1_main_indicator_default.set_bg_grad_color(lv.color_make(0xf0,0x00,0x6c))
style_screen_brightness_slider_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_brightness_slider_1_main_indicator_default.set_bg_opa(255)

# add style for Screen_Brightness_slider_1
Screen_Brightness_slider_1.add_style(style_screen_brightness_slider_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_screen_brightness_slider_1_main_knob_default
style_screen_brightness_slider_1_main_knob_default = lv.style_t()
style_screen_brightness_slider_1_main_knob_default.init()
style_screen_brightness_slider_1_main_knob_default.set_radius(50)
style_screen_brightness_slider_1_main_knob_default.set_bg_color(lv.color_make(0xc8,0x23,0xf6))
style_screen_brightness_slider_1_main_knob_default.set_bg_grad_color(lv.color_make(0x23,0xc1,0xf6))
style_screen_brightness_slider_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_brightness_slider_1_main_knob_default.set_bg_opa(255)

# add style for Screen_Brightness_slider_1
Screen_Brightness_slider_1.add_style(style_screen_brightness_slider_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

Screen_Brightness_btn_1 = lv.btn(Screen_Brightness)
Screen_Brightness_btn_1.set_pos(397,280)
Screen_Brightness_btn_1.set_size(80,40)
Screen_Brightness_btn_1_label = lv.label(Screen_Brightness_btn_1)
Screen_Brightness_btn_1_label.set_text("Cancel")
Screen_Brightness_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
Screen_Brightness_btn_1_label.align(lv.ALIGN.CENTER,0,0)
Screen_Brightness_btn_1_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    Screen_Brightness_btn_1_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Screen_Brightness_btn_1_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Screen_Brightness_btn_1_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_screen_brightness_btn_1_main_main_default
style_screen_brightness_btn_1_main_main_default = lv.style_t()
style_screen_brightness_btn_1_main_main_default.init()
style_screen_brightness_btn_1_main_main_default.set_radius(10)
style_screen_brightness_btn_1_main_main_default.set_bg_color(lv.color_make(0x07,0xcf,0x68))
style_screen_brightness_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_screen_brightness_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_brightness_btn_1_main_main_default.set_bg_opa(48)
style_screen_brightness_btn_1_main_main_default.set_shadow_color(lv.color_make(0xff,0x00,0x00))
style_screen_brightness_btn_1_main_main_default.set_shadow_opa(216)
style_screen_brightness_btn_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_screen_brightness_btn_1_main_main_default.set_border_width(0)
style_screen_brightness_btn_1_main_main_default.set_border_opa(255)

# add style for Screen_Brightness_btn_1
Screen_Brightness_btn_1.add_style(style_screen_brightness_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Buzzer = lv.obj()
# create style style_buzzer_main_main_default
style_buzzer_main_main_default = lv.style_t()
style_buzzer_main_main_default.init()
style_buzzer_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_buzzer_main_main_default.set_bg_opa(0)

# add style for Buzzer
Buzzer.add_style(style_buzzer_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Buzzer_cont_1 = lv.obj(Buzzer)
Buzzer_cont_1.set_pos(0,0)
Buzzer_cont_1.set_size(480,320)
# create style style_buzzer_cont_1_main_main_default
style_buzzer_cont_1_main_main_default = lv.style_t()
style_buzzer_cont_1_main_main_default.init()
style_buzzer_cont_1_main_main_default.set_radius(0)
style_buzzer_cont_1_main_main_default.set_bg_color(lv.color_make(0x01,0x04,0x09))
style_buzzer_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x1b,0x29,0x33))
style_buzzer_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_buzzer_cont_1_main_main_default.set_bg_opa(255)
style_buzzer_cont_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_buzzer_cont_1_main_main_default.set_border_width(0)
style_buzzer_cont_1_main_main_default.set_border_opa(255)
style_buzzer_cont_1_main_main_default.set_pad_left(0)
style_buzzer_cont_1_main_main_default.set_pad_right(0)
style_buzzer_cont_1_main_main_default.set_pad_top(0)
style_buzzer_cont_1_main_main_default.set_pad_bottom(0)

# add style for Buzzer_cont_1
Buzzer_cont_1.add_style(style_buzzer_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Buzzer_label_1 = lv.label(Buzzer)
Buzzer_label_1.set_pos(149,20)
Buzzer_label_1.set_size(180,20)
Buzzer_label_1.set_text("Buzzer")
Buzzer_label_1.set_long_mode(lv.label.LONG.WRAP)
Buzzer_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_buzzer_label_1_main_main_default
style_buzzer_label_1_main_main_default = lv.style_t()
style_buzzer_label_1_main_main_default.init()
style_buzzer_label_1_main_main_default.set_radius(10)
style_buzzer_label_1_main_main_default.set_bg_color(lv.color_make(0xd3,0xf6,0x23))
style_buzzer_label_1_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0x23,0x23))
style_buzzer_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_buzzer_label_1_main_main_default.set_bg_opa(0)
style_buzzer_label_1_main_main_default.set_text_color(lv.color_make(0x00,0xf5,0x49))
try:
    style_buzzer_label_1_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_buzzer_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_buzzer_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_buzzer_label_1_main_main_default.set_text_letter_space(1)
style_buzzer_label_1_main_main_default.set_pad_left(0)
style_buzzer_label_1_main_main_default.set_pad_right(0)
style_buzzer_label_1_main_main_default.set_pad_top(0)
style_buzzer_label_1_main_main_default.set_pad_bottom(0)

# add style for Buzzer_label_1
Buzzer_label_1.add_style(style_buzzer_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Buzzer_sw_1 = lv.switch(Buzzer)
Buzzer_sw_1.set_pos(220,145)
Buzzer_sw_1.set_size(40,20)
# create style style_buzzer_sw_1_main_main_default
style_buzzer_sw_1_main_main_default = lv.style_t()
style_buzzer_sw_1_main_main_default.init()
style_buzzer_sw_1_main_main_default.set_radius(100)
style_buzzer_sw_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe2,0xe6))
style_buzzer_sw_1_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe2,0xe6))
style_buzzer_sw_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_buzzer_sw_1_main_main_default.set_bg_opa(255)

# add style for Buzzer_sw_1
Buzzer_sw_1.add_style(style_buzzer_sw_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_buzzer_sw_1_main_indicator_checked
style_buzzer_sw_1_main_indicator_checked = lv.style_t()
style_buzzer_sw_1_main_indicator_checked.init()
style_buzzer_sw_1_main_indicator_checked.set_radius(100)
style_buzzer_sw_1_main_indicator_checked.set_bg_color(lv.color_make(0x23,0xf6,0x89))
style_buzzer_sw_1_main_indicator_checked.set_bg_grad_color(lv.color_make(0x23,0xf6,0x74))
style_buzzer_sw_1_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_buzzer_sw_1_main_indicator_checked.set_bg_opa(255)

# add style for Buzzer_sw_1
Buzzer_sw_1.add_style(style_buzzer_sw_1_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_buzzer_sw_1_main_knob_default
style_buzzer_sw_1_main_knob_default = lv.style_t()
style_buzzer_sw_1_main_knob_default.init()
style_buzzer_sw_1_main_knob_default.set_radius(100)
style_buzzer_sw_1_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_buzzer_sw_1_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_buzzer_sw_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_buzzer_sw_1_main_knob_default.set_bg_opa(255)

# add style for Buzzer_sw_1
Buzzer_sw_1.add_style(style_buzzer_sw_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

Buzzer_btn_1 = lv.btn(Buzzer)
Buzzer_btn_1.set_pos(397,280)
Buzzer_btn_1.set_size(80,40)
Buzzer_btn_1_label = lv.label(Buzzer_btn_1)
Buzzer_btn_1_label.set_text("Cancel")
Buzzer_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
Buzzer_btn_1_label.align(lv.ALIGN.CENTER,0,0)
Buzzer_btn_1_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    Buzzer_btn_1_label.set_style_text_font(lv.font_montserratMedium_18, lv.STATE.DEFAULT)
except AttributeError:
    try:
        Buzzer_btn_1_label.set_style_text_font(lv.font_montserrat_18, lv.STATE.DEFAULT)
    except AttributeError:
        Buzzer_btn_1_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_buzzer_btn_1_main_main_default
style_buzzer_btn_1_main_main_default = lv.style_t()
style_buzzer_btn_1_main_main_default.init()
style_buzzer_btn_1_main_main_default.set_radius(10)
style_buzzer_btn_1_main_main_default.set_bg_color(lv.color_make(0x07,0xcf,0x68))
style_buzzer_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x06,0xf4,0xe4))
style_buzzer_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_buzzer_btn_1_main_main_default.set_bg_opa(48)
style_buzzer_btn_1_main_main_default.set_shadow_color(lv.color_make(0xff,0x00,0x00))
style_buzzer_btn_1_main_main_default.set_shadow_opa(216)
style_buzzer_btn_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_buzzer_btn_1_main_main_default.set_border_width(0)
style_buzzer_btn_1_main_main_default.set_border_opa(255)

# add style for Buzzer_btn_1
Buzzer_btn_1.add_style(style_buzzer_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)



def Screen_Brightness_btn_1_pressed_1_event_cb(e,Menue):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Menue, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Screen_Brightness_btn_1.add_event_cb(lambda e: Screen_Brightness_btn_1_pressed_1_event_cb(e,Menue), lv.EVENT.PRESSED, None)


def Buzzer_btn_1_pressed_1_event_cb(e,Menue):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Menue, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Buzzer_btn_1.add_event_cb(lambda e: Buzzer_btn_1_pressed_1_event_cb(e,Menue), lv.EVENT.PRESSED, None)


def Main_btn_1_pressed_1_event_cb(e,Menue):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Menue, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Main_btn_1.add_event_cb(lambda e: Main_btn_1_pressed_1_event_cb(e,Menue), lv.EVENT.PRESSED, None)


def Menue_btn_1_pressed_1_event_cb(e,CMYK_Revise):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(CMYK_Revise, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Menue_btn_1.add_event_cb(lambda e: Menue_btn_1_pressed_1_event_cb(e,CMYK_Revise), lv.EVENT.PRESSED, None)


def Menue_btn_3_pressed_1_event_cb(e,Calendar):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Calendar, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Menue_btn_3.add_event_cb(lambda e: Menue_btn_3_pressed_1_event_cb(e,Calendar), lv.EVENT.PRESSED, None)


def Timer_btn_1_pressed_1_event_cb(e,Main):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Main, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Timer_btn_1.add_event_cb(lambda e: Timer_btn_1_pressed_1_event_cb(e,Main), lv.EVENT.PRESSED, None)



def Menue_btn_2_pressed_1_event_cb(e,Timer):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Timer, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Menue_btn_2.add_event_cb(lambda e: Menue_btn_2_pressed_1_event_cb(e,Timer), lv.EVENT.PRESSED, None)


def Timer_btn_2_pressed_1_event_cb(e,Menue):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Menue, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Timer_btn_2.add_event_cb(lambda e: Timer_btn_2_pressed_1_event_cb(e,Menue), lv.EVENT.PRESSED, None)


def Menue_btn_5_pressed_1_event_cb(e,Buzzer):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Buzzer, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Menue_btn_5.add_event_cb(lambda e: Menue_btn_5_pressed_1_event_cb(e,Buzzer), lv.EVENT.PRESSED, None)


def Menue_btn_4_pressed_1_event_cb(e,Screen_Brightness):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Screen_Brightness, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Menue_btn_4.add_event_cb(lambda e: Menue_btn_4_pressed_1_event_cb(e,Screen_Brightness), lv.EVENT.PRESSED, None)


def Menue_btn_7_pressed_1_event_cb(e,Main):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Main, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Menue_btn_7.add_event_cb(lambda e: Menue_btn_7_pressed_1_event_cb(e,Main), lv.EVENT.PRESSED, None)


def Calendar_btn_1_pressed_1_event_cb(e,Menue):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Menue, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Calendar_btn_1.add_event_cb(lambda e: Calendar_btn_1_pressed_1_event_cb(e,Menue), lv.EVENT.PRESSED, None)


def Menue_btn_6_pressed_1_event_cb(e,Main):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Main, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
Menue_btn_6.add_event_cb(lambda e: Menue_btn_6_pressed_1_event_cb(e,Main), lv.EVENT.PRESSED, None)



def CMYK_Revise_btn_2_pressed_1_event_cb(e,Menue):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Menue, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
CMYK_Revise_btn_2.add_event_cb(lambda e: CMYK_Revise_btn_2_pressed_1_event_cb(e,Menue), lv.EVENT.PRESSED, None)


def CMYK_Revise_btn_1_pressed_1_event_cb(e,Main):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Main, lv.SCR_LOAD_ANIM.NONE, 1000, 1000, False)
CMYK_Revise_btn_1.add_event_cb(lambda e: CMYK_Revise_btn_1_pressed_1_event_cb(e,Main), lv.EVENT.PRESSED, None)




# content from custom.py

# Load the default screen
lv.scr_load(Main)

while SDL.check():
    time.sleep_ms(5)
