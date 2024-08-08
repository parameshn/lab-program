#include <stdio.h>
#include <stdlib.h>
typedef struct process
{
    int ID, AT, BT, CT, TAT, WT;
} pro;
/*arrival times (AT) and burst times (BT), calculates completion time (CT), turnaround time (TAT), and waiting time (WT),*/
pro p[15];

void main()
{
    int n, tempBT[15], total_WT = 0, total_TAT = 0;
    float avg_WT = 0, avg_TAT = 0;
    printf("Enter the no of processes:\n");
    scanf("%d", &n);
    printf("Enter AT & BT\n");
    for (int i = 0; i < n; i++)
    {
        p[i].ID = (i + 1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        tempBT[i] = p[i].BT;
    }
    int minidx, minbt, completed = 0, curtime = 0;
    printf("\nGantt chart\n");
    while (completed != n)
    {
        minidx = -1;
        minbt = 9999;
        /*This inner for loop iterates through all processes to find the one with the shortest burst time (BT) 
        that is ready to execute (i.e., AT <= curtime).*/
        for (int i = 0; i < n; i++)
        {
            if (p[i].AT <= curtime && p[i].BT > 0)
            { /*The minbt and minidx variables are updated to keep track of the process with the minimum burst time
            If multiple processes have the same burst time, the one with the earliest arrival time (AT) is selected.*/
                if (p[i].BT <= minbt || (p[i].BT == minbt && p[i].AT < p[minidx].AT))
                {
                    minbt = p[i].BT;
                    minidx = i;
                }
            }
        }
        curtime++;
        if (minidx != -1)
        {
            p[minidx].BT--;
            printf("| P%d(1) %d", p[minidx].ID, curtime);
            if (p[minidx].BT == 0)
            {
                p[minidx].CT = curtime;
                p[minidx].TAT = p[minidx].CT - p[minidx].AT;
                p[minidx].WT += p[minidx].TAT - tempBT[minidx];
                total_TAT += p[minidx].TAT;
                total_WT += p[minidx].WT;
                completed++;
            }
        }
    }
    printf("|\n");
    avg_TAT = (float)total_TAT / n;
    avg_WT = (float)total_WT / n;
    // table
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i].ID, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAvg TAT = %.2f\n", avg_TAT);
    printf("Avg WT = %.2f\n", avg_WT);
}