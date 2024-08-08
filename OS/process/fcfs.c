#include <stdio.h>

typedef struct node
{
    int processid;  // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int completion; // Completion time
    int turnaround; // Turnaround time
    int waiting;    // Waiting time
    int response;   // Response time
} process;

// Function to calculate and display FCFS scheduling
void fcfs(process processes[], int n)
{
    int elapsed = 0;         // Track the time elapsed
    float avgwaiting = 0;    // Average waiting time
    float avgturnaround = 0; // Average turnaround time
    float avgresponse = 0;   // Average response time
    int totalwaiting = 0;    // Total waiting time
    int totalturnaround = 0; // Total turnaround time
    int totalresponse = 0;   // Total response time

    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++)
    {
        // Update elapsed time if the process arrival is later
        if (processes[i].arrival > elapsed)
        {
            elapsed = processes[i].arrival;
        }
        int temp = elapsed;                                                       // Temporary variable to track start time of the process
        processes[i].response = elapsed - processes[i].arrival;                   // Response time calculation
        elapsed += processes[i].burst;                                            // Update elapsed time after process burst
        processes[i].completion = elapsed;                                        // Completion time
        processes[i].turnaround = processes[i].completion - processes[i].arrival; // Turnaround time
        processes[i].waiting = processes[i].turnaround - processes[i].burst;      // Waiting time
        printf("%d\tP%d\t%d\n", temp, processes[i].processid, elapsed);           // Print Gantt chart
    }
    printf("\n");

    printf("Observation Table:\n");
    printf("PID\tAT\tBT\tCT\tTT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               processes[i].processid, processes[i].arrival,
               processes[i].burst, processes[i].completion, processes[i].turnaround,
               processes[i].waiting, processes[i].response);
        totalturnaround += processes[i].turnaround;
        totalwaiting += processes[i].waiting;
        totalresponse += processes[i].response;
    }

    avgturnaround = (float)totalturnaround / n;
    avgwaiting = (float)totalwaiting / n;
    avgresponse = (float)totalresponse / n;

    printf("\nAverage waiting time : %.2f\n", avgwaiting);
    printf("Average turnaround time : %.2f\n", avgturnaround);
    printf("Average response time : %.2f\n", avgresponse);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Array of processes
    process processes[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process %d\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &(processes[i].arrival));
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst);
        processes[i].processid = i + 1; // Set process ID
        printf("\n");
    }

    // Sort processes by arrival time (Bubble Sort)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (processes[j].arrival > processes[j + 1].arrival)
            {
                process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Call FCFS scheduling function
    fcfs(processes, n);
    return 0;
}
