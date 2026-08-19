#include <vector>
#include <algorithm>

class Solution {
  private:
    // Helper function to count triplets with sum <= target
    long long countTripletsLessThanOrEqual(std::vector<int>& arr, int target) {
        long long count = 0;
        int n = arr.size();

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum <= target) {
                    // If arr[i] + arr[left] + arr[right] <= target, then
                    // arr[i] + arr[left] + arr[k] <= target for all k in [left + 1, right]
                    count += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }
        return count;
    }

  public:
    int countTriplets(std::vector<int> &arr, int l, int r) {
        // Step 1: Sort the array to use two pointers
        std::sort(arr.begin(), arr.end());

        // Step 2: Use the inclusion-exclusion principle
        long long tripletsUpToR = countTripletsLessThanOrEqual(arr, r);
        long long tripletsUpToLMinus1 = countTripletsLessThanOrEqual(arr, l - 1);

        return tripletsUpToR - tripletsUpToLMinus1;
    }
};