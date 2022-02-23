#include<stdio.h>

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);

    int max, min, r, gdb;
    if (m >= n)
    {
        max = m;
        min = n;
    }
    else
    {
        max = n;
        min = m;
    }
    r = max % min;
    while (r != 0) //辗转相除法
    {
        max = min;
        min = r;
        r = max % min;
    }
    gdb = min;
    printf("%d ", gdb);
    printf("%d", m * n / gdb); //两数相乘除以最大公因数等于最小公倍数

    return 0;
}