class Solution {
  public:
    int findPosition(int n) {
        // A number with exactly one set bit must be greater than 0
        // and must be a power of 2.
        if (n <= 0 || (n & (n - 1)) != 0) {
            return -1;
        }

        // log2(n) gives the 0-based index of the set bit.
        // We add 1 for the 1-based position.
        return log2(n) + 1;
    }
};