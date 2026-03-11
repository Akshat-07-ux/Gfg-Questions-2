class Solution {
public:
    vector<string> generateCode(int N) {
        // Base case: 1-bit Gray code is "0" and "1"
        if (N <= 0) return {"0"};
        if (N == 1) return {"0", "1"};

        // Recursively get Gray codes for N-1 bits
        vector<string> prevCodes = generateCode(N - 1);
        vector<string> result;

        // 1. Prefix '0' to the original sequence (forward order)
        for (int i = 0; i < prevCodes.size(); i++) {
            result.push_back("0" + prevCodes[i]);
        }

        // 2. Prefix '1' to the reflected sequence (reverse order)
        for (int i = prevCodes.size() - 1; i >= 0; i--) {
            result.push_back("1" + prevCodes[i]);
        }

        return result;
    }
};