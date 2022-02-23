#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inputString(char **, char [], int);
void sortString(char **, int);
void outputString(char **, int);

int main(void)
{
    int i, n, len;
    char **str;
    char temp[1000];

    scanf("%d", &n);    
    getchar();
    str = (char **)malloc(sizeof(char *) * n); //分配内存
    for (i = 0; i < n; i++)
    {
        gets(temp);
        len = strlen(temp);
        str[i] = (char *)malloc(sizeof(char) * (len + 1));
        strcpy(str[i], temp);
        //puts(str[i]);
    }
    sortString(str, n);
    outputString(str, n);
    for (i = 0; i < n; i++)
    {
        free(str[i]); //先释放字符串的内存
    }
    free(str); //再释放指针数组的内存

    return 0;
}

void sortString(char **strPtr, int n)
{
    int i, j, min;
    char *temp;
    //选择排序
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(strPtr[min], strPtr[j]) > 0)
            {
                min = j;
            }
        }
        if (min != i)
            {
                temp = strPtr[i];
                strPtr[i] = strPtr[min];
                strPtr[min] = temp;
            }
    }
}

void outputString(char **str, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        puts(str[i]);
    }
}