# 🛡️ CPU Scheduling Algorithms Simulation

## Overview
This repository contains low-level C implementations of various **CPU Scheduling Algorithms**. 

Understanding how an Operating System creates, schedules, and manages processes is fundamental to **Systems Programming** and **Offensive Security**. This project simulates the internal logic of the OS kernel's short-term scheduler.

## 🚀 Algorithms Implemented

| Algorithm | Status | Description |
| :--- | :--- | :--- |
| **FCFS** (First Come First Serve) | ✅ Completed | Non-preemptive. Processes are executed in the exact order of arrival. |
| **SJF** (Shortest Job First) | ⏳ Planned | Non-preemptive. Selects the process with the smallest burst time. |
| **Round Robin** | ⏳ Planned | Preemptive. Uses a Time Quantum to switch context between processes. |
| **Priority Scheduling** | ⏳ Planned | Preemptive/Non-preemptive. Based on assigned priority values. |

## 🛠️ Technical Implementation Details

All simulations utilize a custom `struct Process` to manage Process Control Block (PCB) data:

```c
struct Process {
    int pid; // Process ID
    int at;  // Arrival Time
    int bt;  // Burst Time
    int ct;  // Completion Time
    int tat; // Turnaround Time
    int wt;  // Waiting Time
};
