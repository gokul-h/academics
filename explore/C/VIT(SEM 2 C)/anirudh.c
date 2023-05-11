#include<stdio.h>

int main(){
	int b_1,b_2,b_3,b_4,avg_2;
	float avg_1;
	printf("Enter the scores");
	scanf("%d%d%d%d",&b_1,&b_2,&b_3,&b_4);
	avg_1 = (b_1+b_2+b_3+b_4)/4;
	avg_2 = (int)(avg_1);
	printf("The average is %d",avg_2);
	return 0;	
}

