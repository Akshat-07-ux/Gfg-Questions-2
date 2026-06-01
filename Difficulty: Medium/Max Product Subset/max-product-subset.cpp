#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: If there's only one element, that's our maximum product.
        if (n == 1) {
            return arr[0];
        }

        long long max_neg = INT_MIN; // To track the largest (closest to 0) negative number
        int count_neg = 0;
        int count_zero = 0;
        int count_pos = 0;
        long long prod = 1;
        long long MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                count_zero++;
                continue;
            }
            if (arr[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, (long long)arr[i]);
            } else {
                count_pos++;
            }
            
            // Multiply the element (taking absolute value for negatives initially 
            // to safely apply modulo, or handling signs carefully)
            prod = (prod * abs(arr[i])) % MOD;
        }

        // Case 1: All elements are zeros
        if (count_zero == n) {
            return 0;
        }

        // Case 2: There are negative numbers and their count is odd
        if (count_neg % 2 != 0) {
            // Exceptional sub-case: If there is only 1 negative number, no positive numbers,
            // and the rest are zeros (e.g., [-3, 0, 0]), the max product we can achieve is 0.
            if (count_neg == 1 && count_pos == 0 && count_zero > 0) {
                return 0;
            }
            
            // Otherwise, exclude the maximum (closest to 0) negative number.
            // To exclude it mathematically under modulo, we multiply by its modular inverse.
            // Alternatively, since we used abs(), we just divide out abs(max_neg).
            // Using standard modular inverse for division under modulo:
            long long inv = power(abs(max_neg), MOD - 2, MOD);
            prod = (prod * inv) % MOD;
        }

        return prod;
    }

  private:
    // Helper function to calculate (base^exp) % mod
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
};