#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        
        // Use a prefix sum array to quickly calculate range sums
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + arr[i];
        }
        
        for (int i = 0; i < n; i++) {
            int mid = i / 2;
            
            // Sum of the left half: from index 0 to mid
            long long left_sum = pref[mid + 1] - pref[0];
            
            // Sum of the right half: from index mid to i (if even length) 
            // or from mid + 1 to i (if odd length)
            long long right_sum = pref[i + 1] - pref[mid + (i % 2 == 0 ? 0 : 1)];
            
            ans[i] = right_sum - left_sum;
        }
        
        return ans;
    }
};