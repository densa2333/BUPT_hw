#include<stdio.h>

int    getDays(int,int) ;

int main(void)
{
    int    year, month ;

    scanf("%d %d",&year,&month);
    printf("There are %d days in month %d year %d.",getDays(year,month), month, year) ;

    return 0 ;    
}

/* 请在这里填写答案 */
int getDays(int y, int m)
{
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
    {
        if (m == 2)
            return 29;
        else
            if (m == 4 || m == 6 || m == 9 || m == 11)
                return 30;
            else
                return 31;
    }
    else
    {
        if (m == 2)
            return 28;
        else
            if (m == 4 || m == 6 || m == 9 || m == 11)
                return 30;
            else
                return 31;
    }
}