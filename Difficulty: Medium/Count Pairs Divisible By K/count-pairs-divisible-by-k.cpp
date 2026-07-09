#include <vector>
#include <unordered_map>

class Solution {
  public:
    int countKdivPairs(std::vector<int>& arr, int k) {
        // Frequency array to store counts of remainders (0 to k-1)
        std::vector<long long> remFreq(k, 0);
        
        // Count frequencies of each remainder
        for (int num : arr) {
            int rem = num % k;
            remFreq[rem]++;
        }
        
        long long ans = 0;
        
        // 1. Pairs where both elements have remainder 0
        ans += (remFreq[0] * (remFreq[0] - 1)) / 2;
        
        // 2. Pairs with remaining complementary remainders (i and k-i)
        for (int i = 1; i <= k / 2; i++) {
            // If i is exactly equal to k - i (only happens when k is even)
            if (i == k - i) {
                ans += (remFreq[i] * (remFreq[i] - 1)) / 2;
            } else {
                ans += remFreq[i] * remFreq[k - i];
            }
        }
        
        return static_cast<int>(ans);
    }
};