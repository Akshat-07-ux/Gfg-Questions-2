class Solution {
  public:
    string chartostr(char arr[], int n) {
        // Initialize an empty string
        string result = "";
        
        // Append each character to the result string
        for (int i = 0; i < n; i++) {
            result += arr[i];
        }
        
        return result;
    }
};
