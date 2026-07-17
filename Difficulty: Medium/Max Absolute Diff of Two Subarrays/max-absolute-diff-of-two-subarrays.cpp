#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();
        
        // Arrays to store max and min subarray sums from left to right
        vector<int> left_max(n), left_min(n);
        // Arrays to store max and min subarray sums from right to left
        vector<int> right_max(n), right_min(n);
        
        // Fill left_max and left_min using Kadane's algorithm
        int current_max = arr[0], max_so_far = arr[0];
        int current_min = arr[0], min_so_far = arr[0];
        left_max[0] = max_so_far;
        left_min[0] = min_so_far;
        
        for (int i = 1; i < n; i++) {
            current_max = max(arr[i], current_max + arr[i]);
            max_so_far = max(max_so_far, current_max);
            left_max[i] = max_so_far;
            
            current_min = min(arr[i], current_min + arr[i]);
            min_so_far = min(min_so_far, current_min);
            left_min[i] = min_so_far;
        }
        
        // Fill right_max and right_min going backwards
        current_max = arr[n - 1]; max_so_far = arr[n - 1];
        current_min = arr[n - 1]; min_so_far = arr[n - 1];
        right_max[n - 1] = max_so_far;
        right_min[n - 1] = min_so_far;
        
        for (int i = n - 2; i >= 0; i--) {
            current_max = max(arr[i], current_max + arr[i]);
            max_so_far = max(max_so_far, current_max);
            right_max[i] = max_so_far;
            
            current_min = min(arr[i], current_min + arr[i]);
            min_so_far = min(min_so_far, current_min);
            right_min[i] = min_so_far;
        }
        
        // Find the maximum absolute difference by splitting the array at every index i
        int max_diff = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            // Case 1: Max on left, Min on right
            int diff1 = abs(left_max[i] - right_min[i + 1]);
            // Case 2: Min on left, Max on right
            int diff2 = abs(left_min[i] - right_max[i + 1]);
            
            max_diff = max({max_diff, diff1, diff2});
        }
        
        return max_diff;
    }
};