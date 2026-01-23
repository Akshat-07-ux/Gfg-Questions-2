#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> left_boundary(n, -1);
        vector<int> right_boundary(n, n);
        stack<int> s;

        // Find nearest element to the left that is >= arr[i]
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                left_boundary[i] = s.top();
            }
            s.push(i);
        }

        // Clear stack for the next pass
        while(!s.empty()) s.pop();

        // Find nearest element to the right that is >= arr[i]
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                right_boundary[i] = s.top();
            }
            s.push(i);
        }

        int max_seen = 0;
        for (int i = 0; i < n; i++) {
            // The range of people seen is (left_boundary[i] + 1) to (right_boundary[i] - 1)
            // The count is: (right_boundary - 1) - (left_boundary + 1) + 1
            int visible_count = right_boundary[i] - left_boundary[i] - 1;
            max_seen = max(max_seen, visible_count);
        }

        return max_seen;
    }
};