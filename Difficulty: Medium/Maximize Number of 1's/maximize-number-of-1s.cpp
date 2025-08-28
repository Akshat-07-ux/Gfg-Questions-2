#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, right = 0;
        int zeroCount = 0, maxLen = 0;
        
        for (right = 0; right < arr.size(); right++) {
            if (arr[right] == 0) {
                zeroCount++;
            }
            
            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
