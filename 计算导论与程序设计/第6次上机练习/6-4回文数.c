#include<stdio.h>

int main(void)
{
    int n, m, reverse;
    scanf("%d", &n);
    m = n;
    reverse = 0; //将原数逆转，若逆转后的数与原来相同则为回文数
    while (m)
    {
        reverse = reverse * 10 + m % 10; //组装：原来基础上乘以十再加上上一次操作的数最后一位
        m /= 10; //每次都截断最后一位
    }
    if (reverse == n)
      printf("Yes\n");
    else
      printf("No\n");
    return 0;
}