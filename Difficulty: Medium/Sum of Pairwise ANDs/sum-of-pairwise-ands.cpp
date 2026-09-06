class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        long long total_sum = 0;

        // Iterate through all possible bit positions (0 to 31)
        for (int i = 0; i < 32; ++i) {
            long long count = 0;

            // Count how many numbers have the i-th bit set
            for (int num : arr) {
                if ((num >> i) & 1) {
                    count++;
                }
            }

            // If at least 2 numbers have the i-th bit set, they form pairs
            if (count >= 2) {
                long long pairs = (count * (count - 1)) / 2;
                total_sum += pairs * (1LL << i);
            }
        }

        return total_sum;
    }
};