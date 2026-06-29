#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  private:
    void backtrack(string &s, string &current, vector<bool> &visited, vector<string> &result) {
        if (current.length() == s.length()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (visited[i]) continue;
            
            visited[i] = true;
            current.push_back(s[i]);
            
            backtrack(s, current, visited, result);
            
            current.pop_back();
            visited[i] = false;
        }
    }

  public:
    vector<string> permutation(string s) {
        vector<string> result;
        string current = "";
        vector<bool> visited(s.length(), false);
        
        // 1. Generate all N! index-based permutations
        backtrack(s, current, visited, result);
        
        // 2. Sort them lexicographically so identical strings group together perfectly
        sort(result.begin(), result.end());
        
        return result;
    }
};