#include<stdio.h>
#include<stdlib.h>

typedef struct partyMember    //���浳Ա��Ϣ�Ľṹ 
{
    char    id[16];        //��Ա��� 
    int        score;        //ѧϰǿ����Ȼ���
    int        appraisal;    //�Ƿ�����������������鵳Ա�б���Ϊ�����㡱 
    int        isOutstanding;    //�Ƿ���У����������ѡ�б���Ϊ���㵳Ա 
} PARTYMEMBER;

void    getAll(PARTYMEMBER * mumbers , int size ) ;
PARTYMEMBER * getMemory(int size) ; 


int main()
{
    int            i , n ;
    PARTYMEMBER    *mumbers ;

    scanf( "%d" , &n ) ;

    mumbers = getMemory(n) ;
    if ( mumbers != NULL )    //������뵽���ڴ� 
    {
        for( i = 0 ; i < n ; i++ ) /*�������е�Ա��Ϣ*/
        {
            scanf( "%s%d%d%d" , mumbers[i].id , &mumbers[i].score ,
                    &mumbers[i].appraisal , &mumbers[i].isOutstanding );
        }

        getAll( mumbers , n ) ; 
        free(mumbers) ;//�ͷ��ڴ�
    }                        

    return 0;
}

/* ����������д�� */

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