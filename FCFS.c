#include <stdio.h>

// Define a structure to keep related variables together
struct Process {
    int pid; // Process ID (P1, P2...)
    int at;  // Arrival Time
    int bt;  // Burst Time
    int ct;  // Completion Time
    int tat; // Turnaround Time
    int wt;  // Waiting Time
};

void sortProcessesByArrival(struct Process p[], int n) {
    // Simple Bubble Sort to order processes by Arrival Time
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                // Swap the entire process struct
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // 1. Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    // 2. Sort by Arrival Time (Crucial Step!)
    sortProcessesByArrival(p, n);

    // 3. Calculation
    int current_time = 0;
    
    for (int i = 0; i < n; i++) {
        // EDGE CASE: If CPU is free but process hasn't arrived yet
        if (current_time < p[i].at) {
            current_time = p[i].at; // Jump time forward to when process arrives
        }

        // Calculate Completion Time
        p[i].ct = current_time + p[i].bt;
        
        // Update Current Time -> moved to the end of this process
        current_time = p[i].ct; 

        // Calculate TAT and WT
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        
        // Safety check: Waiting time cannot be negative
        if (p[i].wt < 0) p[i].wt = 0; 
    }

    // 4. Output Table
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("-------------------------------------------------\n");
    
    float total_wt = 0, total_tat = 0;
    
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}