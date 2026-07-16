#include <vector>
#include <numeric>

class Solution {
  private:
    int memo[10][82]; // dp table to store state: memo[current_digit_index][remaining_sum]

    int countWaysRecursive(int digits_left, int current_sum) {
        // If remaining sum becomes negative, this path is invalid
        if (current_sum < 0) return 0;
        
        // Base case: all digits are placed
        if (digits_left == 0) {
            return current_sum == 0 ? 1 : 0;
        }

        // Return cached result if already calculated
        if (memo[digits_left][current_sum] != -1) {
            return memo[digits_left][current_sum];
        }

        int ans = 0;
        // Loop through all possible choices for the current digit (0 to 9)
        for (int i = 0; i <= 9; i++) {
            ans += countWaysRecursive(digits_left - 1, current_sum - i);
        }

        return memo[digits_left][current_sum] = ans;
    }

  public:
    int countWays(int n, int sum) {
        // Impossible edge cases (e.g., maximum possible sum for n digits is 9 * n)
        if (sum < 1 || sum > 9 * n) {
            return -1;
        }

        // Initialize memoization table with -1
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                memo[i][j] = -1;
            }
        }

        int totalWays = 0;
        // The first digit cannot be 0, so it ranges from 1 to 9
        for (int i = 1; i <= 9; i++) {
            totalWays += countWaysRecursive(n - 1, sum - i);
        }

        return totalWays == 0 ? -1 : totalWays;
    }
};