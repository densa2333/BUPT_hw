#include<stdio.h>
#include<stdbool.h>

bool is_prime(int n);

int main()
{
    int n;
    scanf("%d", &n);

    int number, sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;

        scanf("%d", &number);
        while (number != -1)
        {
            if (is_prime(number)) sum++;

            scanf("%d", &number);
        }

        printf("%d\n", sum);
    }
    
    
    return 0;
}

bool is_prime(int n)
{
    if (n < 2) return false;
    else
        for (int divisor = 2; divisor * divisor <= n; divisor++)
        {
            if (n % divisor == 0) return false;
        }
    
    return true;
}