On Error Resume Next
str = WScript.Arguments(0)
On Error Goto 0
Select Case str
	Case "h"
		help()
	Case "big"
		MsgBox "����̫����!",48
		MsgBox "��ʷ�ǻ�����",48
		MsgBox "��·��ڸ���",48
	Case "mall"
		MsgBox "malloc error",16
	Case "read"
		MsgBox "read text error",16
	Case "html"
		MsgBox "create html error",16
	Case Else 
		CreateObject("SAPI.SpVoice").Speak"�����ʲô"
End Select
		
Sub help()
	msgbox "����ı�����text.txt��,���б��������hh.html",vbokonly,"����ʵ�ʼ���by wsm"
	msgbox "��Ҫ����ʵ�ʣ�����ϵ����via 2497767405@qq.com",vbokonly,"����ʵ�ʼ���by wsm"
	msgbox "ʵ�ʣ��ȱɱ����˳ִӴﵱ���Ì����������������ʹ˹۹���úŻ���ݼ����Ƽüټ����߾����Ӿپ߾�������������������������ƽ��ǿ��������ȡȥȫ����������������ʤʦʩʵʳʹ����������˵����ͽ��Ϊί������Чл��������������Ѱҵ������������������ӯ������ԵԶ����ֹ֪־����ר����������",vbokonly,"����ʵ�ʼ���by wsm"
End Sub