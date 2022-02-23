#include<stdio.h>

#define MAX 50

void inputNote(float [][5], int);
void outputNote(float [][5]);

int main(void)
{
    int n;
    float result[6][5] = {0.0};

    scanf("%d", &n);
    inputNote(result, n);
    outputNote(result);

    return 0;
}

void inputNote(float result[6][5], int n)
{
    int i, num, product;
    float sale;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %f", &num, &product, &sale);
        result[product - 1][num - 1] += sale;
        result[5][num - 1] += sale;
        result[product - 1][4] += sale;
    }
    for (i = 0; i < 4; i++)
    {
        result[5][4] += result[5][i];
    }
}

void outputNote(float result[6][5])
{
    int i, j;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%.1lf\t", result[i][j]);
        }
        printf("%.1lf\n", result[i][4]);
    }
}
