#include<stdio.h>

int main(void)
{
    int i, n, n2, n0, len, n1, p;
    scanf("%d", &n);

    if (n >= 1 && n <= 10000)
    {
        n2 = n * n; //先求x的平方
        n0 = n; 
        len = 1;
        while (n0 / 10) //求x的长度
        {
            len++;
            n0 /= 10;
        }
        
        p = 1;
        for (i = 0; i < len; i++)
          p *= 10;
        n1 = n2 % p; //取出n2最后len位，方便后续比对
    
        if (n1 == n)
          printf("Yes\n");
        else
          printf("No\n");
    }
    else
        printf("%d out of range\n", n);
    
    return 0;
}