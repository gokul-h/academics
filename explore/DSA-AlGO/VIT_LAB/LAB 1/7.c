/*
 *Screenshot guide*
*********************************************************************
*/
#include<stdio.h>
void swap(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
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
    swap(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
/*
 *Screenshot guide*
*********************************************************************
*/
/*
 * Enter the number of elements:
6
Enter the elements:
5
6
10
3
1
90
1 3 5 6 10 90
 */