#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{

	int rem_bt[n];
	for (int i = 0; i < n; i++)
		rem_bt[i] = bt[i];

	int t = 0;

	while (1)
	{
		bool done = true;
		for (int i = 0; i < n; i++)
		{
			if (rem_bt[i] > 0)
			{
				done = false;

				if (rem_bt[i] > quantum)
				{
					t += quantum;
					rem_bt[i] -= quantum;
				}

				else
				{
					t = t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
		if (done == true)
			break;
	}
}

void findTurnAroundTime(int processes[], int n,
						int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

void findTime(int processes[], int n, int bt[], int quantum)
{
	int wt[n], tat[n];
	findWaitingTime(processes, n, bt, wt, quantum);
	findTurnAroundTime(processes, n, bt, wt, tat);
	cout << "\nProcesses\tBurst time\t"
		 << "Waiting time\tTurn around time\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "\t\t" << bt[i] << "\t\t"
			 << wt[i] << "\t\t " << tat[i] << endl;
	}
}

int main()
{
	int processes[] = {1, 2, 3};
	int n = sizeof processes / sizeof processes[0];
	int burst_time[] = {20, 12, 8};
	int quantum = 12;
	findTime(processes, n, burst_time, quantum);
	return 0;
}
