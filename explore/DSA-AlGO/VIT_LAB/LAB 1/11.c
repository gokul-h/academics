/* Question 11
    Assume that the given matrix is a square matrix. Write program to print oth
    the diagonal elements. Optimize on the code to use lesser loop statements,
    lesser conditional statements. e.g.
    Matrix
        5 7 9 4
        2 4 7 3
        1 5 9 2
        3 7 4 8
    Output
        5 4 9 8
        4 7 5 3
*/
/*
 *Screenshot guide*
*********************************************************************
*/
#include<stdio.h>
int main(void)
{
    int size;
    printf("Enter the size of square matrix : ");
    scanf("%d",&size);
    int mat[size][size],i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    int new_arr[2][size],c1=0,c2=0;
    // Processing
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(i==j)
            {
                new_arr[0][c1] = mat[i][j];
                c1++;
            }
            else if(i+j==size-1)
            {
                new_arr[1][c2] = mat[i][j];
                c2++;
            }
        }
    }
    for(i=0;i<2;i++)
    {
        printf("\n");
        for(j=0;j<size;j++)
        {
            printf("%d ",new_arr[i][j]);
        }
    }
    return 0;
}
/*
 *Screenshot guide*
*********************************************************************
*/
/*
 * Sample Input
 * Size 4
 * Values 5 7 9 4 2 4 7 3 1 5 9 2 3 7 4 8
 * Solution
        5 4 9 8
        4 7 5 3
 */