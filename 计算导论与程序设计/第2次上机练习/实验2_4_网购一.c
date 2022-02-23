#include<stdio.h>

int main()
{
	int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int sum = a + b + c + d;

    if ( sum < 20 ) printf("%d", sum + 10);
    if ( sum >= 20 && sum < 30 ) printf("%d", sum + 8);
    if ( sum >= 30 && sum < 40 ) printf("%d", sum + 5);
    if ( sum >= 40 ) printf("%d", sum);

	return 0;
}
