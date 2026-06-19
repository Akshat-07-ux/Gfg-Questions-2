#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = 1; i < n; i++) {
            // Convert 0-based index to 1-based index logic
            // If 1-based index is even (i.e., 0-based index is odd)
            if (i % 2 == 1) {
                if (arr[i] < arr[i - 1]) {
                    swap(arr[i], arr[i - 1]);
                }
            } 
            // If 1-based index is odd (i.e., 0-based index is even)
            else {
                if (arr[i] > arr[i - 1]) {
                    swap(arr[i], arr[i - 1]);
                }
            }
        }
        
        return arr;
    }
};