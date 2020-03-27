# 懒人实词检索

可以使你省去目测实词的痛苦而无用的时光  

**说明：本软件只用作检索实词，字词解释自行查字典**。

👉<a href="https://attachments-cdn.shimo.im/wbgEwdm91b0dMWJt/lr.exe" target="_blank" rel="noopener noreferrer">下载1</a>👈（如果403 Forbidden，请新标签页打开）		[下载2](https://github.com/wsm25/lr/releases/download/v1.1.0/lr.exe)

## 使用方法
在有`懒人实词检索.exe`的文件夹中创建`text.txt`，把目标文本复制 ~~或打入~~ 到文件中，运行`懒人诗词检索.exe`，稍等片刻  

## 说明

| release文件 | 说明 |
|  :----:  | :----:  |
| lr.exe | 主文件，不可删除 |
| lr.html | 运行软件后文本结果，可打开，可删除 |
| 示例文本.7z | 顾名思义 |

| 源文件 | 说明 |
|  :----:  | :----:  |
| lr.c | 主程序，依赖`error.c`，用于Windows |
| error.c | 帮助和错误处理 |
| README.md | 本文件 |
| lr_unix.c | 可在Linux和Mac OS中运行 |

+ 本软件只用作检索实词，字词解释自行查字典。~~当然也可以用于老师出题。~~

+ （不知如何修复的bug）人名，地名中的实词也会划进去

+ 最多支持一千万字（加字自行下载源代码重新编译）

+ 支持emoji 🌹🍀🍎💰📱🌙🍁🍂🍃🌷💎🔪🔫🏀⚽⚡👄👍🔥

+ 使用2019版145实词：
>比鄙兵病乘 持从达当道 得尓伐犯方 负赋更苟故 顾观归过好 

>号还会惠及 极计济假间 简见竭尽进 居举具俱聚 遽决绝类临 

>虑论漫明名 命难平戚强 窃请穷求取 去全任入若 善少舍涉生 

>胜师施实食 使释市恃数 属说素汤徒 亡为委务鲜 向效谢信行 

>形兴修徐许 寻业遗贻夷 异易诣益阴 引盈余狱御 缘远云章知 

>止志致质专 走足卒作坐 

  若有变化,请上报至[issue](https://github.com/wsm25/lr/issues)或[联系作者](mailto://wsm_25@qq.com)

+ [版本说明](/EDITION.md)

## 可能问题
+ 杀毒软件报毒  

	允许运行即可。本软件绿色无毒。
+ 输出乱码  

	打开“text.txt”，查看窗口右下角，若显示“ANSI”或“GBxxxxxx”，则另存为——文件编码设为“UTF-8”，重新打开exe  
	
	![01.PNG](https://i.loli.net/2020/03/08/xBhCwNAkSQFtzEn.png)
	![02.PNG](https://i.loli.net/2020/03/08/9zSLw4ydmHBW618.png)
	![03.PNG](https://i.loli.net/2020/03/08/qMjZiCeV1IRuh7U.png)
	![04.PNG](https://i.loli.net/2020/03/08/wahYQI61XlC379S.png)
+ 有其他问题，请上报至[issue](https://github.com/wsm25/lr/issues)或[联系作者](mailto://wsm_25@qq.com)

## 关于
wsm，一个自学编程的初中生，兼学习狂魔。  

希望大家多多支持
