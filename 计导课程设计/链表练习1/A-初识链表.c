/*
��Ŀ������
��֪һ�����������У�����δ֪����������һ��Ԫ�أ���������ǽ���һ��������
��ʹ�ø�����洢������������У�Ȼ��ͳ�����������Ԫ�ص����ֵ����Сֵ����������ȫ��Ԫ��֮�͡�
��������������-1��Ϊ������־��ע��-1������������������е�Ԫ�أ���Ҫͳ��-1����

���룺
һ�����������У�����������Ԫ�صĸ���δ֪���������롰-1�����������롰-1��ǰ��������һ����������
�����е�Ԫ�ط�Χ��1��999999999֮�䡣

�����
�����������������ֵ����Сֵ������Ԫ��֮�͡�
�������Ĳ��������ڵ�����1000�������������������������int�ʹ洢��
��ע�����������ʽ��

�������룺
1 4 99 21 50 61 32 4 -1
���������
The maximum,minmum and the total are:99 1 272
*/

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
    /* ����Ĵ�����Ҫ�������ָ�룺��ͷ����β����ʱ�ڵ�ָ�� */
    List headPtr = NULL, currentPtr = NULL, lastPtr = NULL;
    while (scanf("%d", &num) && num != -1) { //��������
        currentPtr = (List)malloc(sizeof(struct LNode)); //����ʱָ�����ڵ�
        if (currentPtr != NULL) { //����ڴ����ɹ�
            currentPtr->Data = num; //����������ݴ���ýڵ��������
            /* �����ж��Ǳ�ͷ�ڵ㻹�Ǻ����ڵ� */
            if (headPtr == NULL) { //����Ǵ�����ͷ���
                headPtr = currentPtr;
                lastPtr = currentPtr;
            } else { //����Ǻ����ڵ�
                lastPtr->Next = currentPtr; //����ʱ�ڵ���ϱ�β�ڵ�
                lastPtr = currentPtr; //������β�ڵ�ָ��
            }
        }
    }
    lastPtr->Next = NULL; //��ȫ�����β�ڵ��ָ����Ҫ��Ϊ��ָ��
    return headPtr;
}

int FindMax(List L)
{
    List MaxNode = L, TempNode = L;
    while (TempNode != NULL) { //��ֹ������TempNode����Ϊ��ָ��
        if (TempNode->Data > MaxNode->Data)
          MaxNode = TempNode;
        TempNode = TempNode->Next; //��Ϊ���һ�����Լ�ָ����NULL
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