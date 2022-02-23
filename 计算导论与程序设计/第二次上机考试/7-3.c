#include<stdio.h>

int main(void)
{
    int i, n, yearx, up, down;
    char year[3] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &yearx);
        up = yearx % 10;
        down = yearx % 12;
        switch(up)
        {
            case 0: year[0] = '6'; break;
            case 1: year[0] = '7'; break;
            case 2: year[0] = '8'; break;
            case 3: year[0] = '9'; break;
            case 4: year[0] = '0'; break;
            case 5: year[0] = '1'; break;
            case 6: year[0] = '2'; break;
            case 7: year[0] = '3'; break;
            case 8: year[0] = '4'; break;
            case 9: year[0] = '5'; break;
        }
        switch(down)
        {
            case 0: year[1] = 'I'; break;
            case 1: year[1] = 'J'; break;
            case 2: year[1] = 'K'; break;
            case 3: year[1] = 'L'; break;
            case 4: year[1] = 'A'; break;
            case 5: year[1] = 'B'; break;
            case 6: year[1] = 'C'; break;
            case 7: year[1] = 'D'; break;
            case 8: year[1] = 'E'; break;
            case 9: year[1] = 'F'; break;
            case 10: year[1] = 'G'; break;
            case 11: year[1] = 'H'; break;
        }
        printf("%s\n", year);
    }
    return 0;
}