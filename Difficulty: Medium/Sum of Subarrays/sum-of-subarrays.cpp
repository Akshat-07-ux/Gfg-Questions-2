class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;
        for (int i = 0; i < n; ++i) {
            totalSum += (long long)arr[i] * (i + 1) * (n - i);
        }
        return (int)totalSum;  // As guaranteed, it fits in 32-bit int
    }
};
