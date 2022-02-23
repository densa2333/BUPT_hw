#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inputString(char *[], char [], int);
void sortString(char *[], int);
void outputString(char *[], int);

int main(void)
{
    int n, i;
    char str[100000];
    char *strPtr[100];

    scanf("%d", &n);
    inputString(strPtr, str, n);
    sortString(strPtr, n);
    outputString(strPtr, n);
    
    return 0;
}

void inputString(char *strPtr[], char str[], int n)
{
    int i;
    char *p = str;
    getchar();
    for (i = 0; i < n; i++)
    {
        *p = getchar();
        strPtr[i] = p;
        while (*p != '\n')
        {
            p++;
            *p = getchar();
        }
        *p = '\0';
        //printf("%c\n", *(strPtr[i]));
        p++;
    }
}

void sortString(char *strPtr[], int n)
{
    int i, j, min;
    char *temp;
    //Ñ¡ÔñÅÅÐò
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

void outputString(char *strPtr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s\n", strPtr[i]);
    }
}