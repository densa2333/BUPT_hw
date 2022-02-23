#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void inputMatrix(int [][MAX], int, int);
void transform(int [][MAX], int[][MAX], int, int);
void outputMatrix(int [][MAX], int, int);

int main(void)
{
    int n, m;
    int matrix[MAX][MAX];
    int result[MAX][MAX];

    scanf("%d %d", &n, &m);
    inputMatrix(matrix, n, m);
    transform(matrix, result, n, m);
    outputMatrix(result, n, m);

    return 0;
}

void inputMatrix(int matrix[][MAX], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void transform(int matrix[][MAX], int result[][MAX], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

void outputMatrix(int result[][MAX], int n, int m)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("%d\n", result[i][n - 1]);
    }
}