#include<stdio.h>

int main(void)
{
    int n, i, swap;
    int a[10], b[10];
    
    scanf("%d", &n);

    for (i = 0; i < n; i++) //读入A
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) //读入B
    {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n; i++) //依据B进行交换
    {
        swap = a[i];
        a[i] = a[b[i]];
        a[b[i]] = swap;
    }

    printf("%d", a[0]);

    for (i = 1; i < n; i++)
    {
        printf(" %d", a[i]);
    }

    return 0;
}