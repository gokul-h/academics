#include<stdio.h>
int linearSearch(int *arr,int size,int key){
    int i;
    for(i=0;i<size;i++){
        if (arr[i]==key){
            return 1;
        }
        else if(arr[i]>key){
            return 0;
        }
    }
    return 0;
}
int main()
{
    // Array can be user input as well
    int i,size=10,key;
    int arr[10] = {1,2,3,4,6,7,8,9,10,15};
    printf("List:\n");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    int *arrptr = arr;
    printf("\nEnter the number to be searched for\n");
    scanf("%d",&key);
    if(linearSearch(arrptr,size,key)){
        printf("Element found!!!");
    }
    else{
        printf("Element not found!!!");
    }
    return 0;
}

