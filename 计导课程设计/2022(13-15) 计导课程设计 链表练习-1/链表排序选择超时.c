#include <stdio.h>
#include <stdlib.h>

typedef struct LNode* List;
struct LNode {
    int Data;
    List Next;
};

List Input();
void NodeSwap(List, List, List);
List FindMin(List L);
void SelectSort(List);
void Output(List);

int main(void)
{
    List p, q;
    List L = Input();
    SelectSort(L);
    Output(L);
    for (p = L; p; p = q) {
        q = p->Next;
        free(p);
    }
    return 0;
}

List Input()
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

void NodeSwap(List L, List p1, List p2)
{
    if (p1 == p2) return;
    List Pre1, Pre2, tmp;
    for (Pre1 = L; Pre1 && Pre1->Next != p1; Pre1 = Pre1->Next);
    for (Pre2 = L; Pre2 && Pre2->Next != p2; Pre2 = Pre2->Next);
    if (p1->Next != NULL && p2->Next != NULL) {
        Pre1->Next = p1->Next;
        Pre2->Next = p2->Next;
        p1->Next = Pre2->Next;
        Pre2->Next = p1;
        p2->Next = Pre1->Next;
        Pre1->Next = p2;
    } else if (p1->Next == NULL) {
        Pre2->Next = p2->Next;
        p1->Next = Pre2->Next;
        Pre2->Next = p1;
        Pre1->Next = p2;
        p2->Next = NULL;
    } else {
        Pre1->Next = p1->Next;
        p2->Next = Pre1->Next;
        Pre1->Next = p2;
        Pre2->Next = p1;
        p1->Next = NULL;
    }
}

List FindMin(List L)
{
    List MinNode = L, TempNode = L;
    while (TempNode != NULL) {
        if (TempNode->Data < MinNode->Data)
          MinNode = TempNode;
        TempNode = TempNode->Next;
    }
    return MinNode;
}

void SelectSort(List L)
{
    List p1, p2, tmp;
    for (p1 = L->Next; p1; p1 = p1->Next) {
        p2 = FindMin(p1);
        if (p2->Data < p1->Data) {
            tmp = p1;
            p1 = p2;
            p2 = tmp;
            NodeSwap(L, p1, p2);
        }
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