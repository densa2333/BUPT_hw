#include<stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    if ( A >= 0 && A <= 21 && B >= 0 && B <= 21 )
    {
        if ( A > B ) printf("A win");
    
        if ( A < B ) printf("B win");

        if ( A == B && A != 21 ) printf("no result");

        if ( A == 21 && B == 21 ) printf("error");
    }
    else if ( A == 22 && B < 21 ) printf("A win");
    else if ( B == 22 && A < 21 ) printf("B win");
    
    else printf("error");

    return 0;
}