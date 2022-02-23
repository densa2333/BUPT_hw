#include<stdio.h>

int main(void)
{
    char ch;

    scanf("%c", &ch);

    while (ch != '\n')
    {   
        if (ch >= 'A' && ch <= 'Z')
            printf("%c", ch + 32);
        else
            if (ch >= 'a' && ch <= 'z')
                printf("%c", ch - 32);
            else
                printf("%c", ch);

        scanf("%c", &ch);
    }

    return 0;
}