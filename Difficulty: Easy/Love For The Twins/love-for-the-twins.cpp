#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getTwinCount(int N, int Arr[]) {
        unordered_map<int,int> freq;
        
        // Count frequencies
        for(int i = 0; i < N; i++) {
            freq[Arr[i]]++;
        }
        
        int countPairs = 0;
        // Count elements that can form pairs
        for(auto &p : freq) {
            countPairs += (p.second / 2) * 2;  // each pair contributes 2 elements
        }
        
        return countPairs;
    }
};
