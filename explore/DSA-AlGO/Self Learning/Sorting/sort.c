void bubblesort(int *arr,int size){
    int i,j;
    for(j=0;j<size-1;j++){
    for(i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] =  temp;
        }
    }}
}
int main()
{
    input the array
    call the function
    print the array
}
5 1 9 2 6 3   1 5 9 2 6 3   1 5 9 2 6 3  1 5 2 9 6 3

i 0