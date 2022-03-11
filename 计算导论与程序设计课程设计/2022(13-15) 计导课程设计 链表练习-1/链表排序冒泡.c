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
void BubbleSort(List);
void Output(List);
void Clear(List);

int main(void)
{
    List L = Input();
    BubbleSort(L);
    Output(L);
    Clear(L);
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

void BubbleSort(List L) //链表的冒泡排序
{
    List tmp, pre, cur, nxt, end = NULL;                    //pre前一项 cur当前项 nxt后一项
    while (L->Next != end) {                                //当end提前到空节点后一项时已经排完
        for (pre = L, cur = pre->Next, nxt = cur->Next;            //初始化三个位置指针
             nxt != end;                                           //循环结束条件是到达最后一项
             pre = pre->Next, cur = cur->Next, nxt = nxt ->Next) { //三个指针集体后移
            if (cur->Data > nxt->Data) {
                pre->Next = nxt;
                cur->Next = nxt->Next;
                nxt->Next = cur;
                //因为做了结点的交换，节点顺序仍需换回来继续循环
                tmp = cur;
                cur = nxt;
                nxt = tmp;
            }
        }
        end = cur; //一轮循环结束，最后一项已经排好，end提前一项
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

void Clear(List L)
{
    List p, q;
    for (p = L; p; p = q) {
        q = p->Next;
        free(p);
    }
}