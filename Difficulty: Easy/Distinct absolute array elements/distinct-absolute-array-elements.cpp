#include <vector>
#include <cmath>

class Solution {
  public:
    int distinctCount(std::vector<int> &arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        int count = 0;
        
        while (left <= right) {
            // Skip duplicate elements from the left side
            while (left < right && arr[left] == arr[left + 1]) {
                left++;
            }
            // Skip duplicate elements from the right side
            while (right > left && arr[right] == arr[right - 1]) {
                right--;
            }
            
            // Get the absolute values
            long long absLeft = std::abs((long long)arr[left]);
            long long absRight = std::abs((long long)arr[right]);
            
            if (absLeft == absRight) {
                count++;
                left++;
                right--;
            } else if (absLeft > absRight) {
                count++;
                left++;
            } else {
                count++;
                right--;
            }
        }
        
        return count;
    }
};