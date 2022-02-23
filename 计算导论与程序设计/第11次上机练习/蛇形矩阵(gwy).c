#include<stdio.h>
#define SIZE 100
void change_1(int a[][SIZE],int n,int m);
void situation1(int a[][SIZE],int n,int m,int i,int j,int num);
void situation2(int a[][SIZE],int n,int m,int i,int j,int num);
void situation3(int a[][SIZE],int n,int m,int i,int j,int num);
void situation4(int a[][SIZE],int n,int m,int i,int j,int num);
void output(int a[][SIZE],int n,int m);
int main()
{
	int a[SIZE][SIZE]={0},i,j,n;
	scanf("%d",&n);
	change_1(a,n,n);
	output(a,n,n);
	return 0;
}
void change_1(int a[][SIZE],int n,int m)
{
	int i_1=0,i=0,j=0,num=2;
	a[0][0]=1;
	a[n][m]=n*m;
	while(i_1<n-1)
	{
		if(i_1%2==0){
		    situation1(a,n,m,i,j,num);
			i=0;
			j=i_1+1;
			}
		else{
		    situation2(a,n,m,i,j,num);
		    i=i_1+1;
		    j=0;
		    }
		num=num+i_1+2;
		i_1++;
	}
	num=num-i_1-1;
	while(i_1>=n-1&&i_1<2*n-1)
	{
		if(i_1%2!=0){
			situation3(a,n,m,i,j,num);
			j=m-1;
			i=i_1-n+1;
		}
		else{
			situation4(a,n,m,i,j,num);
			i=n-1;
			j=i_1-m+1;	
		}
		num=num+2*n-1-i_1;
		i_1++; 
	}
}

void situation1(int a[][SIZE],int n,int m,int i,int j,int num)
{
	i=i+1;
	while(i>=0)
	{
		a[i][j]=num;
		num++;
		i=i-1;
		j=j+1;
	}
}

void situation2(int a[][SIZE],int n,int m,int i,int j,int num)
{
	j=j+1;
	while(j>=0)
	{
		a[i][j]=num;
		num++;
		j=j-1;
		i=i+1;
	}
}

void situation3(int a[][SIZE],int n,int m,int i,int j,int num)
{
	j=j+1;
	while(j<=m-1)
	{
		a[i][j]=num;
		num++;
		j=j+1;
		i=i-1;
	}
} 

void situation4(int a[][SIZE],int n,int m,int i,int j,int num)
{
	i=i+1;
	while(i<=n-1)
	{
		a[i][j]=num;
		num++;
		i=i+1;
		j=j-1;
	}
}

void output(int a[][SIZE],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++){
	    for(j=0;j<m-1;j++)
	    {
	   	    printf("%d ",a[i][j]);
		} 
		printf("%d\n",a[i][j]);}
}