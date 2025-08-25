#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kSmallestElements(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> temp = arr;
        
        // Step 1: Sort a copy of the array
        sort(temp.begin(), temp.end());
        
        // Step 2: Count frequency of k smallest elements
        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) {
            freq[temp[i]]++;
        }
        
        // Step 3: Traverse original array and pick elements
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (freq.find(arr[i]) != freq.end() && freq[arr[i]] > 0) {
                result.push_back(arr[i]);
                freq[arr[i]]--;
                if ((int)result.size() == k) break; // Stop once we have k elements
            }
        }
        
        return result;
    }
};
