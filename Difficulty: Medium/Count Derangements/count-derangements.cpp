class Solution {
  public:
    int derangeCount(int n) {
        // Base case: if n is 1, no derangement is possible
        if (n == 1) return 0;
        // Base case: if n is 2, only [2, 1] is possible
        if (n == 2) return 1;

        // We use long long for intermediate calculations to prevent overflow 
        // before returning as int, though for n=12, int is sufficient.
        long long prev2 = 0; // D(1)
        long long prev1 = 1; // D(2)
        long long current = 0;

        for (int i = 3; i <= n; i++) {
            current = (i - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = current;
        }

        return (int)prev1;
    }
};