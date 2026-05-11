class Solution {
  public:
    bool isPalindrome(string& s) {
        int low = 0, high = s.length() - 1;
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }

    bool palindromePair(vector<string>& arr) {
        int n = arr.size();
        if (n < 2) return false;

        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            string s = arr[i];
            int len = s.length();

            for (int j = 0; j <= len; j++) {
                // Check prefix
                string pref = s.substr(0, j);
                string suff = s.substr(j);

                // If prefix is a palindrome, we need reverse of suffix to the left
                if (isPalindrome(pref)) {
                    string rev_suff = suff;
                    reverse(rev_suff.begin(), rev_suff.end());
                    if (mp.count(rev_suff) && mp[rev_suff] != i) {
                        return true;
                    }
                }

                // If suffix is a palindrome, we need reverse of prefix to the right
                // j > 0 to avoid duplicate checks with the prefix logic
                if (j < len && isPalindrome(suff)) {
                    string rev_pref = pref;
                    reverse(rev_pref.begin(), rev_pref.end());
                    if (mp.count(rev_pref) && mp[rev_pref] != i) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};