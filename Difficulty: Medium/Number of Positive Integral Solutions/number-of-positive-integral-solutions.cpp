class Solution {
  public:
    int countSolutions(int n, int k) {
        // If k is less than n, it's impossible for n positive integers to sum to k.
        if (k < n) {
            return 0;
        }

        // We need to calculate C(k - 1, n - 1)
        int N = k - 1;
        int R = n - 1;

        // Optimization: C(N, R) == C(N, N - R)
        if (R > N - R) {
            R = N - R;
        }

        long long ans = 1;
        for (int i = 1; i <= R; i++) {
            ans = ans * (N - i + 1) / i;
        }

        return static_cast<int>(ans);
    }
};