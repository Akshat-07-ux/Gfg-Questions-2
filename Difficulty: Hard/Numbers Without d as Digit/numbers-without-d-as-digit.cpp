#include <string>
#include <vector>

class Solution {
  public:
    int countWithout(int n, int d) {
        if (n <= 0) return 0;

        std::string s = std::to_string(n);
        int len = s.length();

        // Precompute powers of 9
        std::vector<int> pow9(len + 1, 1);
        for (int i = 1; i <= len; i++) {
            pow9[i] = pow9[i - 1] * 9;
        }

        if (d == 0) {
            int count = 0;

            // 1. Add all valid numbers of length shorter than `len`
            // A k-digit number with non-zero digits has 9^k possibilities
            for (int k = 1; k < len; k++) {
                count += pow9[k];
            }

            // 2. Add valid numbers of length `len` up to `n`
            bool valid_prefix = true;
            for (int i = 0; i < len; i++) {
                int current_digit = s[i] - '0';
                int remaining = len - 1 - i;

                if (current_digit == 0) {
                    valid_prefix = false;
                    break;
                }

                // Digits smaller than current_digit excluding 0 -> (current_digit - 1) options
                int options = current_digit - 1;
                count += options * pow9[remaining];
            }

            // If n itself contains no 0, include n
            if (valid_prefix) {
                count++;
            }

            return count;
        } else {
            // Standard Digit DP for d != 0
            int count = 0;
            bool contains_d = false;

            for (int i = 0; i < len; i++) {
                int current_digit = s[i] - '0';
                int remaining = len - 1 - i;

                int valid_choices = 0;
                for (int digit = 0; digit < current_digit; digit++) {
                    if (digit != d) {
                        valid_choices++;
                    }
                }

                count += valid_choices * pow9[remaining];

                if (current_digit == d) {
                    contains_d = true;
                    break;
                }
            }

            if (!contains_d) {
                count++;
            }

            // Subtract 1 to exclude 0 (since range is 1 to n)
            return count - 1;
        }
    }
};