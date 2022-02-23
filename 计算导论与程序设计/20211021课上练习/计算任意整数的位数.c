#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int len = 1;
    while (n / 10) //如果是二进制就可以改成 2 ，ak * 2ek
    {
        len++;
        n /= 10;
    }

    printf("%d", len);
    
    return 0;
}