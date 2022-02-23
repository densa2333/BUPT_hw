#include<stdio.h>

#define MAX 100

void inputMatrix(int [][MAX], int);
void swap(int [][MAX], int);
void outputMatrix(int [][MAX], int);

int main(void)
{
    int n, i;
    int a[MAX][MAX];

    scanf("%d", &n);
    inputMatrix(a, n);
    swap(a, n);
    outputMatrix(a, n);

    return 0;
}

void inputMatrix(int a[MAX][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void swap(int a[][MAX], int n)
{
    int i, j, k;
    int temp[n];
    int sum1, sum2;

    for (i = n; i > 1; i--)
    {
        for (j = 0; j < i - 1; j++)
        {
            sum1 = 0;
            sum2 = 0;
            for (k = 0; k < n; k++)
            {
                sum1 += a[j][k];
                sum2 += a[j + 1][k];
            }
            if (sum1 > sum2)
            {
                for (k = 0; k < n; k++)
                {
                    temp[k] = a[j][k];
                    a[j][k] = a[j + 1][k];
                    a[j + 1][k] = temp[k];
                }
            }
        }
    }
}

void outputMatrix(int a[][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][n - 1]);
    }
}