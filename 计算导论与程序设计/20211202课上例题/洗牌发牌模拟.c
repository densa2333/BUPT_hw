#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle (int [][13]);
void deal(const int [][13]);
void outputCard(int i,int row,int col);
 
int main(void)
{
    int deck[4][13]={0}; //保存一副牌
    srand (time(NULL)); //避免每次出现相同的随机数
    shuffle(deck); //洗牌
    deal(deck); //发牌
    return 0;
}

void shuffle(int wdeck[][13]) /*洗牌*/
{
    int card,row,column;
    for(card = 1; card <= 52; card++)
    {
        //生成第card张牌的花色和面值
        row = rand() % 4;
        column = rand() % 13;
 
        while(wdeck[row][column] != 0) //避免两次拿到同一张牌
        {
            row = rand() % 4;
            column = rand() % 13;
        }
        
        //发出第card张牌
        wdeck[row][column] = card;
     }
}

void deal (const int wdeck[][13]) /*发牌*/
{
    int card,row,column,found;

    for (card = 1;card <= 52;card++) //遍历二维数组，查找值为card的元素，输出对应的花色和面值
    {
        found = 0;
        for (row=0; row <= 3 && !found; row++)
          for (column=0; column <= 12 && !found; column++)
            if (wdeck[row][column] == card)
            {
                found = 1;
                outputCard(card,row,column); //输出第card张牌的花色面值
            }
      }
}

//暴力输出
void outputCard(int i,int row,int col)
{
    printf("第%d张牌：",i);
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
      default:printf("无效的面值 !");
    }
    printf(" of ");
    switch (row){
      case 0:printf("Hearts");break;
      case 1:printf("diamonds");break;
      case 2:printf("Clubs");break;
      case 3:printf("Spades");break;
      default:printf("无效的花色 !");
    }
    printf("\n");
}

//存字符串二维数组输出
void outputCard  (int i,int row,int col)
{ 
    char face[13][10]={"Ace", "Deuce", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Jeck","Queen", "King"};   
    char suit[4][10]={"Hearts", "Diamonds", "Clubs", "Spades"};           
    
    printf  ("第%d张牌：",i);
    if ( 0<= col && col <= 12 )
      printf("%s",face[col]);
    else  printf("无效的面值 !");
    printf(" of ");

    if ( 0<= row && row <= 3 )   
    printf("%s",suit[row]);   
    else  printf("无效的花色 !");  
    printf("\n");
}
