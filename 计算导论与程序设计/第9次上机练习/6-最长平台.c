#include<stdio.h>

int main(void)
{
    int n, i, same = 1, max = 1;
    int a[1001];
    scanf("%d", &n);
    scanf("%d", &a[0]); /*�ȶ���һ��*/
    for (i = 1; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == a[i - 1]) //��ѭ����ÿ������һ�����Ƚ��Ƿ���ͬ
          same++; //��ͬ��ƽ̨����+1
        else
          same = 1; //����ͬ��ƽ̨���Ȼָ�1
        if (same > max) //���ָ�����ƽ̨�͸���max��ֵ
          max = same;
    }
    printf("%d", max);
    return 0;
}