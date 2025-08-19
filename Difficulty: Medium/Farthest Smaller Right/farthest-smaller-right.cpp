#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffMin(n), ans(n, -1);

        // Build suffix minima
        suffMin[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffMin[i] = min(arr[i], suffMin[i+1]);
        }

        // For each element, binary search in suffix
        for (int i = 0; i < n; i++) {
            int l = i+1, r = n-1, res = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (suffMin[mid] < arr[i]) {
                    res = mid;      // valid, try farther right
                    l = mid + 1;
                } else {
                    r = mid - 1;    // move left
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};

