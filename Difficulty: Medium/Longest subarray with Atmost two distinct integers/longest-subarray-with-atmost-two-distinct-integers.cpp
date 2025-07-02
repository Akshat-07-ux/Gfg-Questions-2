#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> freq; // stores frequency of elements in current window
        int left = 0, right = 0;
        int maxLen = 0;
        
        while (right < arr.size()) {
            freq[arr[right]]++; // include current element
            // Shrink window from left if more than 2 distinct elements
            while (freq.size() > 2) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};
