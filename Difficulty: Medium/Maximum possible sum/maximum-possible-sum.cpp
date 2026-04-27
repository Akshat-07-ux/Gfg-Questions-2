#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long int returnMaxSum(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        unordered_set<int> uniqueElements;
        long int maxSum = 0;
        long int currentSum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // If arr1[right] is already in the set, it's a duplicate.
            // Shrink the window from the left until the duplicate is removed.
            while (uniqueElements.find(arr1[right]) != uniqueElements.end()) {
                currentSum -= arr2[left];
                uniqueElements.erase(arr1[left]);
                left++;
            }

            // Add the current element to the window
            uniqueElements.insert(arr1[right]);
            currentSum += arr2[right];

            // Update the global maximum sum
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};