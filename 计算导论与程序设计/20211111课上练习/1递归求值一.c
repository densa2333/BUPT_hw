#include<stdio.h>

int    fuc(int n) ;

int main()
{
    int n ;

    scanf("%d",&n); 
    printf("%d\n",fuc(n));

    return 0 ;
}

/* ����������д�� */

int fuc(int n)
{
    if (n == 0)
        return 0;
    else
        return fuc(n - 1) + n * n * n;
}