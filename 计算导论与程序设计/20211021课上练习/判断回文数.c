#include<stdio.h>

int len(int n);

//算法2：反着读，假设读得的数为 reverseNum，判断 num 和 reverseNum 是否相等
int main(void)
{
    int originNum;
    scanf("%d", &originNum);

    int num = originNum, reverseNum = 0;
    int bit, length = len(originNum);
    while(num / 10)
    {
        bit = num % 10;
        for (int i = 0; i < length - 1; i++)
        {
            bit *= 10;
        }
        reverseNum += bit;
        num /= 10;
        length--;
    }
    reverseNum += num;

    if (originNum == reverseNum)
        printf("Yes\n");
    else
        printf("No\n");
    
    return 0;
}

int len(int n)
{
    int length = 1;
    while (n / 10)
    {
        length++;
        n /= 10;
    }
    
    return length;
}