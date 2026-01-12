#include <stdio.h>
#include <string.h>

typedef struct{
    char process_name[50];
    int bt;
    int wt;
    int tat;
} Process;

int main(){
    int n, i, j;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process p[n];

    for(i = 0; i < n; i++){
        printf("Enter process name: ");
        scanf("%s", p[i].process_name);
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
    }

    // sorting based on burst time
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(p[j].bt > p[j + 1].bt){
                // swap full structure
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    // calculating waiting time
    p[0].wt = 0;
    p[0].tat = p[0].bt;

    for(i = 1; i < n; i++){
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    // printing table
    printf("Process Name\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++){
        printf("%s\t\t%d\t\t%d\t\t%d\n", p[i].process_name, p[i].bt, p[i].wt, p[i].tat);
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

}