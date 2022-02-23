#include<stdio.h>

int countBinary(int);

int main()
{
    int        n;

    scanf("%d",&n);
    printf("%d\n",countBinary(n));

    return 0 ;
}

/* 请在这里填写答案 */

int countBinary(int n)
{
    if (n == 0 || n == 1)
      return 1;
    else
      return countBinary(n / 2) + 1; //十进制转二进制除二取余倒序输出
}