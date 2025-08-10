class Solution {
  public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;
        
        // helper lambda to expand from the center
        auto expand = [&](int left, int right) {
            int localCount = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2)  // only count length >= 2
                    localCount++;
                left--;
                right++;
            }
            return localCount;
        };
        
        // consider every index as center for odd and even length palindromes
        for (int i = 0; i < n; i++) {
            count += expand(i, i);     // odd length
            count += expand(i, i + 1); // even length
        }
        
        return count;
    }
};
