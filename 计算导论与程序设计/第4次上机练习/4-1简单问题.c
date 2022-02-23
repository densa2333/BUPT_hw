#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int x, sum = 0, min, max;
    scanf("%d", &x);
    min = x;
    max = x;
    sum += x;
    for (int  i = 0; i < n - 1; i++)
    {
        scanf("%d", &x);
        sum += x;
        if (x > max) max = x;
        if (x < min) min = x;
    }

    printf("%d %d %d", sum, max, min);
    
    return 0;
}