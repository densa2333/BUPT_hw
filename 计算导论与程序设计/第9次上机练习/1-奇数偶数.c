#include<stdio.h>

int main(void)
{
    int n, i, j;
    int a[200] = {0};
    int b[200] = {0};

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    j = 0; //���j��ѭ�����¼λ����Ϣ
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] % 2)
        {
            b[j] = a[i];
            j++;
        }
    }

    printf("%d", b[0]);

    for (i = 1; i < j; i++)
    {
        printf(" %d", b[i]);
    }

    return 0;
}