#include<stdio.h>

#define MAX 100

void construct(int [][MAX], int);
void output(int [][MAX], int);

int main(void)
{
    int n;
    int a[MAX][MAX];

    scanf("%d", &n);
    construct(a, n);
    output(a, n);

    return 0;
}

void construct(int a[][MAX], int n)
{
    int i = 0, j = 0, num = 1, group = 1, sum;
    while (group <= n)
    {
        if (group % 2)
        {
            for (i = 0; i < group; i++)
            {
                a[i][group - 1 - i] = num;
                num++;
            }
            group++;
        }
        else
        {
            for (i = 0; i < group; i++)
            {
                a[group - 1 - i][i] = num;
                num++;
            }
            group++;
        }
    }

    sum = n;
    group--;
    while (group > 0)
    {
        if (group % 2 == 0)
        {
            for (i =  n - 1; i > sum - n; i--)
            {
                a[sum - i][i] = num;
                num++;
            }
            group--;
            sum++;
        }
        else
        {
            for (i = n - 1; i > sum - n; i--)
            {
                a[i][sum - i] = num;
                num++;
            }
            group--;
            sum++;
        }
    }
}

void output(int a[][MAX], int n)
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