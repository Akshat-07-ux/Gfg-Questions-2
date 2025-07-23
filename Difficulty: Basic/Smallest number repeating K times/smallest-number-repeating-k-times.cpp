#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
  public:
    int findDuplicate(const vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        
        // Count frequencies of each element
        for (int num : arr) {
            freq[num]++;
        }
        
        int result = INT_MAX;
        
        // Find the smallest number with frequency exactly k
        for (const auto& pair : freq) {
            if (pair.second == k) {
                result = min(result, pair.first);
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};
