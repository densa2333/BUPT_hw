#include<stdio.h>

int isPrime(int);
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
    for (int i = 2; i * i <= n; i++) //找因数判断条件一定要记得限定循环次数，而且是<=
    {
        if (n % i == 0) isprime = 0;
    }
    if (isprime == 1) return 1;
    else return 0;
}

void printFactor(int a, int b)
{
    if (b == 1)
        printf("%d=", a);
    
    int i, flag = 1;
    if (isPrime(a)) //如果剩下的就是质数了就是最后一个直接输出不带乘号，而且不再进行递归调用
        printf("%d\n", a);
    else
    {
        for (i = 2; i <= a / 2 && flag; i++) //找因数判断条件一定要记得限定循环次数，而且是<=
        {
            if (isPrime(i) && a % i == 0) //要求是质因子
            {
                printf("%d*", i);
                flag = 0; //找到质因子就跳出循环
            }
        }
        printFactor(a / (i - 1), b - 1); //找下一个质因子
    }
}