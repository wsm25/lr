void werror(int errcod)
{
	int i=25;
	switch (errcod)
	{
		case 1 :
			MessageBox(NULL,"����html�ļ�ʧ��\n�����Ҫ�Թ���ԱȨ������","",MB_ICONHAND);
			break;
		case 2 :
			MessageBox(NULL,"�򿪡�text.txt��ʧ��\n�����Ҫ�Թ���ԱȨ������","",MB_ICONHAND);
			break;
		case 3 :
			MessageBox(NULL,"�ļ�̫������","",MB_ICONHAND);
			for(;i;--i) MessageBox(NULL,"��·��ڸ���","",MB_OK);//this may cause false positives of anti-virus software 
			break;
		case 4 :
			MessageBox(NULL,"�����ڴ�ʧ��\n�����Ҫ����ɱ��������б����","",MB_ICONHAND);
			break;
		case 5 :
			MessageBox(NULL,"�ļ���ȡʧ��","",MB_ICONHAND);
			break;
		default :
			MessageBox(NULL,"???","",MB_OK);
			break;
	}
	exit(errcod);
}

void whelp(void)
{
	MessageBox(NULL,"����ı�����text.txt��,���б����","����ʵ�ʼ���by wsm",MB_OK);
	MessageBox(NULL,"��Ҫ����ʵ�ʣ�����ϵ����via wsm_25@qq.com","����ʵ�ʼ���by wsm",MB_OK);
	MessageBox(NULL,"ʵ�ʣ�\n�ȱɱ����� �ִӴﵱ�� �Ì������� ���������� �˹۹���� \n�Ż���ݼ� ���Ƽüټ� ����߾��� �Ӿپ߾�� ��������� \n���������� ����ƽ��ǿ ��������ȡ ȥȫ������ ���������� \nʤʦʩʵʳ ʹ�������� ��˵����ͽ ��Ϊί���� ��Чл���� \n���������� Ѱҵ������ ���������� ��ӯ������ ԵԶ����֪ \nֹ־����ר ����������","����ʵ�ʼ���by wsm",MB_OK);
	if(MessageBox(NULL,"������ǡ��򿪹���","����ʵ�ʼ���by wsm",MB_YESNO)==IDYES) system("start https://github.com/wsm25/lr");
}