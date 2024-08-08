#include <stdio.h>
#include <stdlib.h>
typedef struct process
{
    int ID, AT, BT, CT, TAT, WT, isComp;
} pro;

pro p[15];

int main() // Changed from void main to int main
{
    int n, total_WT = 0, total_TAT = 0;
    float avg_WT = 0, avg_TAT = 0;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    printf("Enter AT & BT\n");
    for (int i = 0; i < n; i++)
    {
        p[i].ID = (i + 1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].isComp = 0;
    }

    int minidx, minbt, completed = 0, curtime = 0;
    printf("\nGantt chart\n");

    while (completed != n)
    {
        minidx = -1;
        minbt = 9999;

        // Find the process with the shortest burst time that is available
        for (int i = 0; i < n; i++)
        {
            if (p[i].AT <= curtime && p[i].isComp == 0)
            {
                if (p[i].BT < minbt || (p[i].BT == minbt && p[i].AT < p[minidx].AT))
                {
                    minbt = p[i].BT;
                    minidx = i;
                }
            }
        }

        if (minidx == -1)
        {
            // No process is available to execute; increment curtime to move forward
            curtime++;
        }
        else
        {
            // Execute the process with the shortest burst time
            curtime += p[minidx].BT;
            p[minidx].CT = curtime;
            p[minidx].TAT = p[minidx].CT - p[minidx].AT;
            p[minidx].WT = p[minidx].TAT - p[minidx].BT; // Correctly calculate waiting time

            total_TAT += p[minidx].TAT;
            total_WT += p[minidx].WT;
            p[minidx].isComp = 1;
            completed++;

            printf("| P%d(%d) %d", p[minidx].ID, p[minidx].BT, p[minidx].CT);
        }
    }

    printf("|\n");

    avg_TAT = (float)total_TAT / n;
    avg_WT = (float)total_WT / n;

    // Print the table
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].ID, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }

    printf("\nAvg TAT = %.2f\n", avg_TAT);
    printf("Avg WT = %.2f\n", avg_WT);

    return 0; // Return 0 from main
}
