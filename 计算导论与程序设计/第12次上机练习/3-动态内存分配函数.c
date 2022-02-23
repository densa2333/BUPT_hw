#include<stdio.h>
#include<stdlib.h>


int * create(int n) ;
void cal(int * array, int size) ;

int main()
{
    int * array , n , i ;

    scanf( "%d", &n );

    array = create(n) ;
    if ( array == NULL )
        return -1 ; //�����return����Ϊû�л���ڴ��ֱ�ӽ�������

    cal( array, n) ;
    for ( i = 0 ; i < n ; i++ )
    {
        printf("%d" , *(array+i) ) ;
        if ( i == n - 1 ) printf("\n") ;
        else printf(" ") ;
    }     

    free(array) ; //���궯̬�����ڴ�һ��Ҫ�ǵ��ֶ��ͷ�

    return 0;
}

/* ����������д�� */

int * create(int n)
{
    int *array = NULL;
    array = malloc(sizeof(int) * n);
    return array;
}

void cal(int * array, int size)
{
    int i, sum = 0, max, min;
    float ave;

    for (i = 0; i < size; i++)
    {
        scanf("%d", array + i);
    }

    max = *array;
    min = *array;
    for (i = 0; i < size; i++)
    {
        sum += *(array + i);
        if (*(array + i) > max)
          max = *(array + i);
        else
            if (*(array + i) < min)
              min = *(array + i);
    }

    ave =  (float)sum / size;

    printf("%d\n%.2f\n%d\n%d\n", sum, ave, max, min);
}