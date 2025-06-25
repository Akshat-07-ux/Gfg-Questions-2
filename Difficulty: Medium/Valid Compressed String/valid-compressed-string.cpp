// User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i = 0, j = 0;
        int n = S.length(), m = T.length();
        
        while (i < n && j < m) {
            if (isdigit(T[j])) {
                int count = 0;
                while (j < m && isdigit(T[j])) {
                    count = count * 10 + (T[j] - '0');
                    j++;
                }
                i += count;  // skip 'count' characters in S
            } else {
                if (i >= n || S[i] != T[j]) {
                    return 0;  // mismatch
                }
                i++;
                j++;
            }
        }
        
        // After processing both strings, both indices should be at the end
        return (i == n && j == m) ? 1 : 0;
    }
};
