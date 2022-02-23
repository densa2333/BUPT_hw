#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int num; //存放输入的整数 
    int num1;    //循环中处理的数,每循环一次,右边少一位,假设num为1234,则 num1初始值为1234,然后是123,然后是12......;
    int reverse;     //是用分解出来的数字组成的新数
    int m;   //m:存放每一个分解出来的数字;
   
    scanf("%d",&num);   //从右到左依次取出各个数字组装成一个新的整数保持到reverse中
    num1=num; 
    reverse=0;
    while(num1!=0)
    {
   	    m=num1%10;    //取出num1的最低位
        reverse=reverse*10+m;     //将最低位组装到reverse中
   	    num1=num1/10;     //去掉num1的最低位
    }
                
    if (num==reverse) 
        printf("%d YES\n",num); 	
    else
        printf("%d NO\n",num); 	

    return 0; 
}