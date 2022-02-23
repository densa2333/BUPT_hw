#include<stdio.h>

int main(void)
{
    int n, i, value = 0;
    int a[10] = {0};
    int b[10] = {0};

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n; i++)
    {
        value += a[i] * b[i];
    }

    printf("%d", value);

    return 0;
}