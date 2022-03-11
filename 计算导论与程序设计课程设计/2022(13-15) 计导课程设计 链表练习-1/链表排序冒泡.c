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
    /* ������ͷ�ڵ������ */
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

void BubbleSort(List L) //�����ð������
{
    List tmp, pre, cur, nxt, end = NULL;                    //preǰһ�� cur��ǰ�� nxt��һ��
    while (L->Next != end) {                                //��end��ǰ���սڵ��һ��ʱ�Ѿ�����
        for (pre = L, cur = pre->Next, nxt = cur->Next;            //��ʼ������λ��ָ��
             nxt != end;                                           //ѭ�����������ǵ������һ��
             pre = pre->Next, cur = cur->Next, nxt = nxt ->Next) { //����ָ�뼯�����
            if (cur->Data > nxt->Data) {
                pre->Next = nxt;
                cur->Next = nxt->Next;
                nxt->Next = cur;
                //��Ϊ���˽��Ľ������ڵ�˳�����軻��������ѭ��
                tmp = cur;
                cur = nxt;
                nxt = tmp;
            }
        }
        end = cur; //һ��ѭ�����������һ���Ѿ��źã�end��ǰһ��
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