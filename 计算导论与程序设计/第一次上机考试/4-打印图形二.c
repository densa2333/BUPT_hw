#include<stdio.h>

int main(void)
{
    int l, c, n, i, j, k;

    scanf("%d %d %d", &l, &c, &n);

    for (i = 0; i < l; i++)
    {
        for (k = 0; k < (n + 1) * c; k++)
        {
            printf("*");
        }
        printf("*\n");

        for (j = 0; j < c; j++)
        {
            printf("*");
            for (k = 0; k < n; k++)
            {
                printf(".");
            }
        }
        printf("*\n");

        for (j = 0; j < c; j++)
        {
            printf("*");
            for (k = 0; k < n; k++)
            {
                printf(".");
            }
        }
        printf("*\n");

        for (j = 0; j < c; j++)
        {
            printf("*");
            for (k = 0; k < n; k++)
            {
                printf(".");
            }
        }
        printf("*\n");

    }

    for (k = 0; k < (n + 1) * c; k++)
    {
        printf("*");
    }
    printf("*\n");

    return 0;
}