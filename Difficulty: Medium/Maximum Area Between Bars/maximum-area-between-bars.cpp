#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            // Calculate width as the number of bars strictly between left and right
            int width = right - left - 1;
            
            // Calculate area only if there's at least one bar between them
            if (width > 0) {
                int current_height = min(height[left], height[right]);
                int current_area = current_height * width;
                max_area = max(max_area, current_area);
            }
            
            // Move the pointer pointing to the shorter bar
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};