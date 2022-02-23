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

/* ����������д�� */

int isPrime(int n)
{
    int isprime = 1;
    if (n == 1)
        isprime = 0;
    for (int i = 2; i * i <= n; i++) //�������ж�����һ��Ҫ�ǵ��޶�ѭ��������������<=
    {
        if (n % i == 0) isprime = 0;
    }
    if (isprime == 1) return 1;
    else return 0;
}

void printFactor(int n, int p) //p���������õ�
{
    if (p == 1)
        printf("%d=", n);
    
    if (isPrime(n))
        printf("%d\n", n); //�˺ŷź��棬���һ���ǵ��������Ĳ���*
    else
    {
        if (isPrime(p) && n % p == 0)
        {
            printf("%d*", p); //�����ʽ�����˺ŷź���
            printFactor(n / p, p);
        }
        else
            printFactor(n, p + 1); //���p����������+1����ö��
    }
    
}