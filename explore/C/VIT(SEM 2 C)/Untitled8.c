#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num_days,average,i,sum=0,*ptr;
    printf("Enter the number of days:-");
    scanf("%d",&num_days);
    ptr = (int*) malloc(num_days * sizeof(int));
    if(ptr==NULL)
        exit(0);
    printf("Enter the values:-");
    for(i=0;i<num_days;i++)
    {
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }
    average = sum/num_days;
    printf("The average value is %d",average);
    printf("\nThe difference of values in respective days are:-\n");
    for(i=0;i<num_days;i++)
        printf("%d\n",abs(*(ptr+i)-average));
    free(ptr);
    return 0;
}

