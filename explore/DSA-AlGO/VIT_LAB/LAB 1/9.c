/*
 *Screenshot guide*
*********************************************************************
*/
#include<stdio.h>
int main(void)
{
    int k;
    printf("Enter the number : ");
    scanf("%d",&k);
    int rem,count=0;
    while(k)
    {
        rem = k%10;
        if(rem==0)
        {
            count++;
        }
        k=k/10;
    }
    printf("The number of 0s are %d",count);
    return 0;
}
