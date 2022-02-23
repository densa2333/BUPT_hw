#include<stdio.h>

//ѡ���������� 
//����˵�������飬����������Ԫ�ظ��� 
void selectSort(int data[],int elementCount) ;

//�������ܣ��������е���СֵԪ�أ����������±� 
//����˵������������������ʼλ���±꣬������ֹλ���±�
int findMin(int data[], int startLoc, int endLoc) ; 

//�������������Ԫ�� 
//����˵�������飬����������Ԫ�ظ��� 
void outputData(int data[],int elementCount) ;

int main()
{
    int        n , i,    num[1010] ;

    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
    selectSort(num,n) ; 
    return 0 ;
}

/* ����������д�� */

void selectSort(int data[],int elementCount)
{
    int i, temp, minLoc; //�������СԪ�ص�λ��Ȼ�󽻻�
    for (i = 0; i < elementCount - 1; i++)
    {
        minLoc = findMin(data, i, elementCount - 1); //����Ҫ����minLoc����Ȼ��������findMin�������Ϊdata[i]�ı���
        temp = data[i];
        data[i] = data[minLoc];
        data[minLoc] = temp;
        outputData(data, elementCount);
    }
}

int findMin(int data[], int startLoc, int endLoc)
{
    int i, min = data[startLoc], minLoc = startLoc;
    for (i = startLoc; i <= endLoc; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
            minLoc = i;
        }
    }
    return minLoc;
}

void outputData(int data[],int elementCount)
{
    int i;
    for (i = 0; i < elementCount - 1; i++)
    {
        printf("%d ", data[i]);
    }
    printf("%d\n", data[elementCount - 1]);
}