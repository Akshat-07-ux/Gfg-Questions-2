class Solution {
  public:
    string ReFormatString(string S, int K) {
        string cleaned;
        
        // Step 1: Remove dashes and convert to uppercase
        for (char ch : S) {
            if (ch != '-') {
                cleaned += toupper(ch);
            }
        }
        
        // Step 2: Reverse the cleaned string
        reverse(cleaned.begin(), cleaned.end());
        
        string result;
        for (int i = 0; i < cleaned.length(); i++) {
            if (i > 0 && i % K == 0) {
                result += '-';
            }
            result += cleaned[i];
        }
        
        // Step 3: Reverse the final string to restore correct order
        reverse(result.begin(), result.end());
        return result;
    }
};
