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

- 从词库文件中取词
-  **逐行** 处理输入

```C
#include<stdio.h>

void GetWords(char [][11]);				// review the syntax of function parameter
void Harmonize(char [][11], char *);
int Compare(char *, char [][11]);

int main()
{
    int cnt;
    char s[11][11] = {0}; 		// use two-dimension array to store the words
    char textline[111];			// harmonize the text line by line
    GetWords(s);
    while (gets(textline)) { 	// gets() to get every line
        if (textline[0] == EOF) return 0; 	// if get ^Z, then return
        for (cnt = 0; textline[cnt]; cnt++);// guarantee correct output
        textline[cnt] = '\n';		// replenish the '\n'
        textline[cnt + 1] = '\0';	// string end sign '\0'
        Harmonize(s, textline);	// harmonize every line
    }
    return 0;
}

/* Get words from dict.dic */
void GetWords(char s[][11])
{
    int i, j;
    char c;
    FILE *fp = NULL;
    if ((fp = fopen("dict.dic", "r")) == NULL)
      printf("Can't open the file.\n");
    else { 												// open the file
        i = 0;
        while ((c = fgetc(fp)) != EOF) { 	// words loop
            for (j = 0; j < 10 && c != '\n'; j++) {		// letters loop, fgetc while '\n'
                s[i][j] = c;
                c = fgetc(fp);
            }
            s[i][10] = j;	// store the length of every word
            i++;
        }
    }
}

/* Harmonize one line */
void Harmonize(char s[][11], char *textline)
{
    int i = 0, n;	// i points the location of every letter, n means the number of letters
    while (textline[i]) { 				//check word by word
        n = Compare(textline + i, s);	// compare the following letters
        if (n != -1) {					// need to harmon
            printf("!@#$%^&*");
            i += s[n][10];	// i moves to the end of the word
        } else {
            printf("%c", textline[i]);	// no need to harmonize
            i++;			// i moves to next word
        }
    }
}

/* Judge the word */
int Compare(char *text, char s[][11])
{
    int i = 0, j, flag;
    while (s[i][0]) {	// loop of words library
        flag = 1;
        j = 0;
        while (s[i][j] && text[j]) {	// loop of letters
            if (text[j] != s[i][j]) {	// not the same then find next word in library
                flag = 0;
                break;
            }
            j++;
        }
        if (flag) return i;	// if find in the library, then return the word length
        i++;
    }
    return -1;	// if not in the library, then return -1
}
```

