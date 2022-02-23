#include <stdio.h>

int    evaluation(int n,int a) ;
int main()
{
       int        n , a ; 

       scanf("%d%d",&n,&a);       
       printf("%d\n",evaluation(n,a));

    return 0;
}

/* 请在这里填写答案 */

int evaluation(int n,int a)
{
    if (n == 0)
        return 1 + a;
    else
        return 1 + a * evaluation(n - 1, a);
    // s = 1 + a * (1 + a * (1 + a * (...))) 提公因式发现递归公式
}