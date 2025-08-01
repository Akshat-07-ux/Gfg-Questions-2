class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        unordered_map<int, int> prefixDiffCount;
        prefixDiffCount[0] = 1; // For subarrays starting from index 0
        
        int totalVowels = 0, totalConsonants = 0;
        int result = 0;
        
        for (const string& str : arr) {
            for (char ch : str) {
                if (isVowel(ch))
                    totalVowels++;
                else
                    totalConsonants++;
            }

            int diff = totalVowels - totalConsonants;
            result += prefixDiffCount[diff];
            prefixDiffCount[diff]++;
        }
        
        return result;
    }

  private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
