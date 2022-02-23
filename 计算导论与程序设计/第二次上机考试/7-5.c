#include<stdio.h>

int main(void)
{
    int i, n, num, k, flag = 1, find = 1;
    int a[102], b[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (k = 1; find; k++)
    {
        flag = 1;
        for (i = 0; i < 1000; i++)
        {
            b[i] = 0;
        }
        for (i = 0; i < n && flag; i++)
        {
            if (b[a[i] % k] == 0)
            {
                b[a[i] % k] = 1;
            }
            else
                flag = 0;
        }
        if (flag) find = 0;
    }
    printf("%d", k - 1);
    return 0;
}