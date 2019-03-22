#include"myhead.h"

struct student
{ 
	char age[10];
	char name[20];
	char tel[15];
	char sch[30];
	char class[20];
	char emotional[5];

	
}stu[100];

int k=0;

int study_time[3];

int rest_time[3];

float consume_money[3];



int main(int argc ,char *argv[])
{
	system("clear");
	heart();
	system("clear");
	menu();
	return 0;
}




void menu()//主菜单界面
{
	int a;  
   do
   {

		printf("\n\n       **************************************************\n");
		printf("       *");printf("\t\t学习生活记录仪");       printf("\t\t*\n");
		printf("       **************************************************\n");
		printf("       *");printf("****************GEC Live System******************\n");
		printf("       *");printf("****************ACCOUNT OPERATE******************\n");
		printf("       *");printf("\t\t1.注册用户信息    ---》");  printf("\t\t*\n");
		printf("       *");printf("\t\t2.显示用户信息    ---》");  printf("\t\t*\n");
		printf("       *");printf("\t\t3.记录用户状态    ---》");  printf("\t\t*\n");
		printf("       *");printf("\t\t4.删除用户信息    ---》");  printf("\t\t*\n");
		printf("       *");printf("\t\t5.参与用户评比    ---》");  printf("\t\t*\n");
		printf("       *");printf("\t\t6.退出用户系统    ---》");        printf("\t\t*\n");
		printf("       **************************************************\n");
    
		printf(" 请选择 : ");
		scanf("%d",&a);
   
 		switch(a)//选择函数
		{
			case 1:printf("\n");system("clear");input();break;
			case 2:printf("\n");system("clear");display();break;
			case 3:printf("\n");system("clear");time1();break;
			case 4:printf("\n");system("clear");delete1();break;
			case 5:printf("\n");system("clear");appraisal1();break;
			case 6:printf("\n");system("clear");exit(0);break;
			default:system("clear");printf("\n请选择 1 到 6.\n");
		} 
   }while(a!=0);
}

void input()//注册用户信息函数
{  
	char ch[20];
	printf("\n------------------------输入用户信息------------------------\n");
	do
	{
		if (k>2)
		{
			printf("只允许注册三个用户0.0\n");
			printf("正在退出....");sleep(1);
			break;
		}
		printf("\n请输入姓名: ");
		scanf("%s",stu[k].name);
		printf("\n请输入年龄: ");
		scanf("%s",stu[k].age);
		printf("\n请输入联系方式: ");
		scanf("%s",stu[k].tel);
		printf("\n请输入学校: ");
		scanf("%s",stu[k].sch);
		printf("\n请输入班级: ");
		scanf("%s",stu[k].class);
		printf("\n请输入情感状态: ");
		scanf("%s",stu[k].emotional);
		
		k++;
		printf("是否继续注册学生信息?(y/n)\n");
		scanf ("%s",(char*)&ch);
	}while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0);//strcmp函数确认输入
	system("clear");
	printf("-------------------注册成功------------------\n");
	sleep(1);
	system("clear");
}

void display()//显示用户信息函数
{  
	int i;
	char a;
    printf(" -------------------------用户信息是:--------------------------\n");
	printf("姓名      年龄      联系方式    学校     班级     情感状态\n");
	for(i=0;i<3;i++)
	{
	printf("%-10s %-10s %-10s %-10s %-7s %-7s  \n",stu[i].name,stu[i].age,stu[i].tel,stu[i].sch,stu[i].class,stu[i].emotional);//打印结构体中数据
    }
	printf("---------------------------------------------------------------");
	printf("\n");
	printf("                 。。。                   ");
	sleep(1);

	
	printf("正在转入主界面...\n");  
	sleep(2);
	system("clear");
}




void heart()//打印心型函数
{
	int i,j,n,b,m,t;
	int a=78;
	printf( CLEAR );  //清除屏幕
	printf( RED );    //设置画笔为红色
	n=(a+1)/2;
	m=3*n/4;
	b=(80-a)/2;

	for(i=m/2;i<n/2;i++)
	{
		for(j=0;j<n/2-i;j++)
		printf("  ");usleep(10000);//闪屏
		for(j=0;j<2*i-n/2;j++)
		printf("**");usleep(10000);
		for(j=0;j<2*(n/2-i)-1;j++)
		printf("  ");usleep(10000);
		printf(" ");usleep(10000);
		for(j=0;j<2*i-n/2;j++)
		printf("**");usleep(10000);

	  	printf("\n");usleep(10000);
	}
	for(i=n/2;i>0;i--)
	{
		if(i==n/2)
		{
		printf(" ");usleep(10000);
		for(j=0;j<4*i-3;j++)
		printf("*");usleep(10000);
		printf("\n");usleep(10000);
		}
		else
		{
		for(j=0;j<n/2-i;j++)
		printf("  ");usleep(10000);
		for(j=0;j<4*i-1;j++)
		printf("*");usleep(10000);
		printf("\n");usleep(10000);
		}
	}
	if(n%2==0)
	{
		  for(j=0;j<n-1;j++)
		   printf(" ");usleep(10000);
		  printf("*\n");usleep(10000);
	 }
	 else
	 {
		  for(j=0;j<n-2;j++)
		   printf(" ");usleep(10000);
		  printf("*\n");usleep(100000);
	 }
	 sleep(1);
	printf(NONE);
}


void appraisal1()//用户评比函数
{
	char a[20];
	int i,b;
	int point;
	aa:printf("\n");
	system("clear");
	printf("---------------------------------------\n");
	printf("      需要参与评比的学生为：\n");
	printf("---------------------------------------\n");
	scanf("%s",a);
	for (i=0;i<k;i++)
	{
		if(strcmp(stu[i].name,a)==0)//strcmp函数确认用户
		{
			point=study_time[i]*2-rest_time[i];
			printf("-------------------------\n");
			printf("该用户总共学习了%d秒。\n",study_time[i]);
			printf("该用户总共休息了%d秒。\n",rest_time[i]);
			printf("该用户总共消费了%f元。\n",consume_money[i]);usleep(100000);
			printf("该用户的评分为%d分!!!\n",point);
			printf("-------------------------\n");
			printf("输入1查看其它用户评分\n输入2退出\n");
			scanf("%d",&b);
			if(b==1)
			{
				goto aa;
			}
			else if(b==2)
			{
				goto bb;
			}
			else
				break;
		}
	}
	printf("输入错误\n");
	
	bb:printf ("\n");
	printf ("正在转入主菜单\n");
	sleep(1);
	system("clear");
}




void time1()//用户状态函数
{
	int a,b=0,c=0,d=0,e=0;  
	float f=0,g=0;
	char h[20];
	int i;
	aa:printf("\n");
	printf("请输入需要更改状态的学生:\n");
	scanf("%s",h);
	for(i=0;i<k;i++)
	{
		if(strcmp(stu[i].name,h)==0)
		{
			do
			{			
				printf("       **************************************************\n");
				printf ("1 .开始学习\n");
				printf ("2 .开始休息\n");
				printf ("3 .开始消费\n");
				printf ("4 .更改学生\n");
				printf ("5 .返回界面\n");
				printf("       **************************************************\n");
				printf(" 请选择 :\n");
				scanf("%d",&a);
   
				switch(a)
				{
					case 1:
					printf("\n");b=time_study();c+=b;study_time[i]=study_time[i]+c;
					printf("总的学习时间为%d秒\n\n\n",study_time[i]);break;
					
					case 2:
					printf("\n");d=time_rest();e+=d;rest_time[i]=rest_time[i]+e;
					printf("总的休息时间为%d秒\n\n\n",rest_time[i]);break;
					
					case 3:
					printf("\n");f=consume();g+=f;consume_money[i]=consume_money[i]+g;
					printf("总的消费金额为%f元\n\n\n",consume_money[i]);break;
					
					case 4:
					printf("\n");
					system("clear");time1();break;
					
					case 5:
					printf("\n");printf("返回主界面");
					system("clear");menu();break;
					
					default:printf("\n请选择 1 到 5\n");
				}
			}while(a!=0);

		}
	printf("输入错误，正在返回\n");
	
	sleep(1);
	system("clear");
	goto aa;
	}
}


float consume()//用户消费函数
{
	float a;
	printf ("请输入消费金额:\n");
	scanf("%f",&a);
	printf ("本次消费金额为%f元\n",a);
	printf ("消费完成  正在退出..\n");
	sleep(1);
	return a;
}


int time_study()//学习时间函数
{
	int  sum=0;

	int a,hour,min,second;
	time_t start, end;
	system("clear");

	printf("------------------------本次学习开始-------------------\n");
	time(&start);
	sleep(2);printf("\n\n\n\n\n");
	aa:printf ("\n");
	printf("-----------------------输入1结束学习-------------------\n");
	scanf("%d",&a);
	
	if(a==1)
	{
		time(&end);
	}
	else 
	{
		sleep(1);
		goto aa;
	}
	

	sum=difftime(end,start);
	hour=sum/3600;
	min=sum/60;
	second=(sum%3600)%60;
	
	system("clear");
	printf("本次学习时间为 %d时%d分%d秒。\n",hour,min,second);

	return sum;
	
}




int time_rest()//休息时间函数
{
	int sum=0 ;
	int a,hour,min,second;
	time_t start, end;
	system("clear");
	
	printf("----------------------本次休息开始--------------\n");
	time(&start);
	sleep(2);printf("\n\n\n\n\n");
	aa:printf("\n");
	printf("----------------------输入1结束休息-------------\n");
	scanf("%d",&a);
	
	if (a==1)
		time(&end);
	else
	{
		sleep(1);
		goto aa;
	}
	
	sum=difftime(end,start);
	hour=sum/3600;
	min=sum/60;
	second=(sum%3600)%60;
	
	system("clear");
	printf("本次休息时间为 %d时%d分%d秒。\n",hour,min,second);
	
	return sum;
	
}


void delete1()//删除函数
{
	int pass[4]; int i,j,l,flag;
    char a[20],ch[10],c[20];
    printf("这是信息管理系统:\n");
  
	flag=0;
	printf(" 输入管理员密码: ");
	scanf("%1d%1d%1d%1d",&pass[0],&pass[1],&pass[2],&pass[3]);
	for(i=0;i<4;i++)
	{
	if(pass[i]==i+1)  flag=flag+1;
	}
	if(flag==4)
	{
		printf("\n确定要删除信息吗(y/n): ");
		scanf("%s",ch);
		if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
		{
			printf("\n确定要删除吗 ：\n");
			printf("要删除的用户姓名为:\n");
			scanf("%s",(char*)&c);
			for(i=0;i<k;i++)
			{
				if(strcmp(c,stu[i].name)==0)  
				for(j=i;j<=2;j++)
				{
					stu[j]=stu[j+1];
				}//循环覆盖，让后一个覆盖前一个
				printf("\t\t\t删除成功 %s\n",c);
				k--; //结构体中的元素减少1个
			}
		}
		else
		{
			printf("正在转入主菜单\n");
			sleep(2);
			system("clear");
			menu();
		}
	}
	else 
	{
		printf("\n密码错误.\n\n"); 
		printf ("正在转入主菜单");
		sleep(2);
		system("clear");
		menu();
	}
}











