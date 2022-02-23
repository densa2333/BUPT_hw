#include<stdio.h>

int main(void)
{
    int m, n, i, j, k, n1;
    scanf("%d %d", &m, &n);

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= m; j++)
        {
            for (k = 0; k <= m; k++)
            {
                n1 = m + i + j * 2 + k * 3;
                if (n1 == n && i + j + k <= m)
                    printf("%d %d %d\n", i, j ,k);
            }
        }
    }
    return 0;
}