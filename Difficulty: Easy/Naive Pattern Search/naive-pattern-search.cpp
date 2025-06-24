class Solution {
  public:
    // Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt) {
        int N = txt.size();
        int M = pat.size();

        // Loop through the text
        for (int i = 0; i <= N - M; ++i) {
            int j;
            // Check for pattern match starting at position i
            for (j = 0; j < M; ++j) {
                if (txt[i + j] != pat[j])
                    break;
            }
            // If pattern matched completely
            if (j == M)
                return true;
        }

        // Pattern not found
        return false;
    }
};
