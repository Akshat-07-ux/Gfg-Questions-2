class Solution {
  public:
    bool passed(string s) {
        int n = s.length();
        if (n <= 1) return true;

        // Frequency array for 26 lowercase English letters
        vector<int> count(26, 0);

        // Process the first half
        for (int i = 0; i < n / 2; i++) {
            count[s[i] - 'a']++;
        }

        // Determine the start of the second half
        // If n is odd, (n+1)/2 skips the middle element
        int startOfSecondHalf = (n + 1) / 2;

        // Process the second half
        for (int i = startOfSecondHalf; i < n; i++) {
            count[s[i] - 'a']--;
        }

        // If all frequencies are zero, both halves match
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};