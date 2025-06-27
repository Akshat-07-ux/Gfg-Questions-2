class Solution {
  public:
    int getCount(int n) {
        if (n <= 0) return 0;
        
        // Keypad layout as positions:
        // 1 2 3
        // 4 5 6
        // 7 8 9
        //   0

        // Possible moves from each digit
        vector<vector<int>> moves = {
            {0, 8},       // 0
            {1, 2, 4},    // 1
            {2, 1, 3, 5}, // 2
            {3, 2, 6},    // 3
            {4, 1, 5, 7}, // 4
            {5, 2, 4, 6, 8}, // 5
            {6, 3, 5, 9}, // 6
            {7, 4, 8},    // 7
            {8, 5, 7, 9, 0}, // 8
            {9, 6, 8}     // 9
        };

        // dp[d][k] will store count of sequences of length k starting from digit d
        vector<vector<int>> dp(10, vector<int>(n + 1, 0));

        // Base case: sequences of length 1
        for (int digit = 0; digit <= 9; ++digit)
            dp[digit][1] = 1;

        // Fill dp table for lengths from 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int digit = 0; digit <= 9; ++digit) {
                for (int next : moves[digit]) {
                    dp[digit][len] += dp[next][len - 1];
                }
            }
        }

        // Sum all sequences starting from any digit
        int total = 0;
        for (int digit = 0; digit <= 9; ++digit)
            total += dp[digit][n];

        return total;
    }
};
