class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        // Sort both arrays to track events chronologically
        sort(start, start + N);
        sort(end, end + N);
        
        int laptops_needed = 0;
        int max_laptops = 0;
        
        int i = 0; // Pointer for start times
        int j = 0; // Pointer for end times
        
        while (i < N) {
            // If the next job starts before the current oldest job finishes
            if (start[i] < end[j]) {
                laptops_needed++;
                i++;
            } 
            // If a job has finished, a laptop becomes free
            else {
                laptops_needed--;
                j++;
            }
            
            // Track the maximum laptops used at any point in time
            max_laptops = max(max_laptops, laptops_needed);
        }
        
        return max_laptops;
    }
};