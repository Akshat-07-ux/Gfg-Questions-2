#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // Convert all numbers to strings
        vector<string> nums;
        for (int x : arr) {
            nums.push_back(to_string(x));
        }

        // Custom comparator: compare by concatenation
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // Edge case: if the largest is "0", then all are zeros
        if (nums[0] == "0") return "0";

        // Build the result
        string result = "";
        for (string &s : nums) {
            result += s;
        }
        return result;
    }
};
