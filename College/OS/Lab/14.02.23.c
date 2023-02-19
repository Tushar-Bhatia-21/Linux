//SJF
#include <stdio.h>

// Function to calculate the turn around time, exit time, waiting time, avg waiting time and avg turn around time for each process
void calculateTime(int process[], int n, int arrival[], int burst[])
{
    int exit[n], turn_around[n], waiting_time[n];
    float avg_waiting_time = 0, avg_turn_around_time = 0;

 int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < arrival[i]) {
            current_time = arrival[i];
        }
        waiting_time[i] = current_time - arrival[i];
        exit[i] = current_time + burst[i];
        turn_around[i] = exit[i] - arrival[i];
        current_time = exit[i];
        avg_waiting_time += waiting_time[i];
        avg_turn_around_time += turn_around[i];
    }
    // Calculating the average waiting time and average turn around time
    avg_waiting_time /= n;
    avg_turn_around_time /= n;

    // Printing the turn around time, exit time, waiting time, avg waiting time and avg turn around time for each process
    printf("\nProcess\t Arrival Time\t Burst Time\t Exit Time\t Turn Around Time\t Waiting Time\n");
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
        printf("\nEnter the arrival time: ");
        scanf("%d", &arrival[i]);
        printf("\nEnter the burst time: ");
        scanf("%d",&burst[i]);
    
    }

//SORTING ARRIVAL AND BURST TIME
    int temp;
    for(int i=0;i<n;i++)
    {   
        for(int j=i+1;j<n;j++)
        {
            if(arrival[i]>arrival[j] || arrival[i]==arrival[j] && burst[i]>burst[j])
            {
                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
                temp=arrival[i];
                arrival[i]=arrival[j];
                arrival[j]=temp;
                temp=process[i];
                process[i]=process[j];
                process[j]=temp;
            }
        }
    }


    // Calculating the turn around time, exit time, waiting time, avg waiting time and avg turn around time
    calculateTime(process, n, arrival, burst);
    return 0;
}


//SRTF
#include <stdio.h>

int main() {
    int n, time = 0, shortest_time, current_process, exit_time;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    //Process Input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n], arrival_time[n], burst_time[n], remaining_time[n], completed[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        pid[i] = i + 1;
        remaining_time[i] = burst_time[i];
    }
// SRTF function to calculate avg wait time and avg turn around time
    int num_completed = 0; // It keeps  the track of the number of processess completed
    while (num_completed < n) {
        shortest_time = -1;
        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= time && remaining_time[i] > 0) {
                if (shortest_time == -1 || remaining_time[i] < remaining_time[current_process]) {
                    current_process = i;
                    shortest_time = remaining_time[i];
                }
            }
        }
        remaining_time[current_process]--;
        if (remaining_time[current_process] == 0) {
            completed[current_process] = time + 1;
            num_completed++;
            avg_wait_time += completed[current_process] - arrival_time[current_process] - burst_time[current_process];
            avg_turnaround_time += completed[current_process] - arrival_time[current_process];
        }
        time++;
    }
    //Printing the PID, Arrival time, Burst time, Exit time, Waiting time and Turnaround time
    printf("PID\tArrival Time\tBurst Time\tExit Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], arrival_time[i], burst_time[i], completed[i],
               completed[i] - arrival_time[i] - burst_time[i], completed[i] - arrival_time[i]);
    }
    printf("Average waiting time: %.2f\n", avg_wait_time / n);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time / n);
    return 0;
}

