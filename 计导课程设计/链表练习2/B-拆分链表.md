# B - 拆分链表



## 题目描述

已知有一个乱序的字符序列 L ，序列中的字符可能是英文字母、数字字符或其它字符，字符的个数未知，每个字符之间用空格分开。字符序列用 “-1” 作为输入结束标志，这里你要把 -1 当做一个字符串对待，并且不算作字符序列中的元素。如下即为一个合法的字符序列：“a c 3 b a d 6 , & j m 8 7 2 V -1”。你的任务是将这个字符序列拆分为三个独立的序列 A、B 和 C ，其中序列 A 存放序列 L 中的字母，序列 B 存放序列 L 中的数字，序列 C 存放序列 L 中的其他字符，然后，将序列 A、B 和 C 分别按照 ASCII 码的大小关系进行升序排序。最终序列 L 将变为空序列。  
要求：  
建立四个单链表，分别存储序列 L、A、B、C 中的元素。字符序列的输入用 “-1” 作为结束标志。建立链表 L 时，建议使用 scanf(“%s”,s); 来读取字符序列中的字符，即把单独的字符看做一个字符串读取。当 L 建立后，你要按照问题描述中所述，将 L 拆分为 A、B、C 三个链表，然后对每个链表都进行排序，这部分的操作都应该是对指针进行修改，而不是删除节点与建立新节点。在程序结束前要释放链表 A、B、C 中的所有节点。  



## 输入

一个乱序的字符序列，序列元素的个数未知，以输入 “-1” 结束，输入 “-1” 前可能没有其它元素，每个字符序列占一行。  



## 输出

链表 A 中的元素，占一行；然后是链表 B 中的元素，占一行。最后是链表 C 中的元素，占一行。每行的每个元素后有一个空格，注意最后一个元素后只有换行符，如果某个链表为空则，则输出“There is no item in X list.”  
数据最多的测试用例节点数在100这个数量级。  
**请注意输入输出格式。**    



## 样例输入

```
Sample 1:
a c 3 b a d 6 , & j m 8 7 2 V -1

Sample 2:
z m v 1 a K 2 m p 9 a 0 a d -1
```



### 样例输出

```
Sample 1:
The list A is: V a a b c d j m
The list B is: 2 3 6 7 8
The list C is: & ,

Sample 2:
The list A is: K a a a d m m p v z
The list B is: 0 1 2 9
There is no item in C list.
```



## 解

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ElementType char

typedef struct LNode * List;
struct LNode {
    ElementType Data;
    List Next;
};

List ReadList();
List CutList(List, int);
void BubbleSortList(List);
void PrintList(List, char);
void FreeList(List);

int main(void)
{
    List L, A, B, C;
    L = ReadList();
    A = CutList(L, 1);
    B = CutList(L, 2);
    C = CutList(L, 3);
    PrintList(A, 'A');
    PrintList(B, 'B');
    PrintList(C, 'C');
    FreeList(L);
    FreeList(A);
    FreeList(B);
    FreeList(C);
    return 0;
}

List ReadList()
{
    List front, rear, cur;
    front = malloc(sizeof(struct LNode));
    front->Data = '\0';
    front->Next = NULL;
    rear = front;
    char s[3];
    scanf("%s", s);
    getchar();
    while (strcmp("-1", s)) {
        cur = malloc(sizeof(struct LNode));
        cur->Data = s[0];
        cur->Next = NULL;
        rear->Next = cur;
        rear = cur;
        scanf("%s", s);
        getchar();
    }
    return front;
}

//链表的冒泡排序模板
void BubbleSortList(List L)
{
    if (L->Next) {
        List tmp, pre, cur, next, end = NULL;
        while (end != L->Next) {
            for (pre = L, cur = pre->Next, next = cur->Next;
                next != end; 
                pre = pre->Next, cur = cur->Next, next = next->Next) {
                if (cur->Data > next->Data) {
                    cur->Next = next->Next;
                    next->Next = cur;
                    pre->Next = next;
                    tmp = next;
                    next = cur;
                    cur = next;
                }
            }
            end = cur;
        }
    }
}

List CutList(List L, int a)
{
    List first1, pre1 , front2, rear2, cur;
    pre1 = L;
    first1 = pre1->Next;
    front2 = malloc(sizeof(struct LNode));
    front2->Data = '\0';
    front2->Next = NULL;
    rear2 = front2;
    //分割合并实现
    while (first1) {
        char x = first1->Data;
        if ((x >= 'A' && x <= 'Z' || x >= 'a' && x <='z') && a == 1) {
            rear2->Next = first1;
            rear2 = first1;
            first1 = first1->Next;
            pre1->Next = first1;
            rear2->Next = NULL;
        } else if ((x >= '0' && x <= '9') && a == 2) {
            rear2->Next = first1;
            rear2 = first1;
            first1 = first1->Next;
            pre1->Next = first1;
            rear2->Next = NULL;
        } else if (a == 3) {
            rear2->Next = first1;
            rear2 = first1;
            first1 = first1->Next;
            pre1->Next = first1;
            rear2->Next = NULL;
        } else {
            pre1 = first1;
            first1 = first1->Next;
        }
    }
    BubbleSortList(front2);
    return front2;
}

void PrintList(List L, char X)
{
    if (L->Next == NULL)
        printf("There is no item in %c list.", X);
    else {
        printf("The list %c is:", X);
        List p = L->Next;
        while (p) {
            printf(" %c", p->Data);
            p = p->Next;
        }
    }
    printf("\n");
}

void FreeList(List L)
{
    List tmp = L;
    while (L) {
        tmp = L;
        L = L->Next;
        free(tmp);
    }
}
```

