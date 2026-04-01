class Solution {
  public:
    int countStrings(int n) {
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return 2;

        // a[i] = number of binary strings of length i ending in 0
        // b[i] = number of binary strings of length i ending in 1
        long long a = 1; // For n=1, string "0"
        long long b = 1; // For n=1, string "1"

        for (int i = 2; i <= n; i++) {
            long long temp = a;
            a = a + b; // New strings ending in 0
            b = temp;  // New strings ending in 1 (must follow a 0)
        }

        return (int)(a + b);
    }
};