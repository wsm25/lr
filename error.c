void werror(int errcod)
{
	int i=25;
	switch (errcod)
	{
		case 1 :
			MessageBox(NULL,"创建html文件失败\n你可能要以管理员权限运行","",MB_ICONHAND);
			break;
		case 2 :
			MessageBox(NULL,"打开”text.txt“失败\n你可能要以管理员权限运行","",MB_ICONHAND);
			break;
		case 3 :
			MessageBox(NULL,"文件太大啦！","",MB_ICONHAND);
			for(;i;--i) MessageBox(NULL,"你仿佛在搞我","",MB_OK);//this may cause false positives of anti-virus software 
			break;
		case 4 :
			MessageBox(NULL,"分配内存失败\n你可能要允许杀毒软件运行本软件","",MB_ICONHAND);
			break;
		case 5 :
			MessageBox(NULL,"文件读取失败","",MB_ICONHAND);
			break;
		default :
			MessageBox(NULL,"???","",MB_OK);
			break;
	}
	exit(errcod);
}

void whelp(void)
{
	MessageBox(NULL,"请把文本放于text.txt中,运行本软件","懒人实词检索by wsm",MB_OK);
	MessageBox(NULL,"若要更改实词，请联系作者via wsm_25@qq.com","懒人实词检索by wsm",MB_OK);
	MessageBox(NULL,"实词：\n比鄙兵病乘 持从达当道 得尓伐犯方 负赋更苟故 顾观归过好 \n号还会惠及 极计济假间 简见竭尽进 居举具俱聚 遽决绝类临 \n虑论漫明名 命难平戚强 窃请穷求取 去全任入若 善少舍涉生 \n胜师施实食 使释市恃数 属说素汤徒 亡为委务鲜 向效谢信行 \n形兴修徐许 寻业遗贻夷 异易诣益阴 引盈余狱御 缘远云章知 \n止志致质专 走足卒作坐","懒人实词检索by wsm",MB_OK);
	if(MessageBox(NULL,"点击”是“打开官网","懒人实词检索by wsm",MB_YESNO)==IDYES) system("start https://github.com/wsm25/lr");
}