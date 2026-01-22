#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        
        // We use long long for internal calculations to prevent overflow 
        // before returning the final int result.
        return (int)(sumSubarrayMax(arr, n) - sumSubarrayMin(arr, n));
    }

private:
    long long sumSubarrayMin(vector<int>& arr, int n) {
        vector<int> left(n), right(n);
        stack<int> s;

        // Find nearest smaller to the left
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Find nearest smaller to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            // Count of subarrays where arr[i] is the minimum
            sum += (long long)(i - left[i]) * (right[i] - i) * arr[i];
        }
        return sum;
    }

    long long sumSubarrayMax(vector<int>& arr, int n) {
        vector<int> left(n), right(n);
        stack<int> s;

        // Find nearest larger to the left
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Find nearest larger to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] < arr[i]) s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            // Count of subarrays where arr[i] is the maximum
            sum += (long long)(i - left[i]) * (right[i] - i) * arr[i];
        }
        return sum;
    }
};