class Solution {
  public:
    int numberOfSubsequences(string S, string W) {
        int n = S.size();
        vector<bool> used(n, false); // track used characters
        int count = 0;

        while (true) {
            int pos = 0; // pointer for W
            for (int i = 0; i < n && pos < (int)W.size(); i++) {
                if (!used[i] && S[i] == W[pos]) {
                    used[i] = true; // mark as used
                    pos++;
                }
            }
            if (pos == (int)W.size())
                count++;
            else
                break; // can't form more subsequences
        }

        return count;
    }
};
