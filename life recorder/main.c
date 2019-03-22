#include "head.h"

int main()
{
	//1.显示欢迎界面
	system("./jpeg_show weixiao.jpg");
	
	system("madplay faded.mp3 -r &");
	
	show_heart_logo();
	
	//2.清除屏幕的logo
	printf( CLEAR );
	usleep(500000);
	
	//3.显示主功能界面
	show_menu();
	
	return 0;
}