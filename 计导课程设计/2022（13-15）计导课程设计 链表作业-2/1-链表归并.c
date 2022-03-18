/*��Ŀ����
��֪����������������������A��B��������Ԫ�ظ���δ֪��ͬһ�����в������ظ�Ԫ�س��֣��п���ĳ������Ϊ�ա�
��Ҫ������B�鲢������A�У��ҹ鲢������A��������Ȼ������˳�����С�
�������B��ĳЩ����������A��Ҳ���ڣ�����Щ�������ڽڵ���Ȼ��������B�У��������鲢������A�У�
������Щ�������ڽڵ㽫������B��ɾ������ӵ�����A�С�

Ҫ��
��������������A��B���ڴ洢�������������У�Ȼ������Ŀ��Ҫ�󣬽�����B�е�Ԫ�ع鲢������A�С�
�ڹ鲢�Ĺ����У���Ҫ�ͷ�B�еĽڵ�ռ䡢Ȼ�����½ڵ㣬��Ҫ�ı�ָ���ָ��ʹԪ�ش�B��ɾ������ӵ�A�С�
���������а��յ���˳�����룬��-1��Ϊ������־��ע��-1������������������е�Ԫ�أ���Ҫͳ��-1����
�ڳ������ǰҪ�ͷ�����A��B�е����нڵ㡣

����
����������������������������A��B������Ԫ�صĸ���δ֪���������롰-1��������ÿ������������ռһ�С�

���
����������A�е�Ԫ�أ�ռһ�У�Ȼ���Ǵ���������B�е�Ԫ�أ�ռһ�С�
ÿ�е�ÿ��Ԫ�غ���һ���ո�ע�����һ��Ԫ�غ�ֻ�л��з���
���ĳ������Ϊ�����������There is no item in X list.��
�������Ĳ��������ڵ�����100�������������������������int�ʹ洢��
��ע�����������ʽ��

�������� Copy
Sample 1:
1 3 4 5 6 7 -1
2 3 6 8 9 10 11-1

Sample 2:
-1
-1

������� Copy
Sample 1:
The new list A:1 2 3 4 5 6 7 8 9 10 11
The new list B:3 6

Sample 2:
There is no item in A list.
There is no item in B list.*/

#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define Null -1

typedef struct LNode * List;
struct LNode {
    ElementType Data;
    List Next;
};

List ReadList();
int Exist(List, ElementType);
void MergeList(List, List);
void PrintList(List, char);

int main(void)
{
    List A = ReadList();
    List B = ReadList();
    MergeList(A, B);
    PrintList(A, 'A');
    PrintList(B, 'B');
    return 0;
}

List ReadList()
{
    ElementType x;
    List front, rear, cur;
    front = malloc(sizeof(struct LNode));
    front->Data = Null;
    front->Next = NULL;
    rear = front;
    while (scanf("%d", &x)) {
        if (x == Null) break;
        cur = malloc(sizeof(struct LNode));
        cur->Data = x;
        cur->Next = NULL;
        rear->Next = cur;
        rear = cur;
    }
    return front;
}

int Exist(List L, ElementType x)
{
    for (List p = L; p; p = p->Next) {
        if (p->Data == x) return 1;
    }
    return 0;
}

void MergeList(List A, List B)
{
    //��������������Ҫ��ǰ�ڵ�ָ���ǰ�̽ڵ�ָ�룬��ʱ����Ҫ��ʱָ��
    List first1, first2, pre1, pre2, tmp;
    first1 = A->Next;
    first2 = B->Next;
    pre1 = A;
    pre2 = B;
    // �鲢���ֻ�ͼ��� �ص㣡
    while (first1 && first2) {
        if (first2->Data < first1->Data && !Exist(first1, first2->Data)) {
            tmp = first2->Next;
            first2->Next = first1;
            pre1->Next = first2;
            pre1 = first2;
            pre2->Next = tmp;
            first2 = tmp;
        } else if (Exist(first1, first2->Data)) {
            pre2 = first2;
            first2 = first2->Next;
        } else {
            pre1 = first1;
            first1 = first1->Next;
        }
    }
    if (first2) {
        pre1->Next = first2;
        pre2->Next = NULL;
    }
}

void PrintList(List L, char LName)
{
    int flag = 0;
    if (L->Next == NULL)
        printf("There is no item in %c list.", LName);
    else {
        printf("The new list %c:", LName);
        for (List p = L->Next; p; p = p->Next) {
            if (flag)
                printf(" %d", p->Data);
            else {
                printf("%d", p->Data);
                flag = 1;
            }
        }
    }
    printf("\n");
}