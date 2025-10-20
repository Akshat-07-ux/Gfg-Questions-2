#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countNumBST(int n) {
        if (n <= 1) return 1;
        static map<int, int> memo;
        if (memo.count(n)) return memo[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += countNumBST(i) * countNumBST(n - i - 1);
        }
        return memo[n] = count;
    }

    vector<int> countBSTs(vector<int>& arr) {
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            int left = 0, right = 0;

            // Count how many elements are smaller and greater than arr[i]
            for (int j = 0; j < arr.size(); j++) {
                if (arr[j] < arr[i]) left++;
                else if (arr[j] > arr[i]) right++;
            }

            int totalBSTs = countNumBST(left) * countNumBST(right);
            ans.push_back(totalBSTs);
        }

        return ans;
    }
};
