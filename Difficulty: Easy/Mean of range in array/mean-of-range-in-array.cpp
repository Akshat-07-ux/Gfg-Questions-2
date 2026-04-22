class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        // Use long long for prefix sums to prevent overflow
        vector<long long> pref(n + 1, 0);
        
        // Step 1: Precompute prefix sums
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + arr[i];
        }
        
        vector<int> results;
        results.reserve(queries.size()); // Optimization for memory allocation
        
        // Step 2: Process each query
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            // Calculate sum in range [l, r]
            long long rangeSum = pref[r + 1] - pref[l];
            
            // Calculate number of elements
            int count = r - l + 1;
            
            // Calculate floor of mean (integer division in C++ performs floor for positive numbers)
            results.push_back(rangeSum / count);
        }
        
        return results;
    }
};