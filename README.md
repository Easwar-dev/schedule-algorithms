# ⚡ CPU Process Scheduler Simulation

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge)

## 📖 Overview
This project is a high-performance simulation of **CPU Process Scheduling Algorithms** typically found in Operating Systems. It allows for the comparison of various scheduling strategies based on critical system performance metrics such as **Average Waiting Time (AWT)**, **Turnaround Time (TAT)**, and **CPU Utilization**.

The goal of this project is to demonstrate a deep understanding of **Operating System internals**, **Process Control Blocks (PCB)**, and **Algorithmic Efficiency**.

## 🚀 Key Features
- **Dynamic Process Generation:** Simulates realistic process arrival times and burst durations.
- **Context Switch Simulation:** Accounts for overhead during process preemption.
- **Metric Analysis:** Calculates and compares efficiency across different algorithms.

## 🧠 Algorithms Status
| Algorithm | Type | Status |
| :--- | :--- | :--- |
| **FCFS** | Non-Preemptive | ✅ Completed |
| **SJF** | Non-Preemptive | ✅ Completed |
| **Round Robin** | Preemptive | 🚧 In Progress |
| **Priority** | Preemptive | 📅 Planned |
## 📊 Complexity Analysis

- **Sorting Mechanism:** Utilized **Merge Sort** ($O(N \log N)$) to order processes by arrival time, ensuring stability for processes arriving simultaneously.
- **Priority Queue:** Implemented using a **Min-Heap** data structure to optimize the selection of the next process in SJF/SRTF, reducing selection time from $O(N)$ to $O(\log N)$.
- **Space Complexity:** Maintained at $O(N)$ where $N$ is the number of active processes in the ready queue.

## 🛠️ Installation & Usage

### Prerequisites
- GCC Compiler 

### Build Instructions
```bash
# Clone the repository
git clone https://github.com/Easwar-dev/schedule-algorithms.git

# Navigate to directory
cd schedule-algorithms/

# Compile specific algorithm (Example: FCFS)
gcc FCFS.c -o fcfs_scheduler

# Run
./fcfs_scheduler
