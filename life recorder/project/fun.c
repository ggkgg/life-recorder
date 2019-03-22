#include "head.h"

Uinfo UserInfo[5];
int registerd = 0;//初始化为0，表示当前没有用户注册过
char smap[5];//5个位置都是为0，没有用户注册过

void show_heart_logo()
{
	show_logo(50);
	usleep(300000); //0.3秒
	show_logo(25);
	usleep(300000); //0.3秒
	
	show_logo(50);
	usleep(300000); //0.3秒
	show_logo(25);
	usleep(300000); //0.3秒
	
	return ;
}

void show_logo(int diameter) //形式参数
{
	 int i,j,n,a,b,m,t;
	 
	 printf( CLEAR );  //清除屏幕
	 printf( RED );    //设置画笔为红色
	 n=(diameter+1)/2;
	 m=3*n/4;
	 b=(80-diameter)/2;

	 for(i=m/2;i<n/2;i++)
	 {
		  for(j=0;j<n/2-i;j++)
		   printf("  ");
		  for(j=0;j<2*i-n/2;j++)
		   printf("**");
		  for(j=0;j<2*(n/2-i)-1;j++)
		   printf("  ");
		  printf(" ");
		  for(j=0;j<2*i-n/2;j++)
		   printf("**");

	  	printf("\n");
	 }
	 for(i=n/2;i>0;i--)
	 {
	  if(i==n/2)
	  {
		   printf(" ");
		   for(j=0;j<4*i-3;j++)
		    printf("*");
		   printf("\n");
	  }
	  else
	  {
		   for(j=0;j<n/2-i;j++)
		    printf("  ");
		   for(j=0;j<4*i-1;j++)
		    printf("*");
		   printf("\n");
	  }
	 }
	 if(n%2==0)
	 {
		  for(j=0;j<n-1;j++)
		   printf(" ");
		  printf("*\n");
	 }
	 else
	 {
		  for(j=0;j<n-2;j++)
		   printf(" ");
		  printf("*\n");
	 }

	  printf(NONE);
	  return;

}

void show_menu()
{
	int operate;
	
	do{
	//1.显示菜单	
	printf("*************GEC Live System**************\n");
	printf("*********** ACCOUNT OPERATE***************\n");
	printf("*          1: register                   *\n");
	printf("*          2: record                     *\n");
	printf("*          3: check                      *\n");
	printf("*          4: exit                       *\n");
	printf("******************************************\n");
	
	//2.输入选项
	printf("pls input a operate:");
	scanf("%d",&operate);
	
		//3.判断选项的值
		switch(operate)
		{
			case 1:
				//注册函数
				Register();
				continue;
				
			case 2:
				//监测函数
				Record();
				continue;
			
			case 3:
				//显示数据函数
				Check();
				continue;			
			case 4:
				//退出系统
				return;
				
			default:
				return;
			
		}
	}while(1);
	
	return;
}

void Register()
{
	int operate,i,state;
	char Name[20];
	
	do{
		
	printf("*************user register***************\n");
	printf("*********** ACCOUNT OPERATE***************\n");
	printf("*          1: Add New user               *\n");
	printf("*          2: delete user                *\n");
	printf("*          3: exit                       *\n");
	printf("******************************************\n");
	
	printf("pls input a operate:");
	scanf("%d",&operate);
	
		switch(operate)
		{
			case 1:
				//1.判断注册过的用户数目是否大于5
				if(registerd >= 5)
				{
					printf("The registerd max!\n");
				}
				
				//以下代码肯定能找到位置注册
				
				//2.遍历数组5个位置，看看哪个位置的smap[i] == 0
				for(i=0;i<5;i++)
				{
					if(smap[i] == 0)
					{
						//可注册状态
						state = 1;
						break;
					}
					else{ //smap[i] == 1
						//不可注册状态
						state = 0;
						continue;
					}	
				}
				
				//找到位置，并且可注册状态，就开始注册！
				if(state == 1)
				{
					printf("please input your Name:");
					scanf("%s",UserInfo[i].Name);
					
					printf("please input your Age:");
					scanf("%d",(int *)&(UserInfo[i].Age));
					
					printf("please input your Class:");
					scanf("%d",&(UserInfo[i].Class));
					
					printf("please input your State:");
					scanf("%d",(int *)&(UserInfo[i].State));
					
					//情感状态开始为值注册时的值
					UserInfo[i].record_info.State_Start = UserInfo[i].State;

					printf("\n\n");
					printf("New register user:!\n");
					printf("No.%d\n",i);
					printf("user Name:%s\n",UserInfo[i].Name);	
					printf("user Age:%d\n",UserInfo[i].Age);
					printf("user Class:%d\n",UserInfo[i].Class);
					printf("user State:%d\n",UserInfo[i].State);
					
					smap[i] = 1;
					registerd++;	
				}
				
				continue;
				
			case 2:
				//1.判断已经注册过的用户的总数是否等于0
				if(registerd == 0)
				{
					printf("No user register!\n");
					break;
				}
				
				//2.如果有注册过用户，则需要输入删除的人的名字
				printf("pls input delete name:");
				scanf("%s",Name);
				
				//3.与数组上的成员进行匹配，找到需要删除这个人
				for(i=0;i<5;i++)
				{
					if(strcmp(Name,UserInfo[i].Name) == 0)
					{
						state = 1;
						printf("found delete user!\n");
						//一旦找到，则跳出循环，不用继续找了
						break;
					}
					else{
						state = 0;
						//没有找到，则继续循环找人
						printf("not found user!\n");
						continue;
					}		
				}
				
				//4.如果找到了，则把这个结构体的数据清空
				if(state == 1)
				{
					memset(&(UserInfo[i]),0,sizeof(Uinfo));
					smap[i] = 0;
					registerd--;
				}
				continue;
				
			case 3:
				return;
			
			default:
				return;	
		}	
	}while(1);
	return ;
}

void Record()
{
	int i;
	int operate;
	time_t timer;
	
	do{
	printf("*************user Record***************\n");
	printf("************Select Name****************\n");
	
	//1.遍历整个数组
	for(i=0;i<5;i++)
	{
		//表示当前的位置已经有用户注册过，就把名字打印出来
		if(smap[i] == 1)
		{
			printf("             %d.%s\n",i,UserInfo[i].Name);
		}	
	}
	
	//2.输入需要检测的人的下标
	printf("pls select a user:<9 to exit>");
	scanf("%d",&i);
	if(i == 9)
		return;
	
	//已经知道监测哪一个人了！
	//3.选择这个人需要监测项目
	printf("*************user Record*******************\n");
	printf("*********** ACCOUNT OPERATE****************\n");
	printf("*          1: Study Record               **\n");
	printf("*          2: Eat Record                 **\n");
	printf("*          3: Sleep Record               **\n");
	printf("*          4: Play Record                **\n");
	printf("*          5: State Record               **\n");
	printf("*          6: exit                       **\n");
	printf("*******************************************\n");
	
	printf("pls select a Record");
	scanf("%d",&operate);
	
	switch(operate)
	{
		case 1:
			printf("Now start Record Study time!\n");
			printf(" 1.Record   2.Stop \n");
			scanf("%d",&operate);
			if(operate == 1)
			{
				//4.把开始学习的时间记录下来，并赋值给Study_start
				timer = time(NULL);
				UserInfo[i].record_info.Study_start = timer;
				//距离1970年1月1日到现在的秒数
				//printf("timer: %ld \n",(long)timer);
				//以年月日的格式字符串打印出来
				printf("timer: %s\n",(char *)ctime(&timer));	
			}
			else{
				timer = time(NULL);
				printf("timer: %s\n",(char *)ctime(&timer));
				
				UserInfo[i].record_info.Study_Total += timer - UserInfo[i].record_info.Study_start;
				printf("%lu s\n",UserInfo[i].record_info.Study_Total);
			}
			continue;
		
		case 2:
			printf("Now start Record Eat time!\n");
			printf(" 1.Record   2.Stop \n");
			scanf("%d",&operate);
			if(operate == 1)
			{
				//5.把开始吃的时间记录下来，并赋值给Eat_start
				timer = time(NULL);
				UserInfo[i].record_info.Eat_start = timer;
				//距离1970年1月1日到现在的秒数
				//printf("timer: %ld \n",(long)timer);
				//以年月日的格式字符串打印出来
				printf("timer: %s\n",(char *)ctime(&timer));	
			}
			else{
				timer = time(NULL);
				printf("timer: %s\n",(char *)ctime(&timer));
				
				UserInfo[i].record_info.Eat_Total += timer - UserInfo[i].record_info.Eat_start;
				printf("%lu s\n",UserInfo[i].record_info.Eat_Total);
			}
			continue;
		case 3:
			printf("Now start Record Sleep time!\n");
			printf(" 1.Record   2.Stop \n");
			scanf("%d",&operate);
			if(operate == 1)
			{
				//6.把开始睡觉的时间记录下来，并赋值给Sleep_start
				timer = time(NULL);
				UserInfo[i].record_info.Sleep_start = timer;
				//距离1970年1月1日到现在的秒数
				//printf("timer: %ld \n",(long)timer);
				//以年月日的格式字符串打印出来
				printf("timer: %s\n",(char *)ctime(&timer));	
			}
			else{
				timer = time(NULL);
				printf("timer: %s\n",(char *)ctime(&timer));
				
				UserInfo[i].record_info.Sleep_Total += timer - UserInfo[i].record_info.Sleep_start;
				printf("%lu s\n",UserInfo[i].record_info.Sleep_Total);
			}
			continue;
		case 4:
			printf("Now start Record Play time!\n");
			printf(" 1.Record   2.Stop \n");
			scanf("%d",&operate);
			if(operate == 1)
			{
				//7.把开始玩的时间记录下来，并赋值给Play_start
				timer = time(NULL);
				UserInfo[i].record_info.Play_start = timer;
				//距离1970年1月1日到现在的秒数
				//printf("timer: %ld \n",(long)timer);
				//以年月日的格式字符串打印出来
				printf("timer: %s\n",(char *)ctime(&timer));	
			}
			else{
				timer = time(NULL);
				printf("timer: %s\n",(char *)ctime(&timer));
				
				UserInfo[i].record_info.Play_Total += timer - UserInfo[i].record_info.Play_start;
				printf("%lu s\n",UserInfo[i].record_info.Play_Total);
			}
			continue;
		case 5:
			printf("Now start Record Study time!\n");
			printf(" 1.Single   2.Pair \n");
			scanf("%d",&operate);
			if(operate == 1)
			{
				if(UserInfo[i].record_info.State_Start == 2)
				{
					printf("oh my god\n");
				}
				
				UserInfo[i].State = 1;
				UserInfo[i].record_info.State_Start = 1;
			}
			else
			{
				if(UserInfo[i].record_info.State_Start == 1)
				{
					printf("enjoy your new life!\n");
				}
				
				UserInfo[i].State = 2;
				UserInfo[i].record_info.State_Start = 2;	
			}
			continue;
		
		case 6:
			return ;
		
		default:
			return ;
	}
	
	}while(1);
}

void Check()
{
	//1.输入你需要查看的用户的名字
	
	//2.遍历数组，找到这个人
	
	//3.打印这个人的值（ID，名字，年龄，情感状态）
	
	
}






