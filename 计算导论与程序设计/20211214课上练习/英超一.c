#include <stdio.h>

#define        MAX        48

int        getScore(char * s) ;

int main()
{
    char    input[MAX] ;
    int        score ;

    scanf("%s",input);
    score = getScore(input) ;
    printf("%d\n",score) ;

    return 0;
}

/* ����������д�� */

int getScore(char *s)
{
    int i, score = 0;
    for (i = 0; *(s + i); i++)
    {
        if (*(s + i) == 'W')
          score += 3;
        else
            if (*(s + i) == 'D')
              score += 1;
    }
    return score;
}