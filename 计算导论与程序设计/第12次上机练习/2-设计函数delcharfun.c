#include<stdio.h>

void delcharfun(char *str,char ch);

int main()
{
    char    ch,str[110];

    scanf("%s",str);    //读入字符串 
    getchar();            //读取回车符号 
    scanf("%c",&ch);    //读入字符 
    delcharfun(str,ch);    //删除 
    printf("%s\n",str);    //输出删除后结果 
    return 0;    
}

/* 请在这里填写答案 */

void delcharfun(char *str,char ch)
{
    int i, j;
    i = 0;
    while (*(str + i))
    {
        if (*(str + i) == ch)
        {
            for (j = i; *(str + j); j++) //令j=i可以优化可读性
            {
                *(str + j) = *(str + j + 1);
            }
        }
        else //不是扫过一遍就没事了，如果遇到两个待删字符连在一起就要重新判断
        {
            i++;
        }
    }
}