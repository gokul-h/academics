#include<bits/stdc++.h>
using namespace std;

struct Process
{
	int pid; 
	int bt; 
	int priority; 
};

bool comparison(Process a, Process b)
{
	return (a.priority > b.priority);
}
void findWaitingfindTime(Process proc[], int n, int wt[])
{
	wt[0] = 0;
	for (int i = 1; i < n ; i++ )
		wt[i] = proc[i-1].bt + wt[i-1] ;
}

void findTurnAroundfindTime( Process proc[], int n, int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = proc[i].bt + wt[i];
}

void findTime(Process proc[], int n)
{
	int wt[n], tat[n];

	findWaitingfindTime(proc, n, wt);
	findTurnAroundfindTime(proc, n, wt, tat);

	cout << "\nProcesses\tBurst Time\tWaiting Time\tTurn around Time\n";
	for (int i=0; i<n; i++)
	{
		cout << proc[i].pid << "\t\t"
			<< proc[i].bt << "\t " << wt[i]
			<< "\t\t " << tat[i] <<endl;
	}
}

void priorityScheduling(Process proc[], int n)
{
	sort(proc, proc + n, comparison);

	cout<< "Order in which processes gets executed \n";
	for (int i = 0 ; i < n; i++)
		cout << proc[i].pid <<" " ;

	findTime(proc, n);
}

int main()
{
	Process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
	int n = sizeof proc / sizeof proc[0];
	priorityScheduling(proc, n);
	return 0;
}
