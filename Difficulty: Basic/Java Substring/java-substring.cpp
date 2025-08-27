// User function Template for C++
class Solution {
  public:
    string javaSub(string S, int L, int R) {
        // Check bounds to avoid out of range access
        if (L < 0 || R >= S.length() || L > R) {
            return "";
        }
        
        // Extract substring from index L to R (inclusive)
        // substr(start_index, length)
        return S.substr(L, R - L + 1);
    }
};