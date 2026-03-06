class Solution {
  public:
    string minWindow(string &s, string &p) {
        int n = s.length();
        int m = p.length();

        if (m > n) return "";

        // Frequency maps for characters (using array for speed with lowercase English letters)
        int p_map[26] = {0};
        int s_map[26] = {0};

        for (char c : p) {
            p_map[c - 'a']++;
        }

        int start = 0, min_len = INT_MAX, start_idx = -1;
        int count = 0; // Number of characters in s that match p's requirements

        for (int j = 0; j < n; j++) {
            int char_idx = s[j] - 'a';
            s_map[char_idx]++;

            // If current char is needed by p and we haven't exceeded its required count
            if (p_map[char_idx] != 0 && s_map[char_idx] <= p_map[char_idx]) {
                count++;
            }

            // If the window contains all characters of p
            if (count == m) {
                // Try to shrink the window from the left
                while (s_map[s[start] - 'a'] > p_map[s[start] - 'a'] || p_map[s[start] - 'a'] == 0) {
                    s_map[s[start] - 'a']--;
                    start++;
                }

                // Update minimum window
                int window_len = j - start + 1;
                if (window_len < min_len) {
                    min_len = window_len;
                    start_idx = start;
                }
            }
        }

        if (start_idx == -1) return "";
        return s.substr(start_idx, min_len);
    }
};