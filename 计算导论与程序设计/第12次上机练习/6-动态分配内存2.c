#include<stdio.h>
#include<stdlib.h>

void negate(int **a, int row, int col);

int main(void)
{
    int **a, n, m, i;

    scanf("%d %d", &n, &m);

    a = (int **)malloc(sizeof(int *)*n); //建立长度为n的动态指针数组
    for (i = 0; i < n; i++)
      a[i] = (int *)malloc(sizeof(int)*m); //建立长度为m的一维整型数组

    negate(a, n, m);

    for (i = 0; i < n; i++)
      free(a[i]);
    free(a); //释放动态内存。

    return 0;
}

void negate(int **a, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", a[i] + j);
            *(a[i] + j) *= (-10);
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d", *(a[i] + j));
            if (j == col - 1) printf("\n");
            else printf(" ");
        }
    }
}