class Solution {
  public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int, int> freqMap;
        
        // Step 1: Count the frequency of each element
        for (int i = 0; i < n; i++) {
            freqMap[arr[i]]++;
        }
        
        int minFreq = INT_MAX;
        int maxElement = INT_MIN;
        
        // Step 2: Iterate through the map to find the target
        for (auto const& [val, count] : freqMap) {
            if (count < minFreq) {
                // Found a new lower frequency
                minFreq = count;
                maxElement = val;
            } else if (count == minFreq) {
                // Same frequency, keep the larger element
                if (val > maxElement) {
                    maxElement = val;
                }
            }
        }
        
        return maxElement;
    }
};