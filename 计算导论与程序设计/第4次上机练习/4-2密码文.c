#include<stdio.h>

int main()
{
    char ch;
    while((ch = getchar()) != '\n') //赋值运算符优先级小于关系运算符！！
    {
        switch (ch)
        {
            case 'x':
            printf("%c", 'a');
            break;

            case 'y':
            printf("%c", 'b');
            break;

            case 'z':
            printf("%c", 'c');
            break;

            case 'X':
            printf("%c", 'A');
            break;

            case 'Y':
            printf("%c", 'B');
            break;

            case 'Z':
            printf("%c", 'C');
            break;

            default:
            printf("%c", ch + 3);
            break;
        }
    }
    
    return 0;
}