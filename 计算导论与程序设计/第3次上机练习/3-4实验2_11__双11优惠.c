#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int n, price, sumprice;
    for (int i = 0; i < t; i++)
    {
        sumprice = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &price);
            sumprice += price;
        }

        if (sumprice >= 100 && sumprice < 200)
                printf("%d\n", sumprice - 30);
        else
            if (sumprice >= 200 && sumprice < 300)
                printf("%d\n", sumprice - 70);
        else
            if (sumprice >= 300 && sumprice < 400)
                printf("%d\n", sumprice - 110);
        else
            if (sumprice >= 400)
                printf("%d\n", sumprice - 160);
        else
            printf("%d\n", sumprice);
    }

    return 0;
}