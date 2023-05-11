#include <stdio.h>

int main()
{
    int processID[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(processID) / sizeof(processID[0]); //Find number of processes
    int burst_time[] = {5, 3, 2, 4, 2, 3, 1, 5, 3, 4};
    int exit_time[10], t = 0;
    // Function to calculate exit time
    for (int i = 0; i < n; i++)
    {
        // exit time of process = sum of burst time of all previous processes
        t = t + burst_time[i];
        exit_time[i] = t;
    }
    printf("ProcessID\tBurst time\tExit time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\n", processID[i], burst_time[i], exit_time[i]);
    }
    return 0;
}
