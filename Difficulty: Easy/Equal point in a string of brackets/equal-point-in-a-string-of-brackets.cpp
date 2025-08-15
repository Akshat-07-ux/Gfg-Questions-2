class Solution {
public:
    int findIndex(string& str) {
        int n = str.size();
        vector<int> closeCount(n + 1, 0); // closeCount[i] = count of ')' from i to end

        // Step 1: Fill closeCount from right to left
        for (int i = n - 1; i >= 0; i--) {
            closeCount[i] = closeCount[i + 1] + (str[i] == ')' ? 1 : 0);
        }

        int openCount = 0;

        // Step 2: Traverse and check condition
        for (int i = 0; i <= n; i++) {
            if (openCount == closeCount[i]) {
                return i; // Found equal point
            }
            if (i < n && str[i] == '(') {
                openCount++;
            }
        }
        return -1; // In case no equal point exists (though problem guarantees one)
    }
};
