class Solution {
  public:
    int minimumSum(string s) {
        int n = s.size();

        // Step 1: enforce palindrome constraints
        for (int i = 0; i < n / 2; i++) {
            int j = n - 1 - i;
            if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
                return -1; // impossible
            }
            if (s[i] == '?' && s[j] != '?') s[i] = s[j];
            else if (s[i] != '?' && s[j] == '?') s[j] = s[i];
        }

        if (n % 2 == 1 && s[n/2] == '?') {
            s[n/2] = 'a';
        }

        // Step 2: find first non-'?'
        char last = '?';
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                last = s[i];
            } else if (last != '?') {
                s[i] = last; // propagate left value
                s[n-1-i] = last; // ensure palindrome
            }
        }

        // Step 3: backward pass
        last = '?';
        for (int i = n-1; i >= 0; i--) {
            if (s[i] != '?') {
                last = s[i];
            } else if (last != '?') {
                s[i] = last;
                s[n-1-i] = last;
            }
        }

        // If still all '?', fill with 'a'
        bool allq = true;
        for (char c : s) if (c != '?') { allq = false; break; }
        if (allq) {
            for (int i = 0; i < n; i++) s[i] = 'a';
        }

        // Step 4: compute ascii sum
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += abs(s[i] - s[i-1]);
        }
        return ans;
    }
};
