#include<stdio.h>

//������������ 
//����˵�������飬����������Ԫ�ظ��� 
void InsertSort(int a[],int n);

int main()
{
    int        n , i,    num[1000] ;

    scanf( "%d" , &n ); 
    for( i = 0 ; i < n ; i++ ) 
        scanf( "%d", &num[i] ) ;
    InsertSort( num , n ) ; 
    return 0 ;
}

/* ����������д�� */

void InsertSort(int a[],int n) //��������˼�룺�������Ԫ�ز�����
{
    int i, j, k, temp;
    for (i = 1; i < n; i++) //���±�Ϊ 1 �ĵڶ���Ԫ�ؿ�ʼ������������ n - 1 ��
    {
        for (j = 0; j < i; j++) //���뵽ǰ�溬 i ��Ԫ�ص�������
        {
            if (a[j] > a[i]) //�ҵ���һ���ȱ������������
            {
                temp = a[i];
                for (k = i - 1; k >= j; k--) //ȫ������Ųһ��λ��
                {
                    a[k + 1] = a[k];
                }
                a[j] = temp; //�ѱ��������嵽��һ���������λ����
            }
        }

        for (j = 0; j < n - 1; j++) //�������������
        {
            printf("%d ", a[j]);
        }
        printf("%d\n", a[n - 1]);
    }
}