/*
��Ŀ����
��֪һ����������ɵ��������У�����δ֪����������һ��Ԫ�أ���������ǽ���һ��������
��ʹ�ø�����洢������������У�Ȼ����������������ʹ������������Ϊ�������С�
��������������-1��Ϊ������־��ע��-1������������������е�Ԫ�أ���Ҫͳ��-1����
������Ĺ����У�������Լ�ѡ�������㷨��ð������ѡ������ȣ�����������ͨ���޸Ľ���ָ��������������
�����ǶԽ�������������޸ġ����������Ҫ�ͷ����нڵ�ռ�ݵĿռ䡣

����
һ��Ԫ�ظ���δ֪�����������У������롰-1�����������롰-1��ǰ��������һ����������

���
��������������ÿ��Ԫ�غ���һ���ո�ע�����һ��Ԫ�غ�ֻ�л��з���
�������Ĳ��������ڵ�����1000�������������������������int�ʹ洢��
��ע�����������ʽ��

��������
49 38 65 97 76 13 27 49 -1
�������
The new list is:13 27 38 49 49 65 76 97
*/

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