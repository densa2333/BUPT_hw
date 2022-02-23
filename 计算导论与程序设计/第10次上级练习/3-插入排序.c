#include<stdio.h>

//插入排序（升序） 
//参数说明：数组，数组中已有元素个数 
void InsertSort(int a[],int n);

int main()
{
    int        n , i,    num[1000] ;

    scanf( "%d" , &n ); 
    for( i = 0 ; i < n ; i++ ) 
        scanf( "%d", &num[i] ) ;
    InsertSort( num , n ) ; 
    return 0 ;
}

/* 请在这里填写答案 */

void InsertSort(int a[],int n) //插入排序（思想：数组的逐元素操作）
{
    int i, j, k, temp;
    for (i = 1; i < n; i++) //从下标为 1 的第二个元素开始操作，共操作 n - 1 次
    {
        for (j = 0; j < i; j++) //插入到前面含 i 个元素的序列中
        {
            if (a[j] > a[i]) //找到第一个比被操作数大的数
            {
                temp = a[i];
                for (k = i - 1; k >= j; k--) //全都往右挪一个位置
                {
                    a[k + 1] = a[k];
                }
                a[j] = temp; //把被操作数插到第一个比它大的位置上
            }
        }

        for (j = 0; j < n - 1; j++) //输出排序后的数组
        {
            printf("%d ", a[j]);
        }
        printf("%d\n", a[n - 1]);
    }
}