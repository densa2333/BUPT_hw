#include <stdio.h>

void reverse(int n) ; 

int main()
{
    int     n;

    scanf("%d",&n);
    reverse(n) ;
    printf("\n");
    return 0;
}

/* ����������д�� */

void reverse(int n)
{
    if (n / 10)
    {
        printf("%d", n % 10); //û����λ��ֱ��������һλ
        reverse(n / 10); //�������������һλ
    }
    else
        printf("%d", n); //������������һλ��û�з���ֵ����˳���ߵ�
}