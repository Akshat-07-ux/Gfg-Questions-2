class Solution {
  public:
    vector<string> invIsoTriangle(int n) {
        vector<string> result;
        int maxWidth = 2 * n - 1;
        
        for (int i = 0; i < n; i++) {
            string row = "";
            
            // 1. Leading spaces
            for (int j = 0; j < i; j++) row += " ";
            
            // 2. Stars
            int numStars = 2 * (n - i) - 1;
            for (int j = 0; j < numStars; j++) row += "*";
            
            // 3. Trailing spaces (to make each row width equal to maxWidth)
            for (int j = 0; j < i; j++) row += " ";
            
            result.push_back(row);
        }
        
        return result;
    }
};