#include<stdio.h>

//�������ܣ����ֲ���
//�����������ֱ�Ϊ�����ҵ����飬���鳤�ȣ������ҵ�Ԫ��
//��������ֵ������ҵ����򷵻ظ�Ԫ���������е��±꣬���򷵻�-1 
int BinarySearch(int a[],int n,int key) ; 

int main()
{
    int    num[20000] ; //�������Ƚϴ��������ĵ������޷�������ô����ڴ棬���С����ԡ�
    int        n , m, i;    
    int        key ;

    scanf("%d%d",&n,&m); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;

    for( i = 0 ; i < m ; i++ ) 
    {
        scanf("%d",&key) ;
        printf("%d",BinarySearch(num,n,key)) ;
        if ( i != m - 1 ) printf(" ") ;
        else printf("\n") ;
    }
    return 0 ;
}

/* ����������д�� */

int BinarySearch(int a[],int n,int key)
{
    int mid, left = 0, right = n - 1; //������Ǳ��� mid left right
    while (left <= right) //����������left > right �� �Ѿ��ҵ�
    {
        mid = (left + right) / 2; //ÿһ�˵�mid����ʼ��Ϊleft��right��ƽ����
        if (key == a[mid])
            return mid;
        else
            if (key < a[mid])
                right = mid - 1; //����м�ֵ���ڱ��������Ͱ�right��Ϊmid - 1
            else
                left = mid + 1; //����м�ֵС�ڱ��������Ͱ�left��Ϊmid + 1
    }
    return -1;
}