#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
  public:
    string maxSum(string &s, vector<char> &a, vector<int> &b) {
        // Step 1: Map ASCII values (standard by default, overridden by a[] and b[])
        vector<int> char_value(256);
        for (int i = 0; i < 256; i++) {
            char_value[i] = i;
        }
        for (size_t i = 0; i < a.size(); i++) {
            char_value[(unsigned char)a[i]] = b[i];
        }

        // Step 2: Kadane's Algorithm to find maximum sum substring
        int max_sum = INT_MIN;
        int current_sum = 0;

        int best_start = 0, best_end = 0;
        int current_start = 0;

        for (int i = 0; i < s.length(); i++) {
            current_sum += char_value[(unsigned char)s[i]];

            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_start = current_start;
                best_end = i;
            }

            // If running sum drops below 0, reset candidate starting position
            if (current_sum < 0) {
                current_sum = 0;
                current_start = i + 1;
            }
        }

        // Return the substring with the maximum sum
        return s.substr(best_start, best_end - best_start + 1);
    }
};