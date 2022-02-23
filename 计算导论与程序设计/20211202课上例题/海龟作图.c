#include<stdio.h>

#define COMMANDSIZE 100
#define PICSIZE 50

int main(void)
{
    int commands[COMMANDSIZE]; //´æ´¢ÃüÁî
    int floor[PICSIZE][PICSIZE]={0}; //´æ´¢Í¼Æ¬ 
   
    getCommand(commands, COMMANDSIZE);//»ñÈ¡ÃüÁî
    draw(commands, COMMANDSIZE, floor, PICSIZE, PICSIZE);//×÷Í¼
     
    return 0;
}