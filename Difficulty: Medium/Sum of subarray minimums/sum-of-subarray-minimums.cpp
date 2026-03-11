class Solution {
public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int, int>> s1, s2;

        // Find elements to the left that are greater than arr[i]
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!s1.empty() && s1.top().first > arr[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({arr[i], count});
            left[i] = count;
        }

        // Find elements to the right that are greater than or equal to arr[i]
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!s2.empty() && s2.top().first >= arr[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({arr[i], count});
            right[i] = count;
        }

        long long totalSum = 0;
        for (int i = 0; i < n; ++i) {
            // Contribution = value * (subarrays ending left) * (subarrays ending right)
            totalSum += (long long)arr[i] * left[i] * right[i];
        }

        return (int)totalSum;
    }
};