class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // Difference array initialized to size n + 1
        vector<long long> diff(n + 1, 0);
        int m = a.size();

        // Step 1: Mark boundary updates for all operations
        for (int i = 0; i < m; i++) {
            diff[a[i]] += k[i];
            diff[b[i] + 1] -= k[i];
        }

        // Step 2: Compute prefix sums and track maximum value
        long long current_val = 0;
        long long max_val = 0;

        for (int i = 0; i < n; i++) {
            current_val += diff[i];
            max_val = max(max_val, current_val);
        }

        return max_val;
    }
};