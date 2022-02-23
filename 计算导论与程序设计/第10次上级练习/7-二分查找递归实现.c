#include<stdio.h>

#define MAXN 20000

int RecurBinarySearch( int a[] , int key , int left , int right ) ;

int main()
{
    int        a[MAXN];//�������Ƚϴ��������ĵ������޷�������ô����ڴ棬���С����ԡ�
    int        n , m , i , key ;

    scanf("%d %d",&n , &m );    
    for( i = 0 ; i < n ; i++ )
        scanf("%d", &a[i]);

    for( i =0 ; i < m ; i++ )
    {
        scanf("%d",&key);
        printf( "%d" , RecurBinarySearch( a , key , 0 , n - 1 ) );
        if ( i != m - 1 ) printf(" ") ;
        else printf("\n") ; 
    }

    return 0;
}

/* ����������д�� */

int RecurBinarySearch( int a[] , int key , int left , int right )
{
    int mid;
    mid = (left + right) / 2;
    if (key == a[mid])
    {
        return mid;
    }
    else
        if (left > right)
        {
            return -1;
        }
        else
            if (key > a[mid])
            {
                return RecurBinarySearch(a, key, mid + 1, right);
            }
            else
                if (key < a[mid])
                {
                    return RecurBinarySearch(a, key, left, mid - 1);
                }
}