#include<stdio.h>
#include<string.h>

struct attribute {
    char name[25];
    int total;
} student[100];

void input(struct attribute *);
void sort(struct attribute *, int);
void output(struct attribute *);

int main(void)
{
    int i, n;
    struct attribute *p = student;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      input(p + i);
    sort(p, n);
    for (i = 0; i < n; i++)
      output(p + i);
    return 0;
}

void input(struct attribute *p)
{
    scanf("%s %d", p->name, &p->total);
}

void sort(struct attribute *p, int n)
{
    int i, j, front;
    struct attribute temp;
    for (i = 0; i < n - 1; i++)
    {
        front = i;
        for (j = i + 1; j < n; j++)
        {
            if ((p + j)->total == (p + front)->total) //排序算法一定要扎实，以后还要考虑复杂度
            {
                if (strcmp((p + j)->name, (p + front)->name) < 0)
                  front = j;
            }
            else
                if ((p + j)->total > (p + front)->total)
                  front = j;
        }
        if (i != front)
        {
            temp = *(p + front);
            *(p + front) = *(p + i);
            *(p + i) = temp;
        }
    }
}

void output(struct attribute *p)
{
    printf("Name:%s\ntotal:%d\n\n", p->name, p->total);
}