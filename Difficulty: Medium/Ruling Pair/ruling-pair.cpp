#include <bits/stdc++.h>
using namespace std;

// Helper to calculate digit sum
int digitSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

class Solution {
  public:
    int RulingPair(vector<int> arr, int n) {
        unordered_map<int, pair<int,int>> mp; 
        // map[digitSum] = {largest, secondLargest}

        for (int num : arr) {
            int d = digitSum(num);
            if (mp.find(d) == mp.end()) {
                mp[d] = {num, -1}; // first number in this group
            } else {
                auto &p = mp[d];
                if (num > p.first) {
                    p.second = p.first;
                    p.first = num;
                } else if (num > p.second) {
                    p.second = num;
                }
            }
        }

        int ans = -1;
        for (auto &it : mp) {
            auto [a, b] = it.second;
            if (b != -1) ans = max(ans, a + b);
        }
        return ans;
    }
};
