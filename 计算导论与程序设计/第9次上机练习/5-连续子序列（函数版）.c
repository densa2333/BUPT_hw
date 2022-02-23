#include<stdio.h>
#define SIZE 1000

int inputArray(int [], int);
void outputResult(int);
int match(int [], int[], int, int);

int main(void)
{
    int a[SIZE], b[SIZE];
    int i = 0, num, found = 0;
    int size_a, size_b;
    size_a = inputArray(a, SIZE);
    size_b = inputArray(b, SIZE);

    for (i = 0; i < size_a && found == 0; i++)
      if (a[i] == b[0])
        found = match(&a[i], b, size_a - i, size_b); //从中途传入a数组，要做越界控制

    outputResult(found);

    return 0;
}

int inputArray(int a[], int size)
{
    int i = 0;
    scanf("%d", &a[i]);
    while(a[i] != -1)
    {
        i++;
        scanf("%d", &a[i]);
    }

    return i;
}

void outputResult(int found)
{
    if (found)
      printf("ListB is the sub sequence of ListA.\n");
    else
      printf("ListB is not the sub sequence of ListA.\n");
}

int match(int a[], int b[], int size_a, int size_b)
{
    int i;
    for (i = 0; i < size_b && i < size_a; i++) //要做越界控制，可能a数组剩余的长度小于b数组
    {
        if (a[i] != b[i])
          return 0;
    }

    return 1;
}