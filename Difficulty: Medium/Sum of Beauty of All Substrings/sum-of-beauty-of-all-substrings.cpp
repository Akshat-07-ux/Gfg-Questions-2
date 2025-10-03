class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int totalBeauty = 0;
        
        // Iterate over all starting points of substrings
        for (int i = 0; i < n; ++i) {
            int freq[26] = {0}; // frequency array for 'a' to 'z'
            
            // Expand the substring from i to j
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++; // update frequency
                
                int maxFreq = 0;
                int minFreq = INT_MAX;
                
                // Calculate max and min frequency (only for letters that appear)
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                
                totalBeauty += (maxFreq - minFreq);
            }
        }
        
        return totalBeauty;
    }
};
