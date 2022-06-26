extern FATFS fs; 
extern FIL fsrc;
extern UINT br;//UINT  extern UINT br;
void Ebook(char *filename);
unsigned char *Read_One_GBK16(unsigned char *ch);
void Lcd_WriteASCIIClarity(u16 x,u8 y,u16 CharColor,u16 CharBackColor,u8 *ASCIICode,u8 flag);
void Lcd_WriteChineseClarity(u16 x,u8 y,u16 CharColor,u16 CharBackColor, u8 *ChineseCode,u8 flag);
Lcd_WriteChineseStringClarity(u16 x,u8 y,u16 CharColor,u16 CharBackColor,u8 *s,u8 flag);
void pg_up_dn(void);
