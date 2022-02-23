#include<stdio.h>

int reverseNum(int) ; 

int main()
{
    int        num ;

    scanf("%d",&num);
    printf("The reverse form of number %d is %d.\n",num,reverseNum(num)) ;

    return 0;
}

/* 请在这里填写答案 */

int reverseNum(int n)
{
    int p;
    int reverse = 0;

    while (n / 10)
    {
        p = n % 10;
        reverse = reverse * 10 + p;
        n /= 10;
    }

    reverse = reverse * 10 + n;

    return reverse;
}