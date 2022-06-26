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


screen = lv.obj()
# create style style_screen_main_main_default
style_screen_main_main_default = lv.style_t()
style_screen_main_main_default.init()
style_screen_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_main_main_default.set_bg_opa(0)

# add style for screen
screen.add_style(style_screen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_ddlist1 = lv.dropdown(screen)
screen_ddlist1.set_pos(260,35)
screen_ddlist1.set_width(130)
screen_ddlist1.set_options("list1\nlist2\nlist3")
# create style style_screen_ddlist1_extra_list_selected_default
style_screen_ddlist1_extra_list_selected_default = lv.style_t()
style_screen_ddlist1_extra_list_selected_default.init()
style_screen_ddlist1_extra_list_selected_default.set_radius(3)
style_screen_ddlist1_extra_list_selected_default.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_screen_ddlist1_extra_list_selected_default.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_screen_ddlist1_extra_list_selected_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_ddlist1_extra_list_selected_default.set_bg_opa(255)
style_screen_ddlist1_extra_list_selected_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_screen_ddlist1_extra_list_selected_default.set_border_width(1)
style_screen_ddlist1_extra_list_selected_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen_ddlist1_extra_list_selected_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_screen_ddlist1_extra_list_selected_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_ddlist1_extra_list_selected_default.set_text_font(lv.font_montserrat_16)

def screen_ddlist1_event_cb(e):
    screen_ddlist1.get_list().add_style(style_screen_ddlist1_extra_list_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

screen_ddlist1.add_event_cb(screen_ddlist1_event_cb, lv.EVENT.READY, None)

# create style style_screen_ddlist1_extra_list_main_default
style_screen_ddlist1_extra_list_main_default = lv.style_t()
style_screen_ddlist1_extra_list_main_default.init()
style_screen_ddlist1_extra_list_main_default.set_radius(3)
style_screen_ddlist1_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_ddlist1_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_ddlist1_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_ddlist1_extra_list_main_default.set_bg_opa(255)
style_screen_ddlist1_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_screen_ddlist1_extra_list_main_default.set_border_width(1)
style_screen_ddlist1_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_screen_ddlist1_extra_list_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_screen_ddlist1_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_ddlist1_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_screen_ddlist1_extra_list_main_default.set_max_height(90)

def screen_ddlist1_event_cb(e):
    screen_ddlist1.get_list().add_style(style_screen_ddlist1_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_ddlist1.add_event_cb(screen_ddlist1_event_cb, lv.EVENT.READY, None)

# create style style_screen_ddlist1_extra_list_scrollbar_default
style_screen_ddlist1_extra_list_scrollbar_default = lv.style_t()
style_screen_ddlist1_extra_list_scrollbar_default.init()
style_screen_ddlist1_extra_list_scrollbar_default.set_radius(3)
style_screen_ddlist1_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_screen_ddlist1_extra_list_scrollbar_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_ddlist1_extra_list_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_ddlist1_extra_list_scrollbar_default.set_bg_opa(255)

def screen_ddlist1_event_cb(e):
    screen_ddlist1.get_list().add_style(style_screen_ddlist1_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

screen_ddlist1.add_event_cb(screen_ddlist1_event_cb, lv.EVENT.READY, None)

# create style style_screen_ddlist1_main_main_default
style_screen_ddlist1_main_main_default = lv.style_t()
style_screen_ddlist1_main_main_default.init()
style_screen_ddlist1_main_main_default.set_radius(3)
style_screen_ddlist1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_ddlist1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_ddlist1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_ddlist1_main_main_default.set_bg_opa(255)
style_screen_ddlist1_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_screen_ddlist1_main_main_default.set_border_width(1)
style_screen_ddlist1_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_screen_ddlist1_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_screen_ddlist1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_ddlist1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_ddlist1_main_main_default.set_text_line_space(20)

# add style for screen_ddlist1
screen_ddlist1.add_style(style_screen_ddlist1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_roller1 = lv.roller(screen)
screen_roller1.set_pos(90,35)
screen_roller1.set_options("1\n2\n3\n4\n5", lv.roller.MODE.INFINITE)
screen_roller1.set_visible_row_count(5)
try:
	screen_roller1.set_style_text_font(lv.font_arial_12, lv.PART.MAIN|lv.STATE.DEFAULT)
	screen_roller1.set_style_text_font(lv.font_arial_12, lv.PART.MAIN|lv.STATE.FOCUSED)
	screen_roller1.set_style_text_font(lv.font_arial_12, lv.PART.SELECTED|lv.STATE.DEFAULT)
except AttributeError:
	try:
		screen_roller1.set_style_text_font(lv.font_montserrat_12, lv.PART.MAIN|lv.STATE.DEFAULT)
		screen_roller1.set_style_text_font(lv.font_montserrat_12, lv.PART.MAIN|lv.STATE.FOCUSED)
		screen_roller1.set_style_text_font(lv.font_montserrat_12, lv.PART.SELECTED|lv.STATE.DEFAULT)
	except AttributeError:
		screen_roller1.set_style_text_font(lv.font_montserrat_16, lv.PART.MAIN|lv.STATE.DEFAULT)
		screen_roller1.set_style_text_font(lv.font_montserrat_16, lv.PART.MAIN|lv.STATE.FOCUSED)
		screen_roller1.set_style_text_font(lv.font_montserrat_16, lv.PART.SELECTED|lv.STATE.DEFAULT)
# create style style_screen_roller1_main_main_default
style_screen_roller1_main_main_default = lv.style_t()
style_screen_roller1_main_main_default.init()
style_screen_roller1_main_main_default.set_radius(5)
style_screen_roller1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_roller1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_roller1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_roller1_main_main_default.set_bg_opa(255)
style_screen_roller1_main_main_default.set_border_color(lv.color_make(0xdf,0xe7,0xed))
style_screen_roller1_main_main_default.set_border_width(1)
style_screen_roller1_main_main_default.set_text_color(lv.color_make(0x33,0x33,0x33))

# add style for screen_roller1
screen_roller1.add_style(style_screen_roller1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_roller1_main_selected_default
style_screen_roller1_main_selected_default = lv.style_t()
style_screen_roller1_main_selected_default.init()
style_screen_roller1_main_selected_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_roller1_main_selected_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_roller1_main_selected_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_roller1_main_selected_default.set_bg_opa(255)
style_screen_roller1_main_selected_default.set_text_color(lv.color_make(0xFF,0xFF,0xFF))

# add style for screen_roller1
screen_roller1.add_style(style_screen_roller1_main_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

screen_sw2 = lv.switch(screen)
screen_sw2.set_pos(195,238)
screen_sw2.set_size(40,23)
# create style style_screen_sw2_main_main_default
style_screen_sw2_main_main_default = lv.style_t()
style_screen_sw2_main_main_default.init()
style_screen_sw2_main_main_default.set_radius(100)
style_screen_sw2_main_main_default.set_bg_color(lv.color_make(0xd4,0xd7,0xd9))
style_screen_sw2_main_main_default.set_bg_grad_color(lv.color_make(0xd4,0xd7,0xd9))
style_screen_sw2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_sw2_main_main_default.set_bg_opa(255)

# add style for screen_sw2
screen_sw2.add_style(style_screen_sw2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_sw2_main_indicator_checked
style_screen_sw2_main_indicator_checked = lv.style_t()
style_screen_sw2_main_indicator_checked.init()
style_screen_sw2_main_indicator_checked.set_radius(100)
style_screen_sw2_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_sw2_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_sw2_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_sw2_main_indicator_checked.set_bg_opa(255)

# add style for screen_sw2
screen_sw2.add_style(style_screen_sw2_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_screen_sw2_main_knob_default
style_screen_sw2_main_knob_default = lv.style_t()
style_screen_sw2_main_knob_default.init()
style_screen_sw2_main_knob_default.set_radius(100)
style_screen_sw2_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_sw2_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_sw2_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_sw2_main_knob_default.set_bg_opa(255)

# add style for screen_sw2
screen_sw2.add_style(style_screen_sw2_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

screen_label3 = lv.label(screen)
screen_label3.set_pos(65,241)
screen_label3.set_size(100,23)
screen_label3.set_text("roller")
screen_label3.set_long_mode(lv.label.LONG.WRAP)
screen_label3.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_label3_main_main_default
style_screen_label3_main_main_default = lv.style_t()
style_screen_label3_main_main_default.init()
style_screen_label3_main_main_default.set_radius(0)
style_screen_label3_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_label3_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_label3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label3_main_main_default.set_bg_opa(0)
style_screen_label3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_label3_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_screen_label3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_label3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label3_main_main_default.set_text_letter_space(2)
style_screen_label3_main_main_default.set_pad_left(0)
style_screen_label3_main_main_default.set_pad_right(0)
style_screen_label3_main_main_default.set_pad_top(0)
style_screen_label3_main_main_default.set_pad_bottom(0)

# add style for screen_label3
screen_label3.add_style(style_screen_label3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_label4 = lv.label(screen)
screen_label4.set_pos(261,241)
screen_label4.set_size(100,23)
screen_label4.set_text("select")
screen_label4.set_long_mode(lv.label.LONG.WRAP)
screen_label4.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_screen_label4_main_main_default
style_screen_label4_main_main_default = lv.style_t()
style_screen_label4_main_main_default.init()
style_screen_label4_main_main_default.set_radius(0)
style_screen_label4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_screen_label4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_screen_label4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_screen_label4_main_main_default.set_bg_opa(0)
style_screen_label4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_label4_main_main_default.set_text_font(lv.font_arial_12)
except AttributeError:
    try:
        style_screen_label4_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_label4_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label4_main_main_default.set_text_letter_space(2)
style_screen_label4_main_main_default.set_pad_left(0)
style_screen_label4_main_main_default.set_pad_right(0)
style_screen_label4_main_main_default.set_pad_top(0)
style_screen_label4_main_main_default.set_pad_bottom(0)

# add style for screen_label4
screen_label4.add_style(style_screen_label4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)



def screen_sw2_value_changed_2_event_cb(e):
    src = e.get_target()
    code = e.get_code()
    if code == lv.EVENT.VALUE_CHANGED:
        if screen_sw2.has_state(lv.STATE.CHECKED):
            screen_roller1.add_flag(lv.obj.FLAG.HIDDEN)
            screen_ddlist1.clear_flag(lv.obj.FLAG.HIDDEN)
        else:
            screen_ddlist1.add_flag(lv.obj.FLAG.HIDDEN)
            screen_roller1.clear_flag(lv.obj.FLAG.HIDDEN)

screen_sw2.add_event_cb(lambda e: screen_sw2_value_changed_2_event_cb(e), lv.EVENT.VALUE_CHANGED, None)



# content from custom.py

# Load the default screen
lv.scr_load(screen)

while SDL.check():
    time.sleep_ms(5)
