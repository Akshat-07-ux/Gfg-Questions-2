class Solution {
  public:
    string encryptString(string s) {
        string encoded = "";
        int n = s.size();

        for (int i = 0; i < n; ) {
            char ch = s[i];
            int count = 0;

            // Count consecutive identical characters
            while (i < n && s[i] == ch) {
                count++;
                i++;
            }

            // Append character and its count
            encoded += ch + to_string(count);
        }

        // Reverse the final encoded string
        reverse(encoded.begin(), encoded.end());
        return encoded;
    }
};
