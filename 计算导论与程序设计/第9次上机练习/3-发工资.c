#include<stdio.h>

int main(void)
{
    int salary;
    int par_100 = 0, par_50 = 0, par_20 = 0, par_10 = 0, par_5 = 0, par_2 = 0, par_1 = 0;

    scanf("%d", &salary);

    while (salary / 2)
    {
        if (salary / 100)
        {
            par_100 += salary / 100;
            salary -= par_100 * 100;
        }
        else
            if (salary / 50)
            {
                par_50 += salary / 50;
                salary -= par_50 * 50;
            }
            else
                if (salary / 10)
                {
                    par_10 += salary / 10;
                    salary -= par_10 * 10;
                }
                else
                    if (salary / 5)
                    {
                        par_5 += salary / 5;
                        salary -= par_5 * 5;
                    }
                    else
                        if (salary / 2)
                        {
                            par_2 += salary / 2;
                            salary -= par_2 * 2;
                        }
    }

    par_1 = salary;
    
    if (par_100)
        printf("100:%d\n", par_100);
    if (par_50)
        printf("50:%d\n", par_50);
    if (par_20)
        printf("20:%d\n", par_20);
    if (par_10)
        printf("10:%d\n", par_10);
    if (par_5)
        printf("5:%d\n", par_5);
    if (par_2)
        printf("2:%d\n", par_2);
    if (par_1)
        printf("1:%d\n", par_1);

    return 0;
}