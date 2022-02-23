#include<stdio.h>

int main()
{
    int len = 0;

    printf("Enter a massage: ");

    while ( getchar() != '\n')
      len++;
    
    printf("Your massage was %d character(s) long.\n", len);
    
    return 0;
}