#include<stdio.h>

int main(void)
{
    int i, n, sum;
    scanf("%d", &n);
    sum = 1;
    for (i = 1; i <= n; i++)
      sum += i; //�е� n ��ʱ������ + n
    printf("%d", sum);
    return 0;
}