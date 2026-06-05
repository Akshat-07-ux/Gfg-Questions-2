#include <string>

using namespace std;

class Solution {
private:
    // Helper function to check if a number is a power of 2
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

public:
    string lexicographicallySmallest(string &s, int k) {
        int n = s.length();

        // Step 1: Correct the value of k
        if (isPowerOfTwo(n)) {
            k /= 2;
        } else {
            k *= 2;
        }

        // Step 2: Check constraints for impossibility or empty result
        if (k >= n) {
            return "-1";
        }
        if (k <= 0) {
            return s;
        }

        // Step 3: Use a stack-like approach to find the smallest string
        string result = "";
        
        for (char ch : s) {
            // While the current character is smaller than the previous one
            // and we still have removals left, discard the larger character.
            while (!result.empty() && result.back() > ch && k > 0) {
                result.pop_back();
                k--;
            }
            result.push_back(ch);
        }

        // If we still have removals left (e.g., for an increasing string like "abcd")
        // remove characters from the end.
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        return result;
    }
};