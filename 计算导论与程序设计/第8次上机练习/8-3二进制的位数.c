#include<stdio.h>

int countBinary(int);

int main()
{
    int        n;

    scanf("%d",&n);
    printf("%d\n",countBinary(n));

    return 0 ;
}

/* ����������д�� */

int countBinary(int n)
{
    if (n == 0 || n == 1)
      return 1;
    else
      return countBinary(n / 2) + 1; //ʮ����ת�����Ƴ���ȡ�൹�����
}