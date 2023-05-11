#include<stdio.h>
void linearsearch(int x[]);
void binarysearch(int x[],int,int);
int size,flag=0,i;
int a[25];
int main()
{
    int k,ch=1;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the elements of array:");
    for(k=0;k<size;k++)
    {
        scanf("%d",&a[k]);
    }
    while(ch!=3)
    {
        printf("\n 1.Linear Search \n 2.Binary Search \n 3.Exit \n Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:linearsearch(a);
                break;
            case 2:binarysearch(a,size-1,0);
                break;
            case 3:printf("BYE");
                break;
            default:printf("WRONG CHOICE");
                break;
        }
    }
    return 0;
}
void linearsearch(int x[])
{
    int z,key;
    printf("Enter the Key Element");
    scanf("%d",&key);
    for(z=0;z<size;z++)
    {
        if(x[z]==key)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("Element found at %d",z+1);
    else
        printf("Element not found");
}
void binarysearch(int x[],int high, int low)
{
    int mid,key;
    printf("Enter the Key Element");
    scanf("%d",&key);
    while(low<=high)
    {
        mid=low+(high-1)/2;
        if(x[mid]==key)
        {flag=1;}
        else if(key<x[mid])
        {high=mid-1;}
        else if(key>x[mid])
        {low=mid+1;}
    }
    if (flag==0)
        printf("Element not found \n");
    else
        printf("Element found\n");
}
