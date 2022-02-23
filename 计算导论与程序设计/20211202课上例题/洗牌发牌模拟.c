#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle (int [][13]);
void deal(const int [][13]);
void outputCard(int i,int row,int col);
 
int main(void)
{
    int deck[4][13]={0}; //����һ����
    srand (time(NULL)); //����ÿ�γ�����ͬ�������
    shuffle(deck); //ϴ��
    deal(deck); //����
    return 0;
}

void shuffle(int wdeck[][13]) /*ϴ��*/
{
    int card,row,column;
    for(card = 1; card <= 52; card++)
    {
        //���ɵ�card���ƵĻ�ɫ����ֵ
        row = rand() % 4;
        column = rand() % 13;
 
        while(wdeck[row][column] != 0) //���������õ�ͬһ����
        {
            row = rand() % 4;
            column = rand() % 13;
        }
        
        //������card����
        wdeck[row][column] = card;
     }
}

void deal (const int wdeck[][13]) /*����*/
{
    int card,row,column,found;

    for (card = 1;card <= 52;card++) //������ά���飬����ֵΪcard��Ԫ�أ������Ӧ�Ļ�ɫ����ֵ
    {
        found = 0;
        for (row=0; row <= 3 && !found; row++)
          for (column=0; column <= 12 && !found; column++)
            if (wdeck[row][column] == card)
            {
                found = 1;
                outputCard(card,row,column); //�����card���ƵĻ�ɫ��ֵ
            }
      }
}

//�������
void outputCard(int i,int row,int col)
{
    printf("��%d���ƣ�",i);
    switch (col){
      case 0:printf("Acer");break;
      case 1:printf("Deuce");break;
      case 2:printf("Three");break;
      case 3:printf("Four");break;
      case 4:printf("Five");break;
      case 5:printf("Six");break;
      case 6:printf("Seven");break;
      case 7:printf("Eight");break;
      case 8:printf("Nine");break;
      case 9:printf("Ten");break;
      case 10:printf("Jack");break;
      case 11:printf("Queen");break;
      case 12:printf("King");break;
      default:printf("��Ч����ֵ !");
    }
    printf(" of ");
    switch (row){
      case 0:printf("Hearts");break;
      case 1:printf("diamonds");break;
      case 2:printf("Clubs");break;
      case 3:printf("Spades");break;
      default:printf("��Ч�Ļ�ɫ !");
    }
    printf("\n");
}

//���ַ�����ά�������
void outputCard  (int i,int row,int col)
{ 
    char face[13][10]={"Ace", "Deuce", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Jeck","Queen", "King"};   
    char suit[4][10]={"Hearts", "Diamonds", "Clubs", "Spades"};           
    
    printf  ("��%d���ƣ�",i);
    if ( 0<= col && col <= 12 )
      printf("%s",face[col]);
    else  printf("��Ч����ֵ !");
    printf(" of ");

    if ( 0<= row && row <= 3 )   
    printf("%s",suit[row]);   
    else  printf("��Ч�Ļ�ɫ !");  
    printf("\n");
}
