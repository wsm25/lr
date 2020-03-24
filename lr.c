//Powered by wsm
//Tip: This program is built in utf-8
//this program can only run in windows

#ifndef _WIN32
	#error message("this program can only be built in windows\nyou can run\nwget https://github.com/wsm25/lr/raw/master/lr_unix.c && gcc lr_unix.c -o lr") 
#endif

#define TEX "比鄙兵病乘持从达当道得尓伐犯方负赋更苟故顾观归过好号还会惠及极计济假间简见竭尽进居举具俱聚遽决绝类临虑论漫明名命难平戚强窃请穷求取去全任入若善少舍涉生胜师施实食使释市恃数属说素汤徒亡为委务鲜向效谢信行形兴修徐许寻业遗贻夷异易诣益阴引盈余狱御缘远云章知止志致质专走足卒作坐"
/*Exit codes:
0 normal
1 html create error
2 text open error
3 text too big
4 text malloc error
5 fread error
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "error.c"
#define BUFLEN 30000000
const char *words = TEX ;

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
	const char *p= words ;
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
	ShowWindow(FindWindow("ConsoleWindowClass",argv[0]),0);
	//check help
	if (argc==2)
	{
		if((argv[1][0]=='/'&&argv[1][1]=='?')||
           (argv[1][0]=='-'&&argv[1][1]=='h'))
		{
			whelp();
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
		system("notepad text.txt");
		textfp=fopen("text.txt","r");
		if (textfp==NULL) werror(2);
	}
	//get and check size of text
	fseek(textfp, 0, SEEK_END);
	size_t size=ftell(textfp);
    if (size>BUFLEN)
	{
		fclose(textfp);
		werror(3);
	}
	//memory allocation
	char *texts=(char *)malloc(size);
	char *text=texts;
	if (texts==NULL)
	{
		fclose(textfp);
		werror(4);
	}
	//read text
	fseek(textfp, 0, SEEK_SET);
	if (fread(texts,1,size,textfp)==0)
	{
		fclose(textfp);
		free(texts);
		werror(5);
	}
	fclose(textfp);
	//create and open html
	//Warning: this may clear all data in "lr.html"
	FILE *htmlfp=fopen("lr.html","w");
	if (htmlfp==NULL)
	{
		free(texts);
		werror(1);
	}
	//html heading
	fputs("<!DOCTYPE html>\n<!-- 懒人实词搜索by吴神马 -->\n<html>\n<head>\n<meta  charset=\"utf-8\">\n\t<style>\n\t\tmark {background-color: #F9F900;}\n\t</style>\n\t<title>why do you look at here</title>\n</head>\n<body>\n\t<p>",htmlfp);
	int len=utf8len(*texts);
	for (;size>0;len=utf8len(*texts))
	{
		//ascii characters
		if (len==1)
		{
			if (*texts=='\n')
			{
				fputs("</p><p>",htmlfp);--size;//Question: I don't know why there shoud be a "--size", but if delete, it can't work properly.
			}
			else if(*texts=='\r') ;//and it may ignore the cr ('\r')
			else if (*texts=='<')
			{
				fputs("&lt;",htmlfp);
			}
			else
			{
				fputc(*texts,htmlfp);
			}
			++texts;--size;
			continue;
		}
		//chinese characters
		if (len==3)
		{
			if (search(texts,texts+1,texts+2))
			{
				fputs("<mark>",htmlfp);
				fputc(*texts,htmlfp);
				fputc(*(texts+1),htmlfp);
				fputc(*(texts+2),htmlfp);
				fputs("</mark>",htmlfp);
			}else
			{
				fputc(*texts,htmlfp);
				fputc(*(texts+1),htmlfp);
				fputc(*(texts+2),htmlfp);
			}
			texts+=3;size-=3;
			continue;
		}
		//else
		if (len==-1)
		{
			fputc(*texts,htmlfp);
			++texts;
			--size;
			continue;
		}
		for(;len>0;--len)
		{
			fputc(*texts,htmlfp);
			++texts;--size;
		}
	}
	//html ending
	fputs("</p>\n</body>\n</html>",htmlfp);
	fclose(htmlfp);
	free(text);
	system("start lr.html");
	return 0;
}
