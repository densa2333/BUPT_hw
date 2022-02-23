#include<stdio.h>

int judgeTriangle(int,int,int) ; 

int main()
{
    int        a, b, c ;    

    scanf("%d%d%d",&a,&b,&c);

    switch(judgeTriangle(a,b,c))
    {
        case    -1    :    printf("It is not a triangle.\n") ;    break ;
        case    0    :    printf("It is a scalenous triangle.\n") ;    break ;
        case    1    :    printf("It is a right-angled triangle.\n") ;    break ;
        case    2    :    printf("It is an isosceles triangle.\n") ;    break ;
        case    3    :    printf("It is a equilateral triangle.\n") ;    break ;
    }

    return 0;
}

/* 请在这里填写答案 */

int judgeTriangle(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
            return 1;
        else
            if (a == b && b == c)
                return 3;
            else
                if (a == b && b != c || a == c && c != b || b == c && c != a)
                    return 2;
                else
                    return 0;
    }
    else
        return -1;
}