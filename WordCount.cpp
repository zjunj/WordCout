#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	char ch,address[100];
	int i,a,b,c,n;
	i=a=b=c=n=0;
    printf("文件名：");
	scanf("%s",address);
	fp=fopen(address,"r");
	if(fp==NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	ch=fgetc(fp);
	while (ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	printf("\n");
	rewind(fp);
	ch=fgetc(fp);
	while (ch!=EOF)
	{
		i++;       //i统计字符数量
		if(ch==' ')     //a统计空格数量
			a++;
		ch=fgetc(fp);     
		
	}rewind(fp);
   ch=fgetc(fp);
   if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')          //判断通篇里第一个字符是否为字母，若判断条件为真，直接b+1;
	   b++;
    while (ch!=EOF)
	{
		if(!(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'))         //b统计单词数量
		{	ch=fgetc(fp);
		    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
				b++;
		}
		else ch=fgetc(fp);
	}
	rewind(fp);
   ch=fgetc(fp);
    while (ch!=EOF)
	{
		if(ch=='\n')							//c统计段落数量
		{
			ch=fgetc(fp);
			while(ch==' ')	
			{   
				ch=fgetc(fp);
				if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')    /*  每一段后面必须有回车+空格（可能不止一个）+
														  字母，该段才计数加一，致使最后一段无法在此处
														  被计数，因此在输出c的时候，应该再+1   */
					c++;
			}
		}
		else ch=fgetc(fp);
	}
	fclose(fp);
printf("空格有%d个，字符有%d个，单词有%d个,段落有%d段",a,i,b,c+1);   
}

