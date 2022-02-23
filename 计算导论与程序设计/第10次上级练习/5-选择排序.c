#include<stdio.h>

//选择排序（升序） 
//参数说明：数组，数组中已有元素个数 
void selectSort(int data[],int elementCount) ;

//函数功能：找数组中的最小值元素，并返回其下标 
//参数说明：数组名，查找起始位置下标，查找终止位置下标
int findMin(int data[], int startLoc, int endLoc) ; 

//输出数组中所有元素 
//参数说明：数组，数组中已有元素个数 
void outputData(int data[],int elementCount) ;

int main()
{
    int        n , i,    num[1010] ;

    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
    selectSort(num,n) ; 
    return 0 ;
}

/* 请在这里填写答案 */

void selectSort(int data[],int elementCount)
{
    int i, temp, minLoc; //存的是最小元素的位置然后交换
    for (i = 0; i < elementCount - 1; i++)
    {
        minLoc = findMin(data, i, elementCount - 1); //这里要存下minLoc，不然调用两次findMin会出错，因为data[i]改变了
        temp = data[i];
        data[i] = data[minLoc];
        data[minLoc] = temp;
        outputData(data, elementCount);
    }
}

int findMin(int data[], int startLoc, int endLoc)
{
    int i, min = data[startLoc], minLoc = startLoc;
    for (i = startLoc; i <= endLoc; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
            minLoc = i;
        }
    }
    return minLoc;
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