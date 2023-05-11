#include<stdio.h>

void read_arr(int a[10][10],int row,int col)
{
    int i,j;
    for(i=1;i<=row;i++)
    {
    for(j=1;j<=col;j++)
    {
        printf("Enter Element %d %d : ",i,j);
        scanf("%d",&a[i][j]);
            }
    }
}

void add_arr(int m1[10][10],int m2[10][10],int m3[10][10],int row,int col)
{
    int i,j;
    for(i=1;i<=row;i++)
    {
    for(j=1;j<=col;j++)
    {
    m3[i][j] =  (m1[i][j] + m2[i][j]);
    }
    }
}
void sub_arr(int m1[10][10],int m2[10][10],int m3[10][10],int row,int col)
{
    int i,j;
    for(i=1;i<=row;i++)
    {
    for(j=1;j<=col;j++)
    {
    m3[i][j] =  (m1[i][j] - m2[i][j]);
    }
    }
}
void sub_arr(int m1[10][10],int m2[10][10],int m3[10][10],int row,int col)
{
    int i,j;
    for(i=1;i<=row;i++)
    {
    for(j=1;j<=col;j++)
    {
    m3[i][j] +=  (m1[i][j] * m2[i][j]);
    }
    }
}
void print_arr(int m[10][10],int row,int col)
{
    int i,j;
    for(i=1;i<=row;i++)
        {
        for(j=1;j<=col;j++)
        {
            printf("%d ",m[i][j]);
         }
        printf("\n");
        }
}

int main()
{
    int m1[10][10],m2[10][10],m3[10][10],row1,col1,row2,col2;
    printf("Enter number of rows (MATRIX 1) :");
    scanf("%d",&row1);
    printf("Enter number of colomns(MATRIX 1) :");
    scanf("%d",&col1);
    read_arr(m1,row1,col1);
    printf("Enter number of rows(MATRIX 2):");
    scanf("%d",&row2);
    printf("Enter number of colomns (MATRIX 2) :");
    scanf("%d",&col2);
    read_arr(m2,row2,col2);
    int choice;
    printf("Enter the choice \n 1 for Addition \n 2 for subtraction \n 3 for multiplication\n");
    scanf("%d",&choice);
    if(choice==1)
        {
        if(row1==row2){
            if(col1==col2){
                add_arr(m1,m2,m3,row1,col1);
                print_arr(m3,row1,col1);
            }
        }
    }
    else if(choice==2)
        {
        if(row1==row2){
            if(col1==col2){
                sub_arr(m1,m2,m3,row1,col1);
                print_arr(m3,row1,col1);
            }
        }
    }
    else if(choice==3){
        if(row1==row2){
            if(col1==col2){
                sub_arr(m1,m2,m3,row1,col1);
                print_arr(m3,row1,col1);
            }
        }
    }
    else{
        printf("Not valid input!!1");
    }
    return 0;
}
