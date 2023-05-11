
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr,*arr2 ,i,temp;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    arr2 = (int*) malloc(num * sizeof(int));

    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    /*i=0;
    for (int j = num-1;j>=0;j--){
       arr2[j]=arr[i];
       i++; 
    }*/
    /* Write the logic to reverse the array. */
    int temp;
    for (i = 0; i < num / 2; i++) {
        temp = (int) *(arr + num - i - 1);
        *(arr + num - i - 1) = *(arr + i);
        *(arr + i) = temp;
    }
    for(i = 0; i < num; i++)
        printf("%d ", *(arr2 + i));
        
    return 0;
}
   
