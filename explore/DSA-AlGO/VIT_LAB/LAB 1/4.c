// Question 4
/*
    Write a C program, which outputs all local maximums of a given data of elements. A
    number xi is a local maximum if it is more than both xi1 and xi+1. If the elements are 25,
    19, 22, 23, 21, 12, 10, 17, 11, 13, 10 then 23, 17 and 13 are local maximums.
// For local minimum change comparison sign
*/
/*
 *Screenshot guide*
*********************************************************************
*/

#include<stdio.h>
int main(void)
{
    int num,i;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter the elements: \n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    // Processing
    printf("Local maximums are :\n");
    for(i=1;i<num-1;i++)
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
            printf("%d\n",arr[i]);
        }
    }
    return 0;
}

/*
 * Sample Input: 25 19 22 23 21 12 10 17 11 13 10
 * no of elements : 11
 * Answer 23 17 13
 */