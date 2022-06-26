#include "lv_examples.h"
#if LV_BUILD_EXAMPLES && LV_USE_SWITCH

extern lv_indev_t *indev_encoder;

static void anim_x_cb(void *var, int32_t v)
{
    lv_obj_set_x(var, v);
}

static void sw_event_cb(lv_event_t *e)
{
    lv_obj_t *sw = lv_event_get_target(e);
    lv_obj_t *label = lv_event_get_user_data(e);

    if (lv_obj_has_state(sw, LV_STATE_CHECKED))
    {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, label);
        lv_anim_set_values(&a, lv_obj_get_x(label), 100);
        lv_anim_set_time(&a, 500);
        lv_anim_set_exec_cb(&a, anim_x_cb);
        lv_anim_set_path_cb(&a, lv_anim_path_overshoot);
        lv_anim_start(&a);
    }
    else
    {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, label);
        lv_anim_set_values(&a, lv_obj_get_x(label), -lv_obj_get_width(label));
        lv_anim_set_time(&a, 500);
        lv_anim_set_exec_cb(&a, anim_x_cb);
        lv_anim_set_path_cb(&a, lv_anim_path_ease_in);
        lv_anim_start(&a);
    }
}

/**
 * Start animation on an event
 */
// void lv_example_anim_1(void)
// {
//     // lv_obj_t *label = lv_label_create(lv_scr_act());
//     // lv_label_set_text(label, "Hello animations!");
//     // lv_obj_set_pos(label, 100, 10);

//     // lv_obj_t *sw = lv_switch_create(lv_scr_act());
//     // lv_obj_center(sw);
//     // lv_obj_add_state(sw, LV_STATE_CHECKED);
//     // lv_obj_add_event_cb(sw, sw_event_cb, LV_EVENT_VALUE_CHANGED, label);

//     // lv_group_t *group = lv_group_create();
//     // lv_indev_set_group(indev_encoder, group);
//     // // lv_group_set_default(group);
//     // // lv_group_remove_all_objs(group);
//     // // /*Switch controls are added to the group*/
//     // lv_group_add_obj(group, sw);
//     // // lv_group_set_editing(group, false); //导航模式

//     lv_group_t *test_group = lv_group_create();
//     lv_group_set_default(test_group);
//     lv_indev_set_group(indev_encoder, test_group);
//     // lv_group_focus_obj(test_group);         //分组聚焦到对象
//     lv_group_set_editing(test_group, true); //编辑模式
//     static const char *test_btns[] = {"Ok", "Cancel", ""};
//     lv_obj_t *test_mbox = lv_msgbox_create(lv_layer_top(), "WX17777697205", "Welcome to the  encoder demo", test_btns, true);

//     lv_obj_align(test_mbox, LV_ALIGN_CENTER, 0, 0);
//     lv_group_focus_obj(lv_msgbox_get_btns(test_mbox));
//     lv_obj_add_state(lv_msgbox_get_btns(test_mbox), LV_STATE_FOCUS_KEY | LV_STATE_PRESSED);

//     lv_obj_t *bg = lv_obj_get_parent(test_mbox);
//     lv_obj_set_style_bg_opa(bg, LV_OPA_70, 0);
//     lv_obj_set_style_bg_color(bg, lv_palette_main(LV_PALETTE_GREY), 0);
// }

static void btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    static uint8_t cnt = 0;
    if (code == LV_EVENT_CLICKED)
    {
        cnt++;
        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t *label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
    if (code == LV_EVENT_FOCUSED)
    {
        cnt--;
        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t *label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}
/**
 * Create a button with a label and react on click event.
 */
// void lv_example_get_started_1(void)
void lv_example_anim_1(void)
{
    lv_obj_t *btn = lv_btn_create(lv_scr_act());                /*Add a button the current␣ , →screen*/
    lv_obj_set_pos(btn, 10, 10);                                /*Set its position*/
    lv_obj_set_size(btn, 120, 50);                              /*Set its size*/
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL); /*Assign a␣ , →callback to the button*/
    lv_obj_t *label = lv_label_create(btn);                     /*Add a label to the button*/
    lv_label_set_text(label, "Button");                         /*Set the labels text*/
    lv_obj_center(label);

    lv_obj_t *btn1 = lv_btn_create(lv_scr_act());                /*Add a button the current␣ , →screen*/
    lv_obj_set_pos(btn1, 40, 40);                                /*Set its position*/
    lv_obj_set_size(btn1, 120, 50);                              /*Set its size*/
    lv_obj_add_event_cb(btn1, btn_event_cb, LV_EVENT_ALL, NULL); /*Assign a␣ , →callback to the button*/
    lv_obj_t *label1 = lv_label_create(btn1);                    /*Add a label to the button*/
    lv_label_set_text(label1, "Button1");                        /*Set the labels text*/
    lv_obj_center(label1);

    lv_group_t *group = lv_group_create();
    lv_indev_set_group(indev_encoder, group);
    // lv_group_set_default(group);
    // lv_group_remove_all_objs(group);
    // /*Switch controls are added to the group*/
    lv_group_add_obj(group, btn);
    lv_group_add_obj(group, btn1);
}

#endif
