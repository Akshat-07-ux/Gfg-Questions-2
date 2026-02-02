class Solution {
  public:
    void sortedMerge(vector<int>& arr1, vector<int>& arr2, vector<int>& res) {
        // 1. Sort both individual arrays
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int n = arr1.size();
        int m = arr2.size();
        int i = 0, j = 0;

        // 2. Clear res and reserve space for efficiency
        res.clear();
        res.reserve(n + m);

        // 3. Merge the two sorted arrays using two pointers
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                res.push_back(arr1[i]);
                i++;
            } else {
                res.push_back(arr2[j]);
                j++;
            }
        }

        // 4. Append remaining elements from arr1, if any
        while (i < n) {
            res.push_back(arr1[i]);
            i++;
        }

        // 5. Append remaining elements from arr2, if any
        while (j < m) {
            res.push_back(arr2[j]);
            j++;
        }
    }
};