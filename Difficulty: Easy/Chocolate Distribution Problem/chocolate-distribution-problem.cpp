#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        
        // If there are no chocolates or students
        if (m == 0 || n == 0) return 0;
        
        // Sort the array to bring closer values together
        sort(a.begin(), a.end());
        
        // If students are more than packets, though constraints say m <= n
        if (n < m) return -1;
        
        int min_diff = INT_MAX;
        
        // Find the subarray of size m with the minimum difference 
        // between its last and first elements
        for (int i = 0; i + m - 1 < n; i++) {
            int current_diff = a[i + m - 1] - a[i];
            
            if (current_diff < min_diff) {
                min_diff = current_diff;
            }
        }
        
        return min_diff;
    }
};