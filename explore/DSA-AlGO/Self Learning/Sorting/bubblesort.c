//Bubble Sort Algorithm
#include<stdio.h>
void bubbleSort(int *arr,int size){  // O(n^2)
    int i,j,temp;
    for(i=0;i<size;i++){ // No of times logic runs
        for(j=0;j<size-i-1;j++){ // Comparing adjacent elements
            // size-i-1 (-i save n number of execution since by logic after each iteration last didgit is sorted)
            if(arr[j]>arr[j+1]){
                //swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void bubbleSortImproved(int *arr,int size){ //O(n)
    int i,j,temp,swapped=1;
    //Swapped variable stops Execution if in one pass no swapping occurs
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
int main()
{
    // Array can be user input as well
    int i,size=10;
    int arr[10] = {5,3,9,6,1,2,7,4,8,10};
    int *arrptr = arr;
    // use bubbleSort() / bubbleSortImproved()
    bubbleSortImproved(arrptr,size);
    printf("Sorted Array\n");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
// arrptr - adress
// *arrptr - value
