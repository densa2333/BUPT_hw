#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode * List;
struct LNode {
    int Data;
    List Next;
};

List CreatList();
List FindKth(int, List);
void SwapList(List L, int, int, int, int);
void Output(List);
void FreeList(List);

int main(void)
{
    List L = CreatList();
    int s1, t1, s2, t2;
    scanf("%d %d %d %d", &s1, &t1, &s2, &t2);
    SwapList(L, s1, t1, s2, t2);
    Output(L);
    FreeList(L);
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

List FindKth(int k, List L)
{
    int i = 0;
    List p = L;
    while (p && i < k) {
        p = p->Next;
        i++;
    }
    if (i == k) return p;
    else return NULL;
}

void SwapList(List L, int s1, int t1, int s2, int t2)
{
    List Pre1 = FindKth(s1 - 1, L), Pre2 = FindKth(s2 - 1, L);
    List ps1 = FindKth(s1, L), ps2 = FindKth(s2, L);
    List pt1 = FindKth(t1, L), pt2 = FindKth(t2, L);
    List tmp = pt1->Next;
    if (pt2->Next != NULL && t1 + 1 != s2) {
        Pre1->Next = ps2;
        pt1->Next = pt2->Next;
        pt2->Next = tmp;
        Pre2->Next = ps1;
    } else if (t1 + 1 != s2) {
        pt2->Next = pt1->Next;
        Pre1->Next = ps2;
        Pre2->Next = ps1;
        pt1->Next = NULL;
    }
    if (pt2->Next != NULL && t1 + 1 == s2) {
        pt1->Next = pt2->Next;
        pt2->Next = ps1;
        Pre1->Next = ps2;
    } else if (t1 + 1 == s2) {
        pt2->Next = ps1;
        Pre1->Next = ps2;
        pt1->Next = NULL;
    }
}

void Output(List L)
{
    List p;
    printf("The new list is:");
    printf("%d", L->Next->Data);
    for (p = L->Next->Next; p; p = p->Next) {
        printf(" %d", p->Data);
    }
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