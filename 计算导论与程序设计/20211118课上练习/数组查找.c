#include<stdio.h>

int a[1000], b[100];

int main(void)
{
    int n, m, i, j, no = 1;
    
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &m);

    for (i = 0; i< m; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < m; i++)
    {
        no = 1;
        for (j = 0; j < n; j++)
        {
            if (b[i] == a[j])
            {
                if (j > 0 && j < n - 1)
                {
                    printf("%d %d\n", a[j - 1], a[j + 1]);
                    no = 0;
                }
                else
                    if (j == 0 && a[j + 1]) // n=1特殊情况
                    {
                        printf("%d\n", a[j + 1]);
                        no = 0;
                    }
                    else
                        if (j == n - 1 && a[j - 1]) //n=1特殊情况
                        {
                            printf("%d\n", a[j - 1]);
                            no = 0;
                        }
            }
        }
        if (no)
            printf("NULL\n");
    }

    return 0;
}