#include<stdio.h>

int main(void)
{
    int n;
    int dividedby5, dividedby6, dividedby7, dividedby11;
    scanf("%d", &n);
    dividedby5 = n % 5;
    dividedby6 = n % 6;
    dividedby7 = n % 7;
    dividedby11 = n % 11;
    while (dividedby5 != 1 || dividedby6 != 5 || dividedby7 != 6 || dividedby11 != 10)
    {
        n++;
        dividedby5 = n % 5;
        dividedby6 = n % 6;
        dividedby7 = n % 7;
        dividedby11 = n % 11;
    }

    printf("%d", n);

    return 0;
}