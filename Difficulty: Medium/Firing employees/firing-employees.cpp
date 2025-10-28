#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int firingEmployees(vector<int> &arr, int n) {
        // Build tree structure
        vector<vector<int>> tree(n + 1);
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) root = i + 1;  // Geek's rank
            else tree[arr[i]].push_back(i + 1);
        }

        // Sieve of Eratosthenes for primality check
        int limit = 2 * n + 5;
        vector<bool> isPrime(limit, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < limit; j += i)
                    isPrime[j] = false;
            }
        }

        // BFS to find number of seniors (depth)
        vector<int> depth(n + 1, 0);
        queue<int> q;
        q.push(root);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int child : tree[node]) {
                depth[child] = depth[node] + 1;
                q.push(child);
            }
        }

        // Count black-listed employees
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (i == root) continue;  // Geek not considered
            int perf = i + depth[i];
            if (isPrime[perf]) count++;
        }

        return count;
    }
};
