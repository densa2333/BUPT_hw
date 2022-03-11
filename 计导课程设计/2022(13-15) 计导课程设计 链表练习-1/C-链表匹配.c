/*
��Ŀ����
��֪��������������ɵ���������A��B��ÿ�����е�Ԫ�ظ���δ֪����������һ��Ԫ�ء�
����������ж�����B�Ƿ�������A�����������С�����B�ǡ�1 9 2 4 18����A�ǡ�33 64 1 9 2 4 18 7����
B��A�����������У�����B�ǡ�1 9 2 4 18����A�ǡ�33 1 9 64 2 4 18 7����B����A�����������С�
Ҫ��
��������������A��B���ڴ洢�������������У�Ȼ������Ŀ��Ҫ���ж�����B�Ƿ�������A�����������С�
��������������-1��Ϊ������־��ע��-1������������������е�Ԫ�أ���Ҫͳ��-1����
�ڳ������ǰҪ�ͷ�����A��B�е����нڵ㡣

����
���������������������������A��B��������Ԫ�ظ���δ֪����ÿ������������һ��Ԫ�أ�
�������롰-1��������ÿ������ռһ�С�

���
�������B������A�����������У��������ListB is the sub sequence of ListA.����
���������ListB is not the sub sequence of ListA.����
�������Ĳ��������ڵ�����100�������������������������int�ʹ洢��
��ע�����������ʽ��

�������� Copy
Sample 1:
5 4 3 2 1 -1
3 2 1 -1
Sample 2:
1 2 3 4 5 6 7 8 9 -1
1 2 3 4 5 6 7 8 0 -1
������� Copy
Sample 1:
ListB is the sub sequence of ListA.
Sample 2:
ListB is not the sub sequence of ListA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode * List;
struct LNode {
    int Data;
    List Next;
};

List CreatList();
bool IsSubsequence(List, List);
void FreeList(List);

int main(void)
{
    List A = CreatList();
    List B = CreatList();
    if (IsSubsequence(A, B))
      printf("ListB is the sub sequence of ListA.\n");
    else
      printf("ListB is not the sub sequence of ListA.\n");
    FreeList(A);
    FreeList(B);
    return 0;
}

List CreatList()
{
    int num;
    /* ������ͷ�ڵ������ */
    List headPtr = (List)malloc(sizeof(struct LNode));
    if (headPtr != NULL) {
        headPtr->Data = -1;
        headPtr->Next = NULL;
    List currentPtr = headPtr, lastPtr = headPtr;
    while (scanf("%d", &num) && num != -1) {
        currentPtr = (List)malloc(sizeof(struct LNode));
        if (currentPtr != NULL) {
            currentPtr->Data = num;
            lastPtr->Next = currentPtr;
            lastPtr = currentPtr;
        }
    }
    lastPtr->Next = NULL;
    return headPtr;
    } else return NULL;
}

bool IsSubsequence(List A, List B)
{
    List p, q, tmp;
    bool flag = false;
    for (p = A->Next; p && flag == false; p = p->Next) {
        tmp = p;
        q = B->Next;
        if (p->Data == q->Data) {
            flag = true;
            while (q && tmp && flag) {
                if (tmp->Data != q->Data) {
                    flag = false;
                }
                tmp = tmp->Next;
                q = q->Next;
            }
            if (q == NULL && flag == true) flag = true;
            else flag = false;
        }
    }
    return flag;
}

void FreeList(List L)
{
    List tmp;
    while (L) {
        tmp = L->Next;
        free(L);
        L = tmp;
    }
}