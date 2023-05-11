// Array in C
//Question 1
//Modify the program according to the question
/*Screenshot guide*
*********************************************************************
*/
#include<stdio.h>
int main(void)
{
    int x[20],sum,i,n;
    printf("How many numbers");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Give %dth number",i);
        scanf("%d",&x[i]);
    }
    sum=1;
    for(i=1;i<=n-2;i++)
        sum=sum*(x[i]+x[i+2]);
    printf("%d",sum);
}

// input
//n 7
//values 4 5 2 5 6 4 7
// Expected Output 56160



