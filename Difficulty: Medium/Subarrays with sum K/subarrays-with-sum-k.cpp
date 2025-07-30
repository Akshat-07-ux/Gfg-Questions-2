#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0, count = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            currentSum += arr[i];

            // Case 1: If current prefix sum is equal to k
            if (currentSum == k)
                count++;

            // Case 2: If there's a prefix sum that equals currentSum - k
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            // Record the current prefix sum count
            prefixSumCount[currentSum]++;
        }
        
        return count;
    }
};
