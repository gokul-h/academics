#include <stdio.h>
#include <string.h>
int interest[2] = {0};
int turn;
void entryChecker(int pid)
{
	interest[pid] = 1;
	turn = pid;
	int k = interest[1 - pid];
	while (k == 1 && turn == pid)
		;
}
void exitSetter(int pid)
{
	interest[pid] = 0;
}
void processDoer(int i, int a)
{
	int str;
	entryChecker(i);
	printf("Process P%d is running\n", i);
	printf("Do you want to make contact switching? Press 1 for yes else no: \n");
	scanf("%d", &str);
	if (str == 1)
	{
		printf("\nProcess P2 is running\n");
		printf("Process P2 completed\n");
		printf("Process P1 is running\n");
		printf("Process P1 is completed\n");
	}
	else
	{
		printf("Process P1 completed\n");
		printf("Process P2 is running\n");
		printf("Process P2 is completed\n");
	}

	exitSetter(i);
	printf("\n");
}
int main()
{
	int pid, n, r;
	printf("Enter the number of process : \n");
	scanf("%d", &n);
	printf("Initialize turn value : \n");
	scanf("%d", &turn);
	printf("Which process you want to run : \n");
	scanf("%d", &r);
	processDoer(r, turn);
	return 0;
}
