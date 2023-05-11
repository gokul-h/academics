//Find the average run scored byba6tsman in four matches
#include<stdio.h>
int main(){
	int a,b,c,d;
	printf("Enter the runs scored by batsman in four matches:\n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	float e = (a+b+c+d)/4;
	printf("Average:-%f",e);
	return 0;
}

