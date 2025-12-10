class Solution {
public:
    int solveWordWrap(vector<int> arr, int k) {
        int n = arr.size();
        const int INF = 1e9;
        vector<int> dp(n + 1, 0);  

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INF;
            int currLen = 0;  // sum of word lengths

            for (int j = i; j < n; j++) {
                currLen += arr[j];
                int totalUsed = currLen + (j - i);  // spaces between words

                if (totalUsed > k) break;

                int extraSpaces = k - totalUsed;

                int cost;
                if (j == n - 1)
                    cost = 0; 
                else
                    cost = extraSpaces * extraSpaces;

                dp[i] = min(dp[i], cost + dp[j + 1]);
            }
        }

        return dp[0];
    }
};
