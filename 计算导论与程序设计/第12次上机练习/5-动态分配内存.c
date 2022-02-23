#include<stdio.h>
#include<stdlib.h>

void negate(int *array, int size);

int main(void)
{
    int n;
    int *array = NULL;

    scanf("%d", &n);
    array = (int *)malloc(sizeof(int) * n);
    negate(array, n);
    free(array);
    array = NULL;

    return 0;
}

void negate(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", array + i);
        *(array + i) *= (-10);
    }

    for (i = 0; i < size; i++)
    {
        printf("%d", *(array + i));
        if (i == size - 1) printf("\n");
        else printf(" ");
    }
}