#include <stdio.h>
#include <stdlib.h>

void shift(int *array , int num , int size ) ;

int main()
{
    int        i , n , p , array[100] ;

    scanf(" %d%d" , &n , &p ) ;//����������֤0<p<n<=100
    for( i = 0 ; i < n ; i++ )
        scanf( "%d" , &array[i] ) ;//����������֤����������������ʹ洢

    shift( array , p , n ) ;//������pλ
    for( i = 0 ; i < n - 1 ; i++ )
        printf( "%d " , array[i] ) ;
    printf( "%d\n" , array[i] ) ;

    return 0;    
}

/* ����������д�� */

void shift(int *array , int num , int size )
{
    int i, j, temp;

    for (i = 0; i < num; i++)
    {
        temp = array[0];
        for (j = 0; j < size - 1; j++)
        {
            array[j] = array[j + 1];
        }
        array[size - 1] = temp;
    }
}