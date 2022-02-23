#include<stdio.h>

int main(void)
{
    int n, i, same = 1, max = 1;
    int a[1001];
    scanf("%d", &n);
    scanf("%d", &a[0]); /*先读第一个*/
    for (i = 1; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == a[i - 1]) //在循环内每次与上一个数比较是否相同
          same++; //相同就平台长度+1
        else
          same = 1; //不相同就平台长度恢复1
        if (same > max) //出现更长的平台就更新max的值
          max = same;
    }
    printf("%d", max);
    return 0;
}