#include<stdio.h>

int main(void)
{
    int n, year, i, num;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        num = 0;
        scanf("%d", &year);
        while (year != -1)
        {
            if (year % 100 == 0 && year % 400 == 0)
                num++;
            else
                if (year % 100 && year % 4 == 0)
                    num++;
            
            scanf("%d", &year);
        }
        printf("%d\n", num);
    }

    return 0;
}