#include <vector>
#include <algorithm>
#include <climits>

class Solution {
  public:
    int maxSubsetXOR(std::vector<int> &arr) {
        int n = arr.size();
        int index = 0; // Tracks the position for inserting basis vectors
        
        // Process bits from MSB (bit 20) down to LSB (bit 0)
        for (int bit = 20; bit >= 0; bit--) {
            int maxIdx = index;
            int maxElement = INT_MIN;
            
            // Find the element with the current bit set
            for (int j = index; j < n; j++) {
                if ((arr[j] & (1 << bit)) != 0 && arr[j] > maxElement) {
                    maxElement = arr[j];
                    maxIdx = j;
                }
            }
            
            // If no element has this bit set, move to the next bit
            if (maxElement == INT_MIN)
                continue;
                
            // Bring the chosen basis element to the 'index' position
            std::swap(arr[index], arr[maxIdx]);
            maxIdx = index;
            
            // Clear the current bit in all other elements
            for (int j = 0; j < n; j++) {
                if (j != maxIdx && (arr[j] & (1 << bit)) != 0) {
                    arr[j] ^= arr[maxIdx];
                }
            }
            
            index++;
        }
        
        // Accumulate maximum XOR value from the basis elements
        int res = 0;
        for (int i = 0; i < n; i++) {
            if ((res ^ arr[i]) > res) {
                res ^= arr[i];
            }
        }
        
        return res;
    }
};