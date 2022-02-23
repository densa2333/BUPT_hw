#include<stdio.h>

#define        MAXLEN        110

int        isPrime( int n ) ;//判断一个整数是否是质数，是则返回1，否则返回0 
int        getResult( char word[] ) ;

int main()
{
    char    word[MAXLEN] ;

    scanf( "%s" , word ) ;            
    printf( "%d\n" , getResult( word ) );

    return 0;
}

/* 请在这里填写答案 */

int isPrime(int n)
{
    if (n < 2) return 0;
    else
        for (int divisor = 2; divisor * divisor <= n; divisor++)
        {
            if (n % divisor == 0) return 0;
        }
    
    return 1;
}

int getResult(char word[])
{
    int i, j, min = 0, max = 0, repeat;
    for (i = 0; *(word + i); i++)
    {
        repeat = 0;
        for (j = 0; *(word + j); j++)
        {
            if (*(word + i) == *(word + j)) repeat++;
        }
        if (i == 0) min = repeat;
        else
            if (repeat < min) min = repeat;
        if (repeat > max) max = repeat;
    }
    if (isPrime(max - min)) return max - min;
    else return -1;
}