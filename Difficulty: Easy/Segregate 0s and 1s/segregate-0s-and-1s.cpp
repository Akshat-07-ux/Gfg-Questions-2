class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            // Move left pointer until we find a 1
            while (arr[left] == 0 && left < right) {
                left++;
            }

            // Move right pointer until we find a 0
            while (arr[right] == 1 && left < right) {
                right--;
            }

            // If left is still less than right, swap the elements
            if (left < right) {
                arr[left] = 0;
                arr[right] = 1;
                left++;
                right--;
            }
        }
    }
};