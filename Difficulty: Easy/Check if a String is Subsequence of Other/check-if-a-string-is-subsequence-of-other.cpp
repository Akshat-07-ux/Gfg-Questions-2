class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        int i = 0, j = 0;
        int n1 = s1.size(), n2 = s2.size();
        
        // Traverse both strings
        while (i < n1 && j < n2) {
            if (s1[i] == s2[j]) {
                i++; // match found, move to next char in s1
            }
            j++; // always move through s2
        }
        
        // If i reached end of s1, all chars matched
        return i == n1;
    }
};
