#include<stdio.h>

int main()
{
	double a, b, c, d;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	printf("%lf", ( a + b ) * ( a - b ) + c / d);
	return 0;
}
