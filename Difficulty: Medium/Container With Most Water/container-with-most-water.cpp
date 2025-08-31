#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int maxArea = 0;

        while (l < r) {
            int height = min(arr[l], arr[r]);
            int width = r - l;
            int area = height * width;
            maxArea = max(maxArea, area);

            // Move the pointer pointing to the smaller height
            if (arr[l] < arr[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxArea;
    }
};
