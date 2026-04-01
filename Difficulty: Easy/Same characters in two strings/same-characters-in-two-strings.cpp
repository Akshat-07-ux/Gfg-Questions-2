#include <string>
#include <cctype> // For tolower function

class Solution {
  public:
    int sameChar(string A, string B) {
        int count = 0;
        int n = A.length(); // Strings are of equal length per problem statement
        
        for (int i = 0; i < n; i++) {
            // Convert both characters to lowercase to handle case-insensitivity
            if (tolower(A[i]) == tolower(B[i])) {
                count++;
            }
        }
        
        return count;
    }
};