class Solution {
  public:
    vector<string> graycode(int n) {
        vector<string> result;
        // Total number of codes in a sequence of length n is 2^n
        int totalCodes = 1 << n;

        for (int i = 0; i < totalCodes; i++) {
            // Calculate the Gray code using the formula: i XOR (i >> 1)
            int grayNum = i ^ (i >> 1);
            
            // Convert the integer to a binary string
            string binary = "";
            for (int j = n - 1; j >= 0; j--) {
                // Check if the j-th bit is set
                if ((grayNum >> j) & 1) {
                    binary += '1';
                } else {
                    binary += '0';
                }
            }
            result.push_back(binary);
        }
        
        return result;
    }
};