#include<stdio.h>

int main()
{
    int x;

    scanf("%d", &x);

    int mod3 = 0, mod5 = 0, mod7 = 0;
    double n = 0;
    while (x != 0)
    {
        if (x % 3 == 0 && x % 5 != 0 && x % 7 != 0)
            mod3++;
        else
            if (x % 3 != 0 && x % 5 == 0 && x % 7 != 0)
                mod5++;
        else
            if (x % 3 != 0 && x % 5 != 0 && x % 7 == 0)
                mod7++;
        n++;
        scanf("%d", &x);
    }

    printf("%.2f%%\n%.2f%%\n%.2f%%\n", mod3 / n * 100, mod5 / n * 100, mod7 / n * 100);
    
}