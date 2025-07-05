class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int maxSum = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            // Find the sum of two smallest elements in pair
            int sum = arr[i] + arr[i + 1];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
