#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <tuple> // Required for std::tuple and std::make_tuple
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        // Max heap with tuple: (sum, i, j)
        priority_queue<tuple<int, int, int>> maxHeap;
        set<pair<int, int>> used;

        // Initialize with the largest possible sum
        maxHeap.push(make_tuple(a[0] + b[0], 0, 0));
        used.insert({0, 0});

        vector<int> result;
        while (k-- && !maxHeap.empty()) {
            int sum, i, j;
            tie(sum, i, j) = maxHeap.top();
            maxHeap.pop();
            result.push_back(sum);

            // Next pair (i + 1, j)
            if (i + 1 < n && used.find({i + 1, j}) == used.end()) {
                maxHeap.push(make_tuple(a[i + 1] + b[j], i + 1, j));
                used.insert({i + 1, j});
            }

            // Next pair (i, j + 1)
            if (j + 1 < n && used.find({i, j + 1}) == used.end()) {
                maxHeap.push(make_tuple(a[i] + b[j + 1], i, j + 1));
                used.insert({i, j + 1});
            }
        }

        return result;
    }
};
