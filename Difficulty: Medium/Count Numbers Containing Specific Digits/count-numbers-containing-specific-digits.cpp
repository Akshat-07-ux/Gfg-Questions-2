class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        vector<bool> isTarget(10, false);
        for (int d : arr) isTarget[d] = true;

        // Total number of n-digit positive integers
        int total = 9 * pow(10, n - 1);

        // Count how many n-digit numbers have NONE of the arr[] digits
        // For that, we will use the digits NOT in arr[]
        vector<int> safeDigits;
        for (int d = 0; d <= 9; ++d) {
            if (!isTarget[d]) safeDigits.push_back(d);
        }

        if (safeDigits.empty()) return total; // all digits are from arr, so all numbers are valid

        int countInvalid = 0;
        int m = safeDigits.size();

        // For each position from left to right
        for (int i = 0; i < n; ++i) {
            // On the first digit, we can't use 0
            int choices = 0;
            for (int d : safeDigits) {
                if (i > 0 || d != 0) choices++;
            }

            if (choices == 0) return total; // can't form a valid number at all

            // Remaining positions can be filled with any safeDigits
            countInvalid = choices * pow(m, n - i - 1);
            break;
        }

        return total - countInvalid;
    }
};
