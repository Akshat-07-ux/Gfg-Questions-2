class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
        int originalOnes = 0;
        int maxGain = 0;
        int currentGain = 0;

        for (int i = 0; i < n; i++) {
            // Count original 1s
            if (arr[i] == 1) {
                originalOnes++;
            }

            // Calculate gain for the current element
            // 0 becomes 1 (gain +1), 1 becomes 0 (gain -1)
            int val = (arr[i] == 0) ? 1 : -1;

            // Kadane's Algorithm to find max contiguous gain
            currentGain += val;
            
            if (currentGain > maxGain) {
                maxGain = currentGain;
            }
            
            if (currentGain < 0) {
                currentGain = 0;
            }
        }

        // The result is original 1s + the best possible flip improvement
        return originalOnes + maxGain;
    }
};