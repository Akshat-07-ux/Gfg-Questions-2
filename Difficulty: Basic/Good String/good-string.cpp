class Solution {
  public:
    bool isGoodString(string &s) {
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            int diff = abs(s[i] - s[i + 1]);
            if (diff != 1 && diff != 25) {
                return false;
            }
        }
        return true;
    }
};