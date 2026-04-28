class Solution {
public:
    int longestSubstr(string& s, int k) {
        int n = s.length();
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;
        vector<int> freq(26, 0);

        for (int right = 0; right < n; ++right) {
            // Update frequency of the current character
            freq[s[right] - 'A']++;
            
            // Keep track of the most frequent character in the current window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Window size is (right - left + 1)
            // If (window size - maxFreq) > k, we have too many characters to change
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
                // Note: We don't strictly need to update maxFreq here because 
                // the result only increases when we find a new maxFreq.
            }

            // Update the global maximum length found
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};