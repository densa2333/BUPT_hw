#include <stdio.h>

int    evaluation(int n,int a) ;
int main()
{
       int        n , a ; 

       scanf("%d%d",&n,&a);       
       printf("%d\n",evaluation(n,a));

    return 0;
}

/* ����������д�� */

int evaluation(int n,int a)
{
    if (n == 0)
        return 1 + a;
    else
        return 1 + a * evaluation(n - 1, a);
    // s = 1 + a * (1 + a * (1 + a * (...))) �ṫ��ʽ���ֵݹ鹫ʽ
}