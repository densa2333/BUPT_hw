#include<stdio.h>

int main(void)
{
    int m, n, c, r, d, sum;
    int chiken, rabbit, dragonfly;
    scanf("%d %d", &m, &n);

    for (c = 0; c <= m; c++)
    {
        for (r = 0; r <= m; r++)
        {
            for (d = 0; d <= m; d++)
            {
                sum = c * 2 + r * 4 + d * 6;
                if (sum == n && c + r + d == m)
                {
                    printf("%d %d %d\n", c, r, d);
                }
            }
        }
    }

    return 0;
}