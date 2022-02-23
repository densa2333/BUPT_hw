#include<stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);
    
    int prePrime = 2;
    while (num != 1)
    {
        if (num % prePrime == 0)
        {
            printf("%d ", prePrime);
            num /= prePrime;
        }
        else
            prePrime ++;
    }
    
    return 0;
}
/*
    f(p)=n*f(p/n), p从2开始试探，逐渐变大（加1）。若试探过程中发现p能被n整除，则n肯定是素数。
    原因分析：根据题意，任何合数均能分解为若干个素数的乘积。假设n为6且p除以n余数为0，则n=6*……，
	由于6＝2*3, 因此n=2*3*…，在分解出6之前早就已经分解得到2*3了，所以 p不可能为6。其他的合数也是如此。
*/