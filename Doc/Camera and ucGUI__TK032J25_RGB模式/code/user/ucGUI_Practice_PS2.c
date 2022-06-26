#include <stddef.h>
#include "GUI.h"
#include "DIALOG.h"
#include "ucGUI_Practice.h"



/*********************************************************************
*
*       static data, dialog resource
*
**********************************************************************
*/
#define GUI_ID_Dialog_All                 GUI_ID_USER+0
#define GUI_ID_DIALOG_SliderColor         GUI_ID_USER+1
#define GUI_ID_WM_LateClipping            GUI_ID_USER+2
#define GUI_ID_DIALOG_NestedModal         GUI_ID_USER+3
#define GUI_ID_WIDGET_Effect              GUI_ID_USER+4
#define GUI_ID_WIDGET_NumPad              GUI_ID_USER+5
#define GUI_ID_WIDGET_Multipage           GUI_ID_USER+6
#define GUI_ID_WIDGET_ButtonRound         GUI_ID_USER+7
/*********************************************************************
*
*       Dialog resource
*
* This table conatins the info required to create the dialog.
* It has been created manually, but could also be created by a GUI-builder.
*/
						
void creat_PS2_desktop(void);
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ FRAMEWIN_CreateIndirect, "Tiky ucGUI Practice", 0,         5,  30, 300, 220, FRAMEWIN_CF_MOVEABLE},
//   { TEXT_CreateIndirect,     "Red:" ,  0,                5,  20,  35,  20, TEXT_CF_LEFT },
//   { TEXT_CreateIndirect,     "Green:", 0,                5,  50,  35,  20, TEXT_CF_LEFT },
//   { TEXT_CreateIndirect,     "Blue:",  0,                5,  80,  35,  20, TEXT_CF_LEFT },

	{ BUTTON_CreateIndirect,   "Dialog_All",         GUI_ID_Dialog_All,           10,   5,  144,  20 },
  { BUTTON_CreateIndirect,   "DIALOG_SliderColor", GUI_ID_DIALOG_SliderColor,   10,  30,  144,  20 },
	{ BUTTON_CreateIndirect,   "WM_LateClipping",    GUI_ID_WM_LateClipping,      10,  55,  144,  20 },
  { BUTTON_CreateIndirect,   "DIALOG_NestedModal", GUI_ID_DIALOG_NestedModal,   10,  80,  144,  20 },
	{ BUTTON_CreateIndirect,   "WIDGET_Effect",      GUI_ID_WIDGET_Effect,        10, 105,  144,  20 },
  { BUTTON_CreateIndirect,   "WIDGET_NumPad",      GUI_ID_WIDGET_NumPad,        10, 130,  144,  20 },
	{ BUTTON_CreateIndirect,   "WIDGET_Multipage",   GUI_ID_WIDGET_Multipage,     10, 155,  144,  20 },
  { BUTTON_CreateIndirect,   "WIDGET_ButtonRound", GUI_ID_WIDGET_ButtonRound,   10, 180,  144,  20 },

  { BUTTON_CreateIndirect,   "OK",     GUI_ID_OK,      230, 155,  60,  20 },
  { BUTTON_CreateIndirect,   "Cancel", GUI_ID_CANCEL,  230, 180,  60,  20 },
};

/*********************************************************************
*
*       _cbBkWindow
*/
static void _cbBkWindow(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  case WM_PAINT:
    GUI_SetBkColor(GUI_BLUE);
    GUI_Clear();
    GUI_SetColor(GUI_WHITE);
    GUI_SetFont(&GUI_Font24_ASCII);
    GUI_DispStringHCenterAt("DIALOG_SliderColor - Sample", 160, 5);
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbCallback
*/
static void _cbCallback(WM_MESSAGE * pMsg) {
  int i;
  int NCode, Id;
  WM_HWIN hDlg, hItem;
  hDlg = pMsg->hWin;
  switch (pMsg->MsgId) {
    case WM_KEY:
      switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) {
        case GUI_KEY_ESCAPE:
          ;
          break;
        case GUI_KEY_ENTER:
          GUI_EndDialog(hDlg, 0);
          break;
      }
      break;
    case WM_NOTIFY_PARENT:
      Id    = WM_GetId(pMsg->hWinSrc);      /* Id of widget */
      NCode = pMsg->Data.v;                 /* Notification code */
      switch (NCode) {
        case WM_NOTIFICATION_RELEASED:      /* React only if released */
          if (Id == GUI_ID_OK) {            /* OK Button */
            GUI_EndDialog(hDlg, 0);
          }
          if (Id == GUI_ID_CANCEL) {        /* Cancel Button */
            GUI_EndDialog(hDlg, 1);
          }
					if (Id == GUI_ID_Dialog_All) {        /* MainTask_Dialog_All */
						GUI_EndDialog(hDlg, 1);
            MainTask_Dialog_All();
						creat_PS2_desktop();
          }
					if (Id == GUI_ID_DIALOG_SliderColor) {        /* DIALOG_SliderColor */
						GUI_EndDialog(hDlg, 1);
            DIALOG_SliderColor();
						creat_PS2_desktop();
          }
					if (Id == GUI_ID_WM_LateClipping) {        /* WM_LateClipping */
						GUI_EndDialog(hDlg, 1);
            WM_LateClipping();
						creat_PS2_desktop();
          }
					if (Id == GUI_ID_DIALOG_NestedModal) {        /* DIALOG_NestedModal */
						GUI_EndDialog(hDlg, 1);
            DIALOG_NestedModal();
						creat_PS2_desktop();
          }
					if (Id == GUI_ID_WIDGET_Effect) {        /* MainTask_WIDGET_Effect */
						GUI_EndDialog(hDlg, 1);
            MainTask_WIDGET_Effect();
						creat_PS2_desktop();
          }
					if (Id == GUI_ID_WIDGET_NumPad) {        /* MainTask_WIDGET_NumPad */
						GUI_EndDialog(hDlg, 1);
            MainTask_WIDGET_NumPad();
						creat_PS2_desktop();
          }
					if (Id == GUI_ID_WIDGET_Multipage) {        /* MainTask_WIDGET_Multipage */
						GUI_EndDialog(hDlg, 1);
            MainTask_WIDGET_Multipage();
						creat_PS2_desktop();
          }
					if (Id == GUI_ID_WIDGET_ButtonRound) {        /* MainTask_WIDGET_ButtonRound */
						GUI_EndDialog(hDlg, 1);
            MainTask_WIDGET_ButtonRound();
						creat_PS2_desktop();
          }
          break;

      }
      break;
    default:
      WM_DefaultProc(pMsg);
  }
}
void creat_PS2_desktop(void)
{
	WM_SetCallback(WM_HBKWIN, _cbBkWindow);  
  WM_SetCreateFlags(WM_CF_MEMDEV);  /* Use memory devices on all windows to avoid flicker */
	GUI_ExecDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), &_cbCallback, 0, 0, 0);
}

/*********************************************************************
*
*       MainTask
*
*       Demonstrates a dialog box
*
**********************************************************************
*/

void ucGUI_Practice_PS2(void) {
  GUI_Init();
  GUI_CURSOR_Show();
	creat_PS2_desktop();
  
}
