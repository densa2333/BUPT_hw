#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i, j, m, n, c, x, y, cnt = 0;
    int a[11][11] = {0};
    scanf("%d %d %d", &m, &n, &c);
    for (i = 0; i < c; i++)
    {
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        a[x - 1][y - 1] = 1;
        a[x - 1][y] = 1;
        a[x - 1][y + 1] = 1;
        a[x][y - 1] = 1;
        a[x][y + 1] = 1;
        a[x + 1][y - 1] = 1;
        a[x + 1][y] = 1;
        a[x + 1][y + 1] = 1;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
          if (a[i][j])
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}