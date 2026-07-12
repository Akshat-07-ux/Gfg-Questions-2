#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        long long max_val = 0;
        for (int x : arr) {
            if (x > max_val) max_val = x;
        }
        
        // frequency array to count sellers with 'i' tickets
        vector<long long> freq(max_val + 1, 0);
        for (int x : arr) {
            freq[x]++;
        }
        
        long long total_earning = 0;
        long long MOD = 1e9 + 7;
        
        // Start selling from the highest ticket price downwards
        for (long long p = max_val; p > 0 && k > 0; p--) {
            if (freq[p] == 0) continue;
            
            if (k >= freq[p]) {
                // Sell all available tickets at current price 'p'
                total_earning = (total_earning + (freq[p] * p) % MOD) % MOD;
                k -= freq[p];
                // These sellers now have 'p - 1' tickets left
                freq[p - 1] += freq[p];
            } else {
                // We can only sell 'k' tickets at current price 'p'
                total_earning = (total_earning + (k * p) % MOD) % MOD;
                k = 0;
            }
        }
        
        return total_earning;
    }
};