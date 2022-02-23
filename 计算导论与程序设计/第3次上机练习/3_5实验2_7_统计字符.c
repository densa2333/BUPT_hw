#include<stdio.h>

int main()
{
    char ch;
    int word = 0, blankspase = 0, number = 0, others = 0;

    while ((ch = getchar()) != '\n')
    {
        if ( ('a' <= ch && 'z' >= ch) || ('A' <= ch && 'Z' >= ch)) 
         word++;
        else if ('0' <= ch && '9' >= ch)
          number++;
        else if (ch == ' ')
          blankspase++;
        else others++;
    }

    printf("%d %d %d %d", word, blankspase, number, others);

    return 0;
}