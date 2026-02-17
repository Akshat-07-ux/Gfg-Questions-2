#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
    bool found = false;
    vector<int> subset1;
    vector<bool> used;

    void backtrack(vector<int>& arr, int targetSum, int targetSize, int currentSum, int currentIndex, int count) {
        if (found) return;

        // Base Case: Check if we reached the required size and sum
        if (count == targetSize) {
            if (currentSum == targetSum) {
                found = true;
                for (int i = 0; i < arr.size(); i++) {
                    if (used[i]) subset1.push_back(arr[i]);
                }
            }
            return;
        }

        // Optimization: If no elements left or index out of bounds
        if (currentIndex >= arr.size()) return;

        // Option 1: Include arr[currentIndex]
        used[currentIndex] = true;
        backtrack(arr, targetSum, targetSize, currentSum + arr[currentIndex], currentIndex + 1, count + 1);
        
        if (found) return;

        // Option 2: Exclude arr[currentIndex]
        used[currentIndex] = false;
        backtrack(arr, targetSum, targetSize, currentSum, currentIndex + 1, count);
    }

public:
    vector<vector<int>> equalPartition(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // Target size for the first subset
        int targetSize = n / 2;
        int targetSum = totalSum / 2;

        found = false;
        subset1.clear();
        used.assign(n, false);

        // Start backtracking to find the first subset
        backtrack(arr, targetSum, targetSize, 0, 0, 0);

        // Identify subset2 (elements not in subset1)
        vector<int> subset2;
        vector<bool> inS1(n, false);
        
        // Map subset1 elements back to indices to find leftovers
        // Since there might be duplicate values, we use the 'used' array from backtrack
        vector<int> s1, s2;
        for(int i = 0; i < n; i++) {
            if(used[i]) s1.push_back(arr[i]);
            else s2.push_back(arr[i]);
        }

        return {s1, s2};
    }
};