#include<stdio.h>

#define COMMANDSIZE 100
#define PICSIZE 50

int main(void)
{
    int commands[COMMANDSIZE]; //�洢����
    int floor[PICSIZE][PICSIZE]={0}; //�洢ͼƬ 
   
    getCommand(commands, COMMANDSIZE);//��ȡ����
    draw(commands, COMMANDSIZE, floor, PICSIZE, PICSIZE);//��ͼ
     
    return 0;
}