# A - 初识 ASCII 码文件

## 题目描述

已知一个ASCII码文件，文件名为dict.dic，该文件中只包含ASCII码中的字符，即可对应整数0—127。我们将ASCII码中的字符分为4类，第一类为大写字母“A—Z”、第二类为小写字母“a—z”、第三类为数字字符“0—9”、第四类为其他字符“!@#$%^&*” 等等（不属于前三类的字符即为第四类）。  
要求：  

1. 统计出这四类字符在该文件中的数量。  
2. 统计出该文件的行数、行最大长度、行最小长度。这里要注意，虽然文件的换行符确实为一个字符，ASCII码为10，但在统计行长度时，文件中的换行符并不统计在内。  
3. 输出具体的大小写字母的统计信息，每行一个字母。  
4. 处理完成后，关闭文件。  

内容提示：在本题对文件的操作内容中，会用到三个新的C语言文件操作函数，一种新的打开文件的方式，如下：  
1. `FILE *fp=fopen("file.txt","r");` //fp即为文件指针，"file.txt"为待打开的文件名，此时应与该程序在一个目录下，"r"为以只读方式打开ASCII码文件。  
2. `int ch=fgetc(fp);` //从fp指向的文件中读取一个字节（字符），存入变量ch内。  
3. `fclose(fp);` //关闭fp指向的文件。       



## 输入

只可能是1，2，3三个整数之一，其输出分别对应输出中的Task1，Task2，Task3。  



## 输出

如果dict.dic文件内容如下： (文件每行都有换行符，且前边无空格)  

abcdefghijklmnopqrstuvwxyz    

ABCDEFGHIJKLMNOPQRSTUVWXYZ    

~!@#$%^&*()_+`1234567890- =\][';/.,<>?":{}| 

则三个任务的输出分别如下： （注意：Task1、2、3等也需要输出）

```
Task1:
capital: 26
lowercase: 26
digit: 10
others: 36
```
```
Task2:
line: 3
43 characters in max line.
26 characters in min line.
```
```
Task3:
CAPITAL:
A:1
B:1
C:1
D:1
E:1
F:1
G:1
H:1
I:1
J:1
K:1
L:1
M:1
N:1
O:1
P:1
Q:1
R:1
S:1
T:1
U:1
V:1
W:1
X:1
Y:1
Z:1
LOWERCASE:
a:1
b:1
c:1
d:1
e:1
f:1
g:1
h:1
i:1
j:1
k:1
l:1
m:1
n:1
o:1
p:1
q:1
r:1
s:1
t:1
u:1
v:1
w:1
x:1
y:1
z:1
```



## 样例输入

```
1
```



## 样例输出

```
Task1:
capital: 26
lowercase: 26
digit: 10
others: 36
```



## 解

- 必须掌握的 ASCII 码处理思想

```C
#include<stdio.h>
#include<stdlib.h>

void Task1(FILE *);
void Task2(FILE *);
void Task3(FILE *);

int main()
{
    int x;
    FILE *fp = NULL;
    if ((fp = fopen("dict.dic", "r")) == NULL) {
        printf("Can't opent the file.\n");
        return 0;
    }
    scanf("%d", &x);
    switch (x)
    {
        case 1:
        Task1(fp); break;
        case 2:
        Task2(fp); break;
        case 3:
        Task3(fp); break;
        default:
        break;
    }
    return 0;
}

void Task1(FILE *fp)
{
    int capital = 0, lowercase = 0, digit = 0, others = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if ('A' <= ch && ch <= 'Z')
            capital++;
        else if ('a' <= ch && ch <= 'z')
            lowercase++;
        else if ('0' <= ch && ch <= '9')
            digit++;
        else
            others++;
    }
    fclose(fp);
    printf("Task1:\ncapital: %d\nlowercase: %d\ndigit: %d\n"
           "others: %d\n",capital, lowercase, digit, others);
}

void Task2(FILE *fp)
{
    int maxL = -1, minL = 0x7fffffff, lines = 0, L = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            maxL = L > maxL ? L : maxL;
            minL = L < minL ? L : minL;
            lines++;
            L = 0;
        } else {
            L++;
        }
    }
    fclose(fp);
    printf("Task2:\nline: %d\n%d characters in max line.\n"
           "%d characters in min line.\n",lines, maxL, minL);
}

void Task3(FILE *fp)
{
    int i;
    int capital[26] = {0}, lowercase[26] = {0};
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if ('A' <= ch && ch <= 'Z')
          capital[ch - 'A']++;
        else if ('a' <= ch && ch <= 'z')
          lowercase[ch - 'a']++;
    }
    printf("Task3:\nCAPITAL:\n");
    for (i = 0; i < 26; i++)
      printf("%c:%d\n", i + 'A',capital[i]);
    printf("LOWERCASE:\n");
    for (i = 0; i < 26; i++)
      printf("%c:%d\n", i + 'a',lowercase[i]);
}
```

