#include<stdio.h>

//函数功能：二分查找
//函数参数：分别为被查找的数组，数组长度，所查找的元素
//函数返回值：如果找到，则返回该元素在数组中的下标，否则返回-1 
int BinarySearch(int a[],int n,int key) ; 

int main()
{
    int    num[20000] ; //这个数组比较大，如果在你的电脑中无法分配这么大的内存，请改小后测试。
    int        n , m, i;    
    int        key ;

    scanf("%d%d",&n,&m); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;

    for( i = 0 ; i < m ; i++ ) 
    {
        scanf("%d",&key) ;
        printf("%d",BinarySearch(num,n,key)) ;
        if ( i != m - 1 ) printf(" ") ;
        else printf("\n") ;
    }
    return 0 ;
}

/* 请在这里填写答案 */

int BinarySearch(int a[],int n,int key)
{
    int mid, left = 0, right = n - 1; //三个标记变量 mid left right
    while (left <= right) //结束条件：left > right 或 已经找到
    {
        mid = (left + right) / 2; //每一趟的mid都初始化为left和right的平均数
        if (key == a[mid])
            return mid;
        else
            if (key < a[mid])
                right = mid - 1; //如果中间值大于被查数，就把right变为mid - 1
            else
                left = mid + 1; //如果中间值小于被查数，就把left变为mid + 1
    }
    return -1;
}