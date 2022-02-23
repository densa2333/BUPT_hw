#include<stdio.h>

int main(void)
{
    int number;
    scanf("%d", &number);

    int bit = number;
    int length = 1;
    while (number / 10) //计算长度
    {
        length++;
        number /= 10;
    }

    while (length > 0)
    {
        
        int p = 1;
        for (int i = 0; i < length - 1; i++)
        {
            p *= 10;
        }

        if (length > 1)
        {
            printf("%d ", bit / p); //输出最高位
            bit %= p; //去掉最高位
        }
        else
        {
            printf("%d\n", bit / p);
        }

        number /= 10;
        length -= 1;
    }

    return 0;
}