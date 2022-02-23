#include <stdio.h>

void reverse(int n) ; 

int main()
{
    int     n;

    scanf("%d",&n);
    reverse(n) ;
    printf("\n");
    return 0;
}

/* 请在这里填写答案 */

void reverse(int n)
{
    if (n / 10)
    {
        printf("%d", n % 10); //没到个位就直接输出最后一位
        reverse(n / 10); //再输出后面的最后一位
    }
    else
        printf("%d", n); //最后就输出了最后一位。没有返回值，按顺序走的
}