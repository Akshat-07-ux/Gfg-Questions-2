#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> mergeNsort(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        
        // Reserve space to optimize push_back operations
        result.reserve(arr1.size() + arr2.size());
        
        // Combine both arrays into the result vector
        result.insert(result.end(), arr1.begin(), arr1.end());
        result.insert(result.end(), arr2.begin(), arr2.end());
        
        // Sort the combined elements
        sort(result.begin(), result.end());
        
        // Remove duplicate elements
        auto last = unique(result.begin(), result.end());
        result.erase(last, result.end());
        
        return result;
    }
};