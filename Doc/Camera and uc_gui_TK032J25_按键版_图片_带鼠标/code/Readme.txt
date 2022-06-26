1 软件程序设计
	简易声音播放器的软件工作过程：通过SPI1从SD卡中读取声波文件，将所读取的部分存放在一个缓冲
	器中，利用TIMER2通道1定期产生的中断，从缓冲器中读取声音数据，然后根据声音数据通过TIMER4的
	通道3产生不同频率方波输出。这里使用了两个缓冲器，一个用于存放从SD卡读到的声音数据，另一个
	用于将声音数据输出到PWM，两个缓冲区的功能不断交替，形成一个由2个缓冲区构成的环形缓冲。播
	放声波文件由PC机通过超级终端以命令的方式选择，声音的播放状态也显示在PC机超级终端上。
该系统软件程序主要包含以下源文件，下面分别介绍其中主要的一些函数。限于篇幅这里不能给出工程的
全部源代码，读者可在www.realview.com.cn网站下载。

main.c
该源文件包含以下几个主要函数：
 	SetupClock：用于初始化并设置系统时钟，并允许GPIOA、GPIOB、TIM2、TIM4和SPI的时钟；
 	Speaker_Timer_Config:用于配置定时器TIM2和TIM4，TIM4的通道3处于PWM1模式；TIM2的通道1工作于
	输出比较模式，定期发出中断，在每次中断修改TIM4通道3相关寄存器，使之产生不同频率的方波； 
 	USART_Scanf_Name和USART_Scanf_Cmd：用于从超级终端获取输入字符串；
 	PrintPass：用于在超级终端上输出提示符"X:>"；
 	main: 主函数，首先初始化系统时钟、串口、连接SD卡的SPI1，与SD进行通讯初始化，检测并在超级
	终端上打印SD卡的信息；然后根据用户在超级中输入的命令进行操作，这里有"dir"、"cd"、"read"、
	"free"、"play"五个简单的命令，分别是目录项列表、目录更换、以文本方式读取文件、查询SD空余
	空间和播放声音文件；如果输入"Play ***.wav"，则处理器开始从SD卡中读取相应的声波文件，并将
	其放入相应的缓冲区；
 
msd.c
该文件用于提供SD卡的驱动，由ST公司所带例程提供，本系统用到以下一些函数。
 	SPI_Config：配置与SD卡相连接的SPI1；
 	MSD_Init：初始化SD卡通讯；
 	MSD_WriteByte：向SD卡写一个字节；
 	MSD_WriteByte：从SD卡读一个字节；
 	MSD_GoIdleState：令SD卡处于空闲态；
 	Get_Medium_Characteristics：获取SD卡的容量；
 	MSD_SendCmd：向SD卡发命令；
 	MSD_GetResponse：从SD卡获取响应；
 	MSD_ReadBlock：从SD卡读取一块数据；
 
fat16.c
该文件提供FAT16文件系统的支持，主要包含以下一些函数：
 	ReadMBR：读取MBR数据结构；
 	ReadBPB：读取BPB数据结构；
 	ReadFAT：读取文件分配表指定项；
 	ReadBlock：读取一个扇区；
 	FAT_Init：获取FAT16文件系统基本信息；
 	DirStartSec：获取根目录的开始扇区号；
 	DataStartSec：获取数据区的开始扇区号；
 	ClusConvLBA：获取一个簇的开始扇区号；
 	LBAConvClus：转换扇区号与簇号之间的关系；
 	LBAConvClus：计算可用空间，返回字节数；
 	GetFileName：获取指定文件的首扇区号；
 	List_DateAndTime：获取文件或目录项的日期时间；
 	SearchFoler：在指定范围内查找子目录；
 	List_AllDir_Long：列出指定范围内的目录及目录信息；
 	FAT_FileOpen：打开指定文件；
 	FAT_FileRead：读取文件数据；

uart.c
该文件提供USART串口驱动函数，可以参考7.5串行通讯接口实例的程序；

hw_config.c
该文件包含系统初始化设置函数和中断配置函数。
 	Set_System：用于提供系统时钟及电源设置；
 	NVIC_Config：用于设置中断向量，允许TIM2中断；

stm32f10x_it.c
该文件仅包含一个函数TIM2_IRQHandler，即在每次TIM2中断时从缓冲器中读取音频数据送TIM4定时器，
以用于产生不同频率的声音。

UnicodeToGB2312.c
该文件仅包含一个函数UnicodeToGB2312，处理从UniCode编码到GB2312字符的转换，用于处理长文件名。

2 运行过程
(1)	使用MDK通过ULINK 2仿真器连接开发板，或使用两根USB电缆分别将CN1和CN5 与PC机USB端口相连
（使用板上自带的UlinkMe）； 
(2)	使用串口线将开发板的串口COM0与PC机连接，在PC机上运行windows自带的超级终端串口通信程序
（波特率115200、1位停止位、无校验位、无硬件流控制）；或者使用其它串口通信程序；
(3)	打开实验例程目录MP3 Player\Simple Wave Player下的Simple Wave Player.Uv2工程，将其编译链
接后烧写到开发板中；
(4)	将带有测试声波文件TEST1.wav、TEST2.wav拷贝到SD卡中，并将SD插入评估板的SD连接器中；
(5)	重启动开发板，在超级终端上将看到SD卡的信息以及提示符"X:>"，键入dir命令然后回车将列出
SD卡上的所有文件和目录；
(6)	可在超级终端中输入"dir"、"cd"、"free"、"read"等命令（注：read 命令后跟文件名；读出并
输出文件的文本内容，可以正确显示文本文件如以txt,c,h,s为后缀的文件），观察运行结果；注意，
由于程序中没有进行大小写转换，因此命令只能使用小写；
(7)	在超级终端中输入"play TEST1.wav"或"play TEST2.wav"，如果程序运行正常，通过开发板的扬声
器或者耳机将能听到音乐声。
