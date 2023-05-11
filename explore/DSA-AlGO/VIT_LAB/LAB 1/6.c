// Question 6
/*
    Write a C program that outputs the smallest ‘i’ such that xi and xi+1 are both even. In
    above case 6. (Because 12 and 10 are even).
 */
/*
 *Screenshot guide*
*********************************************************************
*/
#include<stdio.h>
int main(void)
{
    int n,i;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //Processing
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0 && arr[i+1]%2==0)
        {
            printf("Smallest i is %d",i);
            break;
        }
    }
    return 0;
}
//Sample input 25 19 22 23 21 12 10 17 11 13 10
// Number of elements 11