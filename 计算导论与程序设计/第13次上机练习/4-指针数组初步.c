#include<stdio.h>

int getString( char * source , char *strPtr[] ) ;

int main()
{
    char    str[100005];
    char    *strPtr[1005]={0};
    int        i, num ;

    gets(str);
    num = getString( str , strPtr ) ;
    for( i = 0 ; i < num ; i++ )
        puts(strPtr[i]);

    return 0;    
}

/* 请在这里填写答案 */

int getString(char *source, char *strPtr[])
{
    int i, j;
    j = 0;
    for (i = 0; *(source + i); i++)
    {
        if (i == 0 && *(source + i) != ' ')
        {
            strPtr[j] = source + i;
            j++;
        }
        else
            if (*(source + i) == ' ')
            {
                if (*(source + i + 1) != ' ' && *(source + i + 1) != '\0') //状态自动机
                {
                    strPtr[j] = source + i + 1;
                    j++;
                }
                *(source + i) = '\0';
            }
    }
    return j;
}
//带状态变量的自动机
int getString(char *source, char *strPtr[])
{
    int count = 0, index = 0, flag;
    char *s = source; //开指针变量操作，省的后面去加偏移量。声明变量比后面加偏移量要省事
    flag = 0;
    while (*s != '\0')
    {
        if (*s == ' ')
        {
            *s = '\0';
            flag = 0;
        }
        else
            if (flag == 0) //flag代表着上一个字符的状态
            {
                flag = 1;
                strPtr[index] = s;
                index++;
                count++;
            }
        s++;
    }
}