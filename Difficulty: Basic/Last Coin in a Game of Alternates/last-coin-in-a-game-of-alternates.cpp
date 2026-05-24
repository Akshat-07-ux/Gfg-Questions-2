#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int coin(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        // Loop until only one coin remains
        while (left < right) {
            if (arr[left] >= arr[right]) {
                left++; // Pick the left coin
            } else {
                right--; // Pick the right coin
            }
        }
        
        // The last remaining coin
        return arr[left];
    }
};