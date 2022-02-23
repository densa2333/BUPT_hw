#include<stdio.h>

int main()
{
    int num = 1;
    for (int i = 9; i >= 1; --i)
    {
        num = 2 * (num + 1);
    }
    printf("%d\n", num);
    return 0;
}