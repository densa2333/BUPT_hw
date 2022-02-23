#include<stdio.h>

int main(void)
{
    int n, m, num, sum;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        num = i;
        sum = 0;
        while (num / 10)
        {
            sum += (num % 10) * (num % 10);
            num /= 10;
        }
        sum += num * num;

        if ((i / m) == sum)
            printf("%d\n", i);
    }

    return 0;
}