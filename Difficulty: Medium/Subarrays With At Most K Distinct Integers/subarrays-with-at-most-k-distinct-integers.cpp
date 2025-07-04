#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        int left = 0, right = 0;
        int result = 0;
        unordered_map<int, int> freq;

        for (right = 0; right < n; ++right) {
            // Add current element to frequency map
            if (freq[arr[right]] == 0) {
                k--;
            }
            freq[arr[right]]++;

            // Shrink window from left if we have more than k distinct numbers
            while (k < 0) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    k++;
                }
                left++;
            }

            // All subarrays ending at 'right' and starting from any index from 'left' to 'right' are valid
            result += right - left + 1;
        }

        return result;
    }

    int subarraysWithAtMostKDistinct(vector<int> &arr, int k) {
        return countAtMostK(arr, k);
    }
};
