#include<stdio.h>
void insertionSort(int *arr,int size){ //O(n^2)
    int i,j,key;
    for(i=0;i<size;i++){
        key = arr[i];
        j =i;
        while(arr[j-1]>key&&j>=0){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
}
int main()
{
    // Array can be user input as well
    int i,size=10;
    int arr[10] = {5,3,9,6,1,2,7,4,8,10};
    int *arrptr = arr;
    // use insertionSort()
    insertionSort(arrptr,size);
    printf("Sorted Array\n");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

