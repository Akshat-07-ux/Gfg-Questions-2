class Solution {
  public:
    int distinctSubseq(string &str) {
        const int mod = 1000000007;
        int n = str.size();
        
        // dp[i] = number of distinct subsequences of prefix length i
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;  // empty subsequence
        
        // last occurrence for each character
        vector<int> last(26, -1);
        
        for (int i = 1; i <= n; i++) {
            int ch = str[i - 1] - 'a';
            
            // double the subsequences
            dp[i] = (dp[i - 1] * 2) % mod;
            
            // if character seen before, subtract duplicates
            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch] - 1] + mod) % mod;
            }
            
            // update last occurrence
            last[ch] = i;
        }
        
        return dp[n];
    }
};
