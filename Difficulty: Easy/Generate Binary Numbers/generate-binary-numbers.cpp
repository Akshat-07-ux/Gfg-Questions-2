class Solution {
  public:
    vector<string> generateBinary(int n) {
        vector<string> result;
        result.reserve(n);  // reserve memory for efficiency
        
        for (int i = 1; i <= n; i++) {
            result.push_back(toBinary(i));
        }
        
        return result;
    }
    
  private:
    string toBinary(int num) {
        string bin = "";
        while (num > 0) {
            bin = char('0' + (num % 2)) + bin;
            num /= 2;
        }
        return bin;
    }
};
