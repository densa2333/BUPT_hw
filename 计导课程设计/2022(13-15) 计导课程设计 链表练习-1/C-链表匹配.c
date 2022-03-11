/*
题目描述
已知两个由正整数组成的无序序列A、B，每个序列的元素个数未知，但至少有一个元素。
你的任务是判断序列B是否是序列A的连续子序列。假设B是“1 9 2 4 18”，A是“33 64 1 9 2 4 18 7”，
B是A的连续子序列；假设B是“1 9 2 4 18”，A是“33 1 9 64 2 4 18 7”，B不是A的连续子序列。
要求：
建立两个单链表A、B用于存储两个正整数序列，然后按照题目的要求，判断链表B是否是链表A的连续子序列。
正整数的输入用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。
在程序结束前要释放链表A、B中的所有节点。

输入
依次输入两个乱序的正整数序列A、B，序列中元素个数未知，但每个序列至少有一个元素，
并以输入“-1”结束，每个序列占一行。

输出
如果序列B是序列A的连续子序列，则输出“ListB is the sub sequence of ListA.”，
否则输出“ListB is not the sub sequence of ListA.”。
数据最多的测试用例节点数在100这个数量级，所有整数可以用int型存储。
请注意输入输出格式。

样例输入 Copy
Sample 1:
5 4 3 2 1 -1
3 2 1 -1
Sample 2:
1 2 3 4 5 6 7 8 9 -1
1 2 3 4 5 6 7 8 0 -1
样例输出 Copy
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