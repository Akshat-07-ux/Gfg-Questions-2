#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findRepeating(vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: If the array has fewer elements than the range 
        // implies, there can't be duplicates under normal conditions.
        // But if the size matches the range perfectly, no elements are repeated.
        if (n == 0 || arr[n - 1] - arr[0] == n - 1) {
            return {-1, -1};
        }
        
        int low = 0;
        int high = n - 1;
        
        // Binary search to find the first position where the sequence breaks
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If the element matches its expected consecutive position,
            // the repeating element must be to the right.
            if (arr[mid] == arr[0] + mid) {
                low = mid + 1;
            } else {
                // Otherwise, the repetition happened at or before 'mid'
                high = mid;
            }
        }
        
        // 'low' now points to the first duplicate element
        int repeating_element = arr[low];
        
        // Total count of unique elements is (arr[n-1] - arr[0] + 1)
        // Frequency = total elements - unique elements + 1
        int frequency = n - (arr[n - 1] - arr[0]);
        
        return {repeating_element, frequency};
    }
};