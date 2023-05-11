// Program to calculate matrix addition subtraction and multiplication
#include<stdio.h>
#include<string.h>
int i,j;
int mat_inp(int m,int n);
int mat_cal(int arr1[10][10],int arr2[10][10]);
void mat_pri(int arr[10][10]);
int main(){
	int m1,n1,m2,n2;
	printf("Enter the order of matrix A\n");
	scanf("%d%d",&m1,&n1);
	printf("Enter the order of matrix B\n");
	scanf("%d%d",&m2,&n2);
	int arr1[10][10]=mat_inp(m1,n1);
	int arr2[10][10]=mat_inp(m2,n2);
	int arr3[10][10]=mat_cal(arr1,arr2);
	mat_pri(arr3);
	return 0;
}
int mat_inp(int m,int n)
{
    printf("Enter the values of matrix:-\n");
    int arr[10][10];
    for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	return arr[10][10];
}
int mat_cal(int arr1[10][10],int arr2[10][10])
{
    int m=strlen(arr1[0]);
    int n=strlen(arr2);
    int arr3[10][10];
    for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			arr3[i][j] = arr1[i][j]+arr2[i][j];
		}
	}
	return arr3[10][10];
}
void mat_pri(int arr[10][10])
{
    printf("Values of resultant matrix are:-\n");
    int m=strlen(arr);
    int n=strlen(arr[0]);
    for(i=0;i<m;i++)
	{
		printf("");
		for(j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
	}
}
