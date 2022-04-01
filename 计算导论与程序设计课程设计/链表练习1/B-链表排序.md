# B - 链表排序



## 题目描述

已知一个正整数组成的无序序列，个数未知，但至少有一个元素，你的任务是建立一个单链表，并使用该链表存储这个正整数序列，然后将这个链表进行排序，使得排序后的链表为递增序列。正整数的输入用-1作为结束标志，注意 -1 不算这个正整数序列中的元素（不要统计 -1 ）。在排序的过程中，你可以自己选择排序算法（冒泡排序、选择排序等），但必须是通过修改结点的指针域来进行排序，而不是对结点的数据域进行修改。程序结束后要释放所有节点占据的空间。



## 输入

一个元素个数未知的正整数序列，以输入“-1”结束，输入“-1”前至少输入一个正整数。



## 输出

经过排序后的链表，每个元素后有一个空格，注意最后一个元素后只有换行符。  
数据最多的测试用例节点数在1000这个数量级，所有整数可以用int型存储。  
**请注意输入输出格式。 ** 



## 样例输入

```
49 38 65 97 76 13 27 49 -1
```



## 样例输出

```
The new list is:13 27 38 49 49 65 76 97
```



## 解

### 选择排序（RE）

```C
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
```



### 冒泡排序（AC）

```C
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
```