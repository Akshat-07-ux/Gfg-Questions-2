class Solution {
  public:
    // Helper function to calculate the sum of digits of a number
    long long sumOfDigits(long long val) {
        long long sum = 0;
        while (val > 0) {
            sum += val % 10;
            val /= 10;
        }
        return sum;
    }

    int getCount(long long n, long long d) {
        long long low = 1, high = n;
        long long first_idx = -1;

        // Binary search to find the smallest number 'k' such that k - S(k) >= d
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid - sumOfDigits(mid) >= d) {
                first_idx = mid;
                high = mid - 1; // Try to find an even smaller number
            } else {
                low = mid + 1;
            }
        }

        // If no such number was found, return 0
        if (first_idx == -1) {
            return 0;
        }

        // All numbers from first_idx to n satisfy the condition
        return (int)(n - first_idx + 1);
    }
};