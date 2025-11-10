class Solution {
  public:
    int closing(string s, int pos) {
        // We assume s[pos] == '[' as per problem statement
        int count = 0;
        
        // Traverse from the given opening bracket
        for (int i = pos; i < s.size(); i++) {
            if (s[i] == '[')
                count++;          // Found a new opening bracket
            else if (s[i] == ']')
                count--;          // Found a closing bracket
            
            // When all opened brackets are closed
            if (count == 0)
                return i;
        }
        
        // If no closing bracket found (invalid case)
        return -1;
    }
};
