#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();
        // Store the difference and the original index
        // pair<difference, index>
        vector<pair<int, int>> diff(n);
        
        for (int i = 0; i < n; i++) {
            diff[i] = {abs(a[i] - b[i]), i};
        }
        
        // Sort by difference in descending order
        sort(diff.rbegin(), diff.rend());
        
        long long totalProfit = 0;
        
        for (int i = 0; i < n; i++) {
            int idx = diff[i].second;
            
            // If Machine A gives more profit and has capacity
            if (a[idx] > b[idx]) {
                if (x > 0) {
                    totalProfit += a[idx];
                    x--;
                } else {
                    totalProfit += b[idx];
                    y--;
                }
            } 
            // If Machine B gives more profit (or equal) and has capacity
            else {
                if (y > 0) {
                    totalProfit += b[idx];
                    y--;
                } else {
                    totalProfit += a[idx];
                    x--;
                }
            }
        }
        
        return (int)totalProfit;
    }
};