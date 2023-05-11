/*
 *Screenshot guide*
*********************************************************************
*/
#include<stdio.h>
int main(void)
{
    int num,k;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    int i,j,arr[num];
    printf("Enter the elements: ");
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number k: ");
    scanf("%d",&k);
    for(i=0;i<num;i++)
    {
        for(j=i;j<num;j++)
        {
            if(arr[i]+arr[j]==k)
            {
                printf("%d+%d=%d\n",arr[i],arr[j],k);
            }
        }
    }
    return 0;
}
/*
 * Enter the number of elements:5
 Enter the elements:1 2 3 5 0
 Enter the number k:5
 */
