class Solution {
  public:
    int candies(int m, int n) {
        // Since m and n are coprime, use formula from number theory
        return ((m - 1) * (n - 1)) / 2;
    }
};
