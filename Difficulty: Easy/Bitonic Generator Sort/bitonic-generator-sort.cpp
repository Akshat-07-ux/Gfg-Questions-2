#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> bitonicGenerator(vector<int>& arr) {
        vector<int> even_placed;
        vector<int> odd_placed;
        
        // Step 1: Separate elements into even and odd indexed groups
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) {
                even_placed.push_back(arr[i]);
            } else {
                odd_placed.push_back(arr[i]);
            }
        }
        
        // Step 2: Sort even-placed numbers in increasing order
        sort(even_placed.begin(), even_placed.end());
        
        // Step 3: Sort odd-placed numbers in decreasing order
        sort(odd_placed.begin(), odd_placed.end(), greater<int>());
        
        // Step 4: Combine even-placed followed by odd-placed elements
        vector<int> result;
        result.reserve(arr.size()); // Optimize memory allocation
        
        result.insert(result.end(), even_placed.begin(), even_placed.end());
        result.insert(result.end(), odd_placed.begin(), odd_placed.end());
        
        return result;
    }
};