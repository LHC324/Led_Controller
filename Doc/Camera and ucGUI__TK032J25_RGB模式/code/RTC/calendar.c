#include "calendar.h"
#include "stm32f10x.h"

//移植网友的代码
//超强的日历，支持农历，24节气几乎所有日历的功能
//日历时间以1970年为元年，用32bit的时间寄存器可以运行到2100年左右						   	    					  
//正点原子@SCUT
//V1.0

//年份表
unsigned char const year_code[597]=
{
0x04,0xAe,0x53, //1901 0
0x0A,0x57,0x48, //1902 3
0x55,0x26,0xBd, //1903 6
0x0d,0x26,0x50, //1904 9
0x0d,0x95,0x44, //1905 12
0x46,0xAA,0xB9, //1906 15
0x05,0x6A,0x4d, //1907 18
0x09,0xAd,0x42, //1908 21
0x24,0xAe,0xB6, //1909
0x04,0xAe,0x4A, //1910
0x6A,0x4d,0xBe, //1911
0x0A,0x4d,0x52, //1912
0x0d,0x25,0x46, //1913
0x5d,0x52,0xBA, //1914
0x0B,0x54,0x4e, //1915
0x0d,0x6A,0x43, //1916
0x29,0x6d,0x37, //1917
0x09,0x5B,0x4B, //1918
0x74,0x9B,0xC1, //1919
0x04,0x97,0x54, //1920
0x0A,0x4B,0x48, //1921
0x5B,0x25,0xBC, //1922
0x06,0xA5,0x50, //1923
0x06,0xd4,0x45, //1924
0x4A,0xdA,0xB8, //1925
0x02,0xB6,0x4d, //1926
0x09,0x57,0x42, //1927
0x24,0x97,0xB7, //1928
0x04,0x97,0x4A, //1929
0x66,0x4B,0x3e, //1930
0x0d,0x4A,0x51, //1931
0x0e,0xA5,0x46, //1932
0x56,0xd4,0xBA, //1933
0x05,0xAd,0x4e, //1934
0x02,0xB6,0x44, //1935
0x39,0x37,0x38, //1936
0x09,0x2e,0x4B, //1937
0x7C,0x96,0xBf, //1938
0x0C,0x95,0x53, //1939
0x0d,0x4A,0x48, //1940
0x6d,0xA5,0x3B, //1941
0x0B,0x55,0x4f, //1942
0x05,0x6A,0x45, //1943
0x4A,0xAd,0xB9, //1944
0x02,0x5d,0x4d, //1945
0x09,0x2d,0x42, //1946
0x2C,0x95,0xB6, //1947
0x0A,0x95,0x4A, //1948
0x7B,0x4A,0xBd, //1949
0x06,0xCA,0x51, //1950
0x0B,0x55,0x46, //1951
0x55,0x5A,0xBB, //1952
0x04,0xdA,0x4e, //1953
0x0A,0x5B,0x43, //1954
0x35,0x2B,0xB8, //1955
0x05,0x2B,0x4C, //1956
0x8A,0x95,0x3f, //1957
0x0e,0x95,0x52, //1958
0x06,0xAA,0x48, //1959
0x7A,0xd5,0x3C, //1960
0x0A,0xB5,0x4f, //1961
0x04,0xB6,0x45, //1962
0x4A,0x57,0x39, //1963
0x0A,0x57,0x4d, //1964
0x05,0x26,0x42, //1965
0x3e,0x93,0x35, //1966
0x0d,0x95,0x49, //1967
0x75,0xAA,0xBe, //1968
0x05,0x6A,0x51, //1969
0x09,0x6d,0x46, //1970
0x54,0xAe,0xBB, //1971
0x04,0xAd,0x4f, //1972
0x0A,0x4d,0x43, //1973
0x4d,0x26,0xB7, //1974
0x0d,0x25,0x4B, //1975
0x8d,0x52,0xBf, //1976
0x0B,0x54,0x52, //1977
0x0B,0x6A,0x47, //1978
0x69,0x6d,0x3C, //1979
0x09,0x5B,0x50, //1980
0x04,0x9B,0x45, //1981
0x4A,0x4B,0xB9, //1982
0x0A,0x4B,0x4d, //1983
0xAB,0x25,0xC2, //1984
0x06,0xA5,0x54, //1985
0x06,0xd4,0x49, //1986
0x6A,0xdA,0x3d, //1987
0x0A,0xB6,0x51, //1988
0x09,0x37,0x46, //1989
0x54,0x97,0xBB, //1990
0x04,0x97,0x4f, //1991
0x06,0x4B,0x44, //1992
0x36,0xA5,0x37, //1993
0x0e,0xA5,0x4A, //1994
0x86,0xB2,0xBf, //1995
0x05,0xAC,0x53, //1996
0x0A,0xB6,0x47, //1997
0x59,0x36,0xBC, //1998
0x09,0x2e,0x50, //1999 294
0x0C,0x96,0x45, //2000 297
0x4d,0x4A,0xB8, //2001 300
0x0d,0x4A,0x4C, //2002
0x0d,0xA5,0x41, //2003
0x25,0xAA,0xB6, //2004
0x05,0x6A,0x49, //2005
0x7A,0xAd,0xBd, //2006
0x02,0x5d,0x52, //2007
0x09,0x2d,0x47, //2008
0x5C,0x95,0xBA, //2009
0x0A,0x95,0x4e, //2010
0x0B,0x4A,0x43, //2011
0x4B,0x55,0x37, //2012
0x0A,0xd5,0x4A, //2013
0x95,0x5A,0xBf, //2014
0x04,0xBA,0x53, //2015
0x0A,0x5B,0x48, //2016
0x65,0x2B,0xBC, //2017
0x05,0x2B,0x50, //2018
0x0A,0x93,0x45, //2019
0x47,0x4A,0xB9, //2020
0x06,0xAA,0x4C, //2021
0x0A,0xd5,0x41, //2022
0x24,0xdA,0xB6, //2023
0x04,0xB6,0x4A, //2024
0x69,0x57,0x3d, //2025
0x0A,0x4e,0x51, //2026
0x0d,0x26,0x46, //2027
0x5e,0x93,0x3A, //2028
0x0d,0x53,0x4d, //2029
0x05,0xAA,0x43, //2030
0x36,0xB5,0x37, //2031
0x09,0x6d,0x4B, //2032
0xB4,0xAe,0xBf, //2033
0x04,0xAd,0x53, //2034
0x0A,0x4d,0x48, //2035
0x6d,0x25,0xBC, //2036
0x0d,0x25,0x4f, //2037
0x0d,0x52,0x44, //2038
0x5d,0xAA,0x38, //2039
0x0B,0x5A,0x4C, //2040
0x05,0x6d,0x41, //2041
0x24,0xAd,0xB6, //2042
0x04,0x9B,0x4A, //2043
0x7A,0x4B,0xBe, //2044
0x0A,0x4B,0x51, //2045
0x0A,0xA5,0x46, //2046
0x5B,0x52,0xBA, //2047
0x06,0xd2,0x4e, //2048
0x0A,0xdA,0x42, //2049
0x35,0x5B,0x37, //2050
0x09,0x37,0x4B, //2051
0x84,0x97,0xC1, //2052
0x04,0x97,0x53, //2053
0x06,0x4B,0x48, //2054
0x66,0xA5,0x3C, //2055
0x0e,0xA5,0x4f, //2056
0x06,0xB2,0x44, //2057
0x4A,0xB6,0x38, //2058
0x0A,0xAe,0x4C, //2059
0x09,0x2e,0x42, //2060
0x3C,0x97,0x35, //2061
0x0C,0x96,0x49, //2062
0x7d,0x4A,0xBd, //2063
0x0d,0x4A,0x51, //2064
0x0d,0xA5,0x45, //2065
0x55,0xAA,0xBA, //2066
0x05,0x6A,0x4e, //2067
0x0A,0x6d,0x43, //2068
0x45,0x2e,0xB7, //2069
0x05,0x2d,0x4B, //2070
0x8A,0x95,0xBf, //2071
0x0A,0x95,0x53, //2072
0x0B,0x4A,0x47, //2073
0x6B,0x55,0x3B, //2074
0x0A,0xd5,0x4f, //2075
0x05,0x5A,0x45, //2076
0x4A,0x5d,0x38, //2077
0x0A,0x5B,0x4C, //2078
0x05,0x2B,0x42, //2079
0x3A,0x93,0xB6, //2080
0x06,0x93,0x49, //2081
0x77,0x29,0xBd, //2082
0x06,0xAA,0x51, //2083
0x0A,0xd5,0x46, //2084
0x54,0xdA,0xBA, //2085
0x04,0xB6,0x4e, //2086
0x0A,0x57,0x43, //2087
0x45,0x27,0x38, //2088
0x0d,0x26,0x4A, //2089
0x8e,0x93,0x3e, //2090
0x0d,0x52,0x52, //2091
0x0d,0xAA,0x47, //2092
0x66,0xB5,0x3B, //2093
0x05,0x6d,0x4f, //2094
0x04,0xAe,0x45, //2095
0x4A,0x4e,0xB9, //2096
0x0A,0x4d,0x4C, //2097
0x0d,0x15,0x41, //2098
0x2d,0x92,0xB5  //2099
};
///////////////////////////////////////////////////////////////////////////////////////////////////////// 
//         以下为24节气计算相关程序			   
// 
//    每年24节气标志表   
//    有兴趣的朋友可按照上面给的原理添加其它年份的表格
//    不是很清楚的朋友可给我发EMAIL		   
/////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned char const YearMonthBit[]=
{
	0x4E,0xA6,0x99,		//2000
	0x9C,0xA2,0x98,		//2001
	0x80,0x00,0x18,		//2002
	0x00,0x10,0x24,		//2003
	0x4E,0xA6,0x99,		//2004
	0x9C,0xA2,0x98,		//2005
	0x80,0x82,0x18,		//2006
	0x00,0x10,0x24,		//2007
	0x4E,0xA6,0xD9,		//2008
	0x9E,0xA2,0x98,		//2009

	0x80,0x82,0x18,		//2010
	0x00,0x10,0x04,		//2011
	0x4E,0xE6,0xD9,		//2012
	0x9E,0xA6,0xA8,		//2013
	0x80,0x82,0x18,		//2014
	0x00,0x10,0x00,		//2015
	0x0F,0xE6,0xD9,		//2016
	0xBE,0xA6,0x98,		//2017
	0x88,0x82,0x18,		//2018
	0x80,0x00,0x00,		//2019

	0x0F,0xEF,0xD9,		//2020
	0xBE,0xA6,0x99,		//2021
	0x8C,0x82,0x98,		//2022
	0x80,0x00,0x00,		//2023
	0x0F,0xEF,0xDB,		//2024
	0xBE,0xA6,0x99,		//2025
	0x9C,0xA2,0x98,		//2026
	0x80,0x00,0x18,		//2027
	0x0F,0xEF,0xDB,		//2028
	0xBE,0xA6,0x99,		//2029

	0x9C,0xA2,0x98,		//2030
	0x80,0x00,0x18,		//2031
	0x0F,0xEF,0xDB,		//2032
	0xBE,0xA2,0x99,		//2033
	0x8C,0xA0,0x98,		//2034
	0x80,0x82,0x18,		//2035
	0x0B,0xEF,0xDB,		//2036
	0xBE,0xA6,0x99,		//2037
	0x8C,0xA2,0x98,		//2038
	0x80,0x82,0x18,		//2039

	0x0F,0xEF,0xDB,		//2040
	0xBE,0xE6,0xD9,		//2041 
	0x9E,0xA2,0x98,		//2042
	0x80,0x82,0x18,		//2043
	0x0F,0xEF,0xFB,		//2044
	0xBF,0xE6,0xD9,		//2045
	0x9E,0xA6,0x98,		//2046
	0x80,0x82,0x18,		//2047
	0x0F,0xFF,0xFF,		//2048
	0xFC,0xEF,0xD9,		//2049
	0xBE,0xA6,0x18 		//2050
};
const unsigned char days[24]=
{
	6,20,4,19,6,21,         //一月到三月  的节气基本日期
	5,20,6,21,6,21,         //四月到六月  的节气基本日期
	7,23,8,23,8,23,         //七月到九月  的节气基本日期
	8,24,8,22,7,22,         //十月到十二月的节气基本日期
};
//以公历日期先后排序
const char *JieQiStr[24]=   
{
 // 名称        角度    公历日期     周期 //
	"小寒",     //285     1月 6日
	"大寒",     //300     1月20日    29.5天
	"立春",     //315     2月 4日
	"雨水",     //330     2月19日    29.8天
	"惊蛰",     //345     3月 6日
	"春分",     //  0     3月21日    30.2天
	"清明",     // 15     4月 5日
	"谷雨",     // 30     4月20日    30.7天
	"立夏",     // 45     5月 6日
	"夏满",     // 60     5月21日    31.2天
	"芒种",     // 75     6月 6日
	"夏至",     // 90     6月21日    31.4天
	"小暑",     //105     7月 7日
	"大暑",     //120     7月23日    31.4天
	"立秋",     //135     8月 8日
	"处暑",     //150     8月23日    31.1天
	"白露",     //165     9月 8日
	"秋分",     //180     9月23日    30.7天
	"寒露",     //195    10月 8日
	"霜降",     //210    10月24日    30.1天
	"立冬",     //225    11月 8日
	"小雪",     //240    11月22日    29.7天
	"大雪",     //255    12月 7日
	"冬至"      //270    12月22日    29.5天
};

//下部分数据是农历部分要使用的
//月份数据表
u8  const day_code1[9]={0x0,0x1f,0x3b,0x5a,0x78,0x97,0xb5,0xd4,0xf3};
unsigned short const day_code2[3]={0x111,0x130,0x14e};
u8 const table_week[12]={0,3,3,6,1,4,6,2,5,0,3,5}; //月修正数据表
u8 const *sky[10]=  {"甲","乙","丙","丁","戊","己","庚","辛","壬","癸",};//天干
u8 const *earth[12]={"子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥",};//地支
u8 const *monthcode[12]={"一","二","三","四","五","六","七","八","九","十","冬","腊",};//农历月份
u8 const *nongliday[4]={"初","十","廿","三",};//农历日期  

tm timer;//时钟结构体 	  
//实时时钟配置
//BKP->DR1 bit3 时钟是否要重设?
void rtc_init(void)
{	
	//检查是不是第一次配置时钟
	u8 temp=0;
	//temp=FM24C16_ReadOneByte(52);
	if(temp&0X02)//系统继续计时
	{	
// 		printf("TIME Init OK!\n");							    					  
		//NVIC_RTCConfiguration();//RTC中断使能   
    	//while(!(RTC->CRL&(1<<3)));//等待RTC寄存器同步  
    	//RTC->CRH|=0X01;  		  //允许秒中断
    	//while(!(RTC->CRL&(1<<5)));//等待RTC寄存器操作完成	 
	}else //第一次配置(未开启秒中断!!)	
	{	
// 		printf("TIME need INIT!\n");								  
		//NVIC_RTCConfiguration(); //RTC中断使能	 
	  	RCC->APB1ENR|=1<<28;     //使能电源时钟	    
		RCC->APB1ENR|=1<<27;     //使能备份时钟
			
		PWR->CR|=1<<8;           //取消备份区写保护
		RCC->BDCR|=1<<16;        //备份区域软复位	   
		RCC->BDCR&=~(1<<16);     //备份区域软复位
				 
	    RCC->BDCR|=1<<0;         //开启外部低速振荡器 
	    while(!(RCC->BDCR&0X02));//等待外部时钟就绪	 
		RCC->BDCR|=1<<8; //LSI作为RTC时钟 	    
		RCC->BDCR|=1<<15;//RTC时钟使能	    

		RTC->PRLH=0X0000;
		RTC->PRLL=32770;          //时钟周期设置(有待观察,看是否跑慢了?)理论值：32767										 
	  	while(!(RTC->CRL&(1<<5)));//等待RTC寄存器操作完成
											   
		RTC->CRL|=1<<4;   //允许配置	  
		rtc_set(2009,4,19,23,59,55);//设置时间	  
		RTC->CRL&=~(1<<4);//配置更新
		while(!(RTC->CRL&(1<<5)));//等待RTC寄存器操作完成	
		temp|=0x02;//标记时钟被修改了
	 	//FM24C16_WriteOneByte(52,temp);  
	}
	rtc_get();//更新时间 
}
/*
//RTC时钟中断
//每秒触发一次   
void RTC_IRQHandler(void)
{
	u16 RTCCRL;	  
	RTCCRL=RTC->CRL;//读取FLAG
	if(RTCCRL&0x0001)//秒钟中断
	{
		rtc_get();//更新时间 
		printf("sec ok\n");	
	}
	if(RTCCRL&0x0002)//闹钟中断
	{
		RTC->CRL&=~(0x0002);//清闹钟中断
		//Alarm_Process();
		//闹钟处理
	} 				  								 
    RTC->CRL&=0X0FFA;         //清除溢出，秒钟中断标志
	while(!(RTC->CRL&(1<<5)));//等待RTC寄存器操作完成		   							 	   	 
}
*/

//月份   1  2  3  4  5  6  7  8  9  10 11 12
//闰年   31 29 31 30 31 30 31 31 30 31 30 31
//非闰年 31 28 31 30 31 30 31 31 30 31 30 31
//输入:年份
//输出:该年份是不是闰年.1,是.0,不是
u8 Is_Leap_Year(u16 year)
{			  
	if(year%4==0) //必须能被4整除
	{ 
		if(year%100==0) 
		{ 
			if(year%400==0)return 1;//如果以00结尾,还要能被400整除 	   
			else return 0;   
		}else return 1;   
	}else return 0;	
}

//设置时钟
//把输入的时钟转换为秒钟
//以1970年1月1日为基准
//1970~2099年为合法年份

//平年的月份日期表
const u8 mon_table[12]={31,28,31,30,31,30,31,31,30,31,30,31};
u8 rtc_set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec)
{
	u16 t;
	u32 seccount=0;
	if(syear<1970||syear>2099)return 0;	   
	for(t=1970;t<syear;t++)	//把所有年份的秒钟相加
	{
		if(Is_Leap_Year(t))seccount+=31622400;//闰年的秒钟数
		else seccount+=31536000;			  //平年的秒钟数
	}
	smon-=1;
	for(t=0;t<smon;t++)	   //把前面月份的秒钟数相加
	{
		seccount+=(u32)mon_table[t]*86400;//月份秒钟数相加
		if(Is_Leap_Year(syear)&&t==1)seccount+=86400;//闰年2月份增加一天的秒钟数	   
	}
	seccount+=(u32)(sday-1)*86400;//把前面日期的秒钟数相加 
	seccount+=(u32)hour*3600;//小时秒钟数
    seccount+=(u32)min*60;	 //分钟秒钟数
	seccount+=sec;//最后的秒钟加上去
													    
	//设置时钟
    RCC->APB1ENR|=1<<28;//使能电源时钟
    RCC->APB1ENR|=1<<27;//使能备份时钟
	PWR->CR|=1<<8;    //取消备份区写保护
	//上面三步是必须的!
	RTC->CRL|=1<<4;   //允许配置 
	RTC->CNTL=seccount&0xffff;
	RTC->CNTH=seccount>>16;
	RTC->CRL&=~(1<<4);//配置更新
	while(!(RTC->CRL&(1<<5)));//等待RTC寄存器操作完成  	
	return 1;	    
}
//从当前秒钟值,得到时间.
//返回值:0,失败;1,成功
u8 rtc_get(void)
{
	u32 timecount=0; 
	u32 temp=0;
	u16 temp1=0;   
	timecount=RTC->CNTH;//得到计数器中的值(秒钟数)
	timecount<<=16;
	timecount+=RTC->CNTL;			 

	temp=timecount/86400;   //得到天数(秒钟数对应的)
	temp1=1970;	//从1970年开始
	while(temp>=365)
	{				 
		if(Is_Leap_Year(temp1))//是闰年
		{
			if(temp>=366)temp-=366;//闰年的秒钟数
			else {temp1++;break;}  
		}
		else temp-=365;	  //平年 
		temp1++;  
	}   
	timer.w_year=temp1;//得到年份
	temp1=0;
	while(temp>=28)//超过了一个月
	{
		if(Is_Leap_Year(timer.w_year)&&temp1==1)//当年是不是闰年/2月份
		{
			if(temp>=29)temp-=29;//闰年的秒钟数
			else break; 
		}
		else 
		{
			if(temp>=mon_table[temp1])temp-=mon_table[temp1];//平年
			else break;
		}
		temp1++;  
	}
	timer.w_month=temp1+1;//得到月份
	timer.w_date=temp+1;  //得到日期		 

	temp=timecount%86400;     //得到秒钟数   	   
	timer.hour=temp/3600;     //小时
	timer.min=(temp%3600)/60; //分钟	
	timer.sec=(temp%3600)%60; //秒钟
	return 1;
}



///////////////////////////////////////////////////////////////////////
//支持从1900年到2099年的农历查询
//支持从2000年到2050年的节气查询
//子函数,用于读取数据表中农历月的大月或小月,如果该月为大返回1,为小返回0
u8 GetMoonDay(u8 month_p,unsigned short table_addr)
{
	switch (month_p)
	{
		case 1:
			if((year_code[table_addr]&0x08)==0)	return(0);
			else 								return(1); 
		case 2:
			if((year_code[table_addr]&0x04)==0)	return(0);
			else 								return(1);
		case 3:
			if((year_code[table_addr]&0x02)==0)	return(0);
			else 								return(1);
		case 4:
			if((year_code[table_addr]&0x01)==0)	return(0);
			else 								return(1);
		case 5:
			if((year_code[table_addr+1]&0x80)==0)	return(0);
			else 									return(1);
		case 6:
			if((year_code[table_addr+1]&0x40)==0)	return(0);
			else 									return(1);
		case 7:
			if((year_code[table_addr+1]&0x20)==0)	return(0);
			else 									return(1);
		case 8:
			if((year_code[table_addr+1]&0x10)==0)	return(0);
			else 									return(1);
		case 9:
			if((year_code[table_addr+1]&0x08)==0)	return(0);
			else 									return(1);
		case 10:
			if((year_code[table_addr+1]&0x04)==0)	return(0);
			else 									return(1);
		case 11:
			if((year_code[table_addr+1]&0x02)==0)	return(0);
			else 									return(1);
		case 12:
			if((year_code[table_addr+1]&0x01)==0)	return(0);
			else 									return(1);
		case 13:
			if((year_code[table_addr+2]&0x80)==0)	return(0);
			else 									return(1);
	}
	return(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////// 
// 函数名称:GetChinaCalendar
//功能描述:公农历转换(只允许1901-2099年)
// 输　入:  year        公历年
//          month       公历月
//          day         公历日
//          p           储存农历日期地址
// 输　出:  1           成功
//          0           失败																			 
/////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 GetChinaCalendar(u16  year,u8 month,u8 day,u8 *p)
{ 
	u8 temp1,temp2,temp3,month_p,yearH,yearL;	
	u8 flag_y;
	unsigned short temp4,table_addr;

	yearH=year/100;	yearL=year%100;//年份的高低两个字节 
	if((yearH!=19)&&(yearH!=20))return(0);//日期不在19xx ~ 20xx 范围内,则退出
	
	// 定位数据表地址  
	if(yearH==20)	table_addr=(yearL+100-1)*3;
	else  			table_addr=(yearL-1)*3;

	// 取当年春节所在的公历月份  
	temp1=year_code[table_addr+2]&0x60;	
	temp1>>=5;

	// 取当年春节所在的公历日  
	temp2=year_code[table_addr+2]&31; 

	// 计算当年春年离当年元旦的天数,春节只会在公历1月或2月  
	if(temp1==1) 	temp3=temp2-1; 
	else 			temp3=temp2+31-1; 

	// 计算公历日离当年元旦的天数  
	if (month<10) 	temp4=day_code1[month-1]+day-1;
	else  			temp4=day_code2[month-10]+day-1;
	// 如果公历月大于2月并且该年的2月为闰月,天数加1  
	if ((month>2)&&(yearL%4==0)) 	temp4++;

	// 判断公历日在春节前还是春节后  
	if (temp4>=temp3)
	{ 						
		temp4-=temp3;
		month=1;
		month_p=1;
							
		flag_y=0;
		if(GetMoonDay(month_p,table_addr)==0)	temp1=29; //小月29天
		else 									temp1=30; //大小30天
		// 从数据表中取该年的闰月月份,如为0则该年无闰月  
		temp2=year_code[table_addr]/16; 	
		while(temp4>=temp1)
		{
			temp4-=temp1;
			month_p++;
			if(month==temp2)
			{
				flag_y=~flag_y;
				if(flag_y==0)month++;
			}
			else month++;
			if(GetMoonDay(month_p,table_addr)==0)	temp1=29;
			else 									temp1=30;
		}
		day=temp4+1;
	}
	// 公历日在春节前使用下面代码进行运算  
	else
	{ 						
		temp3-=temp4;
		if (yearL==0)
		{
			yearL=100-1;
			yearH=19;
		}
		else yearL--;
		table_addr-=3;
		month=12;
		temp2=year_code[table_addr]/16; 	
		if (temp2==0)	month_p=12; 
		else 			month_p=13; 

		flag_y=0;
		if(GetMoonDay(month_p,table_addr)==0)	temp1=29; 
		else 									temp1=30; 
		while(temp3>temp1)
		{
			temp3-=temp1;
			month_p--;
			if(flag_y==0)		month--;
			if(month==temp2)	flag_y=~flag_y;
			if(GetMoonDay(month_p,table_addr)==0)	temp1=29;
			else 									temp1=30;
		}
		day=temp1-temp3+1;
	}

	*p++=yearH;
	*p++=yearL;
	*p++=month;
	*p=day;	
	return(1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 函数名称:GetWeek
// 功能描述:输入公历日期得到星期(只允许1901-2099年)
// 输　入:  year        公历年
//          month       公历月
//          day	        公历日
//          p           储存星期地址
// 输　出:  无																							 
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void GetWeek(u16 year,u8 month,u8 day,u8 *p)
{	
	u16 temp2;
	u8 yearH,yearL;
	
	yearH=year/100;	yearL=year%100;
	
	// 如果为21世纪,年份数加100  
	if (yearH>19)	 	yearL+=100;
	// 所过闰年数只算1900年之后的  
	temp2=yearL+yearL/4;
	temp2=temp2%7; 
	temp2=temp2+day+table_week[month-1];
	if (yearL%4==0&&month<3)temp2--;
	*p=(temp2%7);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 函数名称:GetSkyEarth
// 功能描述:输入公历日期得到一个甲子年(只允许1901-2099年)
// 输　入:  year        公历年
//          p           储存星期地址
// 输　出:  无																							   
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void GetSkyEarth(u16 year,u8 *p)
{
	u8 x;
	
	if(year>=1984)
	{
		year=year-1984;
		x=year%60;				
	}
	else
	{
		year=1984-year;
		x=60-year%60;
	}
	*p=x;
}
//将指定字符source复制no个给target
void StrCopy(u8 *target,u8 const *source,u8 no)
{
	u16 i;	 
	for(i=0;i<no;i++)
	{
		*target++=*source++;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 函数名称:GetChinaCalendarStr
// 功能描述:输入公历日期得到农历字符串	
//          如:GetChinaCalendarStr(2007,02,06,str) 返回str="丙戌年腊月十九"
// 输　入:  year        公历年
//          month       公历月
//          day         公历日
//          str         储存农历日期字符串地址   15Byte
// 输　出:  无																							  
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void GetChinaCalendarStr(u16 year,u8 month,u8 day,u8 *str)
{
	u8 NLyear[4];
	u8 SEyear;
	
	StrCopy(&str[0],(u8 *)"甲子年正月初一",15);
	if(GetChinaCalendar(year,month,day,(u8 *)NLyear)==0)	return;
	GetSkyEarth(NLyear[0]*100+NLyear[1],&SEyear);
	StrCopy(&str[0],(u8 *)  sky[SEyear%10],2);	//  甲
	StrCopy(&str[2],(u8 *)earth[SEyear%12],2);	//  子	
	
	if(NLyear[2]==1)	StrCopy(&str[6],(u8 *)"正",2);
	else				StrCopy(&str[6],(u8 *)monthcode[NLyear[2]-1],2);		
	
	if(NLyear[3]>10) 	StrCopy(&str[10],(u8 *)nongliday[NLyear[3]/10],2);	
	else				StrCopy(&str[10],(u8 *)"初",2);
	StrCopy(&str[12],(u8 *)monthcode[(NLyear[3]-1)%10],2);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 函数名称:GetJieQi
// 功能描述:输入公历日期得到本月24节气日期 day<15返回上半月节气,反之返回下半月	
//          如:GetJieQiStr(2007,02,08,str) 返回str[0]=4
// 输　入:  year        公历年
//          month       公历月
//          day         公历日
//          str         储存对应本月节气日期地址   1Byte
// 输　出:  1           成功
//          0           失败																			  
/////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 GetJieQi(u16 year,u8 month,u8 day,u8 *JQdate)
{
	u8 bak1,value,JQ;

	if((year<2000)||(year>2050))     return 0;//节气表的范围限制
	if((month==0) ||(month>12))      return 0;
	JQ = (month-1) *2 ;		                        //获得节气顺序标号(0～23
	if(day >= 15) JQ++; 	                        //判断是否是上半月

	bak1=YearMonthBit[(year-2000)*3+JQ/8];          //获得节气日期相对值所在字节  
	value =((bak1<<(JQ%8))&0x80);                   //获得节气日期相对值状态

	*JQdate=days[JQ];								//得到基本节气日
	if( value != 0 )
	{
		//判断年份,以决定节气相对值1代表1,还是－1。
		if( (JQ== 1||JQ== 11||JQ== 18||JQ== 21)&&year< 2044)  (*JQdate)++;
		else                                                  (*JQdate)--;
	}
	return 1;
}
static u8 const MonthDayMax[]={31,28,31,30,31,30,31,31,30,31,30,31,};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 函数名称:GetJieQiStr
// 功能描述:输入公历日期得到24节气字符串	
//          如:GetJieQiStr(2007,02,08,str) 返回str="离雨水还有11天"
// 输　入:  year        公历年
//          month       公历月
//          day         公历日
//          str         储存24节气字符串地址   15Byte
// 输　出:  1           成功
//          0           失败																			  
/////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 GetJieQiStr(u16 year,u8 month,u8 day,u8 *str)
{
	u8 JQdate,JQ,MaxDay;

	if(GetJieQi(year,month,day,&JQdate)==0)	return 0;

	JQ = (month-1) *2 ;                             //获得节气顺序标号(0～23
	if(day >= 15) JQ++;                             //判断是否是上半月

	if(day==JQdate)                                 //今天正是一个节气日
	{
		StrCopy(str,(u8 *)JieQiStr[JQ],5);
		return 1;
	}
	                                                //今天不是一个节气日
	StrCopy(str,(u8 *)"离小寒还有??天",15);
	if(day<JQdate)                                  //如果今天日期小于本月的节气日期
	{
		StrCopy(&str[2],(u8 *)JieQiStr[JQ],4);
		day=JQdate-day;
	} 
	else                                            //如果今天日期大于本月的节气日期
	{
		StrCopy(&str[2],(u8 *)JieQiStr[JQ+1],4);
		if(day < 15)
		{
			GetJieQi(year,month,15,&JQdate);
			day=JQdate-day;
		}
		else                                        //翻月
		{
			MaxDay=MonthDayMax[month-1];
			if(month==2)                            //润月问题
			{
				if((year%4==0)&&((year%100!=0)||(year%400==0))) MaxDay++;
			}
			if(++month==13)	month=1;
			GetJieQi(year,month,1,&JQdate);
			day=MaxDay-day+JQdate;
		}
	}
	str[10]=day/10+'0';
	str[11]=day%10+'0';
	return 1;
}
