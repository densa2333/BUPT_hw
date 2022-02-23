#include<stdio.h>

struct information {
        char name[25];
        char id[25];
        int score[5];
        double average;
        int total;
    } student;

void inputFun(struct information *);
void selectSort(int *);
void outputFun(struct information *);

int main(void)
{
    struct information *ptr = &student;
    inputFun(ptr);
    selectSort((*ptr).score);
    outputFun(ptr);
    return 0;
}

void inputFun(struct information *p)
{
    int i;
    (*p).total = 0;
    gets((*p).name);
    gets((*p).id);
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &(*p).score[i]);
        (*p).total += (*p).score[i];
    }
    (*p).average = (*p).total / 5.0;
}

void selectSort(int *a)
{
    int i, j, max, temp;
    for (i = 0; i < 4; i++)
    {
        max = i; //标记最大元素的位置而不是存最大元素的值
        for (j = i; j < 5; j++) //比较次数要正确
        {
            if (a[j] > a[max]) max = j;
        }
        if (max != i)
        {
            temp = a[i];
            a[i] = a[max];
            a[max] = temp;
        }
    }
}

void outputFun(struct information *ptr)
{
    int i;
    printf("Name:%s\n", ptr->name);
    printf("ID:%s\n", ptr->id);
    printf("Score:");
    for (i = 0; i < 5; i++)
    {
        printf("%d", ptr->score[i]);
        if (i == 4) printf("\n");
        else printf(" ");
    }
    printf("average:%.2f total:%d\n", ptr->average, ptr->total);
}