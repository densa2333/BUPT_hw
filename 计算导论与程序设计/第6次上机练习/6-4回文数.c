#include<stdio.h>

int main(void)
{
    int n, m, reverse;
    scanf("%d", &n);
    m = n;
    reverse = 0; //��ԭ����ת������ת�������ԭ����ͬ��Ϊ������
    while (m)
    {
        reverse = reverse * 10 + m % 10; //��װ��ԭ�������ϳ���ʮ�ټ�����һ�β����������һλ
        m /= 10; //ÿ�ζ��ض����һλ
    }
    if (reverse == n)
      printf("Yes\n");
    else
      printf("No\n");
    return 0;
}