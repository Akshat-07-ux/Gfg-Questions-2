#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(string &s, int k) {
        unordered_map<char, int> freq;

        // Step 1: Count frequencies of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Use a max-heap (priority queue) to store frequencies
        priority_queue<int> maxHeap;
        for (auto &entry : freq) {
            maxHeap.push(entry.second);
        }

        // Step 3: Remove k characters, always from the highest frequency
        while (k-- && !maxHeap.empty()) {
            int top = maxHeap.top();
            maxHeap.pop();
            top--;
            if (top > 0) {
                maxHeap.push(top);
            }
        }

        // Step 4: Calculate the final value as sum of squares of frequencies
        int result = 0;
        while (!maxHeap.empty()) {
            int f = maxHeap.top();
            maxHeap.pop();
            result += f * f;
        }

        return result;
    }
};
