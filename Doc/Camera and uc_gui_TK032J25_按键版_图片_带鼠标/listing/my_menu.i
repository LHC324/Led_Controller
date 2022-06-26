#line 1 "..\\code\\menu\\my_menu.c"








 
#line 1 "..\\code\\menu\\my_menu.h"









 



void List_name(unsigned int cnt);
void main_menu(char* id,char menu);
void scan_menu(char* id);
void Set_Time_Date(void);


 
#line 11 "..\\code\\menu\\my_menu.c"
#line 1 "..\\code\\GUI\\GUI_inc\\gui.h"





















 






#line 1 "..\\code\\GUI\\GUI_inc\\GUI_ConfDefaults.h"





















 




#line 1 "..\\code\\GUI\\Config\\GUIConf.h"

















 








#line 34 "..\\code\\GUI\\Config\\GUIConf.h"




 









#line 28 "..\\code\\GUI\\GUI_inc\\GUI_ConfDefaults.h"






 




 
#line 46 "..\\code\\GUI\\GUI_inc\\GUI_ConfDefaults.h"




 




























#line 86 "..\\code\\GUI\\GUI_inc\\GUI_ConfDefaults.h"













#line 106 "..\\code\\GUI\\GUI_inc\\GUI_ConfDefaults.h"


 
#line 116 "..\\code\\GUI\\GUI_inc\\GUI_ConfDefaults.h"

#line 124 "..\\code\\GUI\\GUI_inc\\GUI_ConfDefaults.h"

 
#line 133 "..\\code\\GUI\\GUI_inc\\GUI_ConfDefaults.h"

 





 
#line 148 "..\\code\\GUI\\GUI_inc\\GUI_ConfDefaults.h"







 
#line 30 "..\\code\\GUI\\GUI_inc\\gui.h"
#line 1 "..\\code\\GUI\\GUI_inc\\GUIType.h"





















 




#line 1 "..\\code\\GUI\\GUI_inc\\LCD.h"

















 




#line 24 "..\\code\\GUI\\GUI_inc\\LCD.h"


















 
 
#line 52 "..\\code\\GUI\\GUI_inc\\LCD.h"













 












 










 







 





 

typedef int LCD_DRAWMODE;
typedef unsigned long LCD_COLOR;

 





 

typedef struct { signed short x,y; } GUI_POINT;
typedef struct { signed short x0,y0,x1,y1; } LCD_RECT;
 

typedef struct {
  int              NumEntries; 
  char             HasTrans;         
  const LCD_COLOR  * pPalEntries; 
} LCD_LOGPALETTE; 

 
typedef struct {
  int x,y;
  unsigned char KeyStat;
} LCD_tMouseState;








 

typedef LCD_COLOR      tLCDDEV_Index2Color  (int Index);
typedef unsigned int   tLCDDEV_Color2Index  (LCD_COLOR Color);
typedef unsigned int   tLCDDEV_GetIndexMask (void);
LCD_COLOR      LCD_L0_Index2Color  (int Index);
LCD_COLOR      LCD_L0_1_Index2Color(int Index);
LCD_COLOR      LCD_L0_2_Index2Color(int Index);
LCD_COLOR      LCD_L0_3_Index2Color(int Index);
LCD_COLOR      LCD_L0_4_Index2Color(int Index);
unsigned int   LCD_L0_Color2Index  (LCD_COLOR Color);
unsigned int   LCD_L0_1_Color2Index(LCD_COLOR Color);
unsigned int   LCD_L0_2_Color2Index(LCD_COLOR Color);
unsigned int   LCD_L0_3_Color2Index(LCD_COLOR Color);
unsigned int   LCD_L0_4_Color2Index(LCD_COLOR Color);
unsigned int   LCD_L0_GetIndexMask  (void);
unsigned int   LCD_L0_1_GetIndexMask(void);
unsigned int   LCD_L0_2_GetIndexMask(void);
unsigned int   LCD_L0_3_GetIndexMask(void);
unsigned int   LCD_L0_4_GetIndexMask(void);





 

typedef struct {
  tLCDDEV_Color2Index*  pfColor2Index;
  tLCDDEV_Index2Color*  pfIndex2Color;
  tLCDDEV_GetIndexMask* pfGetIndexMask;
} LCD_API_COLOR_CONV;

extern const LCD_API_COLOR_CONV LCD_API_ColorConv_1;
extern const LCD_API_COLOR_CONV LCD_API_ColorConv_2;
extern const LCD_API_COLOR_CONV LCD_API_ColorConv_4;
extern const LCD_API_COLOR_CONV LCD_API_ColorConv_8666;



















 
typedef void         tLCDDEV_DrawHLine    (int x0, int y0,  int x1);
typedef void         tLCDDEV_DrawVLine    (int x , int y0,  int y1);
typedef void         tLCDDEV_FillRect     (int x0, int y0, int x1, int y1);
typedef unsigned int tLCDDEV_GetPixelIndex(int x, int y);
typedef void         tLCDDEV_SetPixelIndex(int x, int y, int ColorIndex);
typedef void         tLCDDEV_XorPixel     (int x, int y);
typedef void         tLCDDEV_FillPolygon  (const GUI_POINT* pPoints, int NumPoints, int x0, int y0);
typedef void         tLCDDEV_FillPolygonAA(const GUI_POINT* pPoints, int NumPoints, int x0, int y0);
typedef void         tLCDDEV_GetRect      (LCD_RECT*pRect);
typedef int          tLCDDEV_Init         (void);
typedef void         tLCDDEV_On           (void);
typedef void         tLCDDEV_Off          (void);
typedef void         tLCDDEV_SetLUTEntry  (unsigned char Pos, LCD_COLOR color);




 

  typedef struct tLCDDEV_APIList_struct tLCDDEV_APIList;


typedef void tLCDDEV_DrawBitmap   (int x0, int y0, int xsize, int ysize,
                       int BitsPerPixel, int BytesPerLine,
                       const unsigned char  * pData, int Diff,
                       const void* pTrans);    

struct tLCDDEV_APIList_struct {
  tLCDDEV_Color2Index*        pfColor2Index;
  tLCDDEV_Index2Color*        pfIndex2Color;
  tLCDDEV_GetIndexMask*       pfGetIndexMask;
  tLCDDEV_DrawBitmap*         pfDrawBitmap;
  tLCDDEV_DrawHLine*          pfDrawHLine;
  tLCDDEV_DrawVLine*          pfDrawVLine;
  tLCDDEV_FillRect*           pfFillRect;
  tLCDDEV_GetPixelIndex*      pfGetPixelIndex;
  tLCDDEV_GetRect*            pfGetRect;
  tLCDDEV_SetPixelIndex*      pfSetPixelIndex;
  tLCDDEV_XorPixel*           pfXorPixel;
  tLCDDEV_SetLUTEntry*        pfSetLUTEntry;
#line 242 "..\\code\\GUI\\GUI_inc\\LCD.h"
};

  extern const struct tLCDDEV_APIList_struct GUI_MEMDEV__APIList1;
  extern const struct tLCDDEV_APIList_struct GUI_MEMDEV__APIList8;
  extern const struct tLCDDEV_APIList_struct GUI_MEMDEV__APIList16;























 

#line 283 "..\\code\\GUI\\GUI_inc\\LCD.h"





 
 

int LCD_GetXSize(void);
int LCD_GetXSize_1(void);
int LCD_GetXSizeEx(int Index);

int LCD_GetYSize(void);
int LCD_GetYSize_1(void);
int LCD_GetYSizeEx(int Index);

int LCD_GetVXSize(void);
int LCD_GetVXSize_1(void);
int LCD_GetVXSizeEx(int Index);

int LCD_GetVYSize(void);
int LCD_GetVYSize_1(void);
int LCD_GetVYSizeEx(int Index);

unsigned long LCD_GetNumColors(void);
unsigned long LCD_GetNumColors_1(void);
unsigned long LCD_GetNumColorsEx(int Index);

int LCD_GetBitsPerPixel(void);
int LCD_GetBitsPerPixel_1(void);
int LCD_GetBitsPerPixelEx(int Index);

int LCD_GetFixedPalette(void);
int LCD_GetFixedPalette_1(void);
signed long LCD_GetFixedPaletteEx(int Index);

int LCD_GetXMag(void);
int LCD_GetXMag_1(void);
int LCD_GetXMagEx(int Index);

int LCD_GetYMag(void);
int LCD_GetYMag_1(void);
int LCD_GetYMagEx(int Index);

int LCD_GetMirrorXEx(int LayerIndex);
int LCD_GetMirrorYEx(int LayerIndex);
int LCD_GetSwapXYEx(int LayerIndex);

int LCD_GetSwapRBEx(int LayerIndex);
int LCD_GetDeltaModeEx(int LayerIndex);
int LCD_GetBitsPerPixel_L0Ex(int LayerIndex);

int LCD_GetNumLayers(void);



#line 345 "..\\code\\GUI\\GUI_inc\\LCD.h"







 
typedef void         tLCD_HL_DrawHLine    (int x0, int y0,  int x1);
typedef void         tLCD_HL_DrawPixel    (int x0, int y0);

typedef struct {
  tLCD_HL_DrawHLine*          pfDrawHLine;
  tLCD_HL_DrawPixel*          pfDrawPixel;
} tLCD_HL_APIList;

void LCD_DrawHLine(int x0, int y0,  int x1);
void LCD_DrawPixel(int x0, int y0);
void LCD_DrawVLine  (int x, int y0,  int y1);








 

void LCD_SetClipRectEx(const LCD_RECT* pRect);
void LCD_SetClipRectMax(void);

 
signed long  LCD_GetDevCap(int Index);

 
int LCD_Init(void);

void LCD_SetBkColor   (LCD_COLOR Color);  
void LCD_SetColor     (LCD_COLOR Color);  
void LCD_SetPixelIndex(int x, int y, int ColorIndex);

 
void LCD_InitLUT(void);

 

void         LCD_DrawBitmap_RLE8(int x0,int y0,int xsize, int ysize, const unsigned char  *pPixel, const LCD_LOGPALETTE  * pLogPal, int xMag, int yMag);
void         LCD_DrawBitmap_RLE4(int x0,int y0,int xsize, int ysize, const unsigned char  *pPixel, const LCD_LOGPALETTE  * pLogPal, int xMag, int yMag);
void         LCD_DrawBitmap_565 (int x0,int y0,int xsize, int ysize, const unsigned char  *pPixel, const LCD_LOGPALETTE  * pLogPal, int xMag, int yMag);
void         LCD_DrawBitmap_M565(int x0,int y0,int xsize, int ysize, const unsigned char  *pPixel, const LCD_LOGPALETTE  * pLogPal, int xMag, int yMag);

LCD_DRAWMODE LCD_SetDrawMode  (LCD_DRAWMODE dm);
void LCD_SetColorIndex(int Index);
void LCD_SetBkColorIndex(int Index);
void LCD_FillRect(int x0, int y0, int x1, int y1);
typedef void tLCD_SetPixelAA(int x, int y, unsigned char Intens);

void LCD_SetPixelAA(int x, int y, unsigned char Intens);
void LCD_SetPixelAA_NoTrans(int x, int y, unsigned char Intens);

LCD_COLOR    LCD_AA_MixColors(LCD_COLOR Color, LCD_COLOR BkColor, unsigned char Intens);
LCD_COLOR    LCD_MixColors256(LCD_COLOR Color, LCD_COLOR BkColor, unsigned Intens);
LCD_COLOR    LCD_GetPixelColor(int x, int y);      
unsigned int LCD_GetPixelIndex(int x, int y);
int          LCD_GetBkColorIndex (void);
int          LCD_GetColorIndex (void);






 



typedef void tLCD_DrawBitmap(int x0, int y0, int xsize, int ysize,
                             int xMul, int yMul, int BitsPerPixel, int BytesPerLine,
                             const unsigned char  * pPixel, const void * pTrans);
typedef void tRect2TextRect (LCD_RECT * pRect);

struct tLCD_APIList_struct {
  tLCD_DrawBitmap   * pfDrawBitmap;
  tRect2TextRect    * pfRect2TextRect;
};

typedef struct tLCD_APIList_struct tLCD_APIList;

extern tLCD_APIList LCD_APIListCCW;
extern tLCD_APIList LCD_APIListCW;
extern tLCD_APIList LCD_APIList180;

#line 444 "..\\code\\GUI\\GUI_inc\\LCD.h"












 












unsigned char LCD_L0_ControlCache(unsigned char mode);
unsigned char LCD_L0_1_ControlCache(unsigned char mode);
unsigned char LCD_L0_2_ControlCache(unsigned char mode);
unsigned char LCD_L0_3_ControlCache(unsigned char mode);
unsigned char LCD_L0_4_ControlCache(unsigned char mode);
void LCD_L0_Refresh(void);
void LCD_L0_1_Refresh(void);
void LCD_L0_2_Refresh(void);
void LCD_L0_3_Refresh(void);
void LCD_L0_4_Refresh(void);
 
int  LCD_L0_CheckInit(void);        



 









 

int LCD_SelPage  (int NewPage);     
int LCD_ShowPage (int NewPage);     
int LCD_GetSelPage (void);          
int LCD_GetVisPage (void);          








 
  

int              LCD_Color2Index     (LCD_COLOR Color);
LCD_COLOR        LCD_Index2Color     (int Index);
LCD_COLOR        LCD_Index2ColorEx   (int i, unsigned int LayerIndex);






 

void LCD_X_Init(void);
void LCD_X_On  (void);
void LCD_X_Off (void);

char LCD_X_Read00(void);
char LCD_X_Read01(void);
void LCD_X_Write00(char c);
void LCD_X_Write01(char c);
void LCD_X_WriteM01(char * pData, int NumBytes);







 
#line 28 "..\\code\\GUI\\GUI_inc\\GUIType.h"
#line 29 "..\\code\\GUI\\GUI_inc\\GUIType.h"






 

typedef const char *  GUI_ConstString;







 

typedef LCD_COLOR       GUI_COLOR;
typedef LCD_LOGPALETTE  GUI_LOGPALETTE;
typedef LCD_DRAWMODE    GUI_DRAWMODE;
typedef LCD_RECT        GUI_RECT;

typedef struct {
  void      (* pfDraw)(int x0,int y0,int xsize, int ysize, const unsigned char  * pPixel, const LCD_LOGPALETTE  * pLogPal, int xMag, int yMag);
  GUI_COLOR (* pfIndex2Color)(int Index);
} GUI_BITMAP_METHODS;

typedef struct {
  unsigned short XSize;
  unsigned short YSize;
  unsigned short BytesPerLine;
  unsigned short BitsPerPixel;
  const unsigned char  * pData;
  const GUI_LOGPALETTE  * pPal;
  const GUI_BITMAP_METHODS * pMethods;
} GUI_BITMAP;





 
typedef struct {
  unsigned short ID;            
  unsigned short Version;
  unsigned short XSize;
  unsigned short YSize;
  unsigned short BytesPerLine;
  unsigned short BitsPerPixel;
  unsigned short NumColors;
  unsigned short HasTrans;
} GUI_BITMAP_STREAM;

typedef struct {
  int x,y;
  unsigned char Pressed;
} GUI_PID_STATE;







 



 
typedef struct {
  signed short c0;
  signed short c1;
} GUI_FONT_TRANSLIST;

typedef struct {
  unsigned short FirstChar;
  unsigned short LastChar;
  const GUI_FONT_TRANSLIST  * pList;
} GUI_FONT_TRANSINFO;

typedef struct {
  unsigned char XSize;
  unsigned char XDist;
  unsigned char BytesPerLine;
  const unsigned char  * pData;
} GUI_CHARINFO;

typedef struct GUI_FONT_PROP {
  unsigned short First;                                 
  unsigned short Last;                                  
  const GUI_CHARINFO  * paCharInfo;             
  const struct GUI_FONT_PROP  * pNext;         
} GUI_FONT_PROP;

typedef struct {
  const unsigned char  * pData;
  const unsigned char  * pTransData;
  const GUI_FONT_TRANSINFO  * pTrans;
  unsigned short FirstChar;
  unsigned short LastChar;
  unsigned char XSize;
  unsigned char XDist;
  unsigned char BytesPerLine;
} GUI_FONT_MONO;


typedef struct GUI_FONT_INFO {
  unsigned short First;                         
  unsigned short Last;                          
  const GUI_CHARINFO* paCharInfo;     
  const struct GUI_FONT_INFO* pNext;  
} GUI_FONT_INFO;










 
typedef struct {
  unsigned short Flags;
  unsigned char Baseline;
  unsigned char LHeight;      
  unsigned char CHeight;      
} GUI_FONTINFO;













 
typedef unsigned short  tGUI_GetCharCode(const char  *s);
typedef int  tGUI_GetCharSize(const char  *s);
typedef int  tGUI_CalcSizeOfChar(unsigned short Char);
typedef int  tGUI_Encode(char *s, unsigned short Char);

typedef struct {
  tGUI_GetCharCode*            pfGetCharCode;
  tGUI_GetCharSize*            pfGetCharSize;
  tGUI_CalcSizeOfChar*         pfCalcSizeOfChar;
  tGUI_Encode*                 pfEncode;
} GUI_UC_ENC_APILIST;






 

typedef int  tGUI_GetLineDistX(const char  *s, int Len);
typedef int  tGUI_GetLineLen(const char  *s, int MaxLen);
typedef void tGL_DispLine(const char  *s, int Len);

typedef struct {
  tGUI_GetLineDistX*          pfGetLineDistX;
  tGUI_GetLineLen*            pfGetLineLen;
  tGL_DispLine*               pfDispLine;
} tGUI_ENC_APIList;

extern const tGUI_ENC_APIList GUI_ENC_APIList_SJIS;













 

typedef struct GUI_FONT GUI_FONT;

typedef void GUI_DISPCHAR(unsigned short c);
typedef int  GUI_GETCHARDISTX(unsigned short c);
typedef void GUI_GETFONTINFO(const GUI_FONT  * pFont, GUI_FONTINFO * pfi);
typedef char GUI_ISINFONT   (const GUI_FONT  * pFont, unsigned short c);











 
void GUIMONO_DispChar (unsigned short c); int GUIMONO_GetCharDistX(unsigned short c); void GUIMONO_GetFontInfo (const GUI_FONT  * pFont, GUI_FONTINFO * pfi); char GUIMONO_IsInFont (const GUI_FONT  * pFont, unsigned short c);
#line 243 "..\\code\\GUI\\GUI_inc\\GUIType.h"

 
void GUIPROP_DispChar (unsigned short c); int GUIPROP_GetCharDistX(unsigned short c); void GUIPROP_GetFontInfo (const GUI_FONT  * pFont, GUI_FONTINFO * pfi); char GUIPROP_IsInFont (const GUI_FONT  * pFont, unsigned short c);
#line 252 "..\\code\\GUI\\GUI_inc\\GUIType.h"

 
void GUIPROP_DispChar (unsigned short c); int GUIPROP_GetCharDistX(unsigned short c); void GUIPROP_GetFontInfo (const GUI_FONT  * pFont, GUI_FONTINFO * pfi); char GUIPROP_IsInFont (const GUI_FONT  * pFont, unsigned short c);
#line 261 "..\\code\\GUI\\GUI_inc\\GUIType.h"

 
void GUIPROPAA_DispChar (unsigned short c); int GUIPROPAA_GetCharDistX(unsigned short c); void GUIPROPAA_GetFontInfo (const GUI_FONT  * pFont, GUI_FONTINFO * pfi); char GUIPROPAA_IsInFont (const GUI_FONT  * pFont, unsigned short c);
#line 270 "..\\code\\GUI\\GUI_inc\\GUIType.h"

 
void GUIPROP_AA2_DispChar (unsigned short c); int GUIPROP_AA2_GetCharDistX(unsigned short c); void GUIPROP_AA2_GetFontInfo (const GUI_FONT  * pFont, GUI_FONTINFO * pfi); char GUIPROP_AA2_IsInFont (const GUI_FONT  * pFont, unsigned short c);
#line 279 "..\\code\\GUI\\GUI_inc\\GUIType.h"

 
void GUIPROP_AA2_DispChar (unsigned short c); int GUIPROP_AA2_GetCharDistX(unsigned short c); void GUIPROP_AA2_GetFontInfo (const GUI_FONT  * pFont, GUI_FONTINFO * pfi); char GUIPROP_AA2_IsInFont (const GUI_FONT  * pFont, unsigned short c);
#line 288 "..\\code\\GUI\\GUI_inc\\GUIType.h"

 
void GUIPROP_AA4_DispChar (unsigned short c); int GUIPROP_AA4_GetCharDistX(unsigned short c); void GUIPROP_AA4_GetFontInfo (const GUI_FONT  * pFont, GUI_FONTINFO * pfi); char GUIPROP_AA4_IsInFont (const GUI_FONT  * pFont, unsigned short c);
#line 297 "..\\code\\GUI\\GUI_inc\\GUIType.h"

 
void GUIPROP_AA4_DispChar (unsigned short c); int GUIPROP_AA4_GetCharDistX(unsigned short c); void GUIPROP_AA4_GetFontInfo (const GUI_FONT  * pFont, GUI_FONTINFO * pfi); char GUIPROP_AA4_IsInFont (const GUI_FONT  * pFont, unsigned short c);
#line 306 "..\\code\\GUI\\GUI_inc\\GUIType.h"





struct GUI_FONT {
  GUI_DISPCHAR*     pfDispChar; 
  GUI_GETCHARDISTX* pfGetCharDistX; 
  GUI_GETFONTINFO*  pfGetFontInfo; 
  GUI_ISINFONT*     pfIsInFont;
  const tGUI_ENC_APIList* pafEncode;
  unsigned char YSize;
  unsigned char YDist;
  unsigned char XMag;
  unsigned char YMag;
  union {
    const void           * pFontData;
    const GUI_FONT_MONO  * pMono;
    const GUI_FONT_PROP  * pProp;
  } p;
  unsigned char Baseline;
  unsigned char LHeight;      
  unsigned char CHeight;      
};




 
typedef struct {
  unsigned long ID;            
  unsigned short YSize;         
  unsigned short YDist;         
  unsigned short Baseline;      
  unsigned short LHeight;       
  unsigned short CHeight;       
  unsigned short NumAreas;      
} GUI_SI_FONT;

typedef struct {
  unsigned short First;         
  unsigned short Last;          
} GUI_SIF_CHAR_AREA;

typedef struct {
  unsigned short XSize;         
  unsigned short XDist;         
  unsigned short BytesPerLine;  
  unsigned short Dummy;
  unsigned long OffData;       
} GUI_SIF_CHARINFO;

typedef struct tGUI_SIF_APIList_struct {
  GUI_DISPCHAR     * pDispChar;
  GUI_GETCHARDISTX * pGetCharDistX;
  GUI_GETFONTINFO  * pGetFontInfo;
  GUI_ISINFONT     * pIsInFont;
} tGUI_SIF_APIList;




extern const tGUI_SIF_APIList GUI_SIF_APIList_Prop;







 





typedef     signed short      GUI_HWIN;


 
#line 31 "..\\code\\GUI\\GUI_inc\\gui.h"
#line 1 "..\\code\\GUI\\GUI_inc\\GUIVersion.h"

















 








 
#line 32 "..\\code\\GUI\\GUI_inc\\gui.h"





extern const GUI_FONT GUI_FontHZ_chinese_19;    
extern const GUI_FONT GUI_FontHZ_SimSun_16;





 









 











 

#line 83 "..\\code\\GUI\\GUI_inc\\gui.h"













 

#line 106 "..\\code\\GUI\\GUI_inc\\gui.h"




#line 120 "..\\code\\GUI\\GUI_inc\\gui.h"

#line 131 "..\\code\\GUI\\GUI_inc\\gui.h"

#line 141 "..\\code\\GUI\\GUI_inc\\gui.h"

#line 152 "..\\code\\GUI\\GUI_inc\\gui.h"






#line 166 "..\\code\\GUI\\GUI_inc\\gui.h"

#line 177 "..\\code\\GUI\\GUI_inc\\gui.h"

#line 188 "..\\code\\GUI\\GUI_inc\\gui.h"




























 






 











 













 












 

#line 287 "..\\code\\GUI\\GUI_inc\\gui.h"










 











 


 
extern const GUI_FONT GUI_Font8_ASCII,        GUI_Font8_1;
extern const GUI_FONT GUI_Font10S_ASCII,      GUI_Font10S_1;
extern const GUI_FONT GUI_Font10_ASCII,       GUI_Font10_1;
extern const GUI_FONT GUI_Font13_ASCII,       GUI_Font13_1;
extern const GUI_FONT GUI_Font13B_ASCII,      GUI_Font13B_1;
extern const GUI_FONT GUI_Font13H_ASCII,      GUI_Font13H_1;
extern const GUI_FONT GUI_Font13HB_ASCII,     GUI_Font13HB_1;
extern const GUI_FONT GUI_Font16_ASCII,       GUI_Font16_1,       GUI_Font16_HK,    GUI_Font16_1HK;
extern const GUI_FONT GUI_Font16B_ASCII,      GUI_Font16B_1;
extern const GUI_FONT GUI_Font24_ASCII,       GUI_Font24_1;
extern const GUI_FONT GUI_Font24B_ASCII,      GUI_Font24B_1;
extern const GUI_FONT GUI_Font32_ASCII,       GUI_Font32_1;
extern const GUI_FONT GUI_Font32B_ASCII,      GUI_Font32B_1;

 
extern const GUI_FONT GUI_Font4x6;
extern const GUI_FONT GUI_Font6x8,            GUI_Font6x9;
extern const GUI_FONT GUI_Font8x8,            GUI_Font8x9;
extern const GUI_FONT GUI_Font8x10_ASCII;
extern const GUI_FONT GUI_Font8x12_ASCII;
extern const GUI_FONT GUI_Font8x13_ASCII,     GUI_Font8x13_1;
extern const GUI_FONT GUI_Font8x15B_ASCII,    GUI_Font8x15B_1;
extern const GUI_FONT GUI_Font8x16,           GUI_Font8x17,       GUI_Font8x18;
extern const GUI_FONT GUI_Font8x16x1x2,       GUI_Font8x16x2x2,   GUI_Font8x16x3x3;

 
extern const GUI_FONT GUI_FontD24x32;
extern const GUI_FONT GUI_FontD32;
extern const GUI_FONT GUI_FontD36x48;
extern const GUI_FONT GUI_FontD48;
extern const GUI_FONT GUI_FontD48x64;
extern const GUI_FONT GUI_FontD64;
extern const GUI_FONT GUI_FontD60x80;
extern const GUI_FONT GUI_FontD80;

 
extern const GUI_FONT GUI_FontComic18B_ASCII, GUI_FontComic18B_1;
extern const GUI_FONT GUI_FontComic24B_ASCII, GUI_FontComic24B_1;













 

#line 374 "..\\code\\GUI\\GUI_inc\\gui.h"

#line 383 "..\\code\\GUI\\GUI_inc\\gui.h"

 






 











 
 










 


#line 433 "..\\code\\GUI\\GUI_inc\\gui.h"









 

typedef union {
  unsigned char  aColorIndex8[2];
  unsigned short aColorIndex16[2];
} LCD_COLORINDEX_UNION;

typedef struct {
 
  LCD_COLORINDEX_UNION LCD;
  LCD_RECT       ClipRect;
  unsigned char             DrawMode;
  unsigned char             SelLayer;
  unsigned char             TextStyle;
 
  GUI_RECT* pClipRect_HL;                 
  unsigned char        PenSize;
  unsigned char        PenShape;
  unsigned char        LineStyle;
  unsigned char        FillStyle;
 
  const GUI_FONT            * pAFont;
  const GUI_UC_ENC_APILIST * pUC_API;     
  signed short LBorder;
  signed short DispPosX, DispPosY;
  signed short DrawPosX, DrawPosY;
  signed short TextMode, TextAlign;
  GUI_COLOR Color, BkColor;            
 

    const GUI_RECT* WM__pUserClipRect;
    GUI_HWIN hAWin;
    int xOff, yOff;

 





 

    const tLCD_HL_APIList* pLCD_HL;      
    unsigned char AA_Factor;
    unsigned char AA_HiResEnable;

} GUI_CONTEXT;

 
#line 500 "..\\code\\GUI\\GUI_inc\\gui.h"






 
int          GUI_Init(void);
void         GUI_SetDefault(void);
GUI_DRAWMODE GUI_SetDrawMode(GUI_DRAWMODE dm);
const char * GUI_GetVersionString(void);
void         GUI_SaveContext_W   (      GUI_CONTEXT* pContext);
void         GUI_RestoreContext(const GUI_CONTEXT* pContext);







 

int  GUI_RectsIntersect(const GUI_RECT* pr0, const GUI_RECT* pr1);
void GUI_MoveRect       (GUI_RECT *pRect, int x, int y);
void GUI_MergeRect      (GUI_RECT* pDest, const GUI_RECT* pr0, const GUI_RECT* pr1);
int  GUI__IntersectRects(GUI_RECT* pDest, const GUI_RECT* pr0, const GUI_RECT* pr1);
void GUI__IntersectRect (GUI_RECT* pDest, const GUI_RECT* pr0);
void GUI__ReduceRect    (GUI_RECT* pDest, const GUI_RECT *pRect, int Dist);






 

int  GUI__DivideRound     (int a, int b);
signed long  GUI__DivideRound32   (signed long a, signed long b);
int  GUI__SetText(signed short* phText, const char* s);








 
 
GUI_COLOR GUI_GetBkColor     (void);
GUI_COLOR GUI_GetColor       (void);
int       GUI_GetBkColorIndex(void);
int       GUI_GetColorIndex  (void);
unsigned char        GUI_GetPenSize     (void);
unsigned char        GUI_GetPenShape    (void);
unsigned char        GUI_GetLineStyle   (void);
unsigned char        GUI_GetFillStyle   (void);

void      GUI_SetBkColor   (GUI_COLOR);
void      GUI_SetColor     (GUI_COLOR);
void      GUI_SetBkColorIndex(int Index);
void      GUI_SetColorIndex(int Index);

unsigned char        GUI_SetPenSize   (unsigned char Size);
unsigned char        GUI_SetPenShape  (unsigned char Shape);
unsigned char        GUI_SetLineStyle (unsigned char Style);
unsigned char        GUI_SetFillStyle (unsigned char Style);

 
char      GUI_GetDecChar(void);
char      GUI_SetDecChar(char c);







 

int       GUI_Color2Index(GUI_COLOR color);
GUI_COLOR GUI_Color2VisColor(GUI_COLOR color);
char      GUI_ColorIsAvailable(GUI_COLOR color);
GUI_COLOR GUI_Index2Color(int Index);
void      GUI_InitLUT(void);
void      GUI_SetLUTEntry (unsigned char Pos, GUI_COLOR Color);
void      GUI_SetLUTColor (unsigned char Pos, GUI_COLOR Color);
void      GUI_SetLUTColorEx(unsigned char Pos, LCD_COLOR Color, unsigned int LayerIndex);
unsigned long       GUI_CalcColorDist (GUI_COLOR Color0, GUI_COLOR  Color1);
unsigned long       GUI_CalcVisColorError(GUI_COLOR color);






 
void GUI_Log      (const char *s);
void GUI_Log1     (const char *s, int p0);
void GUI_Log2     (const char *s, int p0, int p1);
void GUI_Log3     (const char *s, int p0, int p1, int p2);
void GUI_Log4     (const char *s, int p0, int p1, int p2,int p3);
void GUI_Warn     (const char *s);
void GUI_Warn1    (const char *s, int p0);
void GUI_Warn2    (const char *s, int p0, int p1);
void GUI_Warn3    (const char *s, int p0, int p1, int p2);
void GUI_Warn4    (const char *s, int p0, int p1, int p2, int p3);
void GUI_ErrorOut (const char *s);
void GUI_ErrorOut1(const char *s, int p0);
void GUI_ErrorOut2(const char *s, int p0, int p1);
void GUI_ErrorOut3(const char *s, int p0, int p1, int p2);
void GUI_ErrorOut4(const char *s, int p0, int p1, int p2, int p3);






 

int  GUI_BMP_Draw         (const void * pFileData, int x0, int y0);
int  GUI_BMP_GetXSize     (const void * pFileData);
int  GUI_BMP_GetYSize     (const void * pFileData);
void GUI_Clear            (void);
void GUI_ClearRect        (int x0, int y0, int x1, int y1);
void GUI_ClearRectEx      (const GUI_RECT* pRect);
void GUI_DrawArc          (int x0, int y0, int rx, int ry, int a0, int a1);
void GUI_DrawBitmap       (const GUI_BITMAP  * pBM, int x0, int y0);
void GUI_DrawBitmapMag    (const GUI_BITMAP  * pBM, int x0, int y0, int XMul, int YMul);
void GUI_DrawBitmapEx     (const GUI_BITMAP  * pBitmap, int x0, int y0, int xCenter, int yCenter, int xMag, int yMag);
void GUI_DrawBitmapExp    (int x0, int y0, int XSize, int YSize, int XMul,  int YMul, int BitsPerPixel, int BytesPerLine, const unsigned char  * pData, const GUI_LOGPALETTE  * pPal);
void GUI_DrawCircle       (int x0, int y0, int r);
void GUI_DrawEllipse      (int x0, int y0, int rx, int ry);
void GUI_DrawGraph        (signed short *pay, int NumPoints, int x0, int y0);
void GUI_DrawHLine        (int y0, int x0, int x1);
void GUI_DrawLine         (int x0, int y0, int x1, int y1);
void GUI_DrawLineRel      (int dx, int dy);
void GUI_DrawLineTo       (int x, int y);
void GUI_DrawPie          (int x0, int y0, int r, int a0, int a1, int Type);
void GUI_DrawPixel        (int x, int y);
void GUI_DrawPoint        (int x, int y);
void GUI_DrawPolygon      (const GUI_POINT* pPoints, int NumPoints, int x0, int y0);
void GUI_DrawPolyLine     (const GUI_POINT* pPoints, int NumPoints, int x0, int y0);
void GUI_DrawFocusRect    (const GUI_RECT *pRect, int Dist);
void GUI_DrawRect         (int x0, int y0, int x1, int y1);
void GUI_DrawRectEx       (const GUI_RECT *pRect);
void GUI_DrawVLine        (int x0, int y0, int y1);
void GUI_FillCircle       (int x0, int y0, int r);
void GUI_FillEllipse      (int x0, int y0, int rx, int ry);
void GUI_FillPolygon      (const GUI_POINT* pPoints, int NumPoints, int x0, int y0);
void GUI_FillRect         (int x0, int y0, int x1, int y1);
void GUI_FillRectEx       (const GUI_RECT* pRect);
void GUI_GetClientRect    (GUI_RECT* pRect);
void GUI_InvertRect       (int x0, int y0, int x1, int y1);
void GUI_MoveRel          (int dx, int dy);
void GUI_MoveTo           (int x, int y);






 
typedef struct {
  int XSize;
  int YSize;
} GUI_JPEG_INFO;

int  GUI_JPEG_Draw        (const void * pFileData, int DataSize, int x0, int y0);
int  GUI_JPEG_GetInfo     (const void * pFileData, int DataSize, GUI_JPEG_INFO* pInfo);






 

typedef struct {
  const  GUI_BITMAP * pBitmap;
  int xHot, yHot;
} GUI_CURSOR;


  void               GUI_CURSOR_Activate   (void);
  void               GUI_CURSOR_Deactivate (void);
  void               GUI_CURSOR_Hide       (void);
  void               GUI_CURSOR_SetXor     (const GUI_BITMAP * pBM, int x, int y);
  void               GUI_CURSOR_SetPosition(int x, int y);
  const GUI_CURSOR  * GUI_CURSOR_Select     (const GUI_CURSOR  * pCursor);
  void               GUI_CURSOR_Show       (void);










 
extern const GUI_CURSOR GUI_CursorArrowS,  GUI_CursorArrowSI;
extern const GUI_CURSOR GUI_CursorArrowM,  GUI_CursorArrowMI;
extern const GUI_CURSOR GUI_CursorArrowL,  GUI_CursorArrowLI;
extern const GUI_CURSOR GUI_CursorCrossS,  GUI_CursorCrossSI;
extern const GUI_CURSOR GUI_CursorCrossM,  GUI_CursorCrossMI;
extern const GUI_CURSOR GUI_CursorCrossL,  GUI_CursorCrossLI;
extern const GUI_CURSOR GUI_CursorHeaderM, GUI_CursorHeaderMI;

extern const GUI_BITMAP GUI_BitmapArrowS, GUI_BitmapArrowSI;
extern const GUI_BITMAP GUI_BitmapArrowM, GUI_BitmapArrowMI;
extern const GUI_BITMAP GUI_BitmapArrowL, GUI_BitmapArrowLI;
extern const GUI_BITMAP GUI_BitmapCrossS, GUI_BitmapCrossSI;
extern const GUI_BITMAP GUI_BitmapCrossM, GUI_BitmapCrossMI;
extern const GUI_BITMAP GUI_BitmapCrossL, GUI_BitmapCrossLI;






 

void  GUI_DispCEOL (void);
void  GUI_DispChar  (unsigned short c);
void  GUI_DispChars (unsigned short c, int Cnt);
void  GUI_DispCharAt(unsigned short c, signed short x, signed short y);
void  GUI_DispString         (const char  *s);
void  GUI_DispStringAt       (const char  *s, int x, int y);
void  GUI_DispStringAtCEOL   (const char  *s, int x, int y);
void  GUI_DispStringHCenterAt(const char  *s, int x, int y);
void  GUI__DispStringInRect  (const char  *s, GUI_RECT* pRect, int TextAlign, int MaxNumChars);
void  GUI_DispStringInRect   (const char  *s, GUI_RECT* pRect, int Flags);

  void  GUI_DispStringInRectEx (const char  *s, GUI_RECT* pRect, int TextAlign, int MaxLen, const tLCD_APIList * pLCD_Api);

void  GUI_DispStringInRectMax(const char  *s, GUI_RECT* pRect, int TextAlign, int MaxLen);  
void  GUI_DispStringLen      (const char  *s, int Len);
void  GUI_GetTextExtend(GUI_RECT* pRect, const char  * s, int Len);
int   GUI_GetYAdjust(void);
int   GUI_GetDispPosX(void);
int   GUI_GetDispPosY(void);
const GUI_FONT  * GUI_GetFont(void);
int   GUI_GetCharDistX(unsigned short c);
int   GUI_GetStringDistX(const char  *s);
int   GUI_GetFontDistY(void);
int   GUI_GetFontSizeY(void);
void  GUI_GetFontInfo   (const GUI_FONT  * pFont, GUI_FONTINFO* pfi);
int   GUI_GetYSizeOfFont(const GUI_FONT  * pFont);
int   GUI_GetYDistOfFont(const GUI_FONT  * pFont);
int   GUI_GetTextAlign(void);
int   GUI_GetTextMode(void);
char  GUI_IsInFont(const GUI_FONT  * pFont, unsigned short c);
int   GUI_SetTextAlign(int Align);
int   GUI_SetTextMode(int Mode);
char  GUI_SetTextStyle(char Style);
int   GUI_SetLBorder(int x);
void  GUI_SetOrg(int x, int y);
const GUI_FONT  * GUI_SetFont(const GUI_FONT  * pNewFont);
char  GUI_GotoXY(int x, int y);
char  GUI_GotoX(int x);
char  GUI_GotoY(int y);
void  GUI_DispNextLine(void);






 
void GUI_SIF_CreateFont(void * pFontData, GUI_FONT * pFont, const tGUI_SIF_APIList * pFontType);
void GUI_SIF_DeleteFont(GUI_FONT * pFont);






 

int   GUI_UC_Encode           (char* s, unsigned short Char);
int   GUI_UC_GetCharSize      (const char  * s);
unsigned short   GUI_UC_GetCharCode      (const char  * s);
void  GUI_UC_SetEncodeNone    (void);
void  GUI_UC_SetEncodeUTF8    (void);

void GUI_UC_DispString(const unsigned short  *s);
void GUI_UC2DB (unsigned short Code, unsigned char* pOut);
unsigned short  GUI_DB2UC (unsigned char Byte0, unsigned char Byte1);






 

void GUI_DispBin  (unsigned long  v, unsigned char Len);
void GUI_DispBinAt(unsigned long  v, signed short x, signed short y, unsigned char Len);
void GUI_DispDec  (signed long v, unsigned char Len);
void GUI_DispDecAt (signed long v, signed short x, signed short y, unsigned char Len);
void GUI_DispDecMin(signed long v);
void GUI_DispDecShift(signed long v, unsigned char Len, unsigned char Shift);
void GUI_DispDecSpace(signed long v, unsigned char MaxDigits);
void GUI_DispHex  (unsigned long v, unsigned char Len);
void GUI_DispHexAt(unsigned long v, signed short x, signed short y, unsigned char Len);
void GUI_DispSDec(signed long v, unsigned char Len);
void GUI_DispSDecShift(signed long v, unsigned char Len, unsigned char Shift);










 

void GUI_DispFloat    (float v, char Len);
void GUI_DispFloatFix (float v, char Len, char Fract);
void GUI_DispFloatMin (float v, char Fract);
void GUI_DispSFloatFix(float v, char Len, char Fract);
void GUI_DispSFloatMin(float v, char Fract);







 


   
  signed short  GUI_ALLOC_GetUsed        (void);
  signed short  GUI_ALLOC_GetNumFreeBytes(void);


signed short           GUI_ALLOC_AllocInit  (const void *pInitData, signed short Size);
signed short           GUI_ALLOC_AllocNoInit(signed short size);
signed short           GUI_ALLOC_AllocZero  (signed short size);
void               GUI_ALLOC_Free       (signed short  hMem);
void               GUI_ALLOC_FreePtr    (signed short *phMem);
signed short GUI_ALLOC_GetSize    (signed short  hMem);
signed short GUI_ALLOC_GetMaxSize (void);
void*              GUI_ALLOC_h2p        (signed short  hMem);
void               GUI_ALLOC_Init       (void);
signed short           GUI_ALLOC_Realloc    (signed short hOld, int NewSize);






 




#line 908 "..\\code\\GUI\\GUI_inc\\gui.h"

void GUI_SelectLCD(void);
unsigned int GUI_SelectLayer(unsigned int Index);






 

typedef signed short GUI_MEASDEV_Handle;

GUI_MEASDEV_Handle GUI_MEASDEV_Create (void);
void               GUI_MEASDEV_Delete (GUI_MEASDEV_Handle hMemDev);
void               GUI_MEASDEV_Select (GUI_MEASDEV_Handle hMem);
void               GUI_MEASDEV_GetRect(GUI_MEASDEV_Handle hMem, GUI_RECT *pRect);
void               GUI_MEASDEV_ClearRect(GUI_MEASDEV_Handle hMem);






 
void GUI_RotatePolygon(GUI_POINT* pDest, const GUI_POINT* pSrc, int NumPoints, float Angle);
void GUI_MagnifyPolygon(GUI_POINT* pDest, const GUI_POINT* pSrc, int NumPoints, int Mag);
void GUI_EnlargePolygon(GUI_POINT* pDest, const GUI_POINT* pSrc, int NumPoints, int Len);






 
void GUI_DrawStreamedBitmap(const GUI_BITMAP_STREAM *pBitmapStream, int x, int y);






 
typedef void GUI_CALLBACK_VOID_U8_P(unsigned char Data, void * p);

void GUI_BMP_SerializeEx(GUI_CALLBACK_VOID_U8_P * pfSerialize, int x0, int y0, int xSize, int ySize, void * p);
void GUI_BMP_Serialize  (GUI_CALLBACK_VOID_U8_P * pfSerialize, void * p);






 
void GUI_Delay  (int Period);
int  GUI_GetTime(void);
int  GUI_Exec(void);          
int  GUI_Exec1(void);         








 
int     GUI_MessageBox   (const char * sMessage, const char * sCaption, int Flags);










 

typedef struct {
  int Time;
  unsigned long            Context;
} GUI_TIMER_MESSAGE;

typedef signed short GUI_TIMER_HANDLE;
typedef void GUI_TIMER_CALLBACK(  GUI_TIMER_MESSAGE* pTM);

GUI_TIMER_HANDLE GUI_TIMER_Create   (GUI_TIMER_CALLBACK* cb, int Time,  unsigned long Context, int Flags);
void             GUI_TIMER_Delete   (GUI_TIMER_HANDLE hObj);

 
void GUI_TIMER_SetPeriod (GUI_TIMER_HANDLE hObj, int Period);
void GUI_TIMER_SetTime   (GUI_TIMER_HANDLE hObj, int Period);
void GUI_TIMER_SetDelay  (GUI_TIMER_HANDLE hObj, int Delay);
void GUI_TIMER_Restart   (GUI_TIMER_HANDLE hObj);
int  GUI_TIMER_Exec(void);







 

void GUI_AA_DisableHiRes   (void);
void GUI_AA_EnableHiRes    (void);
int  GUI_AA_GetFactor      (void);
void GUI_AA_SetFactor      (int Factor);
void GUI_AA_DrawArc        (int x0, int y0, int rx, int ry, int a0, int a1);
void GUI_AA_DrawLine       (int x0, int y0, int x1, int y1);
void GUI_AA_DrawPolyOutline(const GUI_POINT* pSrc, int NumPoints, int Thickness, int x, int y);
void GUI_AA_FillCircle     (int x0, int y0, int r);
void GUI_AA_FillPolygon    (GUI_POINT* pPoints, int NumPoints, int x0, int y0);






 

 
void GUI_StoreKeyMsg(int Key, int Pressed);
void GUI_SendKeyMsg (int Key, int Pressed);
int  GUI_PollKeyMsg(void);

 
typedef int GUI_KEY_MSG_HOOK(int Key, int Pressed);
extern  GUI_KEY_MSG_HOOK* GUI_pfKeyMsgHook;
GUI_KEY_MSG_HOOK* GUI_SetKeyMsgHook(GUI_KEY_MSG_HOOK* pHook);

 
int  GUI_GetKey(void);
int  GUI_WaitKey(void);
void GUI_StoreKey(int c);
void GUI_ClearKeyBuffer(void);




 
void GUI_WaitEvent(void);




 

void GUI_PID_StoreState(const GUI_PID_STATE *pState);
int  GUI_PID_GetState  (      GUI_PID_STATE *pState);




 
int  GUI_MOUSE_GetState  (      GUI_PID_STATE *pState);
void GUI_MOUSE_StoreState(const GUI_PID_STATE *pState);




 

int  GUI_TOUCH_GetState     (GUI_PID_STATE *pState);
void GUI_TOUCH_GetUnstable  (int* px, int* py);   
void GUI_TOUCH_StoreState   (int x, int y);
void GUI_TOUCH_StoreStateEx (const GUI_PID_STATE *pState);
void GUI_TOUCH_StoreUnstable(int x, int y);





 
void GUI_MOUSE_DRIVER_PS2_Init(void);                
void GUI_MOUSE_DRIVER_PS2_OnRx(unsigned char Data);





 
void GUI_TOUCH_Exec(void);
int  GUI_TOUCH_Calibrate(int Coord, int Log0, int Log1, int Phys0, int Phys1);
void GUI_TOUCH_SetDefaultCalibration(void);
int  GUI_TOUCH_GetxPhys(void);     
int  GUI_TOUCH_GetyPhys(void);     
void GUI_TOUCH_GetCalData(int Coord, int* pMin,int* pMax);













 

void GUI_TOUCH_X_ActivateX(void);
void GUI_TOUCH_X_ActivateY(void);
void GUI_TOUCH_X_Disable(void);
int  GUI_TOUCH_X_MeasureX(void);
int  GUI_TOUCH_X_MeasureY(void);






 

extern const GUI_BITMAP_METHODS GUI_BitmapMethodsRLE4;
extern const GUI_BITMAP_METHODS GUI_BitmapMethodsRLE8;
extern const GUI_BITMAP_METHODS GUI_BitmapMethods565;
extern const GUI_BITMAP_METHODS GUI_BitmapMethodsM565;














 

#line 1402 "..\\code\\GUI\\GUI_inc\\gui.h"






 

#line 1420 "..\\code\\GUI\\GUI_inc\\gui.h"



 
#line 12 "..\\code\\menu\\my_menu.c"
#line 1 "..\\code\\TFT\\TFT_ILI9328\\ili9325.h"
#line 1 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"







































 



 



 
    






  


 
  


 

#line 75 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"


















 





#line 109 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"







            
#line 124 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"





 






 
#line 145 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 



 



 
#line 164 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"




 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      

 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMPER_IRQn                 = 2,       
  RTC_IRQn                    = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Channel1_IRQn          = 11,      
  DMA1_Channel2_IRQn          = 12,      
  DMA1_Channel3_IRQn          = 13,      
  DMA1_Channel4_IRQn          = 14,      
  DMA1_Channel5_IRQn          = 15,      
  DMA1_Channel6_IRQn          = 16,      
  DMA1_Channel7_IRQn          = 17,      

#line 223 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 244 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 272 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 298 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"


  ADC1_2_IRQn                 = 18,      
  USB_HP_CAN1_TX_IRQn         = 19,      
  USB_LP_CAN1_RX0_IRQn        = 20,      
  CAN1_RX1_IRQn               = 21,      
  CAN1_SCE_IRQn               = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_IRQn               = 24,      
  TIM1_UP_IRQn                = 25,      
  TIM1_TRG_COM_IRQn           = 26,      
  TIM1_CC_IRQn                = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTCAlarm_IRQn               = 41,      
  USBWakeUp_IRQn              = 42,      
  TIM8_BRK_IRQn               = 43,      
  TIM8_UP_IRQn                = 44,      
  TIM8_TRG_COM_IRQn           = 45,      
  TIM8_CC_IRQn                = 46,      
  ADC3_IRQn                   = 47,      
  FSMC_IRQn                   = 48,      
  SDIO_IRQn                   = 49,      
  TIM5_IRQn                   = 50,      
  SPI3_IRQn                   = 51,      
  UART4_IRQn                  = 52,      
  UART5_IRQn                  = 53,      
  TIM6_IRQn                   = 54,      
  TIM7_IRQn                   = 55,      
  DMA2_Channel1_IRQn          = 56,      
  DMA2_Channel2_IRQn          = 57,      
  DMA2_Channel3_IRQn          = 58,      
  DMA2_Channel4_5_IRQn        = 59       


#line 383 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 428 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 474 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"
} IRQn_Type;



 

#line 1 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"
 







 

























 
























 




 


 

 













#line 110 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"


 







#line 145 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"

#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"
 
 





 










#line 26 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"







 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     
typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;

     
typedef   signed       __int64 intmax_t;
typedef unsigned       __int64 uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     


     


     


     

     


     


     


     

     



     



     


     
    
 



#line 197 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"

     







     










     











#line 261 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"



 



#line 147 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"
#line 1 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cmInstr.h"
 







 

























 






 



 


 









 







 







 






 








 







 







 









 









 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}








 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}










 










 











 









 









 









 











 











 











 







 










 










 









 





#line 684 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cmInstr.h"

   

#line 148 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"
#line 1 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cmFunc.h"
 







 

























 






 



 


 





 
 






 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}







 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}







 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}







 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}







 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}







 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}







 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}







 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}







 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}







 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}







 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}








 







 








 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}







 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xff);
}







 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}







 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1);
}




#line 307 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cmFunc.h"


#line 634 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cmFunc.h"

 

#line 149 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"








 
#line 179 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"

 






 
#line 195 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"

 












 


 





 


 
typedef union
{
  struct
  {

    uint32_t _reserved0:27;               





    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;



 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;



 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       

    uint32_t _reserved0:15;               





    uint32_t T:1;                         
    uint32_t IT:2;                        
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;



 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t FPCA:1;                      
    uint32_t _reserved0:29;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 






 


 
typedef struct
{
  volatile uint32_t ISER[8];                  
       uint32_t RESERVED0[24];
  volatile uint32_t ICER[8];                  
       uint32_t RSERVED1[24];
  volatile uint32_t ISPR[8];                  
       uint32_t RESERVED2[24];
  volatile uint32_t ICPR[8];                  
       uint32_t RESERVED3[24];
  volatile uint32_t IABR[8];                  
       uint32_t RESERVED4[56];
  volatile uint8_t  IP[240];                  
       uint32_t RESERVED5[644];
  volatile  uint32_t STIR;                     
}  NVIC_Type;

 



 






 


 
typedef struct
{
  volatile const  uint32_t CPUID;                    
  volatile uint32_t ICSR;                     
  volatile uint32_t VTOR;                     
  volatile uint32_t AIRCR;                    
  volatile uint32_t SCR;                      
  volatile uint32_t CCR;                      
  volatile uint8_t  SHP[12];                  
  volatile uint32_t SHCSR;                    
  volatile uint32_t CFSR;                     
  volatile uint32_t HFSR;                     
  volatile uint32_t DFSR;                     
  volatile uint32_t MMFAR;                    
  volatile uint32_t BFAR;                     
  volatile uint32_t AFSR;                     
  volatile const  uint32_t PFR[2];                   
  volatile const  uint32_t DFR;                      
  volatile const  uint32_t ADR;                      
  volatile const  uint32_t MMFR[4];                  
  volatile const  uint32_t ISAR[5];                  
       uint32_t RESERVED0[5];
  volatile uint32_t CPACR;                    
} SCB_Type;

 















 






























 




#line 422 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"

 





















 









 


















 










































 









 









 















 






 


 
typedef struct
{
       uint32_t RESERVED0[1];
  volatile const  uint32_t ICTR;                     



       uint32_t RESERVED1[1];

} SCnSCB_Type;

 



 










 






 


 
typedef struct
{
  volatile uint32_t CTRL;                     
  volatile uint32_t LOAD;                     
  volatile uint32_t VAL;                      
  volatile const  uint32_t CALIB;                    
} SysTick_Type;

 












 



 



 









 






 


 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                   
    volatile  uint16_t   u16;                  
    volatile  uint32_t   u32;                  
  }  PORT [32];                           
       uint32_t RESERVED0[864];
  volatile uint32_t TER;                      
       uint32_t RESERVED1[15];
  volatile uint32_t TPR;                      
       uint32_t RESERVED2[15];
  volatile uint32_t TCR;                      
       uint32_t RESERVED3[29];
  volatile  uint32_t IWR;                      
  volatile const  uint32_t IRR;                      
  volatile uint32_t IMCR;                     
       uint32_t RESERVED4[43];
  volatile  uint32_t LAR;                      
  volatile const  uint32_t LSR;                      
       uint32_t RESERVED5[6];
  volatile const  uint32_t PID4;                     
  volatile const  uint32_t PID5;                     
  volatile const  uint32_t PID6;                     
  volatile const  uint32_t PID7;                     
  volatile const  uint32_t PID0;                     
  volatile const  uint32_t PID1;                     
  volatile const  uint32_t PID2;                     
  volatile const  uint32_t PID3;                     
  volatile const  uint32_t CID0;                     
  volatile const  uint32_t CID1;                     
  volatile const  uint32_t CID2;                     
  volatile const  uint32_t CID3;                     
} ITM_Type;

 



 



























 



 



 



 









   






 


 
typedef struct
{
  volatile uint32_t CTRL;                     
  volatile uint32_t CYCCNT;                   
  volatile uint32_t CPICNT;                   
  volatile uint32_t EXCCNT;                   
  volatile uint32_t SLEEPCNT;                 
  volatile uint32_t LSUCNT;                   
  volatile uint32_t FOLDCNT;                  
  volatile const  uint32_t PCSR;                     
  volatile uint32_t COMP0;                    
  volatile uint32_t MASK0;                    
  volatile uint32_t FUNCTION0;                
       uint32_t RESERVED0[1];
  volatile uint32_t COMP1;                    
  volatile uint32_t MASK1;                    
  volatile uint32_t FUNCTION1;                
       uint32_t RESERVED1[1];
  volatile uint32_t COMP2;                    
  volatile uint32_t MASK2;                    
  volatile uint32_t FUNCTION2;                
       uint32_t RESERVED2[1];
  volatile uint32_t COMP3;                    
  volatile uint32_t MASK3;                    
  volatile uint32_t FUNCTION3;                
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   






 


 
typedef struct
{
  volatile uint32_t SSPSR;                    
  volatile uint32_t CSPSR;                    
       uint32_t RESERVED0[2];
  volatile uint32_t ACPR;                     
       uint32_t RESERVED1[55];
  volatile uint32_t SPPR;                     
       uint32_t RESERVED2[131];
  volatile const  uint32_t FFSR;                     
  volatile uint32_t FFCR;                     
  volatile const  uint32_t FSCR;                     
       uint32_t RESERVED3[759];
  volatile const  uint32_t TRIGGER;                  
  volatile const  uint32_t FIFO0;                    
  volatile const  uint32_t ITATBCTR2;                
       uint32_t RESERVED4[1];
  volatile const  uint32_t ITATBCTR0;                
  volatile const  uint32_t FIFO1;                    
  volatile uint32_t ITCTRL;                   
       uint32_t RESERVED5[39];
  volatile uint32_t CLAIMSET;                 
  volatile uint32_t CLAIMCLR;                 
       uint32_t RESERVED7[8];
  volatile const  uint32_t DEVID;                    
  volatile const  uint32_t DEVTYPE;                  
} TPI_Type;

 



 



 












 






 



 





















 



 





















 



 



 


















 






   


#line 1133 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"






 


 
typedef struct
{
  volatile uint32_t DHCSR;                    
  volatile  uint32_t DCRSR;                    
  volatile uint32_t DCRDR;                    
  volatile uint32_t DEMCR;                    
} CoreDebug_Type;

 




































 






 







































 






 

 
#line 1253 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"

#line 1262 "C:\\Keil\\ARM\\CMSIS\\Include\\core_cm3.h"






 










 

 



 




 










 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07);                

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((0xFFFFUL << 16) | (7UL << 8));              
  reg_value  =  (reg_value                                 |
                ((uint32_t)0x5FA << 16) |
                (PriorityGroupTmp << 8));                                      
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}







 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8)) >> 8);    
}







 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}







 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}











 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}







 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}







 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}










 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}










 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - 4)) & 0xff); }  
  else {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[(uint32_t)(IRQn)] = ((priority << (8 - 4)) & 0xff);    }         
}












 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - 4)));  }  
  else {
    return((uint32_t)(((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[(uint32_t)(IRQn)]           >> (8 - 4)));  }  
}













 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;

  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}













 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;

  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}





 
static __inline void NVIC_SystemReset(void)
{
  __dsb(0xF);                                                     
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = ((0x5FA << 16)      |
                 (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8)) |
                 (1UL << 2));                    
  __dsb(0xF);                                                      
  while(1);                                                     
}

 



 




 

















 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1) > (0xFFFFFFUL << 0))  return (1);       

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = ticks - 1;                                   
  NVIC_SetPriority (SysTick_IRQn, (1<<4) - 1);   
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0;                                           
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2) |
                   (1UL << 1)   |
                   (1UL << 0);                     
  return (0);                                                   
}



 



 




 

extern volatile int32_t ITM_RxBuffer;                     












 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if ((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL << 0))                  &&       
      (((ITM_Type *) (0xE0000000UL) )->TER & (1UL << 0)        )                    )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0].u32 == 0);
    ((ITM_Type *) (0xE0000000UL) )->PORT[0].u8 = (uint8_t) ch;
  }
  return (ch);
}








 
static __inline int32_t ITM_ReceiveChar (void) {
  int32_t ch = -1;                            

  if (ITM_RxBuffer != 0x5AA55AA5) {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5;        
  }

  return (ch);
}








 
static __inline int32_t ITM_CheckChar (void) {

  if (ITM_RxBuffer == 0x5AA55AA5) {
    return (0);                                  
  } else {
    return (1);                                  
  }
}

 





#line 481 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"
#line 1 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\system_stm32f10x.h"



















 



 



   
  


 









 



 




 

extern uint32_t SystemCoreClock;           



 



 



 



 



 



 
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


 









 
  


   
 
#line 482 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"
#line 483 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



   

 
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;   
typedef const int16_t sc16;   
typedef const int8_t sc8;    

typedef volatile int32_t  vs32;
typedef volatile int16_t  vs16;
typedef volatile int8_t   vs8;

typedef volatile const int32_t vsc32;   
typedef volatile const int16_t vsc16;   
typedef volatile const int8_t vsc8;    

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;   
typedef const uint16_t uc16;   
typedef const uint8_t uc8;    

typedef volatile uint32_t  vu32;
typedef volatile uint16_t vu16;
typedef volatile uint8_t  vu8;

typedef volatile const uint32_t vuc32;   
typedef volatile const uint16_t vuc16;   
typedef volatile const uint8_t vuc8;    

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;


typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

 





 



    



 

typedef struct
{
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
} ADC_TypeDef;



 

typedef struct
{
  uint32_t  RESERVED0;
  volatile uint16_t DR1;
  uint16_t  RESERVED1;
  volatile uint16_t DR2;
  uint16_t  RESERVED2;
  volatile uint16_t DR3;
  uint16_t  RESERVED3;
  volatile uint16_t DR4;
  uint16_t  RESERVED4;
  volatile uint16_t DR5;
  uint16_t  RESERVED5;
  volatile uint16_t DR6;
  uint16_t  RESERVED6;
  volatile uint16_t DR7;
  uint16_t  RESERVED7;
  volatile uint16_t DR8;
  uint16_t  RESERVED8;
  volatile uint16_t DR9;
  uint16_t  RESERVED9;
  volatile uint16_t DR10;
  uint16_t  RESERVED10; 
  volatile uint16_t RTCCR;
  uint16_t  RESERVED11;
  volatile uint16_t CR;
  uint16_t  RESERVED12;
  volatile uint16_t CSR;
  uint16_t  RESERVED13[5];
  volatile uint16_t DR11;
  uint16_t  RESERVED14;
  volatile uint16_t DR12;
  uint16_t  RESERVED15;
  volatile uint16_t DR13;
  uint16_t  RESERVED16;
  volatile uint16_t DR14;
  uint16_t  RESERVED17;
  volatile uint16_t DR15;
  uint16_t  RESERVED18;
  volatile uint16_t DR16;
  uint16_t  RESERVED19;
  volatile uint16_t DR17;
  uint16_t  RESERVED20;
  volatile uint16_t DR18;
  uint16_t  RESERVED21;
  volatile uint16_t DR19;
  uint16_t  RESERVED22;
  volatile uint16_t DR20;
  uint16_t  RESERVED23;
  volatile uint16_t DR21;
  uint16_t  RESERVED24;
  volatile uint16_t DR22;
  uint16_t  RESERVED25;
  volatile uint16_t DR23;
  uint16_t  RESERVED26;
  volatile uint16_t DR24;
  uint16_t  RESERVED27;
  volatile uint16_t DR25;
  uint16_t  RESERVED28;
  volatile uint16_t DR26;
  uint16_t  RESERVED29;
  volatile uint16_t DR27;
  uint16_t  RESERVED30;
  volatile uint16_t DR28;
  uint16_t  RESERVED31;
  volatile uint16_t DR29;
  uint16_t  RESERVED32;
  volatile uint16_t DR30;
  uint16_t  RESERVED33; 
  volatile uint16_t DR31;
  uint16_t  RESERVED34;
  volatile uint16_t DR32;
  uint16_t  RESERVED35;
  volatile uint16_t DR33;
  uint16_t  RESERVED36;
  volatile uint16_t DR34;
  uint16_t  RESERVED37;
  volatile uint16_t DR35;
  uint16_t  RESERVED38;
  volatile uint16_t DR36;
  uint16_t  RESERVED39;
  volatile uint16_t DR37;
  uint16_t  RESERVED40;
  volatile uint16_t DR38;
  uint16_t  RESERVED41;
  volatile uint16_t DR39;
  uint16_t  RESERVED42;
  volatile uint16_t DR40;
  uint16_t  RESERVED43;
  volatile uint16_t DR41;
  uint16_t  RESERVED44;
  volatile uint16_t DR42;
  uint16_t  RESERVED45;    
} BKP_TypeDef;
  


 

typedef struct
{
  volatile uint32_t TIR;
  volatile uint32_t TDTR;
  volatile uint32_t TDLR;
  volatile uint32_t TDHR;
} CAN_TxMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t RIR;
  volatile uint32_t RDTR;
  volatile uint32_t RDLR;
  volatile uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t FR1;
  volatile uint32_t FR2;
} CAN_FilterRegister_TypeDef;



 
  
typedef struct
{
  volatile uint32_t MCR;
  volatile uint32_t MSR;
  volatile uint32_t TSR;
  volatile uint32_t RF0R;
  volatile uint32_t RF1R;
  volatile uint32_t IER;
  volatile uint32_t ESR;
  volatile uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  volatile uint32_t FMR;
  volatile uint32_t FM1R;
  uint32_t  RESERVED2;
  volatile uint32_t FS1R;
  uint32_t  RESERVED3;
  volatile uint32_t FFA1R;
  uint32_t  RESERVED4;
  volatile uint32_t FA1R;
  uint32_t  RESERVED5[8];

  CAN_FilterRegister_TypeDef sFilterRegister[14];



} CAN_TypeDef;



 
typedef struct
{
  volatile uint32_t CFGR;
  volatile uint32_t OAR;
  volatile uint32_t PRES;
  volatile uint32_t ESR;
  volatile uint32_t CSR;
  volatile uint32_t TXD;
  volatile uint32_t RXD;  
} CEC_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;
  volatile uint8_t  IDR;
  uint8_t   RESERVED0;
  uint16_t  RESERVED1;
  volatile uint32_t CR;
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;



} DAC_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;	
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t MACCR;
  volatile uint32_t MACFFR;
  volatile uint32_t MACHTHR;
  volatile uint32_t MACHTLR;
  volatile uint32_t MACMIIAR;
  volatile uint32_t MACMIIDR;
  volatile uint32_t MACFCR;
  volatile uint32_t MACVLANTR;              
       uint32_t RESERVED0[2];
  volatile uint32_t MACRWUFFR;              
  volatile uint32_t MACPMTCSR;
       uint32_t RESERVED1[2];
  volatile uint32_t MACSR;                  
  volatile uint32_t MACIMR;
  volatile uint32_t MACA0HR;
  volatile uint32_t MACA0LR;
  volatile uint32_t MACA1HR;
  volatile uint32_t MACA1LR;
  volatile uint32_t MACA2HR;
  volatile uint32_t MACA2LR;
  volatile uint32_t MACA3HR;
  volatile uint32_t MACA3LR;                
       uint32_t RESERVED2[40];
  volatile uint32_t MMCCR;                  
  volatile uint32_t MMCRIR;
  volatile uint32_t MMCTIR;
  volatile uint32_t MMCRIMR;
  volatile uint32_t MMCTIMR;                
       uint32_t RESERVED3[14];
  volatile uint32_t MMCTGFSCCR;             
  volatile uint32_t MMCTGFMSCCR;
       uint32_t RESERVED4[5];
  volatile uint32_t MMCTGFCR;
       uint32_t RESERVED5[10];
  volatile uint32_t MMCRFCECR;
  volatile uint32_t MMCRFAECR;
       uint32_t RESERVED6[10];
  volatile uint32_t MMCRGUFCR;
       uint32_t RESERVED7[334];
  volatile uint32_t PTPTSCR;
  volatile uint32_t PTPSSIR;
  volatile uint32_t PTPTSHR;
  volatile uint32_t PTPTSLR;
  volatile uint32_t PTPTSHUR;
  volatile uint32_t PTPTSLUR;
  volatile uint32_t PTPTSAR;
  volatile uint32_t PTPTTHR;
  volatile uint32_t PTPTTLR;
       uint32_t RESERVED8[567];
  volatile uint32_t DMABMR;
  volatile uint32_t DMATPDR;
  volatile uint32_t DMARPDR;
  volatile uint32_t DMARDLAR;
  volatile uint32_t DMATDLAR;
  volatile uint32_t DMASR;
  volatile uint32_t DMAOMR;
  volatile uint32_t DMAIER;
  volatile uint32_t DMAMFBOCR;
       uint32_t RESERVED9[9];
  volatile uint32_t DMACHTDR;
  volatile uint32_t DMACHRDR;
  volatile uint32_t DMACHTBAR;
  volatile uint32_t DMACHRBAR;
} ETH_TypeDef;



 

typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t AR;
  volatile uint32_t RESERVED;
  volatile uint32_t OBR;
  volatile uint32_t WRPR;
#line 922 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"
} FLASH_TypeDef;



 
  
typedef struct
{
  volatile uint16_t RDP;
  volatile uint16_t USER;
  volatile uint16_t Data0;
  volatile uint16_t Data1;
  volatile uint16_t WRP0;
  volatile uint16_t WRP1;
  volatile uint16_t WRP2;
  volatile uint16_t WRP3;
} OB_TypeDef;



 

typedef struct
{
  volatile uint32_t BTCR[8];   
} FSMC_Bank1_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t BWTR[7];
} FSMC_Bank1E_TypeDef;



 
  
typedef struct
{
  volatile uint32_t PCR2;
  volatile uint32_t SR2;
  volatile uint32_t PMEM2;
  volatile uint32_t PATT2;
  uint32_t  RESERVED0;   
  volatile uint32_t ECCR2; 
} FSMC_Bank2_TypeDef;  



 
  
typedef struct
{
  volatile uint32_t PCR3;
  volatile uint32_t SR3;
  volatile uint32_t PMEM3;
  volatile uint32_t PATT3;
  uint32_t  RESERVED0;   
  volatile uint32_t ECCR3; 
} FSMC_Bank3_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t PCR4;
  volatile uint32_t SR4;
  volatile uint32_t PMEM4;
  volatile uint32_t PATT4;
  volatile uint32_t PIO4; 
} FSMC_Bank4_TypeDef; 



 

typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t EVCR;
  volatile uint32_t MAPR;
  volatile uint32_t EXTICR[4];
  uint32_t RESERVED0;
  volatile uint32_t MAPR2;  
} AFIO_TypeDef;


 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t OAR1;
  uint16_t  RESERVED2;
  volatile uint16_t OAR2;
  uint16_t  RESERVED3;
  volatile uint16_t DR;
  uint16_t  RESERVED4;
  volatile uint16_t SR1;
  uint16_t  RESERVED5;
  volatile uint16_t SR2;
  uint16_t  RESERVED6;
  volatile uint16_t CCR;
  uint16_t  RESERVED7;
  volatile uint16_t TRISE;
  uint16_t  RESERVED8;
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
} IWDG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CSR;
} PWR_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;










} RCC_TypeDef;



 

typedef struct
{
  volatile uint16_t CRH;
  uint16_t  RESERVED0;
  volatile uint16_t CRL;
  uint16_t  RESERVED1;
  volatile uint16_t PRLH;
  uint16_t  RESERVED2;
  volatile uint16_t PRLL;
  uint16_t  RESERVED3;
  volatile uint16_t DIVH;
  uint16_t  RESERVED4;
  volatile uint16_t DIVL;
  uint16_t  RESERVED5;
  volatile uint16_t CNTH;
  uint16_t  RESERVED6;
  volatile uint16_t CNTL;
  uint16_t  RESERVED7;
  volatile uint16_t ALRH;
  uint16_t  RESERVED8;
  volatile uint16_t ALRL;
  uint16_t  RESERVED9;
} RTC_TypeDef;



 

typedef struct
{
  volatile uint32_t POWER;
  volatile uint32_t CLKCR;
  volatile uint32_t ARG;
  volatile uint32_t CMD;
  volatile const uint32_t RESPCMD;
  volatile const uint32_t RESP1;
  volatile const uint32_t RESP2;
  volatile const uint32_t RESP3;
  volatile const uint32_t RESP4;
  volatile uint32_t DTIMER;
  volatile uint32_t DLEN;
  volatile uint32_t DCTRL;
  volatile const uint32_t DCOUNT;
  volatile const uint32_t STA;
  volatile uint32_t ICR;
  volatile uint32_t MASK;
  uint32_t  RESERVED0[2];
  volatile const uint32_t FIFOCNT;
  uint32_t  RESERVED1[13];
  volatile uint32_t FIFO;
} SDIO_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SR;
  uint16_t  RESERVED2;
  volatile uint16_t DR;
  uint16_t  RESERVED3;
  volatile uint16_t CRCPR;
  uint16_t  RESERVED4;
  volatile uint16_t RXCRCR;
  uint16_t  RESERVED5;
  volatile uint16_t TXCRCR;
  uint16_t  RESERVED6;
  volatile uint16_t I2SCFGR;
  uint16_t  RESERVED7;
  volatile uint16_t I2SPR;
  uint16_t  RESERVED8;  
} SPI_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SMCR;
  uint16_t  RESERVED2;
  volatile uint16_t DIER;
  uint16_t  RESERVED3;
  volatile uint16_t SR;
  uint16_t  RESERVED4;
  volatile uint16_t EGR;
  uint16_t  RESERVED5;
  volatile uint16_t CCMR1;
  uint16_t  RESERVED6;
  volatile uint16_t CCMR2;
  uint16_t  RESERVED7;
  volatile uint16_t CCER;
  uint16_t  RESERVED8;
  volatile uint16_t CNT;
  uint16_t  RESERVED9;
  volatile uint16_t PSC;
  uint16_t  RESERVED10;
  volatile uint16_t ARR;
  uint16_t  RESERVED11;
  volatile uint16_t RCR;
  uint16_t  RESERVED12;
  volatile uint16_t CCR1;
  uint16_t  RESERVED13;
  volatile uint16_t CCR2;
  uint16_t  RESERVED14;
  volatile uint16_t CCR3;
  uint16_t  RESERVED15;
  volatile uint16_t CCR4;
  uint16_t  RESERVED16;
  volatile uint16_t BDTR;
  uint16_t  RESERVED17;
  volatile uint16_t DCR;
  uint16_t  RESERVED18;
  volatile uint16_t DMAR;
  uint16_t  RESERVED19;
} TIM_TypeDef;



 
 
typedef struct
{
  volatile uint16_t SR;
  uint16_t  RESERVED0;
  volatile uint16_t DR;
  uint16_t  RESERVED1;
  volatile uint16_t BRR;
  uint16_t  RESERVED2;
  volatile uint16_t CR1;
  uint16_t  RESERVED3;
  volatile uint16_t CR2;
  uint16_t  RESERVED4;
  volatile uint16_t CR3;
  uint16_t  RESERVED5;
  volatile uint16_t GTPR;
  uint16_t  RESERVED6;
} USART_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;



 
  


 











 




#line 1314 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 1337 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



#line 1356 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"




















 
  


   

#line 1456 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 



 
  
  

 
    
 
 
 

 
 
 
 
 

 



 



 


 
 
 
 
 

 











 
#line 1517 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"




 





 
 
 
 
 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 





 



 






 
 
 
 
 

 
#line 1693 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 1700 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
 








 








 






#line 1736 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 











 











 













 






#line 1852 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"




#line 1872 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 





#line 1885 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 1904 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 1913 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 1921 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



















#line 1946 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"












 













#line 1978 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"





#line 1992 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 1999 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 2009 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"











 


















#line 2045 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2053 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



















#line 2078 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"












 













#line 2110 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"





#line 2124 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 2131 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 2141 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"











 








 








   
#line 2180 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 2275 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 2302 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"
 
 
 
 
 
 

 




































































 




































































 
#line 2464 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2482 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2500 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 2517 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2535 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2554 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 

 






 
#line 2581 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"






 








 









 








 








 









 










 




#line 2656 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 










#line 2687 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 





 
#line 2702 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2711 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

   
#line 2720 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2729 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 





 
#line 2744 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2753 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

   
#line 2762 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2771 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 





 
#line 2786 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2795 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

   
#line 2804 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2813 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 





 
#line 2828 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2837 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

   
#line 2846 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2855 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 2864 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 2873 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 2883 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
 
 
 
 

 





 


 


 




 
 
 
 
 

 
#line 2947 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 2982 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3017 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3052 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3087 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 





 





 





 





 





 





 





 





 






 
#line 3154 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 



 









 
#line 3178 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"




 




 
#line 3194 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 





 
#line 3216 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
 





 
#line 3231 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"
 
#line 3238 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 




 






 


 


 


 
 
 
 
 

 
#line 3287 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3309 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3331 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3353 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3375 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3397 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
 
 
 
 

 
#line 3433 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3463 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3473 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"















 
#line 3497 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"















 
#line 3521 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"















 
#line 3545 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"















 
#line 3569 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"















 
#line 3593 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"















 
#line 3617 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"















 


 


 


 


 


 


 


 


 


 



 


 


 



 


 


 


 



 


 


 


 


 
 
 
 
 

 






 
#line 3718 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3727 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"















  
 
#line 3750 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"


















 








































 


















































 


 


 


 


 


 


 
#line 3885 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3892 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3899 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3906 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"







 
#line 3920 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3927 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3934 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3941 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3948 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3955 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 3963 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3970 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3977 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3984 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3991 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 3998 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 4006 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 4013 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 4020 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 4027 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"





 


 


 


 


 



 
 
 
 
 

 









































 



 


 


 


 


 


 


 



 



 



 


 


 



 
 
 
 
 
 





 






 


 
#line 4169 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 4179 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 


 


 
 
 
 
 

 
















 









#line 4227 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 

























 
#line 4270 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 4284 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 4294 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 




























 





















 




























 





















 
#line 4413 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
#line 4448 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"





#line 4459 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 4467 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 4474 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 


 
 
 
 
 

 




 
#line 4496 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
 
 
 
 

 


 





 


 



 
 
 
 
 

 
#line 4558 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 
#line 4570 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"







 


 
 
 
 
 

 











#line 4608 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 











#line 4631 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 











#line 4654 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 











#line 4677 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 








































 








































 








































 








































 


































 


































 


































 


































 



























 



























 



























 
#line 5074 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5083 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5092 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5103 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5113 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5123 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5133 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5144 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5154 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5164 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5174 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5185 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5195 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5205 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5215 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5226 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5236 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5246 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5256 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5267 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5277 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5287 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5297 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5308 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5318 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5328 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5338 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5349 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5359 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5369 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

#line 5379 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 


 


 
 
 
 
 

 




 












 


 






#line 5427 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
















 


 
#line 5497 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5512 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5538 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 


 


 
 
 
 
 

 
 























 























 























 























 























 























 























 























 
 
#line 5759 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 5771 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 






 
#line 5788 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



     


 
 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


#line 5932 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 5944 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 5956 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 5968 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 5980 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 5992 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6004 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6016 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 

 


#line 6030 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6042 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6054 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6066 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6078 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6090 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6102 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6114 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6126 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6138 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6150 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6162 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6174 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6186 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6198 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 


#line 6210 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 
 
 
 
 

 
 
#line 6230 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6241 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6259 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"











 





 





 
#line 6297 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 












 
#line 6318 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
 






 




 





 





 






 




 





 





 






   




 





 





 





 




 





 





 





 




 





 





 
 


 
#line 6458 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6475 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6492 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6509 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6543 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6577 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6611 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6645 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6679 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6713 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6747 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6781 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6815 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6849 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6883 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6917 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6951 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 6985 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7019 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7053 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7087 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7121 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7155 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7189 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7223 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7257 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7291 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7325 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7359 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7393 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7427 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7461 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
 
 
 
 

 









#line 7488 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7496 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7506 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 


 


 


 


 





















 




 
 
 
 
 

 
#line 7567 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7576 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"







 



#line 7597 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 



 


 
#line 7622 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7632 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 




 


 
 
 
 
 

 
#line 7658 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 


 



 
#line 7682 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7691 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"







 
#line 7711 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
#line 7722 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 
 
 
 
 

 


#line 7751 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 









#line 7785 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 
 
 
 
 

 









 


 


 





 
#line 7825 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"

 


 









 


 

 



 



 



 



 



 



 



 



#line 8289 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 

 

  

#line 1 "..\\code\\user\\stm32f10x_conf.h"


















  

 



 
 
#line 1 "..\\FWlib\\inc\\stm32f10x_adc.h"




















 

 







 
#line 1 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"







































 



 



 
    
#line 8329 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"



 

  

 

 
#line 33 "..\\FWlib\\inc\\stm32f10x_adc.h"



 



 



 



 

typedef struct
{
  uint32_t ADC_Mode;                      

 

  FunctionalState ADC_ScanConvMode;       

 

  FunctionalState ADC_ContinuousConvMode; 

 

  uint32_t ADC_ExternalTrigConv;          

 

  uint32_t ADC_DataAlign;                 
 

  uint8_t ADC_NbrOfChannel;               

 
}ADC_InitTypeDef;


 



 










 

#line 104 "..\\FWlib\\inc\\stm32f10x_adc.h"

#line 115 "..\\FWlib\\inc\\stm32f10x_adc.h"


 



 

#line 129 "..\\FWlib\\inc\\stm32f10x_adc.h"




#line 139 "..\\FWlib\\inc\\stm32f10x_adc.h"

#line 154 "..\\FWlib\\inc\\stm32f10x_adc.h"


 



 







 



 

#line 192 "..\\FWlib\\inc\\stm32f10x_adc.h"




#line 205 "..\\FWlib\\inc\\stm32f10x_adc.h"


 



 

#line 229 "..\\FWlib\\inc\\stm32f10x_adc.h"


 



 

















#line 266 "..\\FWlib\\inc\\stm32f10x_adc.h"


 



 

#line 282 "..\\FWlib\\inc\\stm32f10x_adc.h"


 



 

#line 297 "..\\FWlib\\inc\\stm32f10x_adc.h"

#line 305 "..\\FWlib\\inc\\stm32f10x_adc.h"


 



 











 



 

#line 338 "..\\FWlib\\inc\\stm32f10x_adc.h"


 



 





 



 





 



 





 



 





  




 




 



 





 



 





 



 



 



 



 

void ADC_DeInit(ADC_TypeDef* ADCx);
void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ITConfig(ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState);
void ADC_ResetCalibration(ADC_TypeDef* ADCx);
FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx);
void ADC_StartCalibration(ADC_TypeDef* ADCx);
FlagStatus ADC_GetCalibrationStatus(ADC_TypeDef* ADCx);
void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx);
void ADC_DiscModeChannelCountConfig(ADC_TypeDef* ADCx, uint8_t Number);
void ADC_DiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_ExternalTrigConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
uint16_t ADC_GetConversionValue(ADC_TypeDef* ADCx);
uint32_t ADC_GetDualModeConversionValue(void);
void ADC_AutoInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_InjectedDiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ExternalTrigInjectedConvConfig(ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConv);
void ADC_ExternalTrigInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartInjectedConvCmdStatus(ADC_TypeDef* ADCx);
void ADC_InjectedChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_InjectedSequencerLengthConfig(ADC_TypeDef* ADCx, uint8_t Length);
void ADC_SetInjectedOffset(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel, uint16_t Offset);
uint16_t ADC_GetInjectedConversionValue(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel);
void ADC_AnalogWatchdogCmd(ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog);
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* ADCx, uint16_t HighThreshold, uint16_t LowThreshold);
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel);
void ADC_TempSensorVrefintCmd(FunctionalState NewState);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
void ADC_ClearFlag(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
ITStatus ADC_GetITStatus(ADC_TypeDef* ADCx, uint16_t ADC_IT);
void ADC_ClearITPendingBit(ADC_TypeDef* ADCx, uint16_t ADC_IT);









 



 



 

 
#line 28 "..\\code\\user\\stm32f10x_conf.h"
#line 1 "..\\FWlib\\inc\\stm32f10x_bkp.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_bkp.h"



 



 



 



 



 



 







 



 

#line 78 "..\\FWlib\\inc\\stm32f10x_bkp.h"


 



 

#line 128 "..\\FWlib\\inc\\stm32f10x_bkp.h"

#line 143 "..\\FWlib\\inc\\stm32f10x_bkp.h"




 



 



 



 



 

void BKP_DeInit(void);
void BKP_TamperPinLevelConfig(uint16_t BKP_TamperPinLevel);
void BKP_TamperPinCmd(FunctionalState NewState);
void BKP_ITConfig(FunctionalState NewState);
void BKP_RTCOutputConfig(uint16_t BKP_RTCOutputSource);
void BKP_SetRTCCalibrationValue(uint8_t CalibrationValue);
void BKP_WriteBackupRegister(uint16_t BKP_DR, uint16_t Data);
uint16_t BKP_ReadBackupRegister(uint16_t BKP_DR);
FlagStatus BKP_GetFlagStatus(void);
void BKP_ClearFlag(void);
ITStatus BKP_GetITStatus(void);
void BKP_ClearITPendingBit(void);








 



 



 

 
#line 29 "..\\code\\user\\stm32f10x_conf.h"
 
 
 
 
#line 1 "..\\FWlib\\inc\\stm32f10x_dma.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_dma.h"



 



 



 



 

typedef struct
{
  uint32_t DMA_PeripheralBaseAddr;  

  uint32_t DMA_MemoryBaseAddr;      

  uint32_t DMA_DIR;                
 

  uint32_t DMA_BufferSize;         

 

  uint32_t DMA_PeripheralInc;      
 

  uint32_t DMA_MemoryInc;          
 

  uint32_t DMA_PeripheralDataSize; 
 

  uint32_t DMA_MemoryDataSize;     
 

  uint32_t DMA_Mode;               


 

  uint32_t DMA_Priority;           
 

  uint32_t DMA_M2M;                
 
}DMA_InitTypeDef;



 



 

#line 107 "..\\FWlib\\inc\\stm32f10x_dma.h"



 







 



 







 



 







 



 

#line 154 "..\\FWlib\\inc\\stm32f10x_dma.h"


 



 

#line 168 "..\\FWlib\\inc\\stm32f10x_dma.h"


 



 






 



 

#line 195 "..\\FWlib\\inc\\stm32f10x_dma.h"


 



 







 



 






#line 248 "..\\FWlib\\inc\\stm32f10x_dma.h"

#line 269 "..\\FWlib\\inc\\stm32f10x_dma.h"



#line 296 "..\\FWlib\\inc\\stm32f10x_dma.h"



 



 
#line 332 "..\\FWlib\\inc\\stm32f10x_dma.h"

#line 353 "..\\FWlib\\inc\\stm32f10x_dma.h"



#line 380 "..\\FWlib\\inc\\stm32f10x_dma.h"


 



 





 



 



 



 



 

void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx);
void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct);
void DMA_StructInit(DMA_InitTypeDef* DMA_InitStruct);
void DMA_Cmd(DMA_Channel_TypeDef* DMAy_Channelx, FunctionalState NewState);
void DMA_ITConfig(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT, FunctionalState NewState);
void DMA_SetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx, uint16_t DataNumber); 
uint16_t DMA_GetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx);
FlagStatus DMA_GetFlagStatus(uint32_t DMAy_FLAG);
void DMA_ClearFlag(uint32_t DMAy_FLAG);
ITStatus DMA_GetITStatus(uint32_t DMAy_IT);
void DMA_ClearITPendingBit(uint32_t DMAy_IT);








 



 



 

 
#line 34 "..\\code\\user\\stm32f10x_conf.h"
#line 1 "..\\FWlib\\inc\\stm32f10x_exti.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_exti.h"



 



 



 



 

typedef enum
{
  EXTI_Mode_Interrupt = 0x00,
  EXTI_Mode_Event = 0x04
}EXTIMode_TypeDef;





 

typedef enum
{
  EXTI_Trigger_Rising = 0x08,
  EXTI_Trigger_Falling = 0x0C,  
  EXTI_Trigger_Rising_Falling = 0x10
}EXTITrigger_TypeDef;






 

typedef struct
{
  uint32_t EXTI_Line;               
 
   
  EXTIMode_TypeDef EXTI_Mode;       
 

  EXTITrigger_TypeDef EXTI_Trigger; 
 

  FunctionalState EXTI_LineCmd;     
  
}EXTI_InitTypeDef;



 



 



 

#line 124 "..\\FWlib\\inc\\stm32f10x_exti.h"
                                          
#line 136 "..\\FWlib\\inc\\stm32f10x_exti.h"

                    


 



 



 



 



 

void EXTI_DeInit(void);
void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);
FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line);
void EXTI_ClearFlag(uint32_t EXTI_Line);
ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);
void EXTI_ClearITPendingBit(uint32_t EXTI_Line);








 



 



 

 
#line 35 "..\\code\\user\\stm32f10x_conf.h"
 
#line 1 "..\\FWlib\\inc\\stm32f10x_fsmc.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_fsmc.h"



 



 



 



 

typedef struct
{
  uint32_t FSMC_AddressSetupTime;       


 

  uint32_t FSMC_AddressHoldTime;        


 

  uint32_t FSMC_DataSetupTime;          


 

  uint32_t FSMC_BusTurnAroundDuration;  


 

  uint32_t FSMC_CLKDivision;            

 

  uint32_t FSMC_DataLatency;            





 

  uint32_t FSMC_AccessMode;             
 
}FSMC_NORSRAMTimingInitTypeDef;



 

typedef struct
{
  uint32_t FSMC_Bank;                
 

  uint32_t FSMC_DataAddressMux;      

 

  uint32_t FSMC_MemoryType;          

 

  uint32_t FSMC_MemoryDataWidth;     
 

  uint32_t FSMC_BurstAccessMode;     

 
                                       
  uint32_t FSMC_AsynchronousWait;     

 

  uint32_t FSMC_WaitSignalPolarity;  

 

  uint32_t FSMC_WrapMode;            

 

  uint32_t FSMC_WaitSignalActive;    


 

  uint32_t FSMC_WriteOperation;      
 

  uint32_t FSMC_WaitSignal;          

 

  uint32_t FSMC_ExtendedMode;        
 

  uint32_t FSMC_WriteBurst;          
  

  FSMC_NORSRAMTimingInitTypeDef* FSMC_ReadWriteTimingStruct;    

  FSMC_NORSRAMTimingInitTypeDef* FSMC_WriteTimingStruct;            
}FSMC_NORSRAMInitTypeDef;



 

typedef struct
{
  uint32_t FSMC_SetupTime;      



 

  uint32_t FSMC_WaitSetupTime;  



 

  uint32_t FSMC_HoldSetupTime;  




 

  uint32_t FSMC_HiZSetupTime;   



 
}FSMC_NAND_PCCARDTimingInitTypeDef;



 

typedef struct
{
  uint32_t FSMC_Bank;              
 

  uint32_t FSMC_Waitfeature;      
 

  uint32_t FSMC_MemoryDataWidth;  
 

  uint32_t FSMC_ECC;              
 

  uint32_t FSMC_ECCPageSize;      
 

  uint32_t FSMC_TCLRSetupTime;    

 

  uint32_t FSMC_TARSetupTime;     

  

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct;     

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct;  
}FSMC_NANDInitTypeDef;



 

typedef struct
{
  uint32_t FSMC_Waitfeature;    
 

  uint32_t FSMC_TCLRSetupTime;  

 

  uint32_t FSMC_TARSetupTime;   

  

  
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct;  

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct;    
  
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_IOSpaceTimingStruct;    
}FSMC_PCCARDInitTypeDef;



 



 



 






 



   




 



     



 



















 



 








 



 

#line 317 "..\\FWlib\\inc\\stm32f10x_fsmc.h"



 



 








 



 







 
  


 







 
  


 








 



 








 



 








 



 





                              


 



 







 



 









 



 







 



 





 



 





 



 





 



 





 



 





 



 





 



 

#line 521 "..\\FWlib\\inc\\stm32f10x_fsmc.h"



 



 
  


 



 








 




 








 



 

#line 577 "..\\FWlib\\inc\\stm32f10x_fsmc.h"



 



 





 



 





 



 





 



 





 



 





 



 





 



 

#line 653 "..\\FWlib\\inc\\stm32f10x_fsmc.h"


 



 

#line 669 "..\\FWlib\\inc\\stm32f10x_fsmc.h"





 



 



 



 



 



 

void FSMC_NORSRAMDeInit(uint32_t FSMC_Bank);
void FSMC_NANDDeInit(uint32_t FSMC_Bank);
void FSMC_PCCARDDeInit(void);
void FSMC_NORSRAMInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct);
void FSMC_NANDInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct);
void FSMC_PCCARDInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct);
void FSMC_NORSRAMStructInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct);
void FSMC_NANDStructInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct);
void FSMC_PCCARDStructInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct);
void FSMC_NORSRAMCmd(uint32_t FSMC_Bank, FunctionalState NewState);
void FSMC_NANDCmd(uint32_t FSMC_Bank, FunctionalState NewState);
void FSMC_PCCARDCmd(FunctionalState NewState);
void FSMC_NANDECCCmd(uint32_t FSMC_Bank, FunctionalState NewState);
uint32_t FSMC_GetECC(uint32_t FSMC_Bank);
void FSMC_ITConfig(uint32_t FSMC_Bank, uint32_t FSMC_IT, FunctionalState NewState);
FlagStatus FSMC_GetFlagStatus(uint32_t FSMC_Bank, uint32_t FSMC_FLAG);
void FSMC_ClearFlag(uint32_t FSMC_Bank, uint32_t FSMC_FLAG);
ITStatus FSMC_GetITStatus(uint32_t FSMC_Bank, uint32_t FSMC_IT);
void FSMC_ClearITPendingBit(uint32_t FSMC_Bank, uint32_t FSMC_IT);








 



 



  

 
#line 37 "..\\code\\user\\stm32f10x_conf.h"
#line 1 "..\\FWlib\\inc\\stm32f10x_gpio.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_gpio.h"



 



 



 

#line 53 "..\\FWlib\\inc\\stm32f10x_gpio.h"
                                     


 

typedef enum
{ 
  GPIO_Speed_10MHz = 1,
  GPIO_Speed_2MHz, 
  GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;





 

typedef enum
{ GPIO_Mode_AIN = 0x0,
  GPIO_Mode_IN_FLOATING = 0x04,
  GPIO_Mode_IPD = 0x28,
  GPIO_Mode_IPU = 0x48,
  GPIO_Mode_Out_OD = 0x14,
  GPIO_Mode_Out_PP = 0x10,
  GPIO_Mode_AF_OD = 0x1C,
  GPIO_Mode_AF_PP = 0x18
}GPIOMode_TypeDef;








 

typedef struct
{
  uint16_t GPIO_Pin;             
 

  GPIOSpeed_TypeDef GPIO_Speed;  
 

  GPIOMode_TypeDef GPIO_Mode;    
 
}GPIO_InitTypeDef;




 

typedef enum
{ Bit_RESET = 0,
  Bit_SET
}BitAction;





 



 



 

#line 144 "..\\FWlib\\inc\\stm32f10x_gpio.h"



#line 163 "..\\FWlib\\inc\\stm32f10x_gpio.h"



 



 

#line 204 "..\\FWlib\\inc\\stm32f10x_gpio.h"







#line 217 "..\\FWlib\\inc\\stm32f10x_gpio.h"






#line 245 "..\\FWlib\\inc\\stm32f10x_gpio.h"
                              


  



 

#line 266 "..\\FWlib\\inc\\stm32f10x_gpio.h"

#line 274 "..\\FWlib\\inc\\stm32f10x_gpio.h"



 



 

#line 299 "..\\FWlib\\inc\\stm32f10x_gpio.h"

#line 316 "..\\FWlib\\inc\\stm32f10x_gpio.h"



 



  








                                                 


 



 



 



 

void GPIO_DeInit(GPIO_TypeDef* GPIOx);
void GPIO_AFIODeInit(void);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
void GPIO_EventOutputCmd(FunctionalState NewState);
void GPIO_PinRemapConfig(uint32_t GPIO_Remap, FunctionalState NewState);
void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
void GPIO_ETH_MediaInterfaceConfig(uint32_t GPIO_ETH_MediaInterface);








 



 



 

 
#line 38 "..\\code\\user\\stm32f10x_conf.h"
 
 
#line 1 "..\\FWlib\\inc\\stm32f10x_pwr.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_pwr.h"



 



  



  



  



  



  

#line 70 "..\\FWlib\\inc\\stm32f10x_pwr.h"


 



 







 



 




 


 



 










 



 



 



 



 

void PWR_DeInit(void);
void PWR_BackupAccessCmd(FunctionalState NewState);
void PWR_PVDCmd(FunctionalState NewState);
void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel);
void PWR_WakeUpPinCmd(FunctionalState NewState);
void PWR_EnterSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry);
void PWR_EnterSTANDBYMode(void);
FlagStatus PWR_GetFlagStatus(uint32_t PWR_FLAG);
void PWR_ClearFlag(uint32_t PWR_FLAG);








 



 



 

 
#line 41 "..\\code\\user\\stm32f10x_conf.h"
#line 1 "..\\FWlib\\inc\\stm32f10x_rcc.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_rcc.h"



 



 



 

typedef struct
{
  uint32_t SYSCLK_Frequency;   
  uint32_t HCLK_Frequency;     
  uint32_t PCLK1_Frequency;    
  uint32_t PCLK2_Frequency;    
  uint32_t ADCCLK_Frequency;   
}RCC_ClocksTypeDef;



 



 



 









  



 



#line 94 "..\\FWlib\\inc\\stm32f10x_rcc.h"



  



 
#line 126 "..\\FWlib\\inc\\stm32f10x_rcc.h"

#line 141 "..\\FWlib\\inc\\stm32f10x_rcc.h"


 



 
#line 175 "..\\FWlib\\inc\\stm32f10x_rcc.h"


 




 
#line 196 "..\\FWlib\\inc\\stm32f10x_rcc.h"


 

#line 283 "..\\FWlib\\inc\\stm32f10x_rcc.h"




 

#line 295 "..\\FWlib\\inc\\stm32f10x_rcc.h"


 



 

#line 317 "..\\FWlib\\inc\\stm32f10x_rcc.h"


  



 

#line 333 "..\\FWlib\\inc\\stm32f10x_rcc.h"


 



 

#line 347 "..\\FWlib\\inc\\stm32f10x_rcc.h"

#line 364 "..\\FWlib\\inc\\stm32f10x_rcc.h"




 




 








 
#line 396 "..\\FWlib\\inc\\stm32f10x_rcc.h"


#line 423 "..\\FWlib\\inc\\stm32f10x_rcc.h"
  



 

#line 435 "..\\FWlib\\inc\\stm32f10x_rcc.h"


 



 








 



 

#line 462 "..\\FWlib\\inc\\stm32f10x_rcc.h"


 



 







#line 489 "..\\FWlib\\inc\\stm32f10x_rcc.h"


 



 

#line 518 "..\\FWlib\\inc\\stm32f10x_rcc.h"




  



 

#line 553 "..\\FWlib\\inc\\stm32f10x_rcc.h"
 




 



 







#line 586 "..\\FWlib\\inc\\stm32f10x_rcc.h"



 



 

#line 606 "..\\FWlib\\inc\\stm32f10x_rcc.h"

#line 625 "..\\FWlib\\inc\\stm32f10x_rcc.h"




 



 



 



 



 

void RCC_DeInit(void);
void RCC_HSEConfig(uint32_t RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
void RCC_HSICmd(FunctionalState NewState);
void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul);
void RCC_PLLCmd(FunctionalState NewState);





#line 666 "..\\FWlib\\inc\\stm32f10x_rcc.h"

void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(uint32_t RCC_SYSCLK);
void RCC_PCLK1Config(uint32_t RCC_HCLK);
void RCC_PCLK2Config(uint32_t RCC_HCLK);
void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);


 void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource);




void RCC_ADCCLKConfig(uint32_t RCC_PCLK2);






void RCC_LSEConfig(uint8_t RCC_LSE);
void RCC_LSICmd(FunctionalState NewState);
void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);
void RCC_RTCCLKCmd(FunctionalState NewState);
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);





void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_BackupResetCmd(FunctionalState NewState);
void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
void RCC_MCOConfig(uint8_t RCC_MCO);
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
void RCC_ClearFlag(void);
ITStatus RCC_GetITStatus(uint8_t RCC_IT);
void RCC_ClearITPendingBit(uint8_t RCC_IT);








 



 



  

 
#line 42 "..\\code\\user\\stm32f10x_conf.h"
#line 1 "..\\FWlib\\inc\\stm32f10x_rtc.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_rtc.h"



 



  



  



  



 



 

#line 64 "..\\FWlib\\inc\\stm32f10x_rtc.h"


  



 

#line 82 "..\\FWlib\\inc\\stm32f10x_rtc.h"



 



 



 



 



 

void RTC_ITConfig(uint16_t RTC_IT, FunctionalState NewState);
void RTC_EnterConfigMode(void);
void RTC_ExitConfigMode(void);
uint32_t  RTC_GetCounter(void);
void RTC_SetCounter(uint32_t CounterValue);
void RTC_SetPrescaler(uint32_t PrescalerValue);
void RTC_SetAlarm(uint32_t AlarmValue);
uint32_t  RTC_GetDivider(void);
void RTC_WaitForLastTask(void);
void RTC_WaitForSynchro(void);
FlagStatus RTC_GetFlagStatus(uint16_t RTC_FLAG);
void RTC_ClearFlag(uint16_t RTC_FLAG);
ITStatus RTC_GetITStatus(uint16_t RTC_IT);
void RTC_ClearITPendingBit(uint16_t RTC_IT);








 



 



 

 
#line 43 "..\\code\\user\\stm32f10x_conf.h"
 
#line 1 "..\\FWlib\\inc\\stm32f10x_spi.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_spi.h"



 



  



 



 

typedef struct
{
  uint16_t SPI_Direction;           
 

  uint16_t SPI_Mode;                
 

  uint16_t SPI_DataSize;            
 

  uint16_t SPI_CPOL;                
 

  uint16_t SPI_CPHA;                
 

  uint16_t SPI_NSS;                 

 
 
  uint16_t SPI_BaudRatePrescaler;   



 

  uint16_t SPI_FirstBit;            
 

  uint16_t SPI_CRCPolynomial;        
}SPI_InitTypeDef;



 

typedef struct
{

  uint16_t I2S_Mode;         
 

  uint16_t I2S_Standard;     
 

  uint16_t I2S_DataFormat;   
 

  uint16_t I2S_MCLKOutput;   
 

  uint32_t I2S_AudioFreq;    
 

  uint16_t I2S_CPOL;         
 
}I2S_InitTypeDef;



 



 










 
  
#line 136 "..\\FWlib\\inc\\stm32f10x_spi.h"


 



 







 



 







  



 







 



 







 



 







  



 

#line 220 "..\\FWlib\\inc\\stm32f10x_spi.h"


  



 







 



 

#line 248 "..\\FWlib\\inc\\stm32f10x_spi.h"


 



 

#line 266 "..\\FWlib\\inc\\stm32f10x_spi.h"


 



 

#line 282 "..\\FWlib\\inc\\stm32f10x_spi.h"


  



 







 



 

#line 312 "..\\FWlib\\inc\\stm32f10x_spi.h"






  



 







 



 






 



 







 



 






 



 







 



 

#line 396 "..\\FWlib\\inc\\stm32f10x_spi.h"


 



 

#line 417 "..\\FWlib\\inc\\stm32f10x_spi.h"


 



 




 



 



 



 



 

void SPI_I2S_DeInit(SPI_TypeDef* SPIx);
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);
void I2S_Init(SPI_TypeDef* SPIx, I2S_InitTypeDef* I2S_InitStruct);
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);
void I2S_StructInit(I2S_InitTypeDef* I2S_InitStruct);
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void I2S_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_I2S_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT, FunctionalState NewState);
void SPI_I2S_DMACmd(SPI_TypeDef* SPIx, uint16_t SPI_I2S_DMAReq, FunctionalState NewState);
void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data);
uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx);
void SPI_NSSInternalSoftwareConfig(SPI_TypeDef* SPIx, uint16_t SPI_NSSInternalSoft);
void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_DataSizeConfig(SPI_TypeDef* SPIx, uint16_t SPI_DataSize);
void SPI_TransmitCRC(SPI_TypeDef* SPIx);
void SPI_CalculateCRC(SPI_TypeDef* SPIx, FunctionalState NewState);
uint16_t SPI_GetCRC(SPI_TypeDef* SPIx, uint8_t SPI_CRC);
uint16_t SPI_GetCRCPolynomial(SPI_TypeDef* SPIx);
void SPI_BiDirectionalLineConfig(SPI_TypeDef* SPIx, uint16_t SPI_Direction);
FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);
void SPI_I2S_ClearFlag(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);
ITStatus SPI_I2S_GetITStatus(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT);
void SPI_I2S_ClearITPendingBit(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT);








 



 



 

 
#line 45 "..\\code\\user\\stm32f10x_conf.h"
#line 1 "..\\FWlib\\inc\\stm32f10x_tim.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_tim.h"



 



  



  




 

typedef struct
{
  uint16_t TIM_Prescaler;         
 

  uint16_t TIM_CounterMode;       
 

  uint16_t TIM_Period;            

  

  uint16_t TIM_ClockDivision;     
 

  uint8_t TIM_RepetitionCounter;  






 
} TIM_TimeBaseInitTypeDef;       



 

typedef struct
{
  uint16_t TIM_OCMode;        
 

  uint16_t TIM_OutputState;   
 

  uint16_t TIM_OutputNState;  

 

  uint16_t TIM_Pulse;         
 

  uint16_t TIM_OCPolarity;    
 

  uint16_t TIM_OCNPolarity;   

 

  uint16_t TIM_OCIdleState;   

 

  uint16_t TIM_OCNIdleState;  

 
} TIM_OCInitTypeDef;



 

typedef struct
{

  uint16_t TIM_Channel;      
 

  uint16_t TIM_ICPolarity;   
 

  uint16_t TIM_ICSelection;  
 

  uint16_t TIM_ICPrescaler;  
 

  uint16_t TIM_ICFilter;     
 
} TIM_ICInitTypeDef;




 

typedef struct
{

  uint16_t TIM_OSSRState;        
 

  uint16_t TIM_OSSIState;        
 

  uint16_t TIM_LOCKLevel;        
  

  uint16_t TIM_DeadTime;         

 

  uint16_t TIM_Break;            
 

  uint16_t TIM_BreakPolarity;    
 

  uint16_t TIM_AutomaticOutput;  
 
} TIM_BDTRInitTypeDef;



 

#line 186 "..\\FWlib\\inc\\stm32f10x_tim.h"

 



 






 
#line 205 "..\\FWlib\\inc\\stm32f10x_tim.h"
									                                 
 
#line 216 "..\\FWlib\\inc\\stm32f10x_tim.h"

                                             
#line 225 "..\\FWlib\\inc\\stm32f10x_tim.h"

 
#line 236 "..\\FWlib\\inc\\stm32f10x_tim.h"

 
#line 249 "..\\FWlib\\inc\\stm32f10x_tim.h"

                                         
#line 266 "..\\FWlib\\inc\\stm32f10x_tim.h"

 
#line 279 "..\\FWlib\\inc\\stm32f10x_tim.h"
                                                                                                                                                                                                                          


  



 

#line 308 "..\\FWlib\\inc\\stm32f10x_tim.h"


 



 







  



 

#line 341 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 

#line 355 "..\\FWlib\\inc\\stm32f10x_tim.h"


 



 

#line 373 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 







 



 
  






 



 







  



 







  



 







  



 







  



 







  



 







  



 







  



 

#line 497 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 







 



 







  



 







  



 







  



 

#line 561 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 

#line 577 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 

#line 593 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 

#line 610 "..\\FWlib\\inc\\stm32f10x_tim.h"

#line 619 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 

#line 665 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 

#line 709 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 

#line 725 "..\\FWlib\\inc\\stm32f10x_tim.h"



  



 

#line 742 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 

#line 770 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 

#line 784 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



  






 



 







  



 







  



 

#line 833 "..\\FWlib\\inc\\stm32f10x_tim.h"


  




 

#line 851 "..\\FWlib\\inc\\stm32f10x_tim.h"



  



 

#line 866 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 







  



 





                                     


  



 







  



 

#line 927 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 

#line 943 "..\\FWlib\\inc\\stm32f10x_tim.h"


  



 







  



 

#line 987 "..\\FWlib\\inc\\stm32f10x_tim.h"
                               
                               



  



 




  



 




  



 

#line 1034 "..\\FWlib\\inc\\stm32f10x_tim.h"


 



 



 



  



 

void TIM_DeInit(TIM_TypeDef* TIMx);
void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct);
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState);
void TIM_GenerateEvent(TIM_TypeDef* TIMx, uint16_t TIM_EventSource);
void TIM_DMAConfig(TIM_TypeDef* TIMx, uint16_t TIM_DMABase, uint16_t TIM_DMABurstLength);
void TIM_DMACmd(TIM_TypeDef* TIMx, uint16_t TIM_DMASource, FunctionalState NewState);
void TIM_InternalClockConfig(TIM_TypeDef* TIMx);
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource,
                                uint16_t TIM_ICPolarity, uint16_t ICFilter);
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                             uint16_t ExtTRGFilter);
void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, 
                             uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter);
void TIM_ETRConfig(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                   uint16_t ExtTRGFilter);
void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler, uint16_t TIM_PSCReloadMode);
void TIM_CounterModeConfig(TIM_TypeDef* TIMx, uint16_t TIM_CounterMode);
void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, uint16_t TIM_EncoderMode,
                                uint16_t TIM_IC1Polarity, uint16_t TIM_IC2Polarity);
void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCOM(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCCDMA(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CCPreloadControl(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC1FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC2FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC3FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC4FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_CCxCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCx);
void TIM_CCxNCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCxN);
void TIM_SelectOCxM(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_OCMode);
void TIM_UpdateDisableConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_UpdateRequestConfig(TIM_TypeDef* TIMx, uint16_t TIM_UpdateSource);
void TIM_SelectHallSensor(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectOnePulseMode(TIM_TypeDef* TIMx, uint16_t TIM_OPMode);
void TIM_SelectOutputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_TRGOSource);
void TIM_SelectSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_SlaveMode);
void TIM_SelectMasterSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_MasterSlaveMode);
void TIM_SetCounter(TIM_TypeDef* TIMx, uint16_t Counter);
void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint16_t Autoreload);
void TIM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1);
void TIM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare2);
void TIM_SetCompare3(TIM_TypeDef* TIMx, uint16_t Compare3);
void TIM_SetCompare4(TIM_TypeDef* TIMx, uint16_t Compare4);
void TIM_SetIC1Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC2Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC3Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC4Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetClockDivision(TIM_TypeDef* TIMx, uint16_t TIM_CKD);
uint16_t TIM_GetCapture1(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture2(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture3(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture4(TIM_TypeDef* TIMx);
uint16_t TIM_GetCounter(TIM_TypeDef* TIMx);
uint16_t TIM_GetPrescaler(TIM_TypeDef* TIMx);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint16_t TIM_IT);
void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);








  



  



 

 
#line 46 "..\\code\\user\\stm32f10x_conf.h"
#line 1 "..\\FWlib\\inc\\stm32f10x_usart.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\stm32f10x_usart.h"



 



  



  



  
  
typedef struct
{
  uint32_t USART_BaudRate;            


 

  uint16_t USART_WordLength;          
 

  uint16_t USART_StopBits;            
 

  uint16_t USART_Parity;              




 
 
  uint16_t USART_Mode;                
 

  uint16_t USART_HardwareFlowControl; 

 
} USART_InitTypeDef;



  
  
typedef struct
{

  uint16_t USART_Clock;   
 

  uint16_t USART_CPOL;    
 

  uint16_t USART_CPHA;    
 

  uint16_t USART_LastBit; 

 
} USART_ClockInitTypeDef;



  



  
  
















  
  


                                    




  



  
  
#line 146 "..\\FWlib\\inc\\stm32f10x_usart.h"


  



  
  
#line 160 "..\\FWlib\\inc\\stm32f10x_usart.h"


  



  
  





  



  
#line 187 "..\\FWlib\\inc\\stm32f10x_usart.h"


  



  






  



 
  






  



 







 



 







  



 
  
#line 264 "..\\FWlib\\inc\\stm32f10x_usart.h"


 



 







  



 







 



 
  







 



 







  



 

#line 336 "..\\FWlib\\inc\\stm32f10x_usart.h"
                              
#line 344 "..\\FWlib\\inc\\stm32f10x_usart.h"



  



  



  



  



 

void USART_DeInit(USART_TypeDef* USARTx);
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
void USART_ClockInit(USART_TypeDef* USARTx, USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState);
void USART_DMACmd(USART_TypeDef* USARTx, uint16_t USART_DMAReq, FunctionalState NewState);
void USART_SetAddress(USART_TypeDef* USARTx, uint8_t USART_Address);
void USART_WakeUpConfig(USART_TypeDef* USARTx, uint16_t USART_WakeUp);
void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, uint16_t USART_LINBreakDetectLength);
void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
uint16_t USART_ReceiveData(USART_TypeDef* USARTx);
void USART_SendBreak(USART_TypeDef* USARTx);
void USART_SetGuardTime(USART_TypeDef* USARTx, uint8_t USART_GuardTime);
void USART_SetPrescaler(USART_TypeDef* USARTx, uint8_t USART_Prescaler);
void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_OverSampling8Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_OneBitMethodCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_IrDAConfig(USART_TypeDef* USARTx, uint16_t USART_IrDAMode);
void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState);
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);
void USART_ClearFlag(USART_TypeDef* USARTx, uint16_t USART_FLAG);
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16_t USART_IT);
void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT);








  



  



  

 
#line 47 "..\\code\\user\\stm32f10x_conf.h"
 
#line 1 "..\\FWlib\\inc\\misc.h"




















 

 







 
#line 33 "..\\FWlib\\inc\\misc.h"



 



 



 



 

typedef struct
{
  uint8_t NVIC_IRQChannel;                    


 

  uint8_t NVIC_IRQChannelPreemptionPriority;  

 

  uint8_t NVIC_IRQChannelSubPriority;         

 

  FunctionalState NVIC_IRQChannelCmd;         

    
} NVIC_InitTypeDef;
 


 



 
























 



 



 



 







 



 

#line 133 "..\\FWlib\\inc\\misc.h"


 



 

#line 151 "..\\FWlib\\inc\\misc.h"















 



 







 



 



 



 



 

void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState);
void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);









 



 



 

 
#line 49 "..\\code\\user\\stm32f10x_conf.h"

 
 

 
 

 
#line 73 "..\\code\\user\\stm32f10x_conf.h"



 
#line 8300 "C:\\Keil\\ARM\\Inc\\ST\\STM32F10x\\stm32f10x.h"




 

















 









 

  

 

 
#line 4 "..\\code\\TFT\\TFT_ILI9328\\ili9325.h"



#line 23 "..\\code\\TFT\\TFT_ILI9328\\ili9325.h"

#line 33 "..\\code\\TFT\\TFT_ILI9328\\ili9325.h"





























void Lcd_Start(void);
void Lcd_Configuration(void);
void DataToWrite(u16 data);
void LCD_Scan_Set(char i);


void Lcd_Initialize(void);

void Lcd_CMD_WR_Start(void);
void Lcd_WR_Start(void);
void LCD_WR_REG(u16 Index,u16 CongfigTemp);


void Lcd_Clear(u16 Color);
void Lcd_ClearCharBox(u16 x,u16 y,u16 Color);
void Lcd_SetBox(u16 xStart,u16 yStart,u16 xLong,u16 yLong,u16 x_offset,u16 y_offset);
void Lcd_ColorBox(u16 x,u16 y,u16 xLong,u16 yLong,u16 Color);
void Lcd_SetCursor(u16 x,u16 y);
void DrawPixel(u16 x, u16 y, int Color);
u16 GetPoint(u16 x,u16 y);
void BlockWrite(unsigned int Xstart,unsigned int Xend,unsigned int Ystart,unsigned int Yend);
void LCD_Fill_Pic(u16 x, u16 y,u16 pic_H, u16 pic_V, const unsigned char* pic);
void Put8_16Char(u16 x,u16 y,const unsigned char *ascii_8x16,u8 ch,u16 charColor,u16 bkColor,u8 flag);
void Put16_16HZ(u16 x,u16 y,const unsigned char *c,u16 charColor,u16 bkColor,u8 flag);
void Put32_32HZ(u16 x,u16 y,const unsigned char *c,u16 charColor,u16 bkColor,u8 flag);
void Put16x32Num(u16 x,u16 y,const unsigned char *num_16x32,u8 ch,u16 charColor,u16 bkColor,u8 flag);

void lcd_scrol_screen(unsigned int line_num);
void lcd_scrol_disable(void);




#line 13 "..\\code\\menu\\my_menu.c"
#line 1 "..\\code\\TFT\\lcm_api.h"








 



#line 14 "..\\code\\TFT\\lcm_api.h"

void virtual_LCM_PutChar(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor,u8 flag);
void virtual_LCM_PutString(u16 x,u16 y,u8* c,u16 charColor,u16 bkColor, u8 flag);
void virtual_LCM_PutNums(u16 x,u16 y,u32 num,u16 charColor,u16 bkColor ,u8 flag);
void virtual_LCM_PutNums_V2(u16 x,u16 y,u32 num,u8* format,u16 charColor,u16 bkColor ,u8 flag);
void virtual_LCM_PutNum_32x16(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor,u8 flag);
void virtual_LCM_PutNums_32x16(u16 x,u16 y,u32 num,u8 *format,u16 charColor,u16 bkColor ,u8 flag);

void virtual_LCM_HLine(u16 x0, u16 y0, u16 x1, u16 color);
void virtual_LCM_RLine(u16 x0, u16 y0, u16 y1, u16 color);
void virtual_LCM_Line(u16 x0, u16 y0, u16 x1, u16 y1,u16 color);  

void GUI_Circle(u16 cx,u16 cy,u16 r,u16 color,u8 fill);

void virtual_LCM_Circle(u16 cx,u16 cy,u16 r,u16 color,u8 fill);  
void virtual_LCM_Rectangle(u16 x0, u16 y0, u16 x1, u16 y1,u16 color,u8 fill); 
void virtual_LCM_Square(u16 x0, u16 y0, u16 with, u16 color,u8 fill);  
void virtual_LCM_Rectangle_V2(u16 x0, u16 y0, u16 lenth, u16 width,u16 color,u8 fill); 
void virtual_LCM_picture_start(void);
  

 
 

#line 14 "..\\code\\menu\\my_menu.c"
#line 1 "..\\code\\TFT\\touch.h"










 



#line 16 "..\\code\\TFT\\touch.h"













#line 44 "..\\code\\TFT\\touch.h"



void Touch_GPIO_Config(void);

int GUI_TOUCH_X_MeasureX(void); 
int GUI_TOUCH_X_MeasureY(void);

unsigned int TOUCH_X(void); 
unsigned int TOUCH_Y(void); 
void TP_GetAdXY(unsigned int *x,unsigned int *y);

char IsPressed(u16 x, u16 y,u16 x0, u16 y0, u16 lenth, u16 width,char* pressed);
char IsPressed_V2(u16 x, u16 y,u16 x0, u16 y0, u16 lenth, u16 width,char* pressed);
char IsPressed_V3(u16 x, u16 y,u16 x0, u16 y0, u16 lenth, u16 width,char* pressed);


#line 15 "..\\code\\menu\\my_menu.c"
#line 1 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"
 
 
 





 






 













#line 38 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"


  
  typedef unsigned int size_t;    








 
 

 
  typedef struct __va_list __va_list;





   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 129 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 
extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 948 "C:\\Keil\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"



 

#line 16 "..\\code\\menu\\my_menu.c"
#line 1 "..\\code\\ffs\\My_FF.h"



#line 1 "..\\code\\ffs\\ff.h"














 








#line 1 "..\\code\\ffs\\integer.h"
 
 
 




#line 14 "..\\code\\ffs\\integer.h"

 
typedef int				INT;
typedef unsigned int	UINT;

 
typedef char			CHAR;
typedef unsigned char	UCHAR;
typedef unsigned char	BYTE;

 
typedef short			SHORT;
typedef unsigned short	USHORT;
typedef unsigned short	WORD;
typedef unsigned short	WCHAR;

 
typedef long			LONG;
typedef unsigned long	ULONG;
typedef unsigned long	DWORD;



#line 25 "..\\code\\ffs\\ff.h"
#line 1 "..\\code\\ffs\\ffconf.h"







 






 




 





 









 



 



 



 



 





 































 














 




 









 





 


 







 





 



 





 











 


 
 










 




 


#line 26 "..\\code\\ffs\\ff.h"






 

#line 51 "..\\code\\ffs\\ff.h"

#line 224 "..\\code\\ffs\\ff.h"



 

#line 241 "..\\code\\ffs\\ff.h"





 

#line 260 "..\\code\\ffs\\ff.h"
typedef char TCHAR;








 

typedef struct {
	BYTE	fs_type;		 
	BYTE	drv;			 
	BYTE	csize;			 
	BYTE	n_fats;			 
	BYTE	wflag;			 
	BYTE	fsi_flag;		 
	WORD	id;				 
	WORD	n_rootdir;		 
#line 287 "..\\code\\ffs\\ff.h"
	DWORD	last_clust;		 
	DWORD	free_clust;		 
	DWORD	fsi_sector;		 


	DWORD	cdir;			 

	DWORD	n_fatent;		 
	DWORD	fsize;			 
	DWORD	fatbase;		 
	DWORD	dirbase;		 
	DWORD	database;		 
	DWORD	winsect;		 
	BYTE	win[512];	 
} FATFS;



 

typedef struct {
	FATFS*	fs;				 
	WORD	id;				 
	BYTE	flag;			 
	BYTE	pad1;
	DWORD	fptr;			 
	DWORD	fsize;			 
	DWORD	org_clust;		 
	DWORD	curr_clust;		 
	DWORD	dsect;			 

	DWORD	dir_sect;		 
	BYTE*	dir_ptr;		 


	DWORD*	cltbl;			 





	BYTE	buf[512];	 

} FIL;



 

typedef struct {
	FATFS*	fs;				 
	WORD	id;				 
	WORD	index;			 
	DWORD	sclust;			 
	DWORD	clust;			 
	DWORD	sect;			 
	BYTE*	dir;			 
	BYTE*	fn;				 




} DIR;



 

typedef struct {
	DWORD	fsize;			 
	WORD	fdate;			 
	WORD	ftime;			 
	BYTE	fattrib;		 
	TCHAR	fname[13];		 




} FILINFO;



 

typedef enum {
	FR_OK = 0,				 
	FR_DISK_ERR,			 
	FR_INT_ERR,				 
	FR_NOT_READY,			 
	FR_NO_FILE,				 
	FR_NO_PATH,				 
	FR_INVALID_NAME,		 
	FR_DENIED,				 
	FR_EXIST,				 
	FR_INVALID_OBJECT,		 
	FR_WRITE_PROTECTED,		 
	FR_INVALID_DRIVE,		 
	FR_NOT_ENABLED,			 
	FR_NO_FILESYSTEM,		 
	FR_MKFS_ABORTED,		 
	FR_TIMEOUT,				 
	FR_LOCKED,				 
	FR_NOT_ENOUGH_CORE,		 
	FR_TOO_MANY_OPEN_FILES	 
} FRESULT;



 
 

FRESULT f_mount (BYTE, FATFS*);						 
FRESULT f_open (FIL*, const TCHAR*, BYTE);			 
FRESULT f_read (FIL*, void*, UINT, UINT*);			 
FRESULT f_lseek (FIL*, DWORD);						 
FRESULT f_close (FIL*);								 
FRESULT f_opendir (DIR*, const TCHAR*);				 
FRESULT f_readdir (DIR*, FILINFO*);					 
FRESULT f_stat (const TCHAR*, FILINFO*);			 


FRESULT f_write (FIL*, const void*, UINT, UINT*);	 
FRESULT f_getfree (const TCHAR*, DWORD*, FATFS**);	 
FRESULT f_truncate (FIL*);							 
FRESULT f_sync (FIL*);								 
FRESULT f_unlink (const TCHAR*);					 
FRESULT	f_mkdir (const TCHAR*);						 
FRESULT f_chmod (const TCHAR*, BYTE, BYTE);			 
FRESULT f_utime (const TCHAR*, const FILINFO*);		 
FRESULT f_rename (const TCHAR*, const TCHAR*);		 











FRESULT f_chdrive (BYTE);							 
FRESULT f_chdir (const TCHAR*);						 
FRESULT f_getcwd (TCHAR*, UINT);					 



int f_putc (TCHAR, FIL*);							 
int f_puts (const TCHAR*, FIL*);					 
int f_printf (FIL*, const TCHAR*, ...);				 
TCHAR* f_gets (TCHAR*, int, FIL*);					 












 
 

 

DWORD get_fattime (void);


 
#line 467 "..\\code\\ffs\\ff.h"

 
#line 475 "..\\code\\ffs\\ff.h"




 
 


 





#line 497 "..\\code\\ffs\\ff.h"


 






 

#line 516 "..\\code\\ffs\\ff.h"


 



 
 

#line 536 "..\\code\\ffs\\ff.h"





#line 5 "..\\code\\ffs\\My_FF.h"

typedef struct
{
  char name[18];

}FILE_NAME_LIT;

void Del_oneWeekAgo(void);

void Del_files(
    char* FileName   
);

void Del_All_bmp(char* path);

void Del_some_bmp(u16 down,u16 up);

void Load_files	(
    char* path,		
	char* fil_ext_lw,		
	char* fil_ext_up,		
    void (*pfun)(char*)
);


unsigned char List_files	(
    char* path,		     
    DIR *start_dirs,     
	unsigned int page,   
	FILE_NAME_LIT  *File_name
);
void My_scan_files(void);

 
#line 17 "..\\code\\menu\\my_menu.c"

#line 1 "..\\code\\RTC\\calendar.h"
#line 4 "..\\code\\RTC\\calendar.h"

typedef struct
{
  u8 hour;
  u8 min;
  u8 sec;

  
  u16 w_year;
  u8  w_month;
  u8  w_date;
  u8  week;
}tm;

extern tm timer;

u8 rtc_get(void);
u8 rtc_set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);

#line 19 "..\\code\\menu\\my_menu.c"
#line 1 "..\\code\\user\\Font_lib_SD.h"
extern FATFS fs; 
extern FIL fsrc;
extern UINT br;
void Ebook(char *filename);
unsigned char *Read_One_GBK16(unsigned char *ch);
void Lcd_WriteASCIIClarity(u16 x,u8 y,u16 CharColor,u16 CharBackColor,u8 *ASCIICode,u8 flag);
void Lcd_WriteChineseClarity(u16 x,u8 y,u16 CharColor,u16 CharBackColor, u8 *ChineseCode,u8 flag);
Lcd_WriteChineseStringClarity(u16 x,u8 y,u16 CharColor,u16 CharBackColor,u8 *s,u8 flag);
void pg_up_dn(void);
#line 20 "..\\code\\menu\\my_menu.c"
  
#line 27 "..\\code\\menu\\my_menu.c"
 FILINFO Finfo;     
extern vu8 touchIRQ;
extern void Delay(u32 nTime);
extern char display_picture(char *filename);
extern char display_button_picture(char *filename);
extern char display_partation_picture(char *filename,u16 x0,u16 y0,u16 pic_x,u16 pic_y,u16 pic_L,u16 pic_H);
extern void Time_Show(u16 x,u16 y);









void main_menu(char* id,char menu)
{
    vu16 x,y;
	
	char pressed=0,pressed_1=0,pressed_2=0,pressed_3=0;
	char re,book=0;
    vu16 time_counter;
    vu8  light_lock,lock;
	
    virtual_LCM_Rectangle_V2(25-1, 55-1, 125, 50,0xffff,0); 
    virtual_LCM_Rectangle_V2(25-1, 55+50+(240-50*2-55*2)-1, 125, 50,0xffff,0); 
    virtual_LCM_Rectangle_V2(25+125+(320-125*2-25*2)-1, 55-1, 125, 50,0xffff,0); 
    virtual_LCM_Rectangle_V2(25+125+(320-125*2-25*2)-1, 55+50+(240-50*2-55*2)-1, 125, 50,0xffff,0); 

    virtual_LCM_Rectangle_V2(25, 55, 125, 50,0x7BEF,1); 
    virtual_LCM_Rectangle_V2(25, 55+50+(240-50*2-55*2), 125, 50,0x7BEF,1); 
    virtual_LCM_Rectangle_V2(25+125+(320-125*2-25*2), 55, 125, 50,0x7BEF,1); 
    virtual_LCM_Rectangle_V2(25+125+(320-125*2-25*2), 55+50+(240-50*2-55*2), 125, 50,0x7BEF,1); 

    if(menu==1)
    {
	    display_button_picture("sys8.bmp");
        

		f_mount(0, &fs);	
		f_open(&fsrc,"st1616.bin", 0x00 | 0x01);		
		Lcd_WriteChineseStringClarity(25+125/2-16,55+50/2-8,0xf800,0,"系统",0); 
		Lcd_WriteChineseStringClarity(25+125+(320-125*2-25*2)+125/2-16,55+50/2-8,0xf800,0,"浏览",0);
		Lcd_WriteChineseStringClarity(25+125/2-12,55+50+(240-50*2-55*2)+50/2-8,0xf800,0,"GPS",0);
		Lcd_WriteChineseStringClarity(25+125+(320-125*2-25*2)+125/2-16,55+50+(240-50*2-55*2)+50/2-8,0xf800,0,"摄像",0);

    }

    if(menu==2)
    {	
	    display_button_picture("sys7.bmp");

		
		f_mount(0, &fs);	
		f_open(&fsrc,"st1616.bin", 0x00 | 0x01);
		Lcd_WriteChineseStringClarity(25+125/2-16,55+50/2-8,0xf800,0,"撤防",0); 
		Lcd_WriteChineseStringClarity(25+125+(320-125*2-25*2)+125/2-16,55+50/2-8,0xf800,0,"布防",0);
		Lcd_WriteChineseStringClarity(25+125/2-16,55+50+(240-50*2-55*2)+50/2-8,0xf800,0,"节能",0);
		Lcd_WriteChineseStringClarity(25+125+(320-125*2-25*2)+125/2-16,55+50+(240-50*2-55*2)+50/2-8,0xf800,0,"退出",0);
	}

    if(menu==3)
    {
		display_button_picture("sys12.bmp");

		
		f_mount(0, &fs);	
		f_open(&fsrc,"st1616.bin", 0x00 | 0x01);
		Lcd_WriteChineseStringClarity(25+125/2-32,55+50/2-8,0xf800,0,"删除全部",0); 
		Lcd_WriteChineseStringClarity(25+125+(320-125*2-25*2)+125/2-32,55+50/2-8,0xf800,0,"时间设置",0);
		Lcd_WriteChineseStringClarity(25+125+(320-125*2-25*2)+125/2-16,55+50+(240-50*2-55*2)+50/2-8,0xf800,0,"退出",0);
		Lcd_WriteChineseStringClarity(25+125/2-28,55+50+(240-50*2-55*2)+50/2-18,0xf800,0,"μC/GUI",0);
		Lcd_WriteChineseStringClarity(25+125/2-24,55+50+(240-50*2-55*2)+50/2+ 2,0xf800,0,"练习场",0);
    }

  time_counter=0;
	light_lock=0;
	lock=1;
	f_mount(0, &fs);	
	f_open(&fsrc,"st1616.bin", 0x00 | 0x01);
	GUI_SetFont(&GUI_Font8x16);
	while(lock)
	{
		Delay(5);
	    if(menu==1)
		Time_Show(72,200); 




	
     x=800;
		 y=800;
		 x= TOUCH_X(); 
		 if(x!=800)y=TOUCH_Y();
	
	
	
			 if(time_counter<1800) time_counter++;
			 else {
				 	((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0800))->BRR = ((uint16_t)0x0002);;
				    while(1)
					{
					    Delay(4);
						x=800;
				    	y=800;
				    	x= TOUCH_X(); 
				    	if(x!=800) y= TOUCH_Y();	
					 	if(x!=800&&y!=800&&((y>=55+50+(240-50*2-55*2)+50+10)||y<=55-10))
		            	{
						    time_counter=0;
							((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0800))->BSRR = ((uint16_t)0x0002);;
				  			break;
		            	}
					 }		 
			 		}
	
			 if(x!=800&&y!=800)
	         {
		       time_counter=0;
	         }
	
		if(light_lock==0)
	    {	
		   re=IsPressed(x, y,25, 55, 125, 50,&pressed);
		   if(re==0){
		      *id=0;
		   	  lock=0;
			  break;
		   } 
		      
		   re=IsPressed(x, y,25+125+(320-125*2-25*2), 55, 125, 50,&pressed_1);
		   if(re==0){
		      *id=1;
		   	  lock=0;
			  break;
		   }    
	    
	       re=IsPressed(x, y,25, 55+50+(240-50*2-55*2), 125, 50,&pressed_2);
		   if(re==0){
		      *id=2;
		   	  lock=0;
			  break;
		   }    
	
	       re=IsPressed(x, y,25+125+(320-125*2-25*2), 55+50+(240-50*2-55*2), 125, 50,&pressed_3);
		   if(re==0){
		      *id=3;
		   	  lock=0;
			  break;
		   }  
		 }
    }  	 
	return;
}

















#line 206 "..\\code\\menu\\my_menu.c"


static char filePressed[12];
char file_num;
extern DIR start_dirs; 
unsigned int page;
FILE_NAME_LIT File_list[12];

void scan_menu(char* id)
{
    vu16 time_counter;
    unsigned int cnt;
    char pressed=0,pressed_1=0,pressed_2=0,pressed_3=0;
	char re,home=0;
    vu16 x,y;
    vu8  light_lock,lock,lock_scan;
	u8 i;

  page = 1;
  lock_scan=1; 

loop_A:

  while(lock_scan)
  {

	
	display_picture("sys3.bmp");
 
    
    virtual_LCM_Rectangle_V2(10-1, (240-10-25)-1, 50, 25,0xffff,0); 
    virtual_LCM_Rectangle_V2(10+50*1+10*1-1, (240-10-25)-1, 50, 25,0xffff,0);  
    virtual_LCM_Rectangle_V2(10+50*2+10*2-1, (240-10-25)-1, 50, 25,0xffff,0); 
    virtual_LCM_Rectangle_V2(10+50*3+10*3-1, (240-10-25)-1, 50, 25,0xffff,0); 
	virtual_LCM_Rectangle_V2(10+50*4+10*4-1, (240-10-25)-1, 50, 25,0xffff,0); 

    virtual_LCM_Rectangle_V2(10, (240-10-25), 50, 25,0x7BEF,1); 
    virtual_LCM_Rectangle_V2(10+50*1+10*1, (240-10-25), 50, 25,0x7BEF,1); 
    virtual_LCM_Rectangle_V2(10+50*2+10*2, (240-10-25), 50, 25,0x7BEF,1); 
    virtual_LCM_Rectangle_V2(10+50*3+10*3, (240-10-25), 50, 25,0x7BEF,1); 
	virtual_LCM_Rectangle_V2(10+50*4+10*4, (240-10-25), 50, 25,0x7BEF,1); 

	GUI_SetBkColor(0x787c78);
    GUI_SetColor(0x000000);
	GUI_DispCharAt('<',10+50/2-4, (240-10-25)+25/2-8);
	GUI_DispCharAt('>',10+50*1+10*1+50/2-4, (240-10-25)+25/2-8);
	GUI_DispStringAt("Del" ,10+50*2+10*2+50/2-4-8, (240-10-25)+25/2-8);
	GUI_DispStringAt("OK"  ,10+50*3+10*3+50/2-4-8, (240-10-25)+25/2-8);
	GUI_DispStringAt("Home",10+50*4+10*4+50/2-4-8, (240-10-25)+25/2-8);

    
    for(i=0;i<12;i++){
        filePressed[i]=0;
    }

    for(i=0;i<6;i++){
        virtual_LCM_Rectangle_V2(10, 5+20*i+13*i, 20, 20,0xF800,1); 
	    

        virtual_LCM_Rectangle_V2(10+170, 5+20*i+13*i, 20, 20,0xF800,1); 
	    
    }


    
    lock=1;
	file_num=0;
	virtual_LCM_Rectangle_V2(10, 5,20,20,0x001F,0); 


  time_counter=0;

  cnt = List_files("\\",&start_dirs,page,File_list);
  List_name(cnt);

loop_B:

    while(lock)
    {
	     Delay(4);


		 if(time_counter<1800)
		 {
			time_counter++;
		 }
		 else {
		 	((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0800))->BRR = ((uint16_t)0x0002);;
			
		    while(1)
			{
			    Delay(4);
				x=800;
		    	y=800;
		    	x= TOUCH_X(); 
		    	if(x!=800){
               		y= TOUCH_Y();
		    	}
			 
		    	if(x!=800&&y<=200)
            	{
					    time_counter=0;
						((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0800))->BSRR = ((uint16_t)0x0002);;
			  			break;
            	}

			}
		 }







         x=800;
		 y=800;
		 x= TOUCH_X(); 
		 if(x!=800){
            y= TOUCH_Y();
		 }
		 
		 if(x!=800&&y!=800)
         {
	       time_counter=0;
         }
 

	   re=IsPressed(x, y,10+50*4+10*4, (240-10-25), 50, 25,&home);
	   
	   if(re==3){
	      *id=0;
		  break;
	   } 


	   re=IsPressed(x, y,10, (240-10-25), 50, 25,&pressed);
	   if(re==3){
	      *id=1;
	   	  lock=0;
		  break;
	   } 
	      
	   re=IsPressed(x, y,10+50*1+10*1, (240-10-25), 50, 25,&pressed_1);
	   if(re==3){
	      *id=2;
	   	  lock=0;
		  break;
	   }    
    
       re=IsPressed(x, y,10+50*2+10*2, (240-10-25), 50, 25,&pressed_2);
	   if(re==3){
	      *id=3;
	   	  lock=0;
		  break;
	   }    

       re=IsPressed(x, y,10+50*3+10*3, (240-10-25), 50, 25,&pressed_3);
	   if(re==3){
	      *id=4;
	   	  lock=0;
		  break;
	   }  

    
    for(i=0;i<6;i++){
        re=IsPressed_V2(x, y,10, 5+20*i+13*i, 130, 20,&filePressed[i]);  
	    if(re==3){
          if(file_num!=i&&file_num>=0){
            if(file_num<6){
			   virtual_LCM_Rectangle_V2(10, 5+20*file_num+13*file_num,20,20,0xF800,0); 
            }else{
			   virtual_LCM_Rectangle_V2(10+170, 5+20*(file_num-6)+13*(file_num-6),20,20,0xF800,0); 
            }
             file_num=i;
          }

		  break;
	    } 

        re=IsPressed_V2(x, y,10+170, 5+20*i+13*i,130,20,&filePressed[i+6]);   
	    if(re==3){
          if(file_num!=i+6&&file_num>=0){
            if(file_num<6){
			   virtual_LCM_Rectangle_V2(10, 5+20*file_num+13*file_num,20,20,0xF800,0); 
            }else{
			   virtual_LCM_Rectangle_V2(10+170, 5+20*(file_num-6)+13*(file_num-6),20,20,0xF800,0); 
            }
             file_num=i+6;
          }

		  break;
	    }   
    }
    


    }
   
   switch(*id)
   {
	  case 0:
			   lock_scan=0;
		      break;

	  case 1:
               page-=1;
               if(page<=0) page=1; 
  			   cnt = List_files("\\",&start_dirs,page,File_list);
  			   List_name(cnt);
			   *id=-1;
			   lock=1;
               goto loop_B;
	        break;

	  case 2:
               page+=1;
  			   cnt = List_files("\\",&start_dirs,page,File_list);
               if(!cnt){
        		 page-=1;
  			     cnt = List_files("\\",&start_dirs,page,File_list);
                 List_name(cnt);
               }else{
				 List_name(cnt);
               }
			   *id=-1;
			   lock=1;
               goto loop_B;
	        break;

	  case 3:
               Del_files(File_list[file_num].name);
  			   cnt = List_files("\\",&start_dirs,page,File_list);
               List_name(cnt);
			   *id=-1;
			   lock=1;
               goto loop_B;
	        break;

	  case 4:
			if( strstr(File_list[file_num].name,"BMP"))
		      if(!display_picture(File_list[file_num].name))
			  {
			    *id=-1;
			    lock_scan=1;
			    goto loop_A;
              }	  
		
			if( strstr(File_list[file_num].name,"TXT") )	  
			  	{
				
				Ebook(File_list[file_num].name);
				} 
			  while(1)
			  {
			    Delay(4);
				x=800;
		    	y=800;
		    	x= TOUCH_X(); 
		    	if(x!=800){
               		y= TOUCH_Y();
		    	}
			 
		    	if(x!=800&&y!=800){
					break;
				}

		 		if(time_counter<1800*3)
		 		{
					time_counter++;
		 		}
		 		else {
		      	
                  ((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0800))->BRR = ((uint16_t)0x0002);;
                  while(1)
			      {
			        Delay(4);
		 			
					x=800;
		    		y=800;
		    		x= TOUCH_X(); 
		    		if(x!=800){
               			y= TOUCH_Y();
		    		}
			 
		    		if(x!=800&&y!=800){
                        ((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0800))->BSRR = ((uint16_t)0x0002);;
						time_counter=0;
                        Delay(40);	 
						break;
					}
				   }
				  }
			   }
			   *id=-1;
			   lock_scan=1;
			   goto loop_A;
			   
	        break;

	  default:
              *id=-1;
	        break;
   }   
 }

}


void List_name(unsigned int cnt)
{
	unsigned char i;
	unsigned char *p;
   f_mount(0, &fs);
   f_open(&fsrc,"st1616.bin", 0x00 | 0x01);
    for(i=0;i<6;i++){
		Lcd_ColorBox(10+35,5+20*i+13*i,8*12,16,0xffff);
		Lcd_ColorBox(10+170+35,5+20*i+13*i,8*12,16,0xffff);
    }
    for(i=0;i<6;i++){
      if(i<cnt){
	  	p = File_list[i].name;
		Lcd_WriteChineseStringClarity(10+35,5+20*i+13*i,0,0,p,0);
	  }
      if(i+6<cnt){
	    p = File_list[i+6].name;
		Lcd_WriteChineseStringClarity(10+170+35,5+20*i+13*i,0,0,p,0);
	  }
    }
	f_mount(0, 0);
}




static char Time_Date[6];






void Set_Time_Date(void)
{
	char re,i;
    vu16 x,y;
    char pressed=0,pressed_1=0,pressed_2=0,pressed_3=0,home=0;
    char slect=0;
	u16 year=2013;
	u8 month=5,day=1,hour=10,min=0,sec=0;
    vu16 time_counter=0;

	for(i=0;i<6;i++){
        Time_Date[i]=0;
    }

	
    
    virtual_LCM_Rectangle_V2(10-1, (240-10-25)-1, 67, 25,0xffff,0); 
    virtual_LCM_Rectangle_V2(10+67*1+10*1-1, (240-10-25)-1, 67, 25,0xffff,0);  
    virtual_LCM_Rectangle_V2(10+67*2+10*2-1, (240-10-25)-1, 67, 25,0xffff,0); 
    virtual_LCM_Rectangle_V2(10+67*3+10*3-1, (240-10-25)-1, 67, 25,0xffff,0); 

    virtual_LCM_Rectangle_V2(10, (240-10-25), 67, 25,0x7BEF,1); 
    virtual_LCM_Rectangle_V2(10+67*1+10*1, (240-10-25), 67, 25,0x7BEF,1); 
    virtual_LCM_Rectangle_V2(10+67*2+10*2, (240-10-25), 67, 25,0x7BEF,1); 
    virtual_LCM_Rectangle_V2(10+67*3+10*3, (240-10-25), 67, 25,0x7BEF,1); 

	GUI_SetBkColor(0x787c78);
  GUI_SetColor(0x000000);
	GUI_DispCharAt('-',10+67/2-4, (240-10-25)+25/2-8);
	GUI_DispCharAt('+',10+67*1+10*1+67/2-4, (240-10-25)+25/2-8);
	GUI_DispStringAt("Set" ,10+67*2+10*2+67/2-4-8, (240-10-25)+25/2-8);
	GUI_DispStringAt("Back",10+67*3+10*3+67/2-2-8, (240-10-25)+25/2-8);
	
	GUI_SetFont(&GUI_Font24_ASCII);
	GUI_SetBkColor(0xFFFFFF);
  GUI_SetColor(0x0000FF);
	
	GUI_DispDecAt(year, 80+8, 60+4, 4);
	GUI_DispCharAt('/',80+16*4+4,60+4);
	GUI_DispDecAt(month, 80+16*5+4, 60+4, 2);
	GUI_DispCharAt('/',80+16*7+4,60+4);
	GUI_DispDecAt(day, 80+16*8+4, 60+4, 2);
	
	GUI_DispDecAt(hour,80+16*1+4,60+64, 2);
	GUI_DispCharAt(':',80+16*3+4,60+64);
	GUI_DispDecAt(min, 80+16*4+4,60+64, 2);
	GUI_DispCharAt(':',80+16*6+4,60+64);
	GUI_DispDecAt(sec, 80+16*7+4,60+64, 2);

	slect=0;
	LCD_Scan_Set(1);
	f_mount(0, &fs);
	f_open(&fsrc,"st1616.bin", 0x00 | 0x01);
	virtual_LCM_Rectangle_V2(80-1,60-1,16*4+1, 32+1,0x001F,0); 

  while(1)
  {
		GUI_SetFont(&GUI_Font24_ASCII);
		GUI_DispDecAt(year, 80+8, 60+4, 4);
		GUI_DispCharAt('/',80+16*4+4,60+4);
		GUI_DispDecAt(month, 80+16*5+4, 60+4, 2);
		GUI_DispCharAt('/',80+16*7+4,60+4);
		GUI_DispDecAt(day, 80+16*8+4, 60+4, 2);







	GUI_DispDecAt(hour,80+16*1+4,60+64, 2);
	GUI_DispCharAt(':',80+16*3+4,60+64);
	GUI_DispDecAt(min, 80+16*4+4,60+64, 2);
	GUI_DispCharAt(':',80+16*6+4,60+64);
	GUI_DispDecAt(sec, 80+16*7+4,60+64, 2);
	Delay(4);
	LCD_Scan_Set(1);
	Time_Show(79,168);
	

		 if(time_counter<1000)
		 {
			time_counter++;
		 }
		 else {
		 	((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0800))->BRR = ((uint16_t)0x0002);;
			
		    while(1)
			{
			    Delay(4);
				x=800;
		    	y=800;
		    	x= TOUCH_X(); 
		    	if(x!=800){
               		y= TOUCH_Y();
		    	}
			 
		    	if(x!=800&&y<=200)
            	{
				    
	          		
	          		
					    time_counter=0;
						((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x10000) + 0x0800))->BSRR = ((uint16_t)0x0002);;
			  			break;
			  		
            	}

			}
		 }


     x=800;
		 y=800;
		 x= TOUCH_X(); 
		 if(x!=800){
            y= TOUCH_Y();
		 }
		 
		 if(x!=800&&y!=800)
         {
	       time_counter=0;
         }





    if(slect!=0)  virtual_LCM_Rectangle_V2(80-1,60-1,16*4+1, 32+1,0xFFFF,0); 

    if(slect!=1)  virtual_LCM_Rectangle_V2(80+16*5-1,60-1,16*2+1, 32+1,0xFFFF,0); 

    if(slect!=2)  virtual_LCM_Rectangle_V2(80+16*8-1,60-1,16*2+1, 32+1,0xFFFF,0); 

    if(slect!=3)  virtual_LCM_Rectangle_V2(16+80-1, 60+60-1,16*2+1, 32+1,0xFFFF,0); 

    if(slect!=4)  virtual_LCM_Rectangle_V2(16+80+16*3-1,60+60-1,16*2+1, 32+1,0xFFFF,0); 

    if(slect!=5)  virtual_LCM_Rectangle_V2(16+80+16*6-1, 60+60-1,16*2+1, 32+1,0xFFFF,0); 


	
        re=IsPressed_V3(x, y,80,60,16*4, 32,&Time_Date[0]);
	    if(re==3){
		    slect=0;
	    } 

        re=IsPressed_V3(x, y,80+16*5,60,16*2,32,&Time_Date[1]);
	    if(re==3){
			slect=1;
         }

        re=IsPressed_V3(x, y,80+16*8,60,16*2,32,&Time_Date[2]);
	    if(re==3){
		    slect=2;
         }

        re=IsPressed_V3(x, y,16+80, 60+60,16*2,32,&Time_Date[3]);
	    if(re==3){
		    slect=3;
         }

        re=IsPressed_V3(x, y,16+80+16*3,60+60,16*2,32,&Time_Date[4]);
	    if(re==3){
		    slect=4;
         }

        re=IsPressed_V3(x, y,16+80+16*6, 60+60,16*2,32,&Time_Date[5]);
	    if(re==3){
		    slect=5;
         }


	   re=IsPressed(x, y,326,201, 342-326, 225-201,&home);
	   if(re==3){
		  break;
	   } 

	   re=IsPressed(x, y,10, (240-10-25), 67, 25,&pressed);
	   if(re==3){
		   switch(slect)
		   {
		   	  case 0:
			      	   year--;
					   if(year==2008)  year=2099;
				        break;

		   	  case 1:
			      	   month--;
					   if(month==0)  month=12;
				        break;

		   	  case 2:
			      	   day--;
					   if(day==0)  day=31;
				        break;

		   	  case 3:
					   if(hour>0)  hour--;
					   else        hour=23;
				        break;

		   	  case 4:
			      	   
					   if(min>0)  min--;
					   else       min=59;
				        break;

		   	  case 5:
			      	   
					   if(sec>0)  sec--;
					   else       sec=59;
				        break;

		   	  default :
				        break;
		   
		   }
	   } 
	      
	   re=IsPressed(x, y,10+67*1+10*1, (240-10-25), 67, 25,&pressed_1);
	   if(re==3){
		   switch(slect)
		   {
		   	  case 0:
			      	   year++;
					   if(year==2100)  year=2009;
				        break;

		   	  case 1:
			      	   month++;
					   if(month==13)  month=1;
				        break;

		   	  case 2:
			      	   day++;
					   if(day==32)  day=1;
				        break;

		   	  case 3:
			      	   hour++;
					   if(hour==24)  hour=0;
				        break;

		   	  case 4:
			      	   min++;
					   if(min==60)  min=0;
				        break;

		   	  case 5:
			      	   sec++;
					   if(sec==60)  sec=0;
				        break;

		   	  default :
				        break;
		   
		   }
	   }    
    
       re=IsPressed(x, y,10+67*2+10*2, (240-10-25), 67, 25,&pressed_2);
	   if(re==3){
		  rtc_set(year,month,day,hour,min,sec);
	   }    

       re=IsPressed(x, y,10+67*3+10*3, (240-10-25), 67, 25,&pressed_3);
	   if(re==3){
		  break;
	   } 
   }
		GUI_SetFont(&GUI_Font8x16);
}


