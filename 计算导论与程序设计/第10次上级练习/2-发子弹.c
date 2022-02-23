#include<stdio.h>
#define LEN 100

//调整函数 
void distribute(int * bullets , int size , int number );

int main()
{
    int        bullets[LEN] ;
    int        n , m , i ;    

    scanf("%d" , &n ) ;    //读入战士总数 
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%d" , &bullets[i] ) ;//读入每个战士手中初始的子弹数 
    }
    scanf("%d" , &m ) ;//读入调整的次数（m>0) 
    distribute(bullets , n , m ) ;//调整 
    for( i = 0 ; i < n - 1 ; i++ )//输出调整后结果 
    {
        printf("%d " , bullets[i] ) ;
    }
    printf("%d\n" , bullets[i] ) ;

    return 0;    
}

/* 请在这里填写答案 */

void distribute(int * bullets , int size , int number)
{
    int i, j, equal;
    int a[LEN];

    for (i = 0; i < number; i++) //调整number次
    {
        for (j = 0; j < size; j++) //每次调整操作size次
        {
            a[j] = bullets[j]; /*先复制到a，用来储存每次分给下一个人的子弹数目*/
        }

        equal = 0;
        for (j = 0; j < size; j++)
        {
            if (bullets[0] == bullets[j])  //计算相等次数
            {
                equal++;
            }
        }

        if (equal < size) //如果已经全相等了就不再操作
        {
            for (j = 0; j < size; j++)
            {
                if (a[j] % 2) //如果子弹数为奇数
                {
                   a[j]++;
                   bullets[j]++; //手里子弹数+1
                }
                a[j] /= 2;
                bullets[j] /= 2; //自己的分一半
            }

            for (j = 0; j < size; j++)
            {
                if (j != size - 1) //如果不是最后一个人
                {
                    bullets[j + 1] += a[j]; //上一个人分一半下来
                }
                else
                {
                    bullets[0] += a[j]; //最后一个人分给第一个
                }
            }
        }
    }
}