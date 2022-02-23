#include<stdio.h>

int fun(int x);

int main(void)
{
    int x;

    scanf("%d", &x);
    printf("The result is:y=%d\n", fun(x));

    return 0;    
}

/* 请在这里填写答案 */
int fun(int x)
{
    int y;
    if (x < 1)
        y = x;
    else
        if (1 <= x && x <= 10)
            y = 2 * x - 1;
        else
            if (10 < x && x <= 100)
                y = 3 * x - 11;
            else
                if (x > 100)
                    y = x * x - 24;

    return y;
}