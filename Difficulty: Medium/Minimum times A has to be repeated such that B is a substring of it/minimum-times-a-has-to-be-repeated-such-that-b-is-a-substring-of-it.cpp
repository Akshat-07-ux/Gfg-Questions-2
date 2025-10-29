// User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        string repeated = A;
        int count = 1;

        // Keep appending until repeated >= B in length
        while (repeated.size() < B.size()) {
            repeated += A;
            count++;
        }

        // Check if B is a substring now
        if (repeated.find(B) != string::npos)
            return count;

        // Try one more time (handles overlap case)
        repeated += A;
        count++;

        if (repeated.find(B) != string::npos)
            return count;

        // If still not found, impossible
        return -1;
    }
};
