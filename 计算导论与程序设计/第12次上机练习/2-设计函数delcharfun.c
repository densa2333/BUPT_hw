#include<stdio.h>

void delcharfun(char *str,char ch);

int main()
{
    char    ch,str[110];

    scanf("%s",str);    //�����ַ��� 
    getchar();            //��ȡ�س����� 
    scanf("%c",&ch);    //�����ַ� 
    delcharfun(str,ch);    //ɾ�� 
    printf("%s\n",str);    //���ɾ������ 
    return 0;    
}

/* ����������д�� */

void delcharfun(char *str,char ch)
{
    int i, j;
    i = 0;
    while (*(str + i))
    {
        if (*(str + i) == ch)
        {
            for (j = i; *(str + j); j++) //��j=i�����Ż��ɶ���
            {
                *(str + j) = *(str + j + 1);
            }
        }
        else //����ɨ��һ���û���ˣ��������������ɾ�ַ�����һ���Ҫ�����ж�
        {
            i++;
        }
    }
}