#include<stdio.h>
#define LEN 100

//�������� 
void distribute(int * bullets , int size , int number );

int main()
{
    int        bullets[LEN] ;
    int        n , m , i ;    

    scanf("%d" , &n ) ;    //����սʿ���� 
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%d" , &bullets[i] ) ;//����ÿ��սʿ���г�ʼ���ӵ��� 
    }
    scanf("%d" , &m ) ;//��������Ĵ�����m>0) 
    distribute(bullets , n , m ) ;//���� 
    for( i = 0 ; i < n - 1 ; i++ )//����������� 
    {
        printf("%d " , bullets[i] ) ;
    }
    printf("%d\n" , bullets[i] ) ;

    return 0;    
}

/* ����������д�� */

void distribute(int * bullets , int size , int number)
{
    int i, j, equal;
    int a[LEN];

    for (i = 0; i < number; i++) //����number��
    {
        for (j = 0; j < size; j++) //ÿ�ε�������size��
        {
            a[j] = bullets[j]; /*�ȸ��Ƶ�a����������ÿ�ηָ���һ���˵��ӵ���Ŀ*/
        }

        equal = 0;
        for (j = 0; j < size; j++)
        {
            if (bullets[0] == bullets[j])  //������ȴ���
            {
                equal++;
            }
        }

        if (equal < size) //����Ѿ�ȫ����˾Ͳ��ٲ���
        {
            for (j = 0; j < size; j++)
            {
                if (a[j] % 2) //����ӵ���Ϊ����
                {
                   a[j]++;
                   bullets[j]++; //�����ӵ���+1
                }
                a[j] /= 2;
                bullets[j] /= 2; //�Լ��ķ�һ��
            }

            for (j = 0; j < size; j++)
            {
                if (j != size - 1) //����������һ����
                {
                    bullets[j + 1] += a[j]; //��һ���˷�һ������
                }
                else
                {
                    bullets[0] += a[j]; //���һ���˷ָ���һ��
                }
            }
        }
    }
}