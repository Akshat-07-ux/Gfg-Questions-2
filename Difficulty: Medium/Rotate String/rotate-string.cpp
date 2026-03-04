class Solution {
  public:
    vector<char> StringQuery(int n, int q, string s, int q1[], int q2[]) {
        vector<char> results;
        // 'offset' tracks the virtual starting index of the string
        long long offset = 0;

        for (int i = 0; i < q; i++) {
            if (q1[i] == 1) {
                // Type 1: Rotate by K from the end
                // Rotating K from end is equivalent to shifting the start back by K
                long long k = q2[i];
                // We use (offset - k) % n, but adding n ensures the result is positive
                offset = (offset - (k % n) + n) % n;
            } else {
                // Type 2: Get character at index I
                int index = q2[i];
                // Map the requested index back to the original string position
                int originalIndex = (offset + index) % n;
                results.push_back(s[originalIndex]);
            }
        }
        
        return results;
    }
};