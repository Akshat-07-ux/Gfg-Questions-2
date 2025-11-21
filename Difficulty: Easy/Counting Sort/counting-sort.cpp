class Solution {
  public:
    string countSort(string s) {
        vector<int> cnt(26, 0);

        // Count frequencies of each character
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Rebuild the sorted string
        string ans = "";
        ans.reserve(s.size());   // optimization

        for (int i = 0; i < 26; i++) {
            ans.append(cnt[i], char('a' + i));
        }

        return ans;
    }
};
