#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int minProd(vector<int>& arr) {
        int n = arr.size();

        int negCount = 0;
        int zeroCount = 0;
        int posCount = 0;

        int maxNeg = INT_MIN;
        int minPos = INT_MAX;
        int product = 1;

        for (int x : arr) {
            if (x == 0) {
                zeroCount++;
                continue;
            }
            if (x < 0) {
                negCount++;
                maxNeg = max(maxNeg, x);
            } else {
                posCount++;
                minPos = min(minPos, x);
            }
            product *= x;
        }

        // Case 1: No negative numbers
        if (negCount == 0) {
            if (zeroCount > 0) return 0;
            return minPos;
        }

        // Case 2: Even number of negative numbers
        if (negCount % 2 == 0) {
            // Exclude the negative number closest to zero to make the product negative
            product /= maxNeg;
        }

        return product;
    }
};