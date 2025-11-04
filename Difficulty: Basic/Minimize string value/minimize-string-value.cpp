#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(string S, int K) {
        // Step 1: Count frequency of each character
        vector<int> freq(26, 0);
        for (char c : S) freq[c - 'a']++;

        // Step 2: Use a max heap to always remove from the most frequent char
        priority_queue<int> pq;
        for (int f : freq)
            if (f > 0)
                pq.push(f);

        // Step 3: Remove K characters, one at a time from the highest frequency
        while (K > 0 && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            top--;
            K--;
            if (top > 0)
                pq.push(top);
        }

        // Step 4: Compute the final value (sum of squares of remaining frequencies)
        int result = 0;
        while (!pq.empty()) {
            int f = pq.top();
            pq.pop();
            result += f * f;
        }

        return result;
    }
};

