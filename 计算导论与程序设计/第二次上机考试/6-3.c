#include<stdio.h>

#define        MAXLEN        500000
void  sortAndOutput(int *data , int size) ;

int main()
{
    int        data[MAXLEN];
    int        n, i;

    scanf( "%d" , &n );
    for ( i = 0 ; i < n ; i++ )
        scanf( "%d" , &data[i] );

    sortAndOutput( data, n ) ;

    return 0;    
}

/* 请在这里填写答案 */

void  sortAndOutput(int *data , int size)
{
    
}