#include<stdio.h>

int main(void)
{
    int i, n, time, dec, p;
    scanf("%d", &n);
    time = 0;
    dec = 0;
    while (n)
    {
        p = n % 10; //取出最后一位
        for (i = 0; i < time; i++) //计算 2 的某次方
          p *= 2;
        dec += p; //组装十进制数
        n /= 10;
        time++;
    }
    printf("%d", dec);
    return 0;
}