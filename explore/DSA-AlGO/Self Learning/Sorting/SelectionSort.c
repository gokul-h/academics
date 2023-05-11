#include<stdio.h>
void selectionSort(int *arr,int size){ //O(n^2)
    int i,j,min,temp;
    for(i=0;i<size-1;i++){
        min = i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    // Array can be user input as well
    int i,size=10;
    int arr[10] = {5,3,9,6,1,2,7,4,8,10};
    int *arrptr = arr;
    // use selectionSort()
    selectionSort(arrptr,size);
    printf("Sorted Array\n");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

