#include <stdio.h>
#include <stdlib.h>

typedef struct LNode* List;
struct LNode {
    int Data;
    List Next;
};

List Input();
int FindMax(List);
int FindMin(List);
int Sum(List);

int main(void)
{
    List L = Input();
    printf("The maximum,minmum and the total are:%d %d %d\n", FindMax(L), FindMin(L), Sum(L));
    return 0;
}

List Input()
{
    int num;
    /* 链表的创建需要三个结点指针：表头、表尾、临时节点指针 */
    List headPtr = NULL, currentPtr = NULL, lastPtr = NULL;
    while (scanf("%d", &num) && num != -1) { //读入数据
        currentPtr = (List)malloc(sizeof(struct LNode)); //给临时指针分配节点
        if (currentPtr != NULL) { //如果内存分配成功
            currentPtr->Data = num; //将读入的数据存入该节点的数据域
            /* 分类判断是表头节点还是后续节点 */
            if (headPtr == NULL) { //如果是创建表头结点
                headPtr = currentPtr;
                lastPtr = currentPtr;
            } else { //如果是后续节点
                lastPtr->Next = currentPtr; //讲临时节点接上表尾节点
                lastPtr = currentPtr; //修正表尾节点指针
            }
        }
    }
    lastPtr->Next = NULL; //安全起见表尾节点的指针域要求为空指针
    return headPtr;
}

int FindMax(List L)
{
    List MaxNode = L, TempNode = L;
    while (TempNode != NULL) { //终止条件是TempNode本身不为空指针
        if (TempNode->Data > MaxNode->Data)
          MaxNode = TempNode;
        TempNode = TempNode->Next; //因为最后一次让自己指向了NULL
    }
    return MaxNode->Data;
}

int FindMin(List L)
{
    List MinNode = L, TempNode = L;
    while (TempNode != NULL) {
        if (TempNode->Data < MinNode->Data)
          MinNode = TempNode;
        TempNode = TempNode->Next;
    }
    return MinNode->Data;
}

int Sum(List L)
{
    int sum = 0;
    List TempNode = L;
    while (TempNode != NULL) {
        sum += TempNode->Data;
        TempNode = TempNode->Next;
    }
    return sum;
}