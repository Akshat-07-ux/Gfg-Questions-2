#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  // base case: 0 odd numbers seen initially

        int countOdd = 0;  // cumulative count of odd numbers
        int res = 0;

        for (int num : arr) {
            if (num % 2 != 0) countOdd++;  // increment if odd

            // Check if (countOdd - k) has been seen before
            if (freq.find(countOdd - k) != freq.end()) {
                res += freq[countOdd - k];
            }

            // Record this count in the map
            freq[countOdd]++;
        }

        return res;
    }
};


