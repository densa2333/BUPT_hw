#include<stdio.h>

int main(void)
{
    int salary, i;
    int par[7] = {100, 50, 20, 10, 5, 2, 1}, 
        num[7] = {0}; //其实可以用结构

    scanf("%d", &salary);

    for (i = 0; i < 7; i++)
    {
        num[i] = salary / par[i]; //计算面值对应钞票的张数
        salary %= par[i]; //工资减去已计算张数的部分
    }

    for (i = 0; i < 7; i++)
    {
        if (num[i])
            printf("%d:%d\n", par[i], num[i]); //一起输出，有点像表
    }

    return 0;
}