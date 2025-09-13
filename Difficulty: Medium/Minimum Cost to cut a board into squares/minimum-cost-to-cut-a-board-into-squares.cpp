#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort in descending order for greedy picking
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        
        int i = 0, j = 0;
        int hzSegments = 1, vtSegments = 1;  // initially 1 each
        int cost = 0;
        
        // While there are cuts remaining
        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                // Take vertical cut
                cost += x[i] * hzSegments;
                vtSegments++;
                i++;
            } else {
                // Take horizontal cut
                cost += y[j] * vtSegments;
                hzSegments++;
                j++;
            }
        }
        
        // Remaining vertical cuts
        while (i < x.size()) {
            cost += x[i] * hzSegments;
            vtSegments++;
            i++;
        }
        
        // Remaining horizontal cuts
        while (j < y.size()) {
            cost += y[j] * vtSegments;
            hzSegments++;
            j++;
        }
        
        return cost;
    }
};
