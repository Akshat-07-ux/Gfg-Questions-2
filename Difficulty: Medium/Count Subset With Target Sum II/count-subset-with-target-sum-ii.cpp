#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        vector<long long> leftSums;
        vector<long long> rightSums;

        // Function to generate all subset sums
        auto generateSums = [](vector<int> &nums, vector<long long> &sums) {
            int m = nums.size();
            for(int mask = 0; mask < (1 << m); mask++) {
                long long sum = 0;
                for(int i = 0; i < m; i++) {
                    if(mask & (1 << i)) sum += nums[i];
                }
                sums.push_back(sum);
            }
        };

        generateSums(left, leftSums);
        generateSums(right, rightSums);

        // Sort right sums for binary search
        sort(rightSums.begin(), rightSums.end());

        long long count = 0;

        // For each sum in left, find complement in right
        for(auto sumL : leftSums) {
            long long target = k - sumL;
            // Count number of occurrences of target in rightSums
            auto range = equal_range(rightSums.begin(), rightSums.end(), target);
            count += range.second - range.first;
        }

        return count;
    }
};


