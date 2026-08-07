class Solution {
  public:
    int countFriendsPairings(int n) {
        if (n <= 2) return n;

        long long prev2 = 1; // f(1)
        long long prev1 = 2; // f(2)
        long long curr = 0;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + (i - 1) * prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};