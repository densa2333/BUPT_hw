#include <stdio.h>

int reverse(int n) ; 

int main()
{
    int        n ;

    scanf( "%d" , &n );
    printf( "%d\n" , reverse(n) );

    return 0 ;
}


/* ����������д�� */
int reverse(int n)
{
    int reverse = 0;
    
    while (n / 10)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    
    reverse = reverse * 10 + n;

    return reverse;
}