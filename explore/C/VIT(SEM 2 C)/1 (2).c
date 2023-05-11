//An university is setting up a new lab at their premises. 
//Design an algorithm and write C code to determine the 
//approximate cost to be spent for setting up the lab. 
//Cost for setting the lab is sum of cost of computers, cost of furnitures and labour cost. 
//Use the following formulae for solving the problem:
//Cost of computer = cost of one computer * number of computers
//Cost of furniture = Number of tables * cost of one table 
//						+ number of chairs * cost of one chair
//Labour cost = number of hours worked * wages per hour
#include<stdio.h>
int main(){
	int com_num,tab_num,cha_num,work_hr;
	float com_cost,tab_cost,cha_cost,wag_hr,total_cost;
	float com_total,fur_total,lab_total;
	printf("Input the number of computers and cost of 1 computer respectively\n");
	scanf("%d%f",&com_num,&com_cost);
	printf("Input the number of tables and cost of 1 table respectively\n");
	scanf("%d%f",&tab_num,&tab_cost);
	printf("Input the number of chairs and cost of 1 chair respectively\n");
	scanf("%d%f",&cha_num,&cha_cost);
	printf("Input the number of hours worked and wage per hour respectively\n");
	scanf("%d%f",&work_hr,&wag_hr);
	com_total = com_num*com_cost;
	fur_total = tab_num*tab_cost + cha_num*cha_cost;
	lab_total = work_hr*wag_hr;
	total_cost = com_total+fur_total+lab_total;
	printf("Total Cost:-%f",total_cost);
	return 0;
}
