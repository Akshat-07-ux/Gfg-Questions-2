class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        // nse[i] will store the index of the first element smaller than arr[i]
        // If no such element exists, we treat it as being at index n
        vector<int> nse(n, n); 
        stack<int> s;

        // Traverse from right to left to find the Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                nse[i] = s.top();
            }
            s.push(i);
        }

        int totalCount = 0;
        for (int i = 0; i < n; i++) {
            // Number of valid subarrays starting at i is (nse[i] - i)
            totalCount += (nse[i] - i);
        }

        return totalCount;
    }
};