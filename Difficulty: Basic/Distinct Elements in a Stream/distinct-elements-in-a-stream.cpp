#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getDistinct(vector<int>& arr) {
        unordered_map<int, int> freq;
        vector<int> result;
        int distinct_count = 0;

        for (int x : arr) {
            if (x > 0) {
                freq[x]++;
                if (freq[x] == 1)
                    distinct_count++;
            } else {
                int val = -x;
                if (freq[val] > 0) {
                    freq[val]--;
                    if (freq[val] == 0)
                        distinct_count--;
                }
            }
            result.push_back(distinct_count);
        }

        return result;
    }
};
