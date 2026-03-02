#include <algorithm>
#include <vector>

class Solution {
  public:
    long long ValidPair(int a[], int n) {
        // Step 1: Sort the array - O(N log N)
        std::sort(a, a + n);
        
        long long count = 0;
        int left = 0;
        int right = n - 1;
        
        // Step 2: Two-pointer approach - O(N)
        while (left < right) {
            if (a[left] + a[right] > 0) {
                // If sum is > 0, all elements from 'left' to 'right-1' 
                // paired with 'right' will also be > 0.
                count += (right - left);
                
                // Move the right pointer to find pairs for the next element
                right--;
            } else {
                // Sum is <= 0, we need a larger value from the left side
                left++;
            }
        }
        
        return count;
    }
};