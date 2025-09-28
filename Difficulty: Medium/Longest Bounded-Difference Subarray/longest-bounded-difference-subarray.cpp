#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        deque<int> minD, maxD;  // indices for min and max
        int l = 0, bestLen = 0, bestStart = 0;

        for (int r = 0; r < n; r++) {
            // Maintain max deque (decreasing)
            while (!maxD.empty() && arr[maxD.back()] <= arr[r]) {
                maxD.pop_back();
            }
            maxD.push_back(r);

            // Maintain min deque (increasing)
            while (!minD.empty() && arr[minD.back()] >= arr[r]) {
                minD.pop_back();
            }
            minD.push_back(r);

            // Shrink window if condition fails
            while (!maxD.empty() && !minD.empty() && arr[maxD.front()] - arr[minD.front()] > x) {
                if (maxD.front() == l) maxD.pop_front();
                if (minD.front() == l) minD.pop_front();
                l++;
            }

            // Update best window
            if (r - l + 1 > bestLen) {
                bestLen = r - l + 1;
                bestStart = l;
            }
        }

        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + bestLen);
    }
};
