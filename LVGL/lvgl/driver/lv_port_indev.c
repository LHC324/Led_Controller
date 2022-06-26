/**
 * @file lv_port_indev.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"
#include "lvgl.h"
#include "Ec11.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void encoder_init(void);
static void encoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
// static void encoder_handler(void);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t *indev_encoder[DEVICES_MAX];

// static int32_t encoder_diff;
// static lv_indev_state_t encoder_state;
// static uint32_t encoder_key;

typedef struct
{
	int32_t diff;
	lv_indev_state_t state;
	uint32_t key;
} Encode_HandleTypeDef;

Encode_HandleTypeDef Encode_Group[DEVICES_MAX];
lv_indev_drv_t g_indev_drv[DEVICES_MAX];

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
	/**
	 * Here you will find example implementation of input devices supported by LittelvGL:
	 *  - Touchpad
	 *  - Mouse (with cursor support)
	 *  - Keypad (supports GUI usage only with key)
	 *  - Encoder (supports GUI usage only with: left, right, push)
	 *  - Button (external buttons to press points on the screen)
	 *
	 *  The `..._read()` function are only examples.
	 *  You should shape them according to your hardware
	 */

	// static lv_indev_drv_t indev_drv[DEVICES_MAX];

	/*------------------
	 * Encoder
	 * -----------------*/

	/*Initialize your encoder if you have*/
	encoder_init();

	/*Register a encoder input device*/
	for (lv_indev_drv_t *p_drv = g_indev_drv; p_drv < g_indev_drv + DEVICES_MAX; p_drv++)
	{
		lv_indev_drv_init(p_drv);
		p_drv->type = LV_INDEV_TYPE_ENCODER;
		p_drv->read_cb = encoder_read;
		indev_encoder[p_drv - g_indev_drv] = lv_indev_drv_register(p_drv);
	}
	// lv_indev_drv_init(&indev_drv[0]);
	// indev_drv[0].type = LV_INDEV_TYPE_ENCODER;
	// indev_drv[0].read_cb = encoder_read;
	// indev_encoder[0] = lv_indev_drv_register(&indev_drv[0]);

	/*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
	 *add objects to the group with `lv_group_add_obj(group, obj)`
	 *and assign this input device to group to navigate in it:
	 *`lv_indev_set_group(indev_encoder, group);`*/
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
/*------------------
 * Encoder
 * -----------------*/

/*Initialize your keypad*/
static void encoder_init(void)
{
	/*Your code comes here*/
}

/*Will be called by the library to read the encoder*/
static void encoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
	uint8_t site = indev_drv - g_indev_drv;
	if (indev_drv && (site < DEVICES_MAX))
	{

		// Ec1x_Type type = Check_Ec1x_Press(site);

		// data->enc_diff = encoder_diff;
		// data->state = encoder_state;
		// data->key = encoder_key;
		// /*clear encoder value*/
		// encoder_diff = None;
		// // encoder_key = LV_KEY_UP;
		// // encoder_state = LV_INDEV_STATE_REL;

		data->enc_diff = Encode_Group[site].diff;
		data->state = Encode_Group[site].state;
		data->key = Encode_Group[site].key;
		/*clear encoder value*/
		// encoder_diff = None;
		Encode_Group[site].diff = None;
		Encode_Group[site].state = LV_INDEV_STATE_REL;
		Encode_Group[site].key = LV_KEY_UP;
		// if ((type.Id != 0xFF) && (type.Option != None))
		// {
		// 	Encode_Group[site].key = LV_KEY_ENTER;
		// 	Encode_Group[site].state = LV_INDEV_STATE_PR;
		// }
		// else
		// {
		// 	Encode_Group[site].key = LV_KEY_UP;
		// 	Encode_Group[site].state = LV_INDEV_STATE_REL;
		// 	// HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
		// }
	}
}

/*Call this function in an interrupt to process encoder events (turn, press)*/
// static void encoder_handler(void)
// {
// 	/*Your code comes here*/

// 	encoder_diff += 0;
// 	encoder_state = LV_INDEV_STATE_REL;
// 	encoder_state = LV_KEY_LEFT;
// }

#include "Ec11.h"
void encoder_handler(Ec1x_Type *ptype)
{
	// if (ptype && (ptype->Id == 1U))
	if (ptype)
	{
		if ((ptype->Id != 0xFF) && (ptype->Option != None))
		{
			switch (ptype->Option)
			{
			case Forward:
			{
				Encode_Group[ptype->Id].diff = (Forward - 1U);
				Encode_Group[ptype->Id].key = LV_KEY_RIGHT;
				Encode_Group[ptype->Id].state = LV_INDEV_STATE_REL;
			}
			break;
			case Reverse:
			{
				Encode_Group[ptype->Id].diff = Reverse;
				Encode_Group[ptype->Id].key = LV_KEY_LEFT;
				Encode_Group[ptype->Id].state = LV_INDEV_STATE_REL;
			}
			break;
			case Down:
			{
				Encode_Group[ptype->Id].diff = None;
				Encode_Group[ptype->Id].key = LV_KEY_ENTER;
				Encode_Group[ptype->Id].state = LV_INDEV_STATE_PR;
			}
			break;
			// case Up:
			// {
			// 	Encode_Group[ptype->Id].diff = None;
			// 	Encode_Group[ptype->Id].key = LV_KEY_UP;
			// 	Encode_Group[ptype->Id].state = LV_INDEV_STATE_REL;
			// }
			// break;
			case DownAndForward:
			{
				// encoder_diff = DownAndForward;
				// encoder_diff = DownAndForward;
				// encoder_key = LV_KEY_ESC;
				// encoder_state = LV_INDEV_STATE_REL;

				Encode_Group[ptype->Id].diff = None;
				Encode_Group[ptype->Id].key = LV_KEY_HOME;
				Encode_Group[ptype->Id].state = LV_INDEV_STATE_PR;
			}
			break;
			case DownAndReverse:
			{
				Encode_Group[ptype->Id].diff = None;
				Encode_Group[ptype->Id].key = LV_KEY_ESC;
				Encode_Group[ptype->Id].state = LV_INDEV_STATE_PR;
			}
			break;
			default:
				break;
			}
#if defined(USING_DEBUG)
			extern void Debug(const char *format, ...);
			Debug("id = %d, type = %d\r\n", ptype->Id, ptype->Option);
			// Debug("id = %d, type = %d\r\n", type.Id, value / 20);
#endif
		}
		else
		{
			// 	encoder_diff = None;
			// 	encoder_key = LV_KEY_UP;
			// 	encoder_state = LV_INDEV_STATE_REL;
			// if (!HAL_GPIO_ReadPin(EC11_KEY1_GPIO_Port, EC11_KEY1_Pin))
			// {
			// 	encoder_key = LV_KEY_ENTER;
			// 	encoder_state = LV_INDEV_STATE_PR;
			// }
			// else
			// {
			// 	encoder_state = LV_INDEV_STATE_REL;
			// }
			// if (HAL_GPIO_ReadPin(EC11_KEY1_GPIO_Port, EC11_KEY1_Pin))
			// {
			// 	encoder_key = LV_KEY_UP;
			// 	encoder_state = LV_INDEV_STATE_PR;
			// }
		}
	}
}
#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
