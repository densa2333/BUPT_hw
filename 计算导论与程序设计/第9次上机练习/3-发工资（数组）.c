#include<stdio.h>

int main(void)
{
    int salary, i;
    int par[7] = {100, 50, 20, 10, 5, 2, 1}, 
        num[7] = {0}; //��ʵ�����ýṹ

    scanf("%d", &salary);

    for (i = 0; i < 7; i++)
    {
        num[i] = salary / par[i]; //������ֵ��Ӧ��Ʊ������
        salary %= par[i]; //���ʼ�ȥ�Ѽ��������Ĳ���
    }

    for (i = 0; i < 7; i++)
    {
        if (num[i])
            printf("%d:%d\n", par[i], num[i]); //һ��������е����
    }

    return 0;
}