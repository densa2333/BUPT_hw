#include<stdio.h>

int main()
{
    long long n;
    scanf("%lld", &n);

    long long An = 0, sum = 0;
    if (n == 1 || n == 2) printf("%lld", An);
    else
    {
        for (long long i = 1; i <= n - 2; i++)
        {
            An += i * (i + 1) * (i + 2);
            sum += An;
        }

        printf("%lld", sum);
    }

}