#include<stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    for (int j = 0; j < r; j++)
    {
        printf("|");
        for (int i = 0; i < c; i++)
        {
            printf("*****|");
        }
        printf("\n");

        printf("|");
        for (int i = 0; i < c; i++)
        {
            printf("  |  |");
        }
        printf("\n");

        printf("|");
        for (int i = 0; i < c; i++)
        {
            printf("--+--|");
        }
        printf("\n");

        printf("|");
        for (int i = 0; i < c; i++)
        {
            printf("  |  |");
        }
        printf("\n");
    }
    
    printf("|");
    for (int i = 0; i < c; i++)
        {
            printf("*****|");
        }
        printf("\n");

    return 0;
}