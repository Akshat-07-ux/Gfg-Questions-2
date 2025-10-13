class Solution {
  public:
    bool isPowerOf2(int n) {
        return (n & (n - 1)) == 0;
    }
    
    string lexicographicallySmallest(string S, int k) {
        int n = S.size();
        
        // Correct k
        if (isPowerOf2(n)) k = k / 2;
        else k = k * 2;
        
        // Check validity
        if (k >= n) return "-1";
        
        string st = "";
        
        for (char c : S) {
            while (!st.empty() && st.back() > c && k > 0) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        
        // If k still remains, remove from end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
        
        return st.empty() ? "-1" : st;
    }
};
