class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // If lengths are different, they cannot be isomorphic
        if (s1.length() != s2.length()) {
            return false;
        }

        // Arrays to store the last seen position (1-indexed) of characters
        // Initialized to 0
        int m1[256] = {0};
        int m2[256] = {0};

        for (int i = 0; i < s1.length(); i++) {
            // If the last seen positions don't match, the mapping is inconsistent
            if (m1[(int)s1[i]] != m2[(int)s2[i]]) {
                return false;
            }

            // Update the mapping to the current index + 1
            m1[(int)s1[i]] = i + 1;
            m2[(int)s2[i]] = i + 1;
        }

        return true;
    }
};