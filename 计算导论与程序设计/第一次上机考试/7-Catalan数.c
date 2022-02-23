#include<stdio.h>

long long fact(long long n);

int main(void)
{
    long long n;
    long long catalan;
    scanf("%d", &n);

    catalan = fact(2 * n) / (fact(n + 1) * fact(n));

    printf("%lld", catalan);
    
    return 0;
}

long long fact(long long n)
{
    long long i, value = 1;
    for (i = 1; i <= n; i++)
    {
        value *= i;
    }
    return value;
}