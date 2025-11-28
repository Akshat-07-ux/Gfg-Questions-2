class Solution {
  public:
    long long int killinSpree(long long int n) {
        long long low = 0, high = 1e6, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            // sum of squares up to mid
            __int128 sum = (__int128)mid * (mid + 1) * (2 * mid + 1) / 6;

            if (sum <= n) {
                ans = mid;         // mid is valid
                low = mid + 1;     // try bigger
            } else {
                high = mid - 1;    // too big, shrink
            }
        }

        return ans;
    }
};
