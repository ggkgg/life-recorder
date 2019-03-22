#include "head.h"

int main()
{
	//1.显示欢迎界面
	show_heart_logo();
	
	//2.清除屏幕的logo
	printf( CLEAR );
	usleep(500000);
	
	//3.显示主功能界面
	show_menu();
	
	return 0;
}