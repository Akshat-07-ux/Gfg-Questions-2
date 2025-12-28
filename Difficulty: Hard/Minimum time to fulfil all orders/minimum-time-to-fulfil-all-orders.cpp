class Solution {
  public:
    int minTime(vector<int>& ranks, int n) {
        int maxRank = *max_element(ranks.begin(), ranks.end());

        long long low = 0;
        long long high = (long long)maxRank * n * (n + 1) / 2;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long donuts = 0;

            for (int r : ranks) {
                long long k = (long long)(sqrt(1 + 8LL * mid / r) - 1) / 2;
                donuts += k;
                if (donuts >= n) break;
            }

            if (donuts >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
