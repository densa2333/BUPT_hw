#include<stdio.h>

#define MAX 100

void inputMatrix(int [][MAX], int, int);
int findRowMax(int [], int);
int findColMin(int [][MAX], int, int);

int main(void)
{
    int n, m, flag, row, rowMax, colMin;
    int a[MAX][MAX];

    scanf("%d %d", &n, &m);
    inputMatrix(a, n, m);
    
    flag = 1;
    row = 0;
    while (row < n && flag)
    {
        rowMax = findRowMax(a[row], m);
        colMin = findColMin(a, n, rowMax);
        if (row == colMin)
        {
            printf("The saddle point is (%d,%d)=%d.", row, rowMax, a[row][rowMax]);
            flag = 0;
        }
        row++;
    }

    if (flag)
    {
        printf("There is no saddle point in the matrix.");
    }

    return 0;
}

void inputMatrix(int a[MAX][MAX], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int findRowMax(int a[], int m)
{
    int i, rowMax = 0;
    for (i = 0; i < m; i++)
    {
        if (a[i] > a[rowMax])
        {
            rowMax = i;
        }
    }
    return rowMax;
}

int findColMin(int a[MAX][MAX], int n, int rowMax)
{
    int i, colMin = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i][rowMax] < a[colMin][rowMax])
        {
            colMin = i;
        }
    }
    return colMin;
}