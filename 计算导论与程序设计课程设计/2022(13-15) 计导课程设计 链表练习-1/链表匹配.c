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
    /* 建立带头节点的链表 */
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