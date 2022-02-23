#include<stdio.h>

int check7(int);

int main(void)
{
    int i, l, r, cnt = 0;
    scanf("%d %d", &l, &r);
    for (i = l; i <= r; i++)
      if (i % 7 == 0 || check7(i))
        cnt++;
    printf("%d", cnt);
    return 0;
}

int check7(int n)
{
    int i, flag = 0;
    while(n / 10)
    {
        if (n % 10 == 7) flag = 1;
        n /= 10;
    }
    if (n % 10 == 7) flag = 1;
    return flag;
}