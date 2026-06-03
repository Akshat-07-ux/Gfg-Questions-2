#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // Map to store the element as key and a list of its indices as value
        // Using an unordered_map for O(1) average lookup time.
        unordered_map<int, vector<int>> elementIndices;
        
        // Store the indices of each element in sorted order
        for (int i = 0; i < arr.size(); ++i) {
            elementIndices[arr[i]].push_back(i);
        }
        
        vector<int> result;
        result.reserve(queries.size()); // Reserve memory to optimize execution
        
        // Process each query
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int x = query[2];
            
            // If the element x doesn't exist in the array at all
            if (elementIndices.find(x) == elementIndices.end()) {
                result.push_back(0);
                continue;
            }
            
            const auto& indices = elementIndices[x];
            
            // Find the first index that is greater than r
            auto right_it = upper_bound(indices.begin(), indices.end(), r);
            
            // Find the first index that is greater than or equal to l
            auto left_it = lower_bound(indices.begin(), indices.end(), l);
            
            // The number of elements in the range [l, r] is the distance between iterators
            result.push_back(distance(left_it, right_it));
        }
        
        return result;
    }
};