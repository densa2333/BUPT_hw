#include <stdio.h>

int findMax(int n) ;

int main()
{   
    int n ; 

    scanf("%d", &n); 
    printf("%d\n" , findMax( n ) ) ; 

    return 0;
}

/* 请在这里填写答案 */

int findMax(int n)
{
    int num, max;
    if (n == 1)
    {
        scanf("%d", &num);
        return num;
    }

    max = findMax(n - 1); //不一定是要return里调用函数本身
    scanf("%d", &num);
    if (num >= max)
        return num;
    else
        return max;
}