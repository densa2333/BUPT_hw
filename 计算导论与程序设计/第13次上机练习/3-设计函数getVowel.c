#include<stdio.h>

//��ֻ����Сд��ĸ���ַ���str�е�Ԫ����ĸ���Ƶ��ַ�����vowel,������Ԫ���ַ��ĸ�����
int getVowel(char str[],char vowel[]);

int main()
{
    char    vowel[101] , str[101];//ÿ�����鶼����Ҫ101���ֽ� 
    int        len ;

    scanf("%s",str);    //�����ַ��� 
    len = getVowel(str,vowel);    //���� 
    if ( len > 0 ) printf("%d %s\n", len , vowel);    //������ƺ��� 
    else printf("%d\n", len);//��������� 

    return 0;    
}

/* ����������д�� */

int getVowel(char str[], char vowel[])
{
    int i, j;
    j = 0;
    for (i = 0; *(str + i); i++)
    {
        if (*(str + i) == 'a' || *(str + i) == 'e' || *(str + i) == 'i' ||
            *(str + i) == 'o' || *(str + i) == 'u')
            {
                *(vowel + j) = *(str + i);
                j++;
            }
    }
    *(vowel + j) = '\0';
    return j;
}