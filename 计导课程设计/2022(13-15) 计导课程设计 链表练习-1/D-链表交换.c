/*
题目描述
已知一个正整数序列，序列元素个数未知，但至少有两个元素，你的任务是建立一个单链表用于存储这个正整数序列。
然后实现交换此链表中任意指定的两段，第一段为[s1,t1]，第二段[s2,t2]。s1、t1、s2、t2代表链表的第几个节点，
且满足s1<=t1，s2<=t2，t1<s2，s2一定小于等于链表节点的总个数。正整数的输入用-1作为结束标志，
注意-1不算这个正整数序列中的元素（不要统计-1）。最后将链表的全部节点释放。

输入
输入一个正整数序列，以输入“-1”结束，序列中元素个数未知，但输入“-1”前至少输入两个正整数。
然后是四个整数，即为s1、t1、s2、t2。

输出
经过处理后的新链表，每个元素后有一个空格，注意最后一个元素后只有换行符。
数据最多的测试用例节点数在100这个数量级，所有整数可以用int型存储。
请注意输入输出格式。

样例输入 Copy
1 2 3 4 5 6 7 8 9 10 -1
1 1 4 7
样例输出 Copy
The new list is:4 5 6 7 2 3 1 8 9 10
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