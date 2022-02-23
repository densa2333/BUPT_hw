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

/* ����������д�� */

int isPrime(int n)
{
    int isprime = 1;
    for (int i = 2; i * i <= n; i++) //�������ж�����һ��Ҫ�ǵ��޶�ѭ��������������<=
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
    if (isPrime(a)) //���ʣ�µľ��������˾������һ��ֱ����������˺ţ����Ҳ��ٽ��еݹ����
        printf("%d\n", a);
    else
    {
        for (i = 2; i <= a / 2 && flag; i++) //�������ж�����һ��Ҫ�ǵ��޶�ѭ��������������<=
        {
            if (isPrime(i) && a % i == 0) //Ҫ����������
            {
                printf("%d*", i);
                flag = 0; //�ҵ������Ӿ�����ѭ��
            }
        }
        printFactor(a / (i - 1), b - 1); //����һ��������
    }
}