class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        
        // Sort the array
        sort(arr.begin(), arr.end());
        
        int count = 0;
        
        // Fix the largest side (third side) and find pairs for the other two sides
        for (int k = 2; k < n; k++) {
            int left = 0, right = k - 1;
            
            // Use two pointers to find valid pairs
            while (left < right) {
                // Check if arr[left] + arr[right] > arr[k]
                if (arr[left] + arr[right] > arr[k]) {
                    // If this condition is satisfied, then all pairs 
                    // (left, right-1), (left, right-2), ..., (left, left+1)
                    // will also satisfy the triangle inequality
                    count += (right - left);
                    right--;
                } else {
                    // If sum is not greater than arr[k], move left pointer
                    left++;
                }
            }
        }
        
        return count;
    }
};