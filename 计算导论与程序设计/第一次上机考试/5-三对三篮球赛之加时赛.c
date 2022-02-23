#include<stdio.h>

int main(void)
{
    int scoreA, scoreB;

    scanf("%d %d", &scoreA, &scoreB);

    if (scoreA >= 21 && scoreB >= 21)
        printf("error\n");
    else
        if (scoreA - scoreB > 2 || scoreB - scoreA > 2)
            printf("error\n");
        else if (scoreA > scoreB && scoreB >= 0)
                printf("A win\n");
            else
                if (scoreB > scoreA && scoreA >= 0)
                    printf("B win\n");
                else
                    if (scoreA == scoreB)
                        printf("error\n");
    return 0;
}