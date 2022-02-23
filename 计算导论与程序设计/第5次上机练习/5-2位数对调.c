#include<stdio.h>

int main(void)
{
    int num, m;
    scanf("%d", &num);
    int num1 = num, reverse = 0;

    while (num1 != 0)
    {
        m = num1 % 10; //取最高位
        reverse = reverse * 10 + m; //组装reverse
        num1 /= 10;
    }

    if (num % 10 == 0)
        printf("The number cannot be changed.");
    else
        printf("%d", reverse);
    
    return 0;
}