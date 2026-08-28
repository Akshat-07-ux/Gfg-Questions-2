class Solution {
  public:
    int findMinOperation(int n) {
        if (n == 1) return 0;

        int ops = 0;
        int factor = 2;

        // Extract prime factors up to sqrt(n)
        while (factor * factor <= n) {
            while (n % factor == 0) {
                ops += factor;
                n /= factor;
            }
            factor++;
        }

        // If n is still greater than 1, the remaining part is a prime number
        if (n > 1) {
            ops += n;
        }

        return ops;
    }
};