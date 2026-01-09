#include <stdio.h>
#include <stdlib.h>

int main() {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg = 0.0f, tatavg = 0.0f;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;  // First process has 0 waiting time
    tat[0] = bt[0];  // Turnaround time of the first process is its burst time

    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  // Waiting time for subsequent processes
        tat[i] = tat[i - 1] + bt[i];  // Turnaround time for subsequent processes
        wtavg += wt[i];  // Add to the total waiting time
        tatavg += tat[i];  // Add to the total turnaround time
    }

    // Print the results
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time -- %.2f", wtavg / n);
    printf("\nAverage Turnaround Time -- %.2f", tatavg / n);

    return 0;
}
