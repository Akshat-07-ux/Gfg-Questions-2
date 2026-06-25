#include <vector>

class Solution {
  private:
    void generateNumbers(int n, int current_num, int last_digit, std::vector<int>& result) {
        // Base case: If the number has reached n digits, add it to the result
        if (n == 0) {
            result.push_back(current_num);
            return;
        }

        // Try appending a valid next digit
        for (int next_digit = last_digit + 1; next_digit <= 9; ++next_digit) {
            generateNumbers(n - 1, current_num * 10 + next_digit, next_digit, result);
        }
    }

  public:
    std::vector<int> increasingNumbers(int n) {
        std::vector<int> result;

        // Constraint check: No strictly increasing number can have more than 9 digits
        if (n > 9) {
            return result; 
        }

        // Special case for single-digit numbers
        if (n == 1) {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }

        // Start the backtracking process for numbers of length n
        // The first digit can range from 1 to 9
        for (int i = 1; i <= 9; ++i) {
            generateNumbers(n - 1, i, i, result);
        }

        return result;
    }
};