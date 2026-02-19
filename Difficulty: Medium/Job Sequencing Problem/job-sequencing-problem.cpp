/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution {
  public:
    // Custom comparator to sort jobs based on profit in descending order
    static bool comparison(Job a, Job b) {
        return (a.profit > b.profit);
    }

    vector<int> JobScheduling(Job arr[], int n) {
        // 1. Sort all jobs according to decreasing order of profit
        sort(arr, arr + n, comparison);

        // 2. Find the maximum deadline to define our time slots
        int max_deadline = 0;
        for (int i = 0; i < n; i++) {
            max_deadline = max(max_deadline, arr[i].dead);
        }

        // 3. Initialize a slot array to keep track of free time slots
        // We use max_deadline + 1 because deadlines are 1-based
        vector<int> slot(max_deadline + 1, -1);

        int countJobs = 0, maxProfit = 0;

        // 4. Iterate through all given jobs
        for (int i = 0; i < n; i++) {
            // Try to schedule this job from its deadline backwards
            for (int j = arr[i].dead; j > 0; j--) {
                // If a free slot is found
                if (slot[j] == -1) {
                    slot[j] = arr[i].id; // Mark slot as filled
                    countJobs++;
                    maxProfit += arr[i].profit;
                    break; 
                }
            }
        }

        return {countJobs, maxProfit};
    }
};