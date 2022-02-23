#include<stdio.h> //���Ա���ɾ���

struct inf {
    long long id;
    char name[11];
    int mth;
    int eng;
    int com;
};

int input(struct inf [], int); //����Ʋ����Žл��ú���
void add(struct inf [], int);
void delete(struct inf [], int);
void update(struct inf [], int);
void output(struct inf [], int);
int find(struct inf [], int);

int main(void)
{
    int i, n;
    struct inf student[130]; //������ʹ��ȫ�ֱ�������϶�̫��
    scanf("%d", &n);
    for (i = 0; i < n; i++) { //�൱��������Ԫ�ز���
        switch (input(student, i)) {
            case 1: add(student, i); break;
            case 2: delete(student, i); break;
            case 3: update(student, i); break;
            case 4: output(student, i); break;
        }
    }
    return 0;
}

int input(struct inf student[], int n)
{
    int op;
    scanf("%d", &op);
    if (op == 1) {
        scanf("%lld", &student[n].id);
        scanf("%s", &student[n].name);
        scanf("%d %d %d", &student[n].mth, &student[n].eng, &student[n].com);
    }
    else
        if (op == 2 || op == 4)
          scanf("%lld", &student[n].id);
        else
            if (op == 3) {
                scanf("%lld", &student[n].id);
                scanf("%d %d %d", &student[n].mth, &student[n].eng, &student[n].com);
            }
    return op;
}

void add(struct inf student[], int n)
{
    int flag;
    flag = find(student, n);
    if (flag == -1)
      printf("Add success\n");
    else {
        student[n].id = -1; //ɾ�ݴ�ѧ�ţ�����
        printf("Students already exist\n");
    }
}

void delete(struct inf student[], int n)
{
    int flag;
    flag = find(student, n);
    if (flag != -1) {
        student[flag].id = -1;
        printf("Delete success\n");
    }
    else
      printf("Students do not exist\n");
    student[n].id = -1; //�ݴ���Ǹ�ѧ��ҲҪɾ��
}

void update(struct inf student[], int n)
{
    
    int flag;
    flag = find(student, n);
    if (flag != -1) {
        student[flag].mth = student[n].mth;
        student[flag].eng = student[n].eng;
        student[flag].com = student[n].com;
        printf("Update success\n");
    }
    else
      printf("Students do not exist\n");
    student[n].id = -1;
}

void output(struct inf student[], int n)
{
    int flag;
    double ave;
    flag = find(student, n);
    if (flag == -1)
      printf("Students do not exist\n");
    else {
        ave = (student[flag].mth + student[flag].eng + student[flag].com) / 3.0;
        printf("Student ID:%lld\n", student[flag].id);
        printf("Name:%s\n", student[flag].name);
        printf("Average Score:%.1f\n", ave);
    }
    student[n].id = -1;
}

int find(struct inf student[], int n)
{
    int i, loc = -1;
    for (i = 0; i < n; i++)
      if (student[i].id == student[n].id)
        loc = i;
    return loc;
}