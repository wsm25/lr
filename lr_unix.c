//Powered by wsm
//Tip: This program is built in utf-8
//this program can only run in unix
#ifdef _WIN32
	#error message("this program can only be built in linux") 
#endif

#define TEX "比鄙兵病乘持从达当道得尓伐犯方负赋更苟故顾观归过好号还会惠及极计济假间简见竭尽进居举具俱聚遽决绝类临虑论漫明名命难平戚强窃请穷求取去全任入若善少舍涉生胜师施实食使释市恃数属说素汤徒亡为委务鲜向效谢信行形兴修徐许寻业遗贻夷异易诣益阴引盈余狱御缘远云章知止志致质专走足卒作坐"
/*Exit codes:
0 normal
2 text open error
3 text too big
4 text malloc error
5 fread error
*/

#include <stdio.h>
#include <stdlib.h>
#define BUFLEN 30000000
char *words = TEX ;

int utf8len(char ch) //refer https://blog.csdn.net/shenyongjun1209/article/details/51785791
{
	if (!(ch&-128)) return 1;
	else if (!(ch&32)) return 2;
	else if (!(ch&16)) return 3;
	else if (!(ch&8)) return 4;
	else if (!(ch&4)) return 5;
	else if (!(ch&2)) return 6;
	return -1;
}

char search(char *ch1,char *ch2,char *ch3) //search those with 3 characters
{
	char *p= words ;
	while (*p!='\0')
	{
		if (*ch1==*p)
		{
			++p;
			if(*ch2==*p)
			{
				++p;
				if(*ch3==*p)
				{
					return 1;
				}
				else ++p;
			}
			else p+=2;
		}
		else p+=3;
	}
	return 0;
}

int main(int argc, char **argv)
{
	//check help
	if (argc==2)
	{
		if((argv[1][0]=='/'&&argv[1][1]=='?')||
           (argv[1][0]=='-'&&argv[1][1]=='h'))
		{
			puts("**********懒人实词检索by wsm**********");
			puts("请把文本放于text.txt中,运行本软件");
			puts("if output is garbled, please set local as languages with utf-8");
			puts("若要更改实词，请联系作者via wsm_25@qq.com");
			puts("实词：比鄙兵病乘持从达当道得尓伐犯方负赋更苟故顾观归过好号还会惠及极计济假间简见竭尽进居举具俱聚遽决绝类临虑论漫明名命难平戚强窃请穷求取去全任入若善少舍涉生胜师施实食使释市恃数属说素汤徒亡为委务鲜向效谢信行形兴修徐许寻业遗贻夷异易诣益阴引盈余狱御缘远云章知止志致质专走足卒作坐");
			puts("你可以访问官网：https://github.com/wsm25/lr");
			return 0;
		}
	}
	//open text
	FILE *textfp=fopen("text.txt","r");
	if (textfp==NULL)
	{
		textfp=fopen("text.txt","w");
		fputs("在这里复制或输入文本，然后保存",textfp);
		fclose(textfp);
		system("vi text.txt");
		textfp=fopen("text.txt","r");
		if (textfp==NULL) exit(2);
	}
	//get and check size of text
	fseek(textfp, 0, SEEK_END);
	size_t size=ftell(textfp);
    if (size>BUFLEN)
	{
		fclose(textfp);
		printf("\033[1;31m""text too huge!!!""\033[m");
		exit(3);
	}
	//memory allocation
	char *texts=(char *)malloc(size);
	char *text=texts;
	if (texts==NULL)
	{
		fclose(textfp);
		printf("\033[1;31m""malloc error!!!""\033[m");
		exit(4);
	}
	//read text
	fseek(textfp, 0, SEEK_SET);
	if (fread(texts,1,size,textfp)==0)
	{
		fclose(textfp);
		free(texts);
		printf("\033[1;31m""failed to read from text!!!""\033[m");
		exit(5);
	}
	fclose(textfp);
	int len=utf8len(*texts);
	for (;size>0;len=utf8len(*texts))
	{
		//chinese characters
		if (len==3)
		{
			if (search(texts,texts+1,texts+2))
			printf("\033[1;36m""%c%c%c""\033[m",*texts,*(texts+1),*(texts+2));
			else
			printf("%c%c%c",*texts,*(texts+1),*(texts+2));
			texts+=3;size-=3;
			continue;
		}
		//else
		if (len==-1)
		{
			putchar(*texts);
			++texts;
			--size;
			continue;
		}
		for(;len>0;--len)
		{
			putchar(*texts);
			++texts;--size;
		}
	}
	free(text);
	return 0;
}
