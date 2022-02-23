#include<stdio.h>

void bubbleSort(int a[],int n);

//输出数组中所有元素 
void outputData(int data[],int elementCount);

int main()
{
    int n, i, num[10010];

    scanf("%d",&n); 

    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]);
    
    bubbleSort(num,n); 

    outputData(num,n);

    return 0 ;
}

/* 请在这里填写答案 */

void bubbleSort(int a[],int n) //冒泡排序
{
    int i, j, temp;
    for (i = n - 1; i > 0; i--) //共冒泡 n - 1 趟
    {
        for (j = 0; j < i; j++) //每趟交换次数由这是第几趟决定
        {
            if (a[j] > a[j + 1]) //判断是否交换
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

    }
}

void outputData(int data[],int elementCount)
{
    int i;
    for (i = 0; i < elementCount - 1; i++)
    {
        printf("%d ", data[i]);
    }
    printf("%d\n", data[elementCount - 1]);
}