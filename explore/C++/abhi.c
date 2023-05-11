#include <stdio.h>
#include<stdlib.h>
int main()
{
    // input array (sorted).
    int num,i,n,a[100];
    printf("how many elements to input ");
    scanf("%d",&n);
    printf("enter the elements");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the number whose index has to be found");
    scanf("%d",&num);
    // binary search algorithm.
    int mid,index=0;
    mid = (n-1)/2;
    //printf("%d",mid);
    while(mid!=0)
    {
        //printf("Hello\n");
        if(a[mid]==num)
        {
            //printf("Found\n");

            index = mid;
            printf("index is%d",index);
            exit(0);
        }
        //middle element less than x
        else if(a[mid]<num)
        {
            mid = mid+(n-1)/2;
            //printf("2-%d",mid);
            continue;
        }
        //middle element greater than x
        else if(a[mid]>num)
        {
            mid = mid/2;
            //printf("1-%d",mid);
            continue;

        }

    }
    //print the index position


    return 0;

}