class Solution {
public:
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> result;
        if (arr.empty()) return result;
        
        string keypad[10] = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        string current = "";
        
        function<void(int)> backtrack = [&](int index) {
            if (index == arr.size()) {
                if (!current.empty()) // Only add if there’s a letter
                    result.push_back(current);
                return;
            }
            
            int digit = arr[index];
            if (digit == 0 || digit == 1) {
                backtrack(index + 1); // Skip digit but continue recursion
            } else {
                for (char ch : keypad[digit]) {
                    current.push_back(ch);
                    backtrack(index + 1);
                    current.pop_back();
                }
            }
        };
        
        backtrack(0);
        return result;
    }
};
