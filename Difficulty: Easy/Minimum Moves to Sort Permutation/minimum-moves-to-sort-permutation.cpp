#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();
        // dp[x] stores the length of the sequence ending at x
        vector<int> dp(n + 1, 0);
        int maxLen = 0;

        for (int x : arr) {
            dp[x] = dp[x - 1] + 1;
            maxLen = max(maxLen, dp[x]);
        }

        return n - maxLen;
    }
};