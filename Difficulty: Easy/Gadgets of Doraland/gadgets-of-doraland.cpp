#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> TopK(vector<int>& array, int k) {
        unordered_map<int,int> freq;
        
        // Step 1: Count frequency
        for (int id : array) {
            freq[id]++;
        }
        
        // Step 2: Put (D-id, frequency) in a vector
        vector<pair<int,int>> v;
        for (auto &it : freq) {
            v.push_back({it.first, it.second});
        }
        
        // Step 3: Sort by frequency desc, then D-id desc
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if (a.second == b.second) 
                return a.first > b.first;  // higher D-id first
            return a.second > b.second;    // higher frequency first
        });
        
        // Step 4: Pick top k
        vector<int> ans;
        for (int i = 0; i < k && i < (int)v.size(); i++) {
            ans.push_back(v[i].first);
        }
        
        return ans;
    }
};
