#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxStop(int n, int m, vector<vector<int>> &trains) {
        // Create buckets for each platform
        vector<vector<pair<int,int>>> platformTrains(m + 1);
        
        for (auto &t : trains) {
            int arr = t[0], dep = t[1], plat = t[2];
            // Skip invalid (arrival == departure)
            if (arr == dep) continue;
            platformTrains[plat].push_back({arr, dep});
        }

        int ans = 0;

        // Process each platform independently
        for (int i = 1; i <= m; i++) {
            auto &vec = platformTrains[i];
            if (vec.empty()) continue;

            // Sort by departure time
            sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first < b.first;
                return a.second < b.second;
            });

            int count = 1; 
            int lastDep = vec[0].second;

            for (int j = 1; j < (int)vec.size(); j++) {
                if (vec[j].first >= lastDep) { // can reuse platform
                    count++;
                    lastDep = vec[j].second;
                }
            }
            ans += count;
        }

        return ans;
    }
};