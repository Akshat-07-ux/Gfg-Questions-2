// User function Template for C++
class Solution {
  public:
    set<string> allPossibleSubsequences(string S) {
        int n = S.size();
        set<string> result;
        string vowels = "aeiouAEIOU"; // include uppercase if needed
        
        // generate all subsequences using bitmasking
        for (int mask = 1; mask < (1 << n); mask++) {
            string subseq = "";
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subseq.push_back(S[i]);
                }
            }
            
            if (!subseq.empty()) {
                char start = subseq.front();
                char end = subseq.back();
                bool isVowel = (vowels.find(start) != string::npos);
                bool isConsonant = (vowels.find(end) == string::npos);
                
                if (isVowel && isConsonant) {
                    result.insert(subseq);
                }
            }
        }
        return result;
    }
};
