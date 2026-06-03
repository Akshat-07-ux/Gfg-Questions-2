#include <string>
#include <vector>
#include <numeric>

using namespace std;

class DSU {
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

class Solution {
public:
    string binaryPalindrome(int n, int k) {
        DSU dsu(n);
        
        // 1. Palindrome condition: symmetric positions must match
        for (int i = 0; i < n / 2; ++i) {
            dsu.unite(i, n - 1 - i);
        }
        
        // 2. Periodicity condition: positions separated by k must match
        for (int i = 0; i + k < n; ++i) {
            dsu.unite(i, i + k);
        }
        
        // Identify the component that contains index 0
        int rootZero = dsu.find(0);
        
        string result(n, '0');
        for (int i = 0; i < n; ++i) {
            if (dsu.find(i) == rootZero) {
                result[i] = '1';
            }
        }
        
        return result;
    }
};