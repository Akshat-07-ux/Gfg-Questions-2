class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // Check if the next value is larger — indicating a subtractive combination
            if (i + 1 < n && romanMap[s[i]] < romanMap[s[i + 1]]) {
                result += romanMap[s[i + 1]] - romanMap[s[i]];
                i++; // Skip next character as it has already been processed
            } else {
                result += romanMap[s[i]];
            }
        }

        return result;
    }
};
