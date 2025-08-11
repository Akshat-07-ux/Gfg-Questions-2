#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int numoffbt(long long int arr[], int n) {
        const int MOD = 1000000007;
        
        // Remove duplicates
        set<long long> unique_set(arr, arr + n);
        vector<long long> nums(unique_set.begin(), unique_set.end());
        
        unordered_map<long long, long long> dp;
        unordered_set<long long> present(nums.begin(), nums.end());
        
        long long ans = 0;
        
        for (auto x : nums) {
            dp[x] = 1;  // single node tree
            
            for (auto a : nums) {
                if (a * a > x) break;  // only check till sqrt(x)
                if (x % a == 0) {
                    long long b = x / a;
                    if (present.count(b)) {
                        if (a == b) {
                            dp[x] = (dp[x] + (dp[a] * dp[b]) % MOD) % MOD;
                        } else {
                            // left-right swap counts as different trees
                            dp[x] = (dp[x] + 2LL * (dp[a] * dp[b] % MOD)) % MOD;
                        }
                    }
                }
            }
            ans = (ans + dp[x]) % MOD;
        }
        return ans;
    }
};
