class Solution {
  public:
    int maxSum(vector<int> &arr) {
        long long n = arr.size();
        long long current_sum = 0;
        long long array_total_sum = 0;

        // Calculate initial sum (S0) and the total sum of array elements
        for (int i = 0; i < n; i++) {
            array_total_sum += arr[i];
            current_sum += (long long)i * arr[i];
        }

        long long max_val = current_sum;

        // Use the recurrence relation to find sums of other rotations
        // S_j = S_{j-1} + Sum - n * arr[n-j]
        for (int j = 1; j < n; j++) {
            current_sum = current_sum + array_total_sum - n * (long long)arr[n - j];
            if (current_sum > max_val) {
                max_val = current_sum;
            }
        }

        return (int)max_val;
    }
};