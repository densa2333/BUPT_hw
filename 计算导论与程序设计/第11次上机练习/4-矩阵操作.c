#include<stdio.h>

#define MAX 11

void inputMatrix(int [][MAX], int, int);
int add(int [][MAX], int, int);

int main(void)
{
    int m, n, x, y;
    int a[MAX][MAX] = {{0}};

    scanf("%d %d", &m, &n);
    inputMatrix(a, m, n);
    scanf("%d %d", &x, &y);
    printf("%d\n",add(a, x, y));

    return 0;
}

void inputMatrix(int a[MAX][MAX], int m, int n)
{
    int i, j;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int add(int a[MAX][MAX], int x, int y)
{
    int result;
    result = a[x - 1][y - 1] + a[x - 1][y] + a[x - 1][y + 1] + a[x][y - 1] + a[x][y + 1] + a[x + 1][y - 1] + a[x + 1][y] + a[x + 1][y + 1];
    return result;
}