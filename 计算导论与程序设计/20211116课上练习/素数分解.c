#include<stdio.h>

void printFactor( int, int ); 

int main()
{
    int a,b,i ;

    scanf( "%d%d", &a, &b );
    for( i = a ; i <= b ; i++ )
        printFactor( i , 1 ) ;    

    return 0;
}

/* 请在这里填写答案 */

int isPrime(int n)
{
    int isprime = 1;
    if (n == 1)
        isprime = 0;
    for (int i = 2; i * i <= n; i++) //找因数判断条件一定要记得限定循环次数，而且是<=
    {
        if (n % i == 0) isprime = 0;
    }
    if (isprime == 1) return 1;
    else return 0;
}

void printFactor(int n, int p) //p是找因数用的
{
    if (p == 1)
        printf("%d=", n);
    
    if (isPrime(n))
        printf("%d\n", n); //乘号放后面，最后一项是单独出来的不用*
    else
    {
        if (isPrime(p) && n % p == 0)
        {
            printf("%d*", p); //输出格式处理，乘号放后面
            printFactor(n / p, p);
        }
        else
            printFactor(n, p + 1); //如果p不是因数就+1继续枚举
    }
    
}