#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if a starting value 'x' is valid
    bool isValid(int x, const vector<int>& arr) {
        long long current_x = x;
        for (int num : arr) {
            current_x = 2 * current_x - num;
            
            // If current_x drops below 0, this 'x' is invalid
            if (current_x < 0) {
                return false;
            }
            // Optimization: If current_x grows very large, it will definitely stay positive
            if (current_x > 1e5) {
                return true;
            }
        }
        return true;
    }

public:
    int find(vector<int>& arr) {
        int low = 0;
        int high = 0;
        for (int num : arr) {
            high = max(high, num);
        }

        int ans = high;

        // Binary search for the smallest valid x
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(mid, arr)) {
                ans = mid;        // Record potential answer
                high = mid - 1;   // Try to find a smaller valid x
            } else {
                low = mid + 1;    // Increase x since mid was too small
            }
        }

        return ans;
    }
};