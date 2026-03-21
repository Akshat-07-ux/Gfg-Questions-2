#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    // Helper function to generate a unique key for shifted strings
    string getShiftPattern(string s) {
        if (s.length() == 0) return "";
        if (s.length() == 1) return "single"; // All single chars are shifts of each other

        string pattern = "";
        for (int i = 1; i < s.length(); i++) {
            // Calculate the difference between consecutive characters
            // Adding 26 before modulo handles negative differences (e.g., 'a' to 'z')
            int diff = (s[i] - s[i-1] + 26) % 26;
            pattern += to_string(diff) + "#"; // Use a delimiter to avoid ambiguity
        }
        return pattern;
    }

    vector<vector<string>> groupShiftedString(vector<string> &arr) {
        unordered_map<string, vector<string>> groups;
        
        // Group strings by their shift pattern
        for (string &s : arr) {
            string key = getShiftPattern(s);
            groups[key].push_back(s);
        }

        // Prepare the final result
        vector<vector<string>> result;
        for (auto &pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};