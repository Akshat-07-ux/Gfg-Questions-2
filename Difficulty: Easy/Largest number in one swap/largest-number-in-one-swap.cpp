class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.length();
        // Array to store the last seen index of each digit 0-9
        vector<int> last(10, -1);
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }

        // Traverse the string from left to right
        for (int i = 0; i < n; i++) {
            // Check digits 9 down to (current digit + 1)
            for (int d = 9; d > (s[i] - '0'); d--) {
                // If a larger digit exists later in the string
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return s; // Return after the first (and best) swap
                }
            }
        }

        return s; // If no beneficial swap is found
    }
};