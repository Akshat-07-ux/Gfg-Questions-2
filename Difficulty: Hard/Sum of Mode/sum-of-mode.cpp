#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return 0;

        unordered_map<int,int> freq; // element -> count
        map<int,set<int>> bucket;    // frequency -> set of elements

        auto add = [&](int x) {
            int oldFreq = freq[x];
            if (oldFreq > 0) {
                bucket[oldFreq].erase(x);
                if (bucket[oldFreq].empty()) bucket.erase(oldFreq);
            }
            freq[x]++;
            bucket[freq[x]].insert(x);
        };

        auto remove = [&](int x) {
            int oldFreq = freq[x];
            bucket[oldFreq].erase(x);
            if (bucket[oldFreq].empty()) bucket.erase(oldFreq);
            freq[x]--;
            if (freq[x] > 0) bucket[freq[x]].insert(x);
            else freq.erase(x);
        };

        int sumModes = 0;

        // first window
        for (int i = 0; i < k; i++) add(arr[i]);

        // mode = smallest element in highest frequency bucket
        sumModes += *bucket.rbegin()->second.begin();

        // slide window
        for (int i = k; i < n; i++) {
            remove(arr[i-k]);
            add(arr[i]);
            sumModes += *bucket.rbegin()->second.begin();
        }

        return sumModes;
    }
};
