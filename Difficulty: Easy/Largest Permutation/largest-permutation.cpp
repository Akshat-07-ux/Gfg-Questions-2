#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> KswapPermutation(vector<int>& arr, int k) {
        int n = arr.size();
        // pos[val] will store the index of value 'val' in arr
        // Since values are 1 to n, we use size n + 1
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }

        for (int i = 0; i < n && k > 0; i++) {
            // The largest possible value that should be at index i
            int expectedValue = n - i;

            // If the current element is not the expected largest value
            if (arr[i] != expectedValue) {
                int currValue = arr[i];
                int targetIdx = pos[expectedValue];

                // Swap in the original array
                swap(arr[i], arr[targetIdx]);

                // Update positions in the pos array
                pos[currValue] = targetIdx;
                pos[expectedValue] = i;

                // Decrement the number of allowed swaps
                k--;
            }
        }
        return arr;
    }
};