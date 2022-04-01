# A - 链表归并



## 题目描述

已知有两个递增的正整数序列 A 和 B ，序列中元素个数未知，同一序列中不会有重复元素出现，有可能某个序列为空。现要求将序列 B 归并到序列 A 中，且归并后序列 A 的数据仍然按递增顺序排列。如果序列 B 中某些数据在序列 A 中也存在，则这些数据所在节点仍然留在序列 B 中，而不被归并到序列 A 中；否则这些数据所在节点将从序列 B 中删除，添加到序列 A 中。  
要求：  
建立两个单链表 A、B 用于存储两个正整数序列，然后按照题目的要求，将链表 B 中的元素归并到链表 A 中。在归并的过程中，不要释放 B 中的节点空间、然后建立新节点，而要改变指针的指向，使元素从 B 中删除并添加到 A 中。正整数序列按照递增顺序输入，用 -1 作为结束标志，注意-1不算这个正整数序列中的元素（不要统计 -1 ）。在程序结束前要释放链表 A、B 中的所有节点。  



## 输入

依次输入两个递增的正整数序列 A 和 B ，序列元素的个数未知，但以输入 “-1” 结束，每个正整数序列占一行。  



## 输出

处理后的链表A中的元素，占一行；然后是处理后的链表B中的元素，占一行。每行的每个元素后有一个空格，注意最后一个元素后只有换行符，如果某个链表为空则，则输出 “There is no item in X list.”  
数据最多的测试用例节点数在100这个数量级，所有整数可以用int型存储。  
**请注意输入输出格式。**  



## 样例输入

```
Sample 1:
1 3 4 5 6 7 -1
2 3 6 8 9 10 11-1

Sample 2:
-1
-1
```



### 样例输出

```
Sample 1:
The new list A:1 2 3 4 5 6 7 8 9 10 11
The new list B:3 6

Sample 2:
There is no item in A list.
There is no item in B list.
```



## 解

```C
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
    //对于链表往往需要当前节点指针和前继节点指针，有时还需要临时指针
    List first1, first2, pre1, pre2, tmp;
    first1 = A->Next;
    first2 = B->Next;
    pre1 = A;
    pre2 = B;
    // 归并部分画图理解 重点！
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
```
