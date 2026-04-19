class Solution {
  public:
    bool isPower(int x, int y) {
        // Any number raised to the power of 0 is 1
        if (y == 1) return true;

        // If x is 1, it can only result in y=1 (handled above)
        if (x == 1) return false;

        long long pw = x;
        while (pw < y) {
            pw *= x;
        }

        return (pw == y);
    }
};