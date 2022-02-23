#include<stdio.h>

int main()
{
	char sex;
	int age;
	float height;
	scanf("%c %d %f", &sex, &age, &height);
	printf("The sex is %c, the age is %d, and the height is %f.", sex, age, height);
	return 0;
}
