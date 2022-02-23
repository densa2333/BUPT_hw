#include <stdio.h>

typedef struct
{
    char    id[16]  ;//学生账号 
    int        total ;    //综合成绩 
    int        ce ;    //机试成绩 
    int        ws ;    //加权成绩 
}STUDENT;

void Sort(STUDENT a[],int size) ; 
void Swap(STUDENT * s1,STUDENT * s2) ;
int  Comp(STUDENT * s1,STUDENT * s2) ;

int main()
{
    STUDENT    stu[100] ;
    int        i , n ;


    scanf("%d",&n) ;
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d",stu[i].id,&stu[i].ce,&stu[i].ws) ;
        stu[i].total = stu[i].ce+stu[i].ws ;
    }

    Sort(stu,n) ;
    for(i=0;i<n;i++)
        printf("%s %d %d %d\n",stu[i].id,stu[i].total,stu[i].ce,stu[i].ws) ;

    return 0;    
}

/* 请在这里填写答案 */

void Sort(STUDENT a[],int size)
{
    int i, j, front;
    STUDENT temp;
    for (i = 0; i < size - 1; i++)
    {
        front = i;
        for (j = i + 1; j < size; j++)
        {
            if (Comp(&a[j],&a[front]))
              front = j;
        }
        if (i != front)
        {
            temp = a[front];
            a[front] = a[i];
            a[i] = temp;
        }
    }
}

void Swap(STUDENT * s1,STUDENT * s2)
{
    STUDENT temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int  Comp(STUDENT * s1,STUDENT * s2)
{
    int result;
    if (s1->total > s2->total)
      result = 1;
    else
        if (s1->total == s2->total)
        {
            if (s1->ce > s2->ce)
              result = 1;
            else
              result = 0;
        }
        else
          result = 0;
    return result;
}