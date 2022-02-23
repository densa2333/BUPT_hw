#include<stdio.h>

#define        MAXLEN        500000
void  sortAndOutput(int *data , int size) ;

int main()
{
    int        data[MAXLEN];
    int        n, i;

    scanf( "%d" , &n );
    for ( i = 0 ; i < n ; i++ )
        scanf( "%d" , &data[i] );

    sortAndOutput( data, n ) ;

    return 0;    
}

/* 请在这里填写答案 */

void  sortAndOutput(int *data , int size)
{
    int i, j, k, cnt = 0, idx, min;
    int p[500][10], temp[1000];
    k = 0;
    for (i = 0; i < size; i++)
    {
        if (cnt == 0)
        {
            p[k][0] = data[i];
            cnt = data[i + 1] + 2;
            idx = 0;
            k++;
        }
        else
          p[k - 1][idx] = data[i];
        cnt--;
        idx++;
    }

    for (i = 0; i < k - 1; i++)
    {
        min = i;
        for (j = i + 1; j < k; j++)
        {
            if (p[j][0] < p[min][0])
            {
                min = j;
            }
        }
        if (min != i)
        {
            for (j = 0; j < 10; j++)
            {
                temp[j] = p[i][j];
                p[i][j] = p[min][j];
                p[min][j] = temp[j];
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < p[i][1] + 2; j++)
        {
            if (j != p[i][1] + 1) printf("%d ", p[i][j]);
            else printf("%d\n", p[i][j]);
        }
    }
}