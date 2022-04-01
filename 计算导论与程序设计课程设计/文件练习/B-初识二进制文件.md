# B - 初识二进制文件



## 题目描述

常用的数据类型有字符型(char 型)、短整型(short 型)、整型(int 型)、长整型(long 型)、拓展长整型(long long 型)、单精度浮点型(float 型)、双精度浮点型(double 型)。问题围绕着数据类型与二进制文件展开。现有一个二进制文件，文件名为dict.dic，生成这个文件的C语言代码大概是这样的：  
变量如下：  

```
  char a,aa[5]; //注意这里数组aa为正常使用的字符串，所以会包含字符'\0'，它不需要输出
  short b,bb[5];
  int c,cc[5];
  long d,dd[5];
  long long e,ee[5];
  float g,gg[5];
  double h,hh[5];
  int i;
```
写入的代码段是这样：  
```
  fwrite(&a,sizeof(a),1,fp);
  fwrite(&b,sizeof(b),1,fp);
  fwrite(&c,sizeof(c),1,fp);
  fwrite(&d,sizeof(d),1,fp);
  fwrite(&e,sizeof(e),1,fp);
  fwrite(&g,sizeof(g),1,fp);
  fwrite(&h,sizeof(h),1,fp);
  fwrite(aa,sizeof(a),5,fp);
  fwrite(bb,sizeof(b),5,fp);
  fwrite(cc,sizeof(c),5,fp);
  fwrite(dd,sizeof(d),5,fp);
  fwrite(ee,sizeof(e),5,fp);
  fwrite(gg,sizeof(g),5,fp);
  fwrite(hh,sizeof(h),5,fp);
```
这个代码段被连续执行了5次。当然每次写入的数据是不同的。  

你的任务是从dict.dic中按照输入的顺序，读出7种单独变量，分别存到对应类型的变量中，假设为a、b、c、d、e、g、h。再从该文件中读出7个长度为5的数组，分别存到aa[5]、bb[5]、cc[5]、dd[5]、ee[5]、gg[5]、hh[5]中。最后将它们的值全部输出到屏幕上。  
注意，所有变量均不会超过其存储范围。    

内容提示：在本题对文件的操作内容中，会用到C语言文件操作函数，其打开文件的方式，如下：  

1. 打开二进制文件：
```
FILE *fp=fopen("file.dat","rb"); //"rb"为以只读方式打开二进制文件。
```

2. fread的样例代码：  

```
#include<stdio.h>
int main()
{
  int c,cc[5]={0};
  FILE *fp=fopen("file.dat","rb");
  fread(&c,sizeof(int),1,fp); //从fp指向的文件中读出一个整型变量
  fread(cc,sizeof(int),5,fp); //从fp指向的文件中读出一个长度为5的整型数组。
  fclose(fp);
  return 0;
}
```



## 输入

为一个整数，只可能是 1，2，3，4，5 之一。   



## 输出

将dict.dic中的相关内容输出到屏幕上，如果输入是1，则输出那段代码第一次写入的内容，如果输入是2，则输出那段代码第二次写入的内容，依此类推。  
形式如样例。  



## 样例输入

```
1
```



## 样例输出

```
X
1234
2000000000
2000000000
500000000000000
1.234500
9.876543
XXX
1234 1234 1234 1234 1234
2000000000 2000000000 2000000000 2000000000 2000000000
2000000000 2000000000 2000000000 2000000000 2000000000
500000000000000 500000000000000 500000000000000 500000000000000 500000000000000
1.234500 1.234500 1.234500 1.234500 1.234500
9.876543 9.876543 9.876543 9.876543 9.876543
```



## 解

```C
#include<stdio.h>
#include<stdlib.h>

void BinaryFileRead(FILE *, int);

int main()
{
    int n;
    FILE *fp = NULL;
    scanf("%d", &n);
    if ((fp = fopen("dict.dic", "rb")) == NULL)
      printf("Can't open the file.\n");
    else
      BinaryFileRead(fp, n);
    return 0;
}

void BinaryFileRead(FILE *fp, int n)
{
    int i, j;
    char a, aa[5]; //注意这里数组aa为正常使用的字符串，所以会包含字符'\0'，它不需要输出
    short b, bb[5];
    int c, cc[5];
    long d, dd[5];
    long long e, ee[5];
    float g, gg[5];
    double h, hh[5];
    
    fseek(fp, (n - 1) * (sizeof(a) + sizeof(aa) + sizeof(b) + sizeof(bb)
            + sizeof(c) + sizeof(cc) + sizeof(d) + sizeof(dd) + sizeof(e)
            + sizeof(ee) + sizeof(g) + sizeof(gg) + sizeof(h) + sizeof(hh)), 0);
    //int fseek(FILE *stream, long offset, int whence);

    fread(&a, sizeof(a), 1, fp);
    fread(&b, sizeof(b), 1, fp);
    fread(&c, sizeof(c), 1, fp);
    fread(&d, sizeof(d), 1, fp);
    fread(&e, sizeof(e), 1, fp);
    fread(&g, sizeof(g), 1, fp);
    fread(&h, sizeof(h), 1, fp);
    printf("%c\n%hd\n%d\n%ld\n%lld\n%f\n%lf\n", a, b, c, d, e, g, h);

    fread(aa, sizeof(a), 5, fp);
    printf("%s\n", aa);

    fread(bb, sizeof(b), 5, fp);
    for (j = 0; j < 5; j++) {
        if (j < 4) printf("%hd ", bb[j]);
        else printf("%hd\n", bb[j]);
    }

    fread(cc, sizeof(c), 5, fp);
    for (j = 0; j < 5; j++) {
        if (j < 4) printf("%d ", cc[j]);
        else printf("%d\n", cc[j]);
    }

    fread(dd, sizeof(d), 5, fp);
    for (j = 0; j < 5; j++) {
        if (j < 4) printf("%ld ", dd[j]);
        else printf("%ld\n", dd[j]);
    }

    fread(ee, sizeof(e), 5, fp);
    for (j = 0; j < 5; j++) {
        if (j < 4) printf("%lld ", ee[j]);
        else printf("%lld\n", ee[j]);
    }

    fread(gg, sizeof(g), 5, fp);
    for (j = 0; j < 5; j++) {
        if (j < 4) printf("%f ", gg[j]);
        else printf("%f\n", gg[j]);
    }

    fread(hh, sizeof(h), 5, fp);
    for (j = 0; j < 5; j++) {
        if (j < 4) printf("%lf ", hh[j]);
        else printf("%lf\n", hh[j]);
    }

    fclose(fp);
}
```

