#include<stdio.h>

int main(void)
{
    double f, m, b;
    int sex;
    scanf("%lf %lf %d", &f, &m, &sex);
    if (sex)
    {
        b = (f + m) * 1.08 / 2;
    }
    else
    {
        b = (f * 0.923 + m) / 2;
    }
    printf("%.2f", b);
    return 0;
}