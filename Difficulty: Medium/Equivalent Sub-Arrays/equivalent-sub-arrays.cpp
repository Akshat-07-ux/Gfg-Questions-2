class Solution {
  public:
    int countDistinctSubarray(int arr[], int n) {
        unordered_map<int, int> totalMap;
        
        // Step 1: Count total distinct elements in the entire array
        for (int i = 0; i < n; ++i) {
            totalMap[arr[i]]++;
        }
        int totalDistinct = totalMap.size();

        // Step 2: Sliding window
        unordered_map<int, int> windowMap;
        int count = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            windowMap[arr[end]]++;

            // Shrink window until it contains exactly totalDistinct unique elements
            while (windowMap.size() == totalDistinct) {
                // All subarrays from start to end, end+1, ..., n-1 are valid
                count += (n - end);
                
                // Shrink from left
                windowMap[arr[start]]--;
                if (windowMap[arr[start]] == 0)
                    windowMap.erase(arr[start]);
                start++;
            }
        }

        return count;
    }
};
