class Solution {
  public:
    int findWays(int n) {
        // If length is odd, valid parentheses are impossible
        if (n % 2 != 0) return 0;

        int k = n / 2;  // number of pairs
        int catalan[11] = {0};

        catalan[0] = 1;

        for (int i = 1; i <= k; i++) {
            catalan[i] = 0;
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }

        return catalan[k];
    }
};
