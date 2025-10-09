class Solution {
  public:
    string makeEven(string s) {
        int n = s.size();
        int lastDigit = s[n - 1] - '0';
        int swapIdx = -1;  // index to swap with last digit

        // Traverse left to right to find the candidate even digit
        for (int i = 0; i < n - 1; i++) {
            int d = s[i] - '0';
            if (d % 2 == 0) {  // even digit
                // If this even digit is smaller than the last digit, swap immediately
                if (d < lastDigit) {
                    swapIdx = i;
                    break;
                }
                // Else keep updating with the latest even index
                swapIdx = i;
            }
        }

        // If no even digit found, return original string
        if (swapIdx == -1)
            return s;

        // Perform the swap
        swap(s[swapIdx], s[n - 1]);
        return s;
    }
};
