#include <stdio.h>  
#include <stdlib.h> 
#include <malloc.h>
#include<string.h>
#include<time.h>
struct test
{
char ask[500];//选择题题目
char answer1[100];  
char answer2[100];  
char answer3[100];  
char answer4[100];
char da[100]; 
int title[100];//随机抽题
char right[10];
}  m[1000];  
void menu()
{
printf(" \n***********单项选择题标准化考试系统?*********\n\n");
printf(" 1.试题录入                                   \n");
printf(" 2.查看所有试题                               \n");
printf(" 3.试题抽取并答题                             \n");
printf(" 4.判卷并打分                                 \n");
printf(" 5.退出系统                                   \n\n");
printf(" ********************************************\n\n");
}
int input(int cnt)
{
	int i,count,choice=0;  
	printf("开始输入记录...\n");
	count=cnt;
   for(i=cnt;i<1000;i++)
	{
		printf("Continue?(1  Yes  0  No):");
		scanf("%d",&choice);
		getchar();
		if(choice==0)
			break;
		else
			if(choice==1)
			{
	    	         printf("请输入第%d道题题目，题干和选项:\n",i+1);
			         printf("请输入题目:");
		             gets(m[i].ask);
			         printf("请输入选项A:");
			         gets(m[i].answer1);
			         printf("请输入选项B:");
			         gets(m[i].answer2);
			         printf("请输入选项C:");
			         gets(m[i].answer3);
			         printf("请输入选项D:");
			         gets(m[i].answer4);
			         printf("请输入答案:");
			         scanf("%c",&m[i].right);
					 cnt++;

			}
   }
   if(count!=cnt)
	   printf("\n题目输入成功：");
   else
	   printf("\n未输入记录！");
	return cnt;
}
void list(int cnt)
{
	int i;
	printf("开始显示所有题目...");
    printf("\n当前文件夹中所有记录显示如下：\n\n");
	for(i=0;i<cnt;i++)
	{
	printf("第（%d）题目:%s\n",i+1,m[i].ask);
	printf("A:%s\n",m[i].answer1);
    printf("B:%s\n",m[i].answer2);
    printf("C:%s\n",m[i].answer3);
    printf("D:%s\n",m[i].answer4);
	}
	printf("所有题目显示完成...\n");
}
void rande(int cnt) 
{
	int i,j,x=1,n,t;
	int title[100];
	printf("请输入你想抽取的题数：");
	scanf("%d",&n);
	if(n>cnt)
	printf("您抽取的题目超过了题目总数"); 
	else 
	{
	for(i=1;i<=n;i++)
    { 
       here:x=rand()%n;
        title[i]=x;
        for(j=0;j<i;j++)
        if(title[i]==title[j])
        {
          goto here; 
        }
        printf(" =============================================\n");
		printf("第%d题:\n",i);
		printf("%s\n",m[x].ask);
      	printf("A:%s\n",m[x].answer1);
        printf("B:%s\n",m[x].answer2);
        printf("C:%s\n",m[x].answer3);
        printf("D:%s\n",m[x].answer4);
        printf("请输入你的答案：");
        scanf("%s",m[x].da);
        printf(" =============================================\n");
	}
    }
    printf("答题成功，按任意键返回主菜单...\n"); 
}
void ask(int cnt)
{
	int i,n;
	int count=0;
	printf("请输入已经答题的数目：");
	scanf("%d",&n);
	for(i=0;i<cnt;i++)
	{
        if(!strcmp(m[i].da,m[i].right))
        {
            count++;
        }
    }
    printf("你答对的总题数是%d\n",count); 
    printf("你最后的得分为%d",(100/n)*count); 
	system("pause");//停顿，使系统不会闪过
}
int main()
{
	FILE * fp;
	int i=0,count=0,select;

	fp=fopen("tiku.txt","a+");
	if(fp==NULL)
	{
		printf("File open error!\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(&m[i],sizeof(struct test),1,fp)==1)
		{
			i++;
			count++;
		}
	}
	fclose(fp);

	while(1)
	{
		printf("当前文件夹总共有%d条记录.\n",count);
		menu();
		printf("请输入你的选择：");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			count=input(count);break;
		case 2:
			list(count);break;
		case 3:
			rande(count);break;
    	case 4:
			ask(count);break;
		case 5:
			fp=fopen("tiku.txt","w");
			printf("开始保存文件，按任意键继续........");
			getchar();
			getchar();
			for(i=0;i<count;i++)
			{
				fwrite(&m[i],sizeof(struct test),1,fp);
			}
			fclose(fp);
			printf("\n文件保存成功，按任意键退出系统.....");
			getchar();
			exit(0);
		default:printf("输入错误，请重新输入.....");
		}
	}
}
