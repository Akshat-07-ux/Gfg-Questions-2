#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeBouquets(vector<int>& arr, int k, int m, int day) {
        int bouquets = 0, count = 0;
        for (int bloomDay : arr) {
            if (bloomDay <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0; // reset after making one bouquet
                }
            } else {
                count = 0; // reset count if bloomDay > day
            }
            if (bouquets >= m) return true; // early exit
        }
        return bouquets >= m;
    }
    
    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long totalFlowers = (long long)k * m;
        if (totalFlowers > arr.size()) return -1; // impossible
        
        int left = *min_element(arr.begin(), arr.end());
        int right = *max_element(arr.begin(), arr.end());
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(arr, k, m, mid)) {
                ans = mid;
                right = mid - 1; // try for earlier day
            } else {
                left = mid + 1; // need more days
            }
        }
        
        return ans;
    }
};
