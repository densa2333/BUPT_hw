#include<stdio.h>

int main(void)
{
    int i, n, time, dec, p;
    scanf("%d", &n);
    time = 0;
    dec = 0;
    while (n)
    {
        p = n % 10; //ȡ�����һλ
        for (i = 0; i < time; i++) //���� 2 ��ĳ�η�
          p *= 2;
        dec += p; //��װʮ������
        n /= 10;
        time++;
    }
    printf("%d", dec);
    return 0;
}