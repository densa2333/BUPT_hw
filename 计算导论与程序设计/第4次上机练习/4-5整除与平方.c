#include<stdio.h>
#include<stdbool.h>

bool aliquot_3_7(int n);

int main()
{
    int n;
    scanf("%d", &n);

    int s;
    for (int i = 1; i < n; i++)
    {
        if (aliquot_3_7(i)) s += i;
    }

    printf("%d", s * s);

    return 0;
}

bool aliquot_3_7(int n)
{
    if (n % 3 == 0 && n % 7 ==0)
        return true;
    else
        return false;
}