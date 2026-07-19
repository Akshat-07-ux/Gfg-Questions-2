#include <vector>

using namespace std;

class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        
        // left[i] stores the leftmost index such that arr[left[i]...i] is non-increasing
        vector<int> left(n);
        left[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[i - 1]) {
                left[i] = left[i - 1];
            } else {
                left[i] = i;
            }
        }
        
        // right[i] stores the rightmost index such that arr[i...right[i]] is non-decreasing
        vector<int> right(n);
        right[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1]) {
                right[i] = right[i + 1];
            } else {
                right[i] = i;
            }
        }
        
        vector<bool> result;
        result.reserve(queries.size());
        
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            
            // Check if the increasing slope from 'l' connects with 
            // the decreasing slope from 'r'
            if (right[l] >= left[r]) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        return result;
    }
};