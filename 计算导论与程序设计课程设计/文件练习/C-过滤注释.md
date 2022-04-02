# C - 过滤注释



## 题目描述

C语言的注释分为两种，第一种：在一行源代码中`//`后的内容为注释内容。第二种:`/*`与`*/`之间的内容为注释内容。第三种：程序中只出现了`/*`，没有`*/`与之对应，那么将`/*`后的全部内容都要过滤掉。注意，只要是注释内容，那么注释内容中的字符应该全部忽略，即不起任何的作用。例如`/*`与`*/`之间如果再有`//`，那么`//`不应起作用；如果`//`再有`/*`，那么`/*`也不应起作用。
你的任务是先打开一个名字为dict.dic的文本文件，该文件中前5行每行为1个整数，从第6行开始为5段C语言的源代码。那5个数字代表这5段源代码结束的行数，比如如果第一行的整数为20，第二行的整数为60，则表示从第6行到第20为第一段代码，从第21行到第60为第二段代码。然后根据输入要求将源代码中所有注释过滤掉。
在本过滤注释系统中，你可以忽略源文件中双引号导致`//`、`/*`、`*/`失去作用的情况，即只要`//`、`/*`、`*/`不是注释内容，在任何情况下都起作用。  



## 输入

只可能是 1，2，3，4，5 之一。  



## 输出

输入为1则输出第一段代码过滤后的结果，输入为2则输出第二段代码过滤后的结果，依此类推。  



## 样例输入

```
1
```



## 样例输出

```
如果第一段代码是这样：

/*
	@Author: BUPT
	@Date: 2010 8 26
*/
#include<stdio.h>

int main()
{
	int a = 10 , b = 2 , c ;
	c = a / b ; //I just want to test '/'
	printf("I love programming C.\n") ; //"printf" is a useful function /*
	printf("I hope you love it too!\n") ;
	/*
	//C is not always hard , if you love it , it will not treat you rough.
	*/
	return 0 ;
}

则输出是这样：

#include<stdio.h>

int main()
{
    int a = 10 , b = 2 , c ;
    c = a / b ;
    printf("I love programming C.\n") ;
       printf("I hope you love it too!\n") ;

        return 0 ;
}
```



## 解

- 对字符串逐行操作的思想很重要  

### 第一次尝试 ：fgetc定位 + 逐字符处理的过滤算法（OLE）

```C
#include<stdio.h>

int main()
{
    int i, n, num[6], line = 6;
    char ch1, ch2;
    long front, rear;
    scanf("%d", &n);
    FILE *fp = NULL;
    if ((fp = fopen("dict.dic", "r")) == NULL)
        printf("Can't open the file.\n");
    else {
        num[0] = 5;

        for (i = 1; i < 6; i++)
          fscanf(fp ,"%d\n", &num[i]);
        while ((line != (num[n - 1] + 1)) && ((ch1 = fgetc(fp)) != EOF)) {
            if (ch1 == '\n') line++;
        }
        front = ftell(fp);
        while ((line != num[n] + 1) && (ch1 = fgetc(fp)) != EOF) {
            if (ch1 == '\n') line++;
        }
        rear = ftell(fp);
        fseek(fp, front, 0);

        ch1 = fgetc(fp);
        while (ftell(fp) != rear) {
            if (ch1 == '/') {
                ch2 = fgetc(fp);
                if (ch2 == '/') {
                    for (ch1 = fgetc(fp); ch1 != '\n'; ch1 = fgetc(fp));
                    printf("%c", ch1);
                } else if (ch2 == '*') {
                    do {
                        for (ch1 = fgetc(fp); ch1 != '*' && ch1 != EOF; ch1 = fgetc(fp));
                        if (ch1 == EOF) break;
                    } while (ch1 = fgetc(fp) != '/');
                    if (ch1 == EOF) break;
                } else {
                    printf("%c%c", ch1, ch2);
                }
            } else {
                printf("%c", ch1);
            }
            ch1 = fgetc(fp);
        }
    }
    fclose(fp); //OLE不是没关文件的问题
    return 0;
}
```



### 第二次尝试 ：fgets定位 + 逐字符处理的过滤算法（OLE）

```C
#include<stdio.h>

int main()
{
    int i, n, num[6], line = 6;
    char ch1, ch2;
    char s[1000];
    long front, rear;
    scanf("%d", &n);
    FILE *fp = NULL;
    if ((fp = fopen("dict.dic", "r")) == NULL)
        printf("Can't open the file.\n");
    else {
        num[0] = 5;

        for (i = 1; i < 6; i++)
          fscanf(fp ,"%d\n", &num[i]);
        while (line != (num[n - 1] + 1) && !feof(fp)) {
            fgets(s, sizeof(s), fp);
            line++;
        }
        front = ftell(fp);
        while (line != (num[n] + 1) && !feof(fp)) {
            fgets(s, sizeof(s), fp);
            line++;
        }
        rear = ftell(fp);
        fseek(fp, front, 0);

        ch1 = fgetc(fp);
        while (ftell(fp) != rear) {
            if (ch1 == '/') {
                ch2 = fgetc(fp);
                if (ch2 == '/') {
                    for (ch1 = fgetc(fp); ch1 != '\n'; ch1 = fgetc(fp));
                    printf("%c", ch1);
                } else if (ch2 == '*') {
                    do {
                        for (ch1 = fgetc(fp); ch1 != '*' && ch1 != EOF; ch1 = fgetc(fp));
                        if (ch1 == EOF) break;
                    } while (ch1 = fgetc(fp) != '/');
                    if (ch1 == EOF) break;
                } else {
                    printf("%c%c", ch1, ch2);
                }
            } else {
                printf("%c", ch1);
            }
            ch1 = fgetc(fp);
        }
    }
    fclose(fp);
    return 0;
}
```



### 第三次尝试：fgets定位 + 逐行处理的过滤算法（AC）

```C
#include<stdio.h>

void Filter(int, int *);

int main()
{
    int i, n, num[6];
    scanf("%d", &n);
    FILE *fp = NULL;
    if ((fp = fopen("dict.dic", "r")) == NULL)
        printf("Can't open the file.\n");
    else {
        num[0] = 5;
        for (i = 1; i < 6; i++)
          fscanf(fp ,"%d\n", &num[i]);
        fclose(fp);
        Filter(n, num);
    } 
    return 0;
}

void Filter(int n, int *num)
{
    int count = 0;
    char c, c1, c2;
    char s[1000];
    FILE * fp = fopen("dict.dic", "r");
    while (count != num[n - 1]) {
        fgets(s, sizeof(s), fp);
        count++;
    }
    count = 0;
    while (count != num[n] - num[n - 1]) {
        c = fgetc(fp);
        if (feof(fp))
          return;
        if (c == '/') {
            c1 = c;
            c2 = fgetc(fp);
            if (c1 == '/' && c2 == '*') {
                while (!feof(fp)) {
                    c = fgetc(fp);
                    c2 = c;
                    if (c1 == '*' && c2 == '/') {
                        c1 = '\0';
                        c2 = '\0';
                        break;
                    }
                    c1 = c2;
                    if (c == '\n') {
                        count++;
                    }
                    if (count > num[n] - num[n - 1])
                        return;
                }
            } else if (c1 == '/' && c2 == '/') {
                while (!feof(fp)) {
                    c = fgetc(fp);
                    if (c == '\n') {
                        c = '\0';
                        c1 = '\0';
                        c2 = '\0';
                        count++;
                        printf("\n");
                        break;
                    }
                }
            } else {
                printf("%c%c", c1, c2);
            }
        } else {
            printf("%c", c);
        }
        if (c == '\n' || feof(fp) == -1)
        count++;
    }
    fclose(fp);
}
```

