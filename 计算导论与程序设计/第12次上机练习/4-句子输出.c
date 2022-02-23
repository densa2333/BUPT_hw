#include<stdio.h>
#define ROW 10
#define COL 30

void fun(char a[][COL], int);

int main(void)
{
    int n;
    char a[ROW][COL];

    scanf("%d", &n);
    fun(a, n);
    
    return 0;
}

void fun(char a[][COL], int n)
{
    int i;
    int order[ROW];

    for (i = 0; i < n; i++)
    {
        scanf("%s", &a[i]);
        getchar(); //scanf特性不读空字符，会留到下次，所以要“吃掉回车”
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &order[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("%s\n", a[order[i]]);
    }
}