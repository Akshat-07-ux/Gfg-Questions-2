class Solution {
  public:
    int maxCharGap(string &s) {
        // Array to store the first occurrence index of each character initialized to -1
        vector<int> firstIndex(26, -1);
        int maxGap = -1;
        
        for (int i = 0; i < s.length(); i++) {
            int charIdx = s[i] - 'a'; // Map 'a'-'z' to 0-25
            
            if (firstIndex[charIdx] == -1) {
                // If this is the first time seeing the character, record its index
                firstIndex[charIdx] = i;
            } else {
                // If seen before, calculate the gap and update maxGap
                int currentGap = i - firstIndex[charIdx] - 1;
                maxGap = max(maxGap, currentGap);
            }
        }
        
        return maxGap;
    }
};