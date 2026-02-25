class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> firstIndex;
        
        int prefixSum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            // Transform values
            if(arr[i] > k)
                prefixSum += 1;
            else
                prefixSum -= 1;
            
            // If prefix sum is positive, whole array till i is valid
            if(prefixSum > 0) {
                maxLen = i + 1;
            }
            
            // Store first occurrence of prefixSum
            if(firstIndex.find(prefixSum) == firstIndex.end()) {
                firstIndex[prefixSum] = i;
            }
            
            // Check if there was a prefixSum - 1 before
            if(firstIndex.find(prefixSum - 1) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[prefixSum - 1]);
            }
        }
        
        return maxLen;
    }
};