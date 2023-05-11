#include<stdio.h>
#include<string.h>
int arr_size(arr)
{
    int length = sizeof(arr)/sizeof(arr[0]);
    return length;
}
int main()
{
    char string[100];
    char unique_let[30];
    int count[30],i,j;
    scanf("%[^\n]%*c",&string);
    for(i=0;i<strlen(string);i++)
        for(j=0;j<arr_size(unique_let);j++)
        {
            if(string[i]==unique_let[j])

        }
    return 0;
}
