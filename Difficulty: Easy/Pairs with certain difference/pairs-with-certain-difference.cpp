#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < 2) return 0;

        // Sort the array in descending order to prioritize larger elements
        sort(arr.begin(), arr.end(), greater<int>());

        int max_sum = 0;
        int i = 0;

        // Traverse the array and look for pairs
        while (i < n - 1) {
            // Check if the current adjacent pair satisfies the condition
            if (arr[i] - arr[i + 1] < k) {
                max_sum += arr[i] + arr[i + 1];
                i += 2; // Move past both elements since pairs must be disjoint
            } else {
                i++;    // Skip the current element and try with the next one
            }
        }

        return max_sum;
    }
};