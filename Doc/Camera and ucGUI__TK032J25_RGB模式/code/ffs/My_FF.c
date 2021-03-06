#include <string.h>
#include <stdio.h>
#include "msd.h"
#include "integer.h"
#include "diskio.h"
#include "ff.h"
#include "My_FF.h"
#include "ili9325.h" 
#include "lcm_api.h"
#include "calendar.h"


#define  SD_CS_ENABLE()	  MSD_CS_LOW()
#define  SD_CS_DISABLE()  MSD_CS_HIGH()


static FATFS Fatfs;            // Work area (file system object) for logical drive
static FRESULT res;         // FatFs function common result code

static DWORD acc_size;				/* Work register for fs command */
static WORD acc_files, acc_dirs;
extern FILINFO Finfo;
static DIR Dir;					/* Directory object */
DIR start_dirs;          //目录起点信息


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//列举指定目录下的文件
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
FRESULT scan_files (
	char* path		/* Pointer to the path name working buffer */
)
{
	DIR dirs;
	FRESULT res;
	BYTE i;
	char *fn;


	if ((res = f_opendir(&dirs, path)) == FR_OK) {
		i = strlen(path);
		while (((res = f_readdir(&dirs, &Finfo)) == FR_OK) && Finfo.fname[0]) {
			if (Finfo.fname[0] == '.') continue;
#if _USE_LFN
			fn = *Finfo.lfname ? Finfo.lfname : Finfo.fname;
#else
			fn = Finfo.fname;
#endif
			if (Finfo.fattrib & AM_DIR) {
				acc_dirs++;
				*(path+i) = '/'; strcpy(path+i+1, fn);
				res = scan_files(path);
				*(path+i) = '\0';
				if (res != FR_OK) break;
			} else {
//				xprintf("%s/%s\n", path, fn);
 				printf("%s/%s\n", path, fn);
				acc_files++;
				acc_size += Finfo.fsize;
			}
		}
	}

	return res;
}


//仅用于测试用
void My_scan_files(void)
{

//   char buffer[5];
//   unsigned int cnt=8;

  f_mount(0, &Fatfs);
  //------------------------------------------

  res = scan_files("");
  //printf("1111111111111111111111111111111\n");
  //res = scan_extern_files("",".bmp",".BMP",buffer,&cnt);
  //printf("2222222222222222222222222222222\n");
  //res = scan_extern_files("","bmp","BMP");
  //printf("3333333333333333333333333333333\n");
  //res = scan_extern_files("",".txt",".TXT");

  //-------------------------------------------
  // Unregister a work area before discard it
  f_mount(0, NULL);
  //SD_CS_DISABLE();
} 

 

//仅用于测试用
/* fl [<path>] - Directory listing */
void My_scan_files_3(void)
{
  long p1;
  UINT s1, s2;
  FRESULT res;
  FATFS *fs;				/* Pointer to file system object */

  f_mount(0, &Fatfs);
  //------------------------------------------

  res = f_opendir(&Dir, "\\");

  if (res) { return; }

  p1 = s1 = s2 = 0;

 for(;;) {

#if _USE_LFN
	Finfo.lfname = Lfname;
	Finfo.lfsize = sizeof(Lfname);
#endif

	res = f_readdir(&Dir, &Finfo);
	if ((res != FR_OK) || !Finfo.fname[0]) break;
	if (Finfo.fattrib & AM_DIR) {
		s2++;
	} else {
		s1++; p1 += Finfo.fsize;
	}

	printf("%c%c%c%c%c %u/%02u/%02u %02u:%02u %9lu  %s\r\n",
		   (Finfo.fattrib & AM_DIR) ? 'D' : '-',
		   (Finfo.fattrib & AM_RDO) ? 'R' : '-',
		   (Finfo.fattrib & AM_HID) ? 'H' : '-',
		   (Finfo.fattrib & AM_SYS) ? 'S' : '-',
		   (Finfo.fattrib & AM_ARC) ? 'A' : '-',
		   (Finfo.fdate >> 9) + 1980, (Finfo.fdate >> 5) & 15, Finfo.fdate & 31,
		   (Finfo.ftime >> 11), (Finfo.ftime >> 5) & 63,
			Finfo.fsize, &(Finfo.fname[0]));

#if _USE_LFN
	printf("  %s\n", Lfname);
#else
	printf("\n");
#endif
 
 }//for(;;)

	printf("%4u File(s),%10lu bytes total\n%4u Dir(s)", s1, p1, s2);

	if (f_getfree("\\", (DWORD*)&p1, &fs) == FR_OK)
		printf(", %10lu bytes free\n", p1 * fs->csize * 512);


  //-------------------------------------------
  // Unregister a work area before discard it
  f_mount(0, NULL);
  //SD_CS_DISABLE();
} 



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//以下为工程中用到的函数
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//列举指定目录下的，指定后缀名的文件
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static FRESULT scan_extern_files (
	char* path,		        //路径
	char* fil_ext_lw,       //后缀的小写（.bmp）
	char* fil_ext_up,       //后缀的大写（.BMP）
    void (*pfun)(char*)     //对每个列举文件进行操作的函数
)
{
	DIR dirs;
	FRESULT res;
	BYTE i;
	char *fn;

	if ((res = f_opendir(&dirs, path)) == FR_OK) {
		i = strlen(path);
		while (((res = f_readdir(&dirs, &Finfo)) == FR_OK) && Finfo.fname[0]) {
			if (Finfo.fname[0] == '.') continue;
#if _USE_LFN
			fn = *Finfo.lfname ? Finfo.lfname : Finfo.fname;
#else
			fn = Finfo.fname;
#endif
			if (Finfo.fattrib & AM_DIR) {
				acc_dirs++;
				*(path+i) = '/'; strcpy(path+i+1, fn);
				//res = scan_extern_files(path,fil_ext_lw,fil_ext_up,pfun);
				*(path+i) = '\0';
				if (res != FR_OK) break;
			} else {
//				xprintf("%s/%s\n", path, fn);
              //if( strstr(fn,(char *)strlwr(fil_ext)) || strstr(fn, (char *)strupr(fil_ext))){  
              if( strstr(fn,fil_ext_lw) || strstr(fn, fil_ext_up)){  
				//printf("%s/%s\n", path, fn);
				//printf("%s\n",fn);
				  //strcpy(buffer+size,fn);
                  (*pfun)(fn);
				  //printf("%s\n",fn);
              }

			}
		}
	}

	return res;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//列举指定目录下的，指定后缀名的文件
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Load_files	(
    char* path,		// Pointer to the path name working buffer //
	char* fil_ext_lw,		// Pointer to the path name working buffer //
	char* fil_ext_up,		// Pointer to the path name working buffer //
    void (*pfun)(char*)
)
{

  f_mount(0, &Fatfs);
  //------------------------------------------

  res = scan_extern_files(path,fil_ext_lw,fil_ext_up,pfun);

  //-------------------------------------------
  // Unregister a work area before discard it
  f_mount(0, NULL);
  SD_CS_DISABLE();
} 




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//删除文件
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Del_files	(
    char* FileName  /* Pointer to the object name */
)
{

  f_mount(0, &Fatfs);
  //------------------------------------------

  res = f_unlink(FileName);
  if(res == 0){ 
	  //printf("del %s OK !%d\n",FileName, res);
  }else{
      //printf("del %s WRONG !%d\n",FileName, res);
  }

  //-------------------------------------------
  // Unregister a work area before discard it
  f_mount(0, NULL);
  //SD_CS_DISABLE();
} 


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//删除所有pic?.bmp文件
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Del_All_bmp_V1(char* path)
{
	DIR dirs;
	FRESULT res;
	BYTE i;
	char *fn;
    u8 cnt=0;

    f_mount(0, &Fatfs);

	virtual_LCM_PutString(100,200,"Wait....",0x0000,0xffff ,1);
	res = f_unlink("record.dat");

	if ((res = f_opendir(&dirs, path)) == FR_OK) {
		i = strlen(path);
		while (((res = f_readdir(&dirs, &Finfo)) == FR_OK) && Finfo.fname[0]) {
			if (Finfo.fname[0] == '.') continue;
#if _USE_LFN
			fn = *Finfo.lfname ? Finfo.lfname : Finfo.fname;
#else
			fn = Finfo.fname;
#endif
			if (Finfo.fattrib & AM_DIR) {
				acc_dirs++;
				*(path+i) = '/'; strcpy(path+i+1, fn);
				//res = scan_extern_files(path,fil_ext_lw,fil_ext_up,pfun);
				*(path+i) = '\0';
				if (res != FR_OK) break;
			} else {

              if( strstr(fn,"BMP") || strstr(fn, "bmp"))
			  {  
				 if( strstr(fn,"PIC") || strstr(fn, "pic")) 
				 {				    
                    res = f_unlink(fn);
					cnt++;
					if(cnt==10){
					   virtual_LCM_Rectangle_V2(280, 200, 20, 20,RED,1); // 画矩形
					}else if(cnt==20){
					   cnt=0;
					   virtual_LCM_Rectangle_V2(280, 200, 20, 20,GREEN,1); // 画矩形
					}
				 }
              }//f( strstr(fn,"BMP") || strstr(fn, "bmp"))
			}//else
		}//while
	}//if ((res = f_opendir(&dirs, path)) == FR_OK)

	virtual_LCM_PutString(100,200,"Done!!!!!!",0x0000,0xffff ,1);
    f_mount(0, NULL);
} 


void Del_All_bmp_V3(char* path)
{
	DIR dirs;
	FRESULT res;
	BYTE i;
	char *fn;
    u8 cnt=0;

    f_mount(0, &Fatfs);

	virtual_LCM_PutString(100,200,"Wait....",0x0000,0xffff ,1);
	res = f_unlink("record.dat");

DEL_LOOP_C:

	if ((res = f_opendir(&dirs, path)) == FR_OK) {
		i = strlen(path);
		while (((res = f_readdir(&dirs, &Finfo)) == FR_OK) && Finfo.fname[0]) {
			if (Finfo.fname[0] == '.') continue;
#if _USE_LFN
			fn = *Finfo.lfname ? Finfo.lfname : Finfo.fname;
#else
			fn = Finfo.fname;
#endif
			if (Finfo.fattrib & AM_DIR) {
				acc_dirs++;
				*(path+i) = '/'; strcpy(path+i+1, fn);
				//res = scan_extern_files(path,fil_ext_lw,fil_ext_up,pfun);
				*(path+i) = '\0';
				if (res != FR_OK) break;
			} else {

              if( strstr(fn,"BMP") || strstr(fn, "bmp"))
			  {  
				 if( strstr(fn,"PIC") || strstr(fn, "pic")) 
				 {				    
                    res = f_unlink(fn);
					cnt++;
					if(cnt==10){
					   virtual_LCM_Rectangle_V2(280, 200, 20, 20,RED,1); // 画矩形
					   goto DEL_LOOP_C;
					}else if(cnt==20){
					   cnt=0;
					   virtual_LCM_Rectangle_V2(280, 200, 20, 20,GREEN,1); // 画矩形
					   goto DEL_LOOP_C;
					}
				 }
              }//f( strstr(fn,"BMP") || strstr(fn, "bmp"))
			}//else
		}//while
	}//if ((res = f_opendir(&dirs, path)) == FR_OK)

	virtual_LCM_PutString(100,200,"Done!!!!!!",0x0000,0xffff ,1);
    f_mount(0, NULL);
} 


void Del_All_bmp(char* path)
{
{
  FRESULT res;
  u8 cnt=0;
   
  f_mount(0, &Fatfs);
	
  virtual_LCM_PutString(100,200,"Wait....",0x0000,0xffff ,1);
  f_unlink("record.dat");

  res = f_opendir(&Dir, path);
  if (res) { return; }
  
 for(;;) {

	res = f_readdir(&Dir, &Finfo);
	if ((res != FR_OK) || !Finfo.fname[0]) break;

   if( strstr(Finfo.fname,"BMP") || strstr(Finfo.fname, "bmp"))
   {  
	  if( strstr(Finfo.fname,"PIC") || strstr(Finfo.fname, "pic")) 
	  {
          f_unlink(Finfo.fname);
		  cnt++;
		  if(cnt==10){
			 virtual_LCM_Rectangle_V2(280, 200, 20, 20,RED,1); // 画矩形
		  }else if(cnt==20){
			 cnt=0;
			 virtual_LCM_Rectangle_V2(280, 200, 20, 20,GREEN,1); // 画矩形
		  }
	  }
   }

 }//for(;;)
  virtual_LCM_PutString(100,200,"Done!!!!!!",0x0000,0xffff ,1);
  // Unregister a work area before discard it
  f_mount(0, NULL);
} 
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//删除部分pic?.bmp文件
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Del_some_bmp(u16 down,u16 up)
{
  char s[30];
  u16 counter;

  if(up<=down)	return;

  f_mount(0, &Fatfs);

  for(counter=down;counter<=up;counter++)
  {
     sprintf(s, "pic%d.bmp",counter);  
	 res = f_unlink(s);
  }

  f_mount(0, NULL);
} 



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//列举指定目录下的摄像头所拍摄的文件pic?.bmp
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static FRESULT List_extern_files (
	char* path,		      //路径
    DIR *start_dirs,       //目录起点信息
	unsigned int page,
    unsigned char *file_conter,  //成功列举出来的文件数
	FILE_NAME_LIT *File_name
)
{
	DIR dirs;
	FRESULT res;
	BYTE i;
	char *fn;
	unsigned int counter=0,up,down;

    up = page*12;
    down = (page-1)*12; 
	dirs = *start_dirs;
	
	{
		i = strlen(path);
		while (((res = f_readdir(&dirs, &Finfo)) == FR_OK) && Finfo.fname[0]) 
		{
			if (Finfo.fname[0] == '.') continue;
#if _USE_LFN
			fn = *Finfo.lfname ? Finfo.lfname : Finfo.fname;
#else
			fn = Finfo.fname;
#endif
			if (Finfo.fattrib & AM_DIR) {
				acc_dirs++;
				*(path+i) = '/'; strcpy(path+i+1, fn);
				//res = scan_extern_files(path,fil_ext_lw,fil_ext_up,pfun);
				*(path+i) = '\0';
				if (res != FR_OK) break;
			} else {
//				xprintf("%s/%s\n", path, fn);
              //if( strstr(fn,(char *)strlwr(fil_ext)) || strstr(fn, (char *)strupr(fil_ext))){  
              if( strstr(fn,"BMP") || strstr(fn, "bmp"))
			  {  
				 if( strstr(fn,"PIC") || strstr(fn, "pic")) 
				 {
//				    if(counter%12==0)
//					{
//					   //counter = 0;
//					   //printf("\r\n-----------------------------------------\r\n");
//					}
					if(counter>=up)	break;

                    if(counter<down || counter>=up)
                    {  counter++;  continue;   }
					//printf("%s/%s\n", path, fn);
					//printf("file%d:%s\r\n",counter,fn);
					strcpy(File_name[*file_conter].name,fn);
					//printf("file%d:%s\r\n",counter,File_name[*file_conter].name); 
					counter++;
					(*file_conter)++;
					//strcpy(buffer+size,fn);
                	//(*pfun)(fn);
			    	//printf("%s\n",fn);
				 }
              }

			}
		}//while
	}

	return res;
}

//==============================================================================================================
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//列举指定目录下的摄像头所拍摄的文件,返回列举出来的文件数
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
unsigned char List_files_V2	(
    char* path,		     // Pointer to the path name working buffer //
    DIR *start_dirs,     //目录起点信息
	unsigned int page,   //页码
	FILE_NAME_LIT  *File_name
)
{
//   FRESULT res;
  unsigned char file_conter=0,i;  //成功列举出来的文件数

  f_mount(0, &Fatfs);
  //------------------------------------------
  if(res = f_opendir(start_dirs, path) != FR_OK){	 //寻找目录起点
     f_mount(0, NULL);
	 MSD_Init();//重新初始化SD卡 
	 return 0;
  }

  res = List_extern_files(path,start_dirs,page,&file_conter,File_name);

  for(i=file_conter;i<12;i++)
  {
	File_name[i].name[0]='\0';
  }
  //-------------------------------------------
  // Unregister a work area before discard it
  f_mount(0, NULL);

  return file_conter;
}


unsigned char List_files	(
    char* path,		     // Pointer to the path name working buffer //
    DIR *start_dirs,     //目录起点信息
	unsigned int page,   //页码
	FILE_NAME_LIT  *File_name
)
{
  FRESULT res;
  unsigned int counter=0,up,down;
  unsigned char file_conter=0,i;  //成功列举出来的文件数

  up = page*12;
  down = (page-1)*12;
   
  f_mount(0, &Fatfs);

  res = f_opendir(&Dir, path);
  if (res) { return; }
  
 for(;;) {

	res = f_readdir(&Dir, &Finfo);
	if ((res != FR_OK) || !Finfo.fname[0]) break;

   //if( strstr(Finfo.fname,"BMP") || strstr(Finfo.fname, "bmp"))
   {  
	  //if( strstr(Finfo.fname,"PIC") || strstr(Finfo.fname, "pic")) 
	  {
		if(counter>=up)	break;

        if(counter<down || counter>=up)
        {  counter++;  continue;   }

		   strcpy(File_name[file_conter].name,Finfo.fname);
		   counter++;
		   file_conter++;
	  }
   }

 }//for(;;)

  for(i=file_conter;i<12;i++)
  {
	File_name[i].name[0]='\0';
  }

  // Unregister a work area before discard it
  //f_mount(0, NULL);

  return file_conter;
} 





//删除一周前的相片
void Del_oneWeekAgo(void)
{
//   long p1;
//   UINT s1, s2;
  FRESULT res;
//   FATFS *fs;				/* Pointer to file system object */
  u32 today,weekAgo;

  f_mount(0, &Fatfs);
  //------------------------------------------

  res = f_opendir(&Dir, "\\");

  if (res) { return; }
  
  rtc_get();//获取当前时间
  today=timer.w_year*365+timer.w_month*30+timer.w_date;

//   p1 = s1 = s2 = 0;

 for(;;) {

#if _USE_LFN
	Finfo.lfname = Lfname;
	Finfo.lfsize = sizeof(Lfname);
#endif

	res = f_readdir(&Dir, &Finfo);
	if ((res != FR_OK) || !Finfo.fname[0]) break;
    /*
	if (Finfo.fattrib & AM_DIR) {
		s2++;
	} else {
		s1++; p1 += Finfo.fsize;
	}

	printf("%c%c%c%c%c %u/%02u/%02u %02u:%02u %9lu  %s\r\n",
		   (Finfo.fattrib & AM_DIR) ? 'D' : '-',
		   (Finfo.fattrib & AM_RDO) ? 'R' : '-',
		   (Finfo.fattrib & AM_HID) ? 'H' : '-',
		   (Finfo.fattrib & AM_SYS) ? 'S' : '-',
		   (Finfo.fattrib & AM_ARC) ? 'A' : '-',
		   (Finfo.fdate >> 9) + 1980, (Finfo.fdate >> 5) & 15, Finfo.fdate & 31,
		   (Finfo.ftime >> 11), (Finfo.ftime >> 5) & 63,
			Finfo.fsize, &(Finfo.fname[0]));
	*/
   if( strstr(Finfo.fname,"BMP") || strstr(Finfo.fname, "bmp"))
   {  
	  if( strstr(Finfo.fname,"PIC") || strstr(Finfo.fname, "pic")) 
	  {
	    weekAgo=((Finfo.fdate >> 9) + 1980)*365+((Finfo.fdate >> 5) & 15)*30+(Finfo.fdate & 31);
		//printf("weekAgo=%d    today=%d     %s\r\n",weekAgo,today, Finfo.fname);

	    if(today-weekAgo>=10)//是约一周之前的文件
		{ 
		   	f_unlink(Finfo.fname);
	    }
	  }
   }

#if _USE_LFN
	//printf("  %s\n", Lfname);
#else
	//printf("\n");
#endif
 
 }//for(;;)
	/*
	printf("%4u File(s),%10lu bytes total\n%4u Dir(s)", s1, p1, s2);

	if (f_getfree("\\", (DWORD*)&p1, &fs) == FR_OK)
		printf(", %10lu bytes free\n", p1 * fs->csize * 512);
	*/

  //-------------------------------------------
  // Unregister a work area before discard it
  f_mount(0, NULL);
  //SD_CS_DISABLE();
}
//FILE_NAME_LIT File_list[12]; 


