class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n <= 2) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            if (arr[left] < arr[right]) {
                // If current left height is less than the right, 
                // the water trapped depends on leftMax
                if (arr[left] >= leftMax) {
                    leftMax = arr[left];
                } else {
                    totalWater += leftMax - arr[left];
                }
                left++;
            } else {
                // If current right height is less than or equal to left, 
                // the water trapped depends on rightMax
                if (arr[right] >= rightMax) {
                    rightMax = arr[right];
                } else {
                    totalWater += rightMax - arr[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};