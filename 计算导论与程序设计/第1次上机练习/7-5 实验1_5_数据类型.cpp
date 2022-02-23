#include<stdio.h>

int main()
{
	char a;
	short b;
	int c;
	long d;
	long long e;
	float f;
	double g;
	scanf("%c %hd %d %ld %lld %f %lf", &a, &b, &c, &d, &e, &f, &g);
	printf("The 'char' variable is %c, it takes %d byte.\n", a, sizeof(char));
	printf("The 'short' variable is %hd, it takes %d bytes.\n", b, sizeof(short));
	printf("The 'int' variable is %d, it takes %d bytes.\n", c, sizeof(int));
	printf("The 'long' variable is %ld, it takes %d bytes.\n", d, sizeof(long));
	printf("The 'long long' variable is %lld, it takes %d bytes.\n", e, sizeof(long long));
	printf("The 'float' variable is %f, it takes %d bytes.\n", f, sizeof(float));
	printf("The 'double' variable is %lf, it takes %d bytes.\n", g, sizeof(double));
	return 0;
}
