#include<stdio.h>

int main(void)
{
    int i, j, k, flag;
    int a[1000], b[1000];

    i = 0;
    scanf("%d", &a[i]);
    while(a[i] != -1)
    {
        i++;
        scanf("%d", &a[i]);
    }

    i = 0;
    scanf("%d", &b[i]);
    while (b[i] != -1)
    {
        i++;
        scanf("%d", &b[i]);
    }

    for (i = 0; a[i] != -1; i++)
    {
        flag = 1;
        k = i;
        if (a[i] == b[0])
        {
            for (j = 0; b[j] != -1; j++)
            {
                if (a[k] != b[j])
                {
                    flag = 0;
                }
                k++;
            }
            if (flag)
            {
                printf("ListB is the sub sequence of ListA.");
                return 0;
            }
        }
    }

    printf("ListB is not the sub sequence of ListA.");
    return 0;
}