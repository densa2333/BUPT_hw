#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	
    double S = ( a + b +c ) / 2;
    double Area = sqrt( S * ( S - a )*( S -b )*( S - c ) );

	if ( a + b > c && a + c > b && b + c > a ) printf("%.3lf", Area);
    	
	else printf("The edges cannot make up of a triangle.");

    return 0;
}
