#include<stdio.h>
#include<stdlib.h>

#define ROWSIZE 5
#define COLSIZE 5

void inputMatrix(int a[][COLSIZE], int, int);
int findRowMax(int data[], int rowSize);
int findColMin(int data[][COLSIZE], int rows, int col);
int main(void)
{
    int matrix[ROWSIZE][COLSIZE]; //存储矩阵
    int found;
    int row,col,minRow,maxCol; 

    inputMatrix (matrix,ROWSIZE,COLSIZE ); //输入矩阵

    /* 查找鞍点 */
    row=0; found=0;
    while (row<ROWSIZE){
           maxCol=findRowMax(matrix[row],COLSIZE);
          minRow=findColMin(matrix,ROWSIZE,maxCol);
            if (minRow==row)
            {   //找到鞍点，则输出
                printf("\nrow=%3d col=%3d element=%3d\n",row,maxCol,matrix[row][maxCol]);
                found=1;
            }
        row++;
      }      

   if (found==0)
       printf("未找到鞍点\n"); 


    return 0;
}

void inputMatrix(int a[][COLSIZE], int row, int col)
{
    
}

/* 函数功能：找数组中的最大值元素，并返回其下标 
   参数说明：数组名，数组中已存放元素的个数*/
int findRowMax(int data[], int elementSize)
{
    int i, maxloc = 0;
    
    for (i=1; i < elementSize; i++)
      if (data[i] > data[maxloc])
        maxloc = i;
          
    return maxloc;
}

/* 函数功能：求col列最小值所在下标并返回 
  参数说明：数组名，数组行数，要查找的列*/ 
int findColMin(int data[][COLSIZE], int rows,int col)
{
    int row,minRow=0;
    
    for (row=1; row<=rows-1; row++)
        if (data[row][col]<data[minRow][col]) 
           minRow=row;
          
    return minRow;
} 
