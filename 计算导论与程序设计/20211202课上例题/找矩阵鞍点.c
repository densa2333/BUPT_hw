#include<stdio.h>
#include<stdlib.h>

#define ROWSIZE 5
#define COLSIZE 5

void inputMatrix(int a[][COLSIZE], int, int);
int findRowMax(int data[], int rowSize);
int findColMin(int data[][COLSIZE], int rows, int col);
int main(void)
{
    int matrix[ROWSIZE][COLSIZE]; //�洢����
    int found;
    int row,col,minRow,maxCol; 

    inputMatrix (matrix,ROWSIZE,COLSIZE ); //�������

    /* ���Ұ��� */
    row=0; found=0;
    while (row<ROWSIZE){
           maxCol=findRowMax(matrix[row],COLSIZE);
          minRow=findColMin(matrix,ROWSIZE,maxCol);
            if (minRow==row)
            {   //�ҵ����㣬�����
                printf("\nrow=%3d col=%3d element=%3d\n",row,maxCol,matrix[row][maxCol]);
                found=1;
            }
        row++;
      }      

   if (found==0)
       printf("δ�ҵ�����\n"); 


    return 0;
}

void inputMatrix(int a[][COLSIZE], int row, int col)
{
    
}

/* �������ܣ��������е����ֵԪ�أ����������±� 
   ����˵�������������������Ѵ��Ԫ�صĸ���*/
int findRowMax(int data[], int elementSize)
{
    int i, maxloc = 0;
    
    for (i=1; i < elementSize; i++)
      if (data[i] > data[maxloc])
        maxloc = i;
          
    return maxloc;
}

/* �������ܣ���col����Сֵ�����±겢���� 
  ����˵����������������������Ҫ���ҵ���*/ 
int findColMin(int data[][COLSIZE], int rows,int col)
{
    int row,minRow=0;
    
    for (row=1; row<=rows-1; row++)
        if (data[row][col]<data[minRow][col]) 
           minRow=row;
          
    return minRow;
} 
