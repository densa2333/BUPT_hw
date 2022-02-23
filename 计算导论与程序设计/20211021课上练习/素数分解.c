#include<stdio.h>
#include<stdbool.h>

bool is_prime(int n);

int main(void)
{
    int p;
    scanf("%d", &p);

    int prePrime = 2;
    int n = prePrime;
    while (p != 1) //每一次找质因数都是从prePrim开始试探
    {
        bool found = true;
        while (n <= p && found) //求p的最小质因数n
        {
            if (is_prime(n))
            {
                if (p % n == 0)
                    found = false;
                else
                    n ++;
            }
            else
                n ++;
        }
        prePrime = n; //最小质因子迭代

        printf("%d ", n);
        p /= n;
    }
    
    return 0;
}

bool is_prime(int n) //判断素数的函数
{
    int divisor;
    for (divisor = 2; divisor * divisor <= n; divisor++)
    {
        if (n % divisor == 0)
            return false;
    }
    return true;
}