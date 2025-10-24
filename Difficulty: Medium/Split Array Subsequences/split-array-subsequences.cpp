#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, int> freq, need;
        for (int num : arr) freq[num]++;

        for (int num : arr) {
            if (freq[num] == 0) continue;

            // Extend existing subsequence
            if (need[num] > 0) {
                need[num]--;
                need[num + 1]++;
                freq[num]--;
            }
            // Start a new subsequence of length >= k
            else {
                // Check next k-1 numbers
                for (int j = 0; j < k; j++) {
                    if (freq[num + j] <= 0)
                        return false;
                }
                // Use up k consecutive numbers
                for (int j = 0; j < k; j++)
                    freq[num + j]--;
                // This subsequence will now need num + k next
                need[num + k]++;
            }
        }
        return true;
    }
};
