#include <stdio.h>

// Function to calculate the turn around time, exit time, waiting time, avg waiting time and avg turn around time for each process
void calculateTime(int process[], int n, int arrival[], int burst[])
{
    int exit[n], turn_around[n], waiting_time[n];
    float avg_waiting_time = 0, avg_turn_around_time = 0;

    // Calculating the exit time
    exit[0] = arrival[0] + burst[0];
    for (int i = 1; i < n; i++)
        exit[i] = exit[i - 1] + burst[i];

    // Calculating the turn around time and waiting time
    for (int i = 0; i < n; i++)
    {
        turn_around[i] = exit[i] - arrival[i];
        waiting_time[i] = turn_around[i] - burst[i];
        avg_waiting_time += waiting_time[i];
        avg_turn_around_time += turn_around[i];
    }

    // Calculating the average waiting time and average turn around time
    avg_waiting_time /= n;
    avg_turn_around_time /= n;

    // Printing the turn around time, exit time, waiting time, avg waiting time and avg turn around time for each process
    printf("Process\t Arrival Time\t Burst Time\t Exit Time\t Turn Around Time\t Waiting Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", process[i], arrival[i], burst[i], exit[i], turn_around[i], waiting_time[i]);

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turn Around Time: %.2f\n", avg_turn_around_time);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n], arrival[n], burst[n];
    printf("Enter the arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        process[i] = i + 1;
        scanf("%d%d", &arrival[i], &burst[i]);
    }

    // Calculating the turn around time, exit time, waiting time, avg waiting time and avg turn around time
    calculateTime(process, n, arrival, burst);
    return 0;
}
