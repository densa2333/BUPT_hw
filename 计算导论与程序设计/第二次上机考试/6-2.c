#include<stdio.h>
#include<stdlib.h>

typedef struct partyMember    //保存党员信息的结构 
{
    char    id[16];        //党员编号 
    int        score;        //学习强国年度积分
    int        appraisal;    //是否在历年年度民主评议党员中被评为“优秀” 
    int        isOutstanding;    //是否在校级及以上评选中被评为优秀党员 
} PARTYMEMBER;

void    getAll(PARTYMEMBER * mumbers , int size ) ;
PARTYMEMBER * getMemory(int size) ; 


int main()
{
    int            i , n ;
    PARTYMEMBER    *mumbers ;

    scanf( "%d" , &n ) ;

    mumbers = getMemory(n) ;
    if ( mumbers != NULL )    //如果申请到了内存 
    {
        for( i = 0 ; i < n ; i++ ) /*读入所有党员信息*/
        {
            scanf( "%s%d%d%d" , mumbers[i].id , &mumbers[i].score ,
                    &mumbers[i].appraisal , &mumbers[i].isOutstanding );
        }

        getAll( mumbers , n ) ; 
        free(mumbers) ;//释放内存
    }                        

    return 0;
}

/* 请在这里填写答案 */

void    getAll(PARTYMEMBER * mumbers , int size )
{
    int i, num;
    for (i = 0; i < size; i++)
    {
        num = 0;
        if (mumbers[i].score >= 15000) num++;
        if (mumbers[i].appraisal == 1) num++;
        if (mumbers[i].isOutstanding == 1) num++;
        if (num >= 2)
        {
            printf("%s %d %d %d\n", mumbers[i].id, mumbers[i].score, mumbers[i].appraisal, mumbers[i].isOutstanding);
        }
    }
}

PARTYMEMBER * getMemory(int size)
{
    int i;
    return malloc(size * sizeof(PARTYMEMBER));
}