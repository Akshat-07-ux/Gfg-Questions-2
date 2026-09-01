class Solution {
  public:
    int palindromicStrings(int n, int k) {
        long long MOD = 1e9 + 7;
        long long total_count = 0;

        for (int L = 1; L <= n; ++L) {
            int m = L / 2;
            int num_distinct_needed = (L % 2 == 0) ? m : m + 1;

            // If we need more distinct characters than available in alphabet k, 
            // no valid string can be formed for this length.
            if (num_distinct_needed > k) {
                continue;
            }

            // Compute P(k, num_distinct_needed) = k * (k-1) * ... * (k - num_distinct_needed + 1)
            long long ways = 1;
            for (int i = 0; i < num_distinct_needed; ++i) {
                ways = (ways * (k - i)) % MOD;
            }

            total_count = (total_count + ways) % MOD;
        }

        return total_count;
    }
};