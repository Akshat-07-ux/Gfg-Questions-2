#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        
        // Step 1: Count frequency of each element
        for (int num : arr) {
            freq[num]++;
        }
        
        // Step 2: Move to a vector for sorting
        vector<pair<int, int>> v;  // {num, frequency}
        for (auto &it : freq) {
            v.push_back({it.first, it.second});
        }
        
        // Step 3: Sort based on frequency desc, then value desc
        sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b) {
            if (a.second == b.second)
                return a.first > b.first; // if same freq, larger num first
            return a.second > b.second;   // higher freq first
        });
        
        // Step 4: Collect top k elements
        vector<int> res;
        for (int i = 0; i < k && i < (int)v.size(); i++) {
            res.push_back(v[i].first);
        }
        
        return res;
    }
};


