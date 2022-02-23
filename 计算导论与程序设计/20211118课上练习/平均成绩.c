#include<stdio.h>

int score[100];

int main(void)
{
    int n, i;
    double ave, sum = 0;
    
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
        sum += score[i];
    }

    ave = sum / n;

    printf("%.2f", ave);

    return 0;
}