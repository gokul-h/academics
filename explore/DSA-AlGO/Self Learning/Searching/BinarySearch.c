//Binary search
// for Ordered list skip the sort step
#include<stdio.h>
void sort(int *arr,int size){
    int i,j,temp,swapped=1;
    for(i=size-1;i>=0 && swapped;i--){
        swapped = 0;
        for(j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                //swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
    }
}
int binarySearch(int *arr,int size,int key){
    int mid,max=size,min=0;
    do{
        mid = (min+max)/2;
        if(arr[mid]>key){
            max = mid;
        }
        else if (arr[mid]<key){
            min = mid;
        }
        else if (arr[mid]==key){
            return mid+1;
        }
    }while(mid>0);
    return 0;
}
int main(){
    int i,size=20,key,ans;
    int arr[20] = {5,3,9,6,1,2,7,4,8,10,15,13,19,26,31,32,27,44,28,120};
    int *arrptr = arr;
    sort(arrptr,size);
    printf("Sorted Array\n");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the number to be searched for\n");
    scanf("%d",&key);
    ans = binarySearch(arrptr,size,key);
    if(ans){
        printf("Element found at index %d ",ans);
    }
    else{
        printf("Element not found!!!");
    }
    return 0;
}

