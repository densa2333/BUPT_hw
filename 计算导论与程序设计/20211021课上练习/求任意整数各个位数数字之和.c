#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    while (n / 10)
    {
        sum += n % 10;
        n /= 10;
    }
    sum += n;

    printf("%d", sum);
    
    return 0;
}