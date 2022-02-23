#include<stdio.h>

int main(void)
{
    int n = 1, i;
    char a[101];

    scanf("%c", &a[0]);
    while (a[n] != '\n')
    {
        n++;
        scanf("%c", &a[n]);
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] >= 'A' && a[i] <='Z')
            printf("%c", a[i] + 32);
        else
            if (a[i] >= 'a' && a[i] <='z')
                printf("%c", a[i] - 32);
            else
                printf("%c", a[i]);
    }

    return 0;
}