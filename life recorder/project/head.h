#ifndef _HEAD_H_ //如果没有定义过_HEAD_H_
#define _HEAD_H_ //则马上定义该宏

//头文件
#include <stdio.h>
#include <string.h>
#include <time.h>


//宏定义
#define RED                  "\e[0;31m"
#define NONE                 "\e[0m"
#define BLUE                 "\e[0;34m"
#define GREEN                "\e[0;32m"
#define CLEAR                "\e[2J"

//函数声明
void show_heart_logo();
void show_logo(int diameter);
void Register();
void Record();
void Check();

//结构体声明
typedef struct Record_info{
	unsigned long Study_start;
	unsigned long Study_Total;
	unsigned long Eat_start;
	unsigned long Eat_Total;
	unsigned long Sleep_start;
	unsigned long Sleep_Total;
	unsigned long Play_start;
	unsigned long Play_Total;
	unsigned long State_Start;
	unsigned long State_Total;
}Rinfo;

typedef struct user_info{
	char Name[20];
	unsigned char Age; 
	unsigned int Class;
	unsigned char State;
	Rinfo record_info;	
}Uinfo;



#endif