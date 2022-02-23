#include <stdio.h>

//判断一个数是否为完全数的函数
int        isPerfect(int);

//打印完全数的函数 
void    printPerfect(int);

int main()
{
    int i,a,b,count;

    scanf("%d%d",&a,&b);
    count = 0 ;//a,b两数间完全数的数量，初始化为0 
    for(i=a;i<=b;i++)
    {
        if (isPerfect(i))  //如果是完全数 
        {
            printPerfect(i) ;//打印该完全数 
            count ++ ;  //计数器加1 
        }        
    }
    printf("The total number is %d.\n",count);//输出a,b两数间完全数的数量 
    return 0 ;
}
/* 请在这里填写答案 */

int isPerfect(int n)
{
    int i, sum = 0;

    for (i = 1; i <= n / 2; i++) //查找因子，避免重复只查找到 n / 2
    {
        if (n % i == 0) //如果是因子就加起来
            sum += i;
    }
    if (n == sum) //判断因子和是否等于这个数
        return 1;
    else
        return 0;
}

void printPerfect(int n)
{
    int i;
    printf("%d=1", n);
    for (i = 1; i <= n / 2; i++)
    {
        if (n % i == 0 && i != 1)
            printf("+%d", i);
    }
    printf("\n");
}