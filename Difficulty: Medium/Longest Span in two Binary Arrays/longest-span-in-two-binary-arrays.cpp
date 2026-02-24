class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        // The maximum possible sum is n, and minimum is -n.
        // We use an array of size 2n+1 to store the first occurrence of prefix sums.
        // We offset the index by 'n' to handle negative sums.
        vector<int> firstOccurrence(2 * n + 1, -1);
        
        int prefixSum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            // Update the running difference sum
            prefixSum += (a1[i] - a2[i]);
            
            // Case 1: If prefixSum is 0, the span is from index 0 to i
            if (prefixSum == 0) {
                maxLen = i + 1;
            }
            
            // Case 2: Check if this prefixSum has been seen before
            // Map the sum range [-n, n] to [0, 2n]
            int mapIdx = prefixSum + n;
            
            if (firstOccurrence[mapIdx] != -1) {
                // If seen, calculate the length of the span
                maxLen = max(maxLen, i - firstOccurrence[mapIdx]);
            } else {
                // If not seen, store the first occurrence index
                firstOccurrence[mapIdx] = i;
            }
        }
        
        return maxLen;
    }
};