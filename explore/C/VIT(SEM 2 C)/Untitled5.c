#include<stdio.h>
#include<string.h>
int main()
{
    // Take the input number as a string
    char num[10];
    scanf("%s",num);
    int length = strlen(num),flag=0,i;
    for(i=1;i<=length;i++)
    {
    	if(i%2==0)
		    if(num[i-1]%2!=0)
		    {
		    	flag = 1;
			}	   
	    else
    	{
    	 	if(num[i-1]%2==0)
		    {
			   flag = 1;
			}
		}
	}
	if (flag==0)
	{
	printf("SAFE Number");	
	}
	   
    else
  	{
  		printf("NOT SAFE Number");	
 }	
    return 0;
}
