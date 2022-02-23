#include<stdio.h>

int main()
{
	double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a ,&b, &c, &d);

    if ( b * c - d < 0.0000001 && b * c - d > - 0.0000001 ) printf("error");
    else printf("%.1lf", a / ( b * c - d ) );

	return 0;
}