#include <stdio.h>  
#include <stdlib.h> 
#include <malloc.h>
#include<string.h>
#include<time.h>
struct test
{
char ask[500];//ѡ������Ŀ
char answer1[100];  
char answer2[100];  
char answer3[100];  
char answer4[100];
char da[100]; 
int title[100];//�������
char right[10];
}  m[1000];  
void menu()
{
printf(" \n***********����ѡ�����׼������ϵͳ?*********\n\n");
printf(" 1.����¼��                                   \n");
printf(" 2.�鿴��������                               \n");
printf(" 3.�����ȡ������                             \n");
printf(" 4.�о����                                 \n");
printf(" 5.�˳�ϵͳ                                   \n\n");
printf(" ********************************************\n\n");
}
int input(int cnt)
{
	int i,count,choice=0;  
	printf("��ʼ�����¼...\n");
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
	    	         printf("�������%d������Ŀ����ɺ�ѡ��:\n",i+1);
			         printf("��������Ŀ:");
		             gets(m[i].ask);
			         printf("������ѡ��A:");
			         gets(m[i].answer1);
			         printf("������ѡ��B:");
			         gets(m[i].answer2);
			         printf("������ѡ��C:");
			         gets(m[i].answer3);
			         printf("������ѡ��D:");
			         gets(m[i].answer4);
			         printf("�������:");
			         scanf("%c",&m[i].right);
					 cnt++;

			}
   }
   if(count!=cnt)
	   printf("\n��Ŀ����ɹ���");
   else
	   printf("\nδ�����¼��");
	return cnt;
}
void list(int cnt)
{
	int i;
	printf("��ʼ��ʾ������Ŀ...");
    printf("\n��ǰ�ļ��������м�¼��ʾ���£�\n\n");
	for(i=0;i<cnt;i++)
	{
	printf("�ڣ�%d����Ŀ:%s\n",i+1,m[i].ask);
	printf("A:%s\n",m[i].answer1);
    printf("B:%s\n",m[i].answer2);
    printf("C:%s\n",m[i].answer3);
    printf("D:%s\n",m[i].answer4);
	}
	printf("������Ŀ��ʾ���...\n");
}
void rande(int cnt) 
{
	int i,j,x=1,n,t;
	int title[100];
	printf("�����������ȡ��������");
	scanf("%d",&n);
	if(n>cnt)
	printf("����ȡ����Ŀ��������Ŀ����"); 
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
		printf("��%d��:\n",i);
		printf("%s\n",m[x].ask);
      	printf("A:%s\n",m[x].answer1);
        printf("B:%s\n",m[x].answer2);
        printf("C:%s\n",m[x].answer3);
        printf("D:%s\n",m[x].answer4);
        printf("��������Ĵ𰸣�");
        scanf("%s",m[x].da);
        printf(" =============================================\n");
	}
    }
    printf("����ɹ�����������������˵�...\n"); 
}
void ask(int cnt)
{
	int i,n;
	int count=0;
	printf("�������Ѿ��������Ŀ��");
	scanf("%d",&n);
	for(i=0;i<cnt;i++)
	{
        if(!strcmp(m[i].da,m[i].right))
        {
            count++;
        }
    }
    printf("���Ե���������%d\n",count); 
    printf("�����ĵ÷�Ϊ%d",(100/n)*count); 
	system("pause");//ͣ�٣�ʹϵͳ��������
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
		printf("��ǰ�ļ����ܹ���%d����¼.\n",count);
		menu();
		printf("���������ѡ��");
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
			printf("��ʼ�����ļ��������������........");
			getchar();
			getchar();
			for(i=0;i<count;i++)
			{
				fwrite(&m[i],sizeof(struct test),1,fp);
			}
			fclose(fp);
			printf("\n�ļ�����ɹ�����������˳�ϵͳ.....");
			getchar();
			exit(0);
		default:printf("�����������������.....");
		}
	}
}
