#include<stdio.h>

int main(void)
{
    int i, n, sum;
    scanf("%d", &n);
    sum = 1;
    for (i = 1; i <= n; i++)
      sum += i; //ÇÐµÚ n µ¶Ê±£¬¿éÊý + n
    printf("%d", sum);
    return 0;
}