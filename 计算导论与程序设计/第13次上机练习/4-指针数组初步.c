#include<stdio.h>

int getString( char * source , char *strPtr[] ) ;

int main()
{
    char    str[100005];
    char    *strPtr[1005]={0};
    int        i, num ;

    gets(str);
    num = getString( str , strPtr ) ;
    for( i = 0 ; i < num ; i++ )
        puts(strPtr[i]);

    return 0;    
}

/* ����������д�� */

int getString(char *source, char *strPtr[])
{
    int i, j;
    j = 0;
    for (i = 0; *(source + i); i++)
    {
        if (i == 0 && *(source + i) != ' ')
        {
            strPtr[j] = source + i;
            j++;
        }
        else
            if (*(source + i) == ' ')
            {
                if (*(source + i + 1) != ' ' && *(source + i + 1) != '\0') //״̬�Զ���
                {
                    strPtr[j] = source + i + 1;
                    j++;
                }
                *(source + i) = '\0';
            }
    }
    return j;
}
//��״̬�������Զ���
int getString(char *source, char *strPtr[])
{
    int count = 0, index = 0, flag;
    char *s = source; //��ָ�����������ʡ�ĺ���ȥ��ƫ���������������Ⱥ����ƫ����Ҫʡ��
    flag = 0;
    while (*s != '\0')
    {
        if (*s == ' ')
        {
            *s = '\0';
            flag = 0;
        }
        else
            if (flag == 0) //flag��������һ���ַ���״̬
            {
                flag = 1;
                strPtr[index] = s;
                index++;
                count++;
            }
        s++;
    }
}