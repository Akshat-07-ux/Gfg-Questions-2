class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        int n = s.size();
        // Use a difference array to store roll counts
        vector<int> diff(n + 1, 0);

        // Mark the range [0, k-1] for each roll[i] = k
        for (int k : roll) {
            diff[0]++;
            if (k < n) {
                diff[k]--;
            }
        }

        // Calculate the prefix sum to get the actual roll count for each index
        int currentRolls = 0;
        for (int i = 0; i < n; i++) {
            currentRolls += diff[i];
            
            // Calculate new character after 'currentRolls' rolls
            // We use (currentRolls % 26) to handle large roll values
            int shift = currentRolls % 26;
            int originalPos = s[i] - 'a';
            int newPos = (originalPos + shift) % 26;
            
            s[i] = (char)('a' + newPos);
        }

        return s;
    }
};