#include <stdio.h>

int findMax(int n) ;

int main()
{   
    int n ; 

    scanf("%d", &n); 
    printf("%d\n" , findMax( n ) ) ; 

    return 0;
}

/* ����������д�� */

int findMax(int n)
{
    int num, max;
    if (n == 1)
    {
        scanf("%d", &num);
        return num;
    }

    max = findMax(n - 1); //��һ����Ҫreturn����ú�������
    scanf("%d", &num);
    if (num >= max)
        return num;
    else
        return max;
}