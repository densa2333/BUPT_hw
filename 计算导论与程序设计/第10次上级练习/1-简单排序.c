#include<stdio.h>

void bubbleSort(int a[],int n);

//�������������Ԫ�� 
void outputData(int data[],int elementCount);

int main()
{
    int n, i, num[10010];

    scanf("%d",&n); 

    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]);
    
    bubbleSort(num,n); 

    outputData(num,n);

    return 0 ;
}

/* ����������д�� */

void bubbleSort(int a[],int n) //ð������
{
    int i, j, temp;
    for (i = n - 1; i > 0; i--) //��ð�� n - 1 ��
    {
        for (j = 0; j < i; j++) //ÿ�˽������������ǵڼ��˾���
        {
            if (a[j] > a[j + 1]) //�ж��Ƿ񽻻�
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

    }
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