#include <stdio.h>

//�ж�һ�����Ƿ�Ϊ��ȫ���ĺ���
int        isPerfect(int);

//��ӡ��ȫ���ĺ��� 
void    printPerfect(int);

int main()
{
    int i,a,b,count;

    scanf("%d%d",&a,&b);
    count = 0 ;//a,b��������ȫ������������ʼ��Ϊ0 
    for(i=a;i<=b;i++)
    {
        if (isPerfect(i))  //�������ȫ�� 
        {
            printPerfect(i) ;//��ӡ����ȫ�� 
            count ++ ;  //��������1 
        }        
    }
    printf("The total number is %d.\n",count);//���a,b��������ȫ�������� 
    return 0 ;
}
/* ����������д�� */

int isPerfect(int n)
{
    int i, sum = 0;

    for (i = 1; i <= n / 2; i++) //�������ӣ������ظ�ֻ���ҵ� n / 2
    {
        if (n % i == 0) //��������Ӿͼ�����
            sum += i;
    }
    if (n == sum) //�ж����Ӻ��Ƿ���������
        return 1;
    else
        return 0;
}

void printPerfect(int n)
{
    int i;
    printf("%d=1", n);
    for (i = 1; i <= n / 2; i++)
    {
        if (n % i == 0 && i != 1)
            printf("+%d", i);
    }
    printf("\n");
}