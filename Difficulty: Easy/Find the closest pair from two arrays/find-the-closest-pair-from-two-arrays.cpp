class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int n = arr1.size();
        int m = arr2.size();
        
        int left = 0;             // Start of arr1
        int right = m - 1;        // End of arr2
        
        int min_diff = INT_MAX;
        vector<int> result(2);
        
        while (left < n && right >= 0) {
            int current_sum = arr1[left] + arr2[right];
            int current_diff = abs(current_sum - x);
            
            // Update result if a closer pair is found
            if (current_diff < min_diff) {
                min_diff = current_diff;
                result[0] = arr1[left];
                result[1] = arr2[right];
            }
            
            // If we find an exact match, we can't get any closer
            if (current_sum == x) {
                return {arr1[left], arr2[right]};
            }
            // If sum is greater than x, move right pointer to decrease sum
            else if (current_sum > x) {
                right--;
            }
            // If sum is less than x, move left pointer to increase sum
            else {
                left++;
            }
        }
        
        return result;
    }
};