/*ʵ��һ�����������������һ���������е����ֵ����Сֵ�����磺2 1 2 5 2�У����ֵ��5����Сֵ��1��*/
#include <stdio.h>
#define SIZE 1000

void Max_Min ( int [], int,  int *, int * );

int main()
{
	int a[SIZE];
	int max,min;
    int n, i;

    scanf("%d", &n);
	
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	Max_Min(a,n,&max,&min); 

    printf("max=%d min=%d\n", max,min);

    return 0;

}
/* �˴���Ӻ�������*/ 
void Max_Min(int a[], int n, int *pMax, int *pMin)
{
	int i, max, min;

	max = a[0];
	for (i = 0; i < n; i++)
	{
		if (a[i] > max) max = a[i];
	}

	min = a[0];
	for (i = 0; i < n; i++)
	{
		if (a[i] < min) min = a[i];
	}

	*pMax = max;
	*pMin = min;
}