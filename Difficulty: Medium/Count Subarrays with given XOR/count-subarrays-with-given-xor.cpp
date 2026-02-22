#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        unordered_map<int, int> freq;
        int prefixXor = 0;
        long count = 0;
        
        // Base case: prefixXor = 0 occurs once
        freq[0] = 1;
        
        for(int i = 0; i < arr.size(); i++) {
            
            // Compute prefix XOR
            prefixXor ^= arr[i];
            
            // Check if there exists a prefix with XOR = prefixXor ^ k
            int required = prefixXor ^ k;
            
            if(freq.find(required) != freq.end()) {
                count += freq[required];
            }
            
            // Store current prefixXor
            freq[prefixXor]++;
        }
        
        return count;
    }
};