#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int cost(vector<int>& arr) {
        int n = arr.size();
        
        // If the array has only one element, no operations are needed.
        if (n <= 1) {
            return 0;
        }

        // Find the smallest element in the array.
        int min_val = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < min_val) {
                min_val = arr[i];
            }
        }

        // We need to perform (n - 1) operations to reduce the array to size 1.
        // Using the minimum element for every operation gives the minimum cost.
        return (n - 1) * min_val;
    }
};