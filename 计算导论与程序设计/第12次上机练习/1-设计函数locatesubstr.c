#include <stdio.h>

char *locatesubstr(char *str1,char *str2);

int main()
{
    char str1[505],str2[505];
    char *p;
    gets(str1);
    gets(str2);
    p=locatesubstr(str1,str2);

    if(p==NULL)    printf("NULL!\n");
    else    puts(p);

    return 0;
}

/* 请在这里填写答案 */

char *locatesubstr(char *str1,char *str2)
{
    int i, j, flag = 1;
    for (i = 0; *(str1 + i); i++)
    {
        flag = 1;
        j = 0;
        while (*(str2 + j) && flag)
        {
            if (*(str1 + i + j) != *(str2 + j) || *(str1 + i + j) == 0) flag = 0;
            j++;
        }
        if (flag) return (str1 + i);
    }
    if (flag == 0) return NULL;
}