#include <vector>
using namespace std;

class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return;

        // Store the original value of the first element
        int prev = arr[0];
        
        // Update the first element
        arr[0] = arr[0] ^ arr[1];

        // Update middle elements
        for (int i = 1; i < n - 1; i++) {
            int curr_val = arr[i]; // Remember the original value before overwriting
            
            arr[i] = prev ^ arr[i + 1]; // XOR of original previous and next element
            
            prev = curr_val; // Update prev for the next element's calculation
        }

        // Update the last element using the original value of the second-to-last element
        arr[n - 1] = prev ^ arr[n - 1];
    }
};