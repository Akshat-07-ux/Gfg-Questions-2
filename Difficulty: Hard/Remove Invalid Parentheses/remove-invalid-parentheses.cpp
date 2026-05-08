#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to check if a string has valid parentheses
    bool isValid(string str) {
        int count = 0;
        for (char ch : str) {
            if (ch == '(') {
                count++;
            } else if (ch == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    vector<string> validParenthesis(string &s) {
        vector<string> result;
        if (s.empty()) return {""};

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> level_valid;

            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    level_valid.insert(curr);
                    found = true;
                }

                // If we haven't found a valid string yet, keep generating next level
                if (!found) {
                    for (int j = 0; j < curr.length(); ++j) {
                        // We only remove parentheses, not letters
                        if (curr[j] != '(' && curr[j] != ')') continue;

                        string next = curr.substr(0, j) + curr.substr(j + 1);
                        if (visited.find(next) == visited.end()) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }

            if (found) {
                for (const string& str : level_valid) {
                    result.push_back(str);
                }
                break; // Minimum removals found, stop BFS
            }
        }

        // Return empty string in a vector if no valid strings are found 
        // (though "" is technically always reachable)
        if (result.empty()) return {""};

        // Sort results lexicographically as per requirements
        sort(result.begin(), result.end());
        return result;
    }
};