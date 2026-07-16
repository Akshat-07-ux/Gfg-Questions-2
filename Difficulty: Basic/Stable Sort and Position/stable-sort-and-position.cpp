#include <vector>

class Solution {
  public:
    int sortedIndex(std::vector<int>& arr, int k) {
        int target = arr[k];
        int count_smaller = 0;
        int count_equal_before = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] < target) {
                count_smaller++;
            } else if (arr[i] == target && i < k) {
                count_equal_before++;
            }
        }

        return count_smaller + count_equal_before;
    }
};