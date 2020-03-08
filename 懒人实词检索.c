//Powered by wsm
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
#define BUFLEN 30000000
char *words = TEX ;

int wordlen(char ch){
	if (!(ch&-128)) return 1;
	else if (!(ch&32)) return 2;
	else if (!(ch&16)) return 3;
	else if (!(ch&8)) return 4;
	else if (!(ch&4)) return 5;
	else if (!(ch&2)) return 6;
	return -1;
}

char search(char *ch1,char *ch2,char *ch3){
	char *p= words ;
	while (*p!='\0'){
		if (*ch1==*p){
			++p;
			if(*ch2==*p){
				++p;
				if(*ch3==*p){
					return 1;
				}else ++p;
			}else p+=2;
		}else p+=3;
	}
	return 0;
}

int main(int agrc, char **agrv){
	if (agrc==2) {if(agrv[1]=="/?"||agrv[1]=="-h") {
		return system("start 1.vbs h");}}
	FILE *textfp=fopen("text.txt","r");
	if (textfp==NULL) {
		textfp=fopen("text.txt","w");
		fputs("在这里复制或输入文本，然后保存",textfp);
		fclose(textfp);
		system("notepad text.txt");
		textfp=fopen("text.txt","r");
		}
	fseek(textfp, 0, SEEK_END);
	size_t size=ftell(textfp);
    if (size>BUFLEN) {fclose(textfp);return system("start 1.vbs big");}
	char *texts=(char *)malloc(size);
	if (texts==NULL) {fclose(textfp);return system("start 1.vbs mall");}
	fseek(textfp, 0, SEEK_SET);
	if (fread(texts,1,size,textfp)==0) {fclose(textfp);return system("start 1.vbs read");}
	fclose(textfp);
	FILE *htmlfp=fopen("lr.html","w");
	if (htmlfp==NULL) return system("start 1.vbs html");
	fputs("<!DOCTYPE html>\n<!-- 懒人实词搜索by吴神马 -->\n<html>\n<head>\n<meta  charset=\"utf-8\">\n\t<style>\n\t\tmark {background-color: #F9F900;}\n\t</style>\n\t<title>why do you look at here</title>\n</head>\n<body>\n\t<p>",htmlfp);
	int len=0;
	for (;size>0;){
		len=wordlen(*texts);
		if (len==1){
			if (*texts=='\n'){
				fputs("</p><p>",htmlfp);
			}else if (*texts=='<'){
				fputs("&lt;",htmlfp);
			}else{
				fputc(*texts,htmlfp);
			}
			++texts;--size;
			continue;
		}
		if (len==3){
			if (search(texts,texts+1,texts+2)){
				fputs("<mark>",htmlfp);
				fputc(*texts,htmlfp);fputc(*(texts+1),htmlfp);fputc(*(texts+2),htmlfp);
				fputs("</mark>",htmlfp);
			}else{
				fputc(*texts,htmlfp);fputc(*(texts+1),htmlfp);fputc(*(texts+2),htmlfp);
			}
			texts+=3;size-=3;
			continue;
		}
		//else
		if (len==-1){++texts;--size;continue;}
		for(;len>0;--len){
			fputc(*texts,htmlfp);
			++texts;--size;
		}
	}
	fputs("</p>\n</body>\n</html>",htmlfp);
	fclose(htmlfp);
	free(texts);
	system("start lr.html");
	return 0;
}
