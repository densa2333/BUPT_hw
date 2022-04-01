# D - 和谐词汇



## 题目描述

互联网中存在许多的不和谐词汇，在我们浏览互联网的时候，搜索引擎经常会出现提示信息“根据相关法律法规和政策，部分搜索结果未予显示”。小王同学也想制作一个自己的屏蔽词库，这样他就可以将自己不喜欢的词汇从文件中换成别的字符了。屏蔽词库是一个ASCII码文件，这个文件中只含有单词，每个单词占一行，每个单词中只可能有大小写字母与空格。题目中和谐词库的文件名为dict.dic。（屏蔽词库中每个词汇长度小于10，屏蔽词汇个数不超过10.）  
你的任务是将输入中的所有和谐词库中的词语全部替换成“!@#$%^&*”（按住键盘shift和数字1至8），然后输出。这里要注意，如果一个词语中包含屏蔽词汇，那么只将屏蔽词汇替换，例如“hehasAAA”被处理后将得到“he!@#$%^&*AAA”，注意屏蔽词汇区分大小写，即aaa与AAA是两个不同的单词，为了使问题简化，屏蔽词汇中不会出现互相包含的情况，如“xabcx”与“abc”不会同时出现在同一个屏蔽词库中。由于小王同学很不擅长文件操作，所以他希望你能帮他制作这个屏蔽词汇程序。  



## 输入

若干长度小于110的字符串。  



## 输出

添加屏蔽词后的结果。  



## 样例输入

```
The night falls gently. And you are not here. I missing you more and more and I start getting worried as
I stare at the door just waiting for you to surprise me with your arrival at any moment.
Sweet delusion... you are so far away right now that all I can ask for is that time moves faster...

```



## 样例输出

```
如果屏蔽词库如下：（文件中每行都有换行符）
is
good
are
the
ha ha
some
get
has
more
bad

则输出：

The night falls gently. And you !@#$%^&* not here. I m!@#$%^&*sing you !@#$%^&* and !@#$%^&* and I start !@#$%^&*ting worried as
I st!@#$%^&* at !@#$%^&* door just waiting for you to surpr!@#$%^&*e me with your arrival at any moment.
Sweet delusion... you !@#$%^&* so far away right now that all I can ask for !@#$%^&* that time moves faster...

```



## 解

```C
```

