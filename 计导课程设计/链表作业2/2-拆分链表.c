/*
��Ŀ����
��֪��һ��������ַ�����L�������е��ַ�������Ӣ����ĸ�������ַ��������ַ����ַ��ĸ���δ֪��ÿ���ַ�֮���ÿո�ֿ���
�ַ������á�-1����Ϊ���������־��������Ҫ��-1����һ���ַ����Դ������Ҳ������ַ������е�Ԫ�ء�
���¼�Ϊһ���Ϸ����ַ����У���a c 3 b a d 6 , & j m 8 7 2 V -1����
��������ǽ�����ַ����в��Ϊ��������������A��B��C����������A�������L�е���ĸ������B�������L�е����֣�����C�������L�е������ַ���
Ȼ�󣬽�����A��B��C�ֱ���ASCII��Ĵ�С��ϵ��������������������L����Ϊ�����С�

Ҫ��
�����ĸ��������ֱ�洢����L��A��B��C�е�Ԫ�ء��ַ����е������á�-1����Ϊ������־��
��������Lʱ������ʹ��scanf(��%s��,s);����ȡ�ַ������е��ַ������ѵ������ַ�����һ���ַ�����ȡ��
��L��������Ҫ����������������������L���ΪA��B��C��������Ȼ���ÿ���������������ⲿ�ֵĲ�����Ӧ���Ƕ�ָ������޸ģ�������ɾ���ڵ��뽨���½ڵ㡣
�ڳ������ǰҪ�ͷ�����A��B��C�е����нڵ㡣

����
һ��������ַ����У�����Ԫ�صĸ���δ֪�������롰-1�����������롰-1��ǰ����û������Ԫ�أ�ÿ���ַ�����ռһ�С�

���
����A�е�Ԫ�أ�ռһ�У�Ȼ��������B�е�Ԫ�أ�ռһ�С����������C�е�Ԫ�أ�ռһ�С�ÿ
�е�ÿ��Ԫ�غ���һ���ո�ע�����һ��Ԫ�غ�ֻ�л��з������ĳ������Ϊ�����������There is no item in X list.��
�������Ĳ��������ڵ�����100�����������
��ע�����������ʽ��

�������� Copy
Sample 1:
a c 3 b a d 6 , & j m 8 7 2 V -1

Sample 2:
z m v 1 a K 2 m p 9 a 0 a d -1

������� Copy
Sample 1:
The list A is: V a a b c d j m
The list B is: 2 3 6 7 8
The list C is: & ,

Sample 2:
The list A is: K a a a d m m p v z
The list B is: 0 1 2 9
There is no item in C list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ElementType char

typedef struct LNode * List;
struct LNode {
    ElementType Data;
    List Next;
};

List ReadList();
List CutList(List, int);
void BubbleSortList(List);
void PrintList(List, char);
void FreeList(List);

int main(void)
{
    List L, A, B, C;
    L = ReadList();
    A = CutList(L, 1);
    B = CutList(L, 2);
    C = CutList(L, 3);
    PrintList(A, 'A');
    PrintList(B, 'B');
    PrintList(C, 'C');
    FreeList(L);
    FreeList(A);
    FreeList(B);
    FreeList(C);
    return 0;
}

List ReadList()
{
    List front, rear, cur;
    front = malloc(sizeof(struct LNode));
    front->Data = '\0';
    front->Next = NULL;
    rear = front;
    char s[3];
    scanf("%s", s);
    getchar();
    while (strcmp("-1", s)) {
        cur = malloc(sizeof(struct LNode));
        cur->Data = s[0];
        cur->Next = NULL;
        rear->Next = cur;
        rear = cur;
        scanf("%s", s);
        getchar();
    }
    return front;
}

//�����ð������ģ��
void BubbleSortList(List L)
{
    if (L->Next) {
        List tmp, pre, cur, next, end = NULL;
        while (end != L->Next) {
            for (pre = L, cur = pre->Next, next = cur->Next;
                next != end; 
                pre = pre->Next, cur = cur->Next, next = next->Next) {
                if (cur->Data > next->Data) {
                    cur->Next = next->Next;
                    next->Next = cur;
                    pre->Next = next;
                    tmp = next;
                    next = cur;
                    cur = next;
                }
            }
            end = cur;
        }
    }
}

List CutList(List L, int a)
{
    List first1, pre1 , front2, rear2, cur;
    pre1 = L;
    first1 = pre1->Next;
    front2 = malloc(sizeof(struct LNode));
    front2->Data = '\0';
    front2->Next = NULL;
    rear2 = front2;
    //�ָ�ϲ�ʵ��
    while (first1) {
        char x = first1->Data;
        if ((x >= 'A' && x <= 'Z' || x >= 'a' && x <='z') && a == 1) {
            rear2->Next = first1;
            rear2 = first1;
            first1 = first1->Next;
            pre1->Next = first1;
            rear2->Next = NULL;
        } else if ((x >= '0' && x <= '9') && a == 2) {
            rear2->Next = first1;
            rear2 = first1;
            first1 = first1->Next;
            pre1->Next = first1;
            rear2->Next = NULL;
        } else if (a == 3) {
            rear2->Next = first1;
            rear2 = first1;
            first1 = first1->Next;
            pre1->Next = first1;
            rear2->Next = NULL;
        } else {
            pre1 = first1;
            first1 = first1->Next;
        }
    }
    BubbleSortList(front2);
    return front2;
}

void PrintList(List L, char X)
{
    if (L->Next == NULL)
        printf("There is no item in %c list.", X);
    else {
        printf("The list %c is:", X);
        List p = L->Next;
        while (p) {
            printf(" %c", p->Data);
            p = p->Next;
        }
    }
    printf("\n");
}

void FreeList(List L)
{
    List tmp = L;
    while (L) {
        tmp = L;
        L = L->Next;
        free(tmp);
    }
}