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
