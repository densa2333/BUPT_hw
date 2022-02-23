#include<stdio.h>
#define PI 3.14159265

int main()
{
	double R;
	scanf("%lf", &R);
	printf("The perimeter is %.4lf, the area is %.4lf.", 2 * PI * R, PI * R * R);
	return 0;
}
