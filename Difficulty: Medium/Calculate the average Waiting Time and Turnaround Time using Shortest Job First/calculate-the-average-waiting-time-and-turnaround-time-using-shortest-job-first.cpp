#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Structure to group process details together
struct Process {
    int id;
    int arrival;
    int burst;
};

// Comparator to sort processes initially by Arrival Time
bool compareArrival(const Process& a, const Process& b) {
    if (a.arrival == b.arrival)
        return a.burst < b.burst;
    return a.arrival < b.arrival;
}

// Comparator for the Min-Heap (Priority Queue)
struct CompareBurst {
    bool operator()(const Process& a, const Process& b) {
        if (a.burst == b.burst) {
            return a.arrival > b.arrival; // Tie-breaker: earlier arrival gets priority
        }
        return a.burst > b.burst; // Min-heap based on burst time
    }
};

class Solution {
  public:
    vector<double> averageTimes(vector<int> arrivalTime, vector<int> burstTime, int n) {
        vector<Process> proc(n);
        for (int i = 0; i < n; i++) {
            proc[i] = {i, arrivalTime[i], burstTime[i]};
        }

        // Step 1: Sort processes by arrival time
        sort(proc.begin(), proc.end(), compareArrival);

        // Step 2: Min-heap to store ready processes sorted by burst time
        priority_queue<Process, vector<Process>, CompareBurst> readyQueue;

        long long totalWaitingTime = 0;
        long long totalTurnaroundTime = 0;
        
        long long currentTime = 0;
        int i = 0; // Pointer for sorted proc array

        // Step 3: Process execution loop
        while (i < n || !readyQueue.empty()) {
            
            // If ready queue is empty, leap directly to the next arriving process's time
            if (readyQueue.empty() && currentTime < proc[i].arrival) {
                currentTime = proc[i].arrival;
            }

            // Push all processes that have arrived up to the currentTime into the heap
            while (i < n && proc[i].arrival <= currentTime) {
                readyQueue.push(proc[i]);
                i++;
            }

            // Fetch and execute the shortest job available
            Process currentJob = readyQueue.top();
            readyQueue.pop();

            long long completionTime = currentTime + currentJob.burst;
            long long turnaroundTime = completionTime - currentJob.arrival;
            long long waitingTime = turnaroundTime - currentJob.burst;

            totalTurnaroundTime += turnaroundTime;
            totalWaitingTime += waitingTime;

            // Advance time clock
            currentTime = completionTime;
        }

        double avgWaitingTime = (double)totalWaitingTime / n;
        double avgTurnaroundTime = (double)totalTurnaroundTime / n;

        return {avgWaitingTime, avgTurnaroundTime};
    }
};