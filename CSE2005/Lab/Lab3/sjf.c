#include <stdio.h>

void main()
{
    int wt[5], tat[5], i, j, total = 0, pos, temp;
    float avg_wt, avg_tat;
    int n = 5; // no of processes
    int p[] = {1, 2, 3, 4, 5};
    int bt[] = {5, 9, 6, 5, 2};

    //sorting burst time in ascending order 
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
                pos = j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    //calculate waiting time
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i]; //calculate turnaround time
        printf("%d\t\t%d\t\t%d\t\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
}
