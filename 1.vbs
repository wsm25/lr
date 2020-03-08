On Error Resume Next
str = WScript.Arguments(0)
On Error Goto 0
Select Case str
	Case "h"
		help()
	Case "big"
		MsgBox "文章太长啦!",48
		MsgBox "比史记还长？",48
		MsgBox "你仿佛在搞我",48
	Case "mall"
		MsgBox "malloc error",16
	Case "read"
		MsgBox "read text error",16
	Case "html"
		MsgBox "create html error",16
	Case Else 
		CreateObject("SAPI.SpVoice").Speak"你想干什么"
End Select
		
Sub help()
	msgbox "请把文本放于text.txt中,运行本软件，打开hh.html",vbokonly,"懒人实词检索by wsm"
	msgbox "实词：比鄙兵病乘持从达当道得尓伐犯方负赋更苟故顾观归过好号还会惠及极计济假间简见竭尽进居举具俱聚遽决绝类临虑论漫明名命难平戚强窃请穷求取去全任入若善少舍涉生胜师施实食使释市恃数属说素汤徒亡为委务鲜向效谢信行形兴修徐许寻业遗贻夷异易诣益阴引盈余狱御缘远云章知止志致质专走足卒作坐",vbokonly,"懒人实词检索by wsm"
	a=msgbox("若要更改实词，请在官网联系作者 "& vbCrLf &"点击“是”打开官网",vbOKCancel)
	if a=vbok then 
		WScript.CreateObject("WScript.Shell").Run "https://github.com/wsm25/lr", 3
	end if
End Sub