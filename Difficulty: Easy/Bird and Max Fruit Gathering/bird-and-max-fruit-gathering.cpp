#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
  public:
    int maxFruits(std::vector<int>& arr, int m) {
        int n = arr.size();

        // If m >= n, the bird can visit every tree in the circle
        if (m >= n) {
            long long total_sum = 0;
            for (int val : arr) {
                total_sum += val;
            }
            return total_sum;
        }

        // Calculate the sum of the first window of size m
        long long current_sum = 0;
        for (int i = 0; i < m; i++) {
            current_sum += arr[i];
        }

        long long max_sum = current_sum;

        // Slide the window across the circular array
        for (int i = 1; i < n; i++) {
            // Subtract the element leaving the window and add the new element
            // Using modulo % n handles the circular boundary seamlessly
            current_sum = current_sum - arr[i - 1] + arr[(i + m - 1) % n];
            max_sum = std::max(max_sum, current_sum);
        }

        return max_sum;
    }
};