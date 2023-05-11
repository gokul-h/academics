#include<stdio.h>
int main(){
	int hour,minute;
	float amount;
	printf("Enter the hours and minutes you browsed");
	scanf("%d%d",&hour,&minute);
	if (hour>7)
	{
		printf("You have exceeded the time limit");
	}	
	else if (hour>5)
	{
		amount = 200 + (hour-5)*50;
		amount += minute*1;
	}
	else if (hour == 5)
	{
		amount = 200+ minute*1;
	}
	else if (hour<5)
	{
		amount = hour*50;
		amount += minute*1;	
	}
	printf("The final amount is %f",amount);
	return 0;
	
}
