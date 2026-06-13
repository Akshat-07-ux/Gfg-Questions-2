class Solution {
  private:
    // Helper function to calculate (base^exp) % mod
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    // Helper function to find modular inverse using Fermat's Little Theorem
    long long modInverse(long long n, long long mod) {
        return power(n, mod - 2, mod);
    }

  public:
    int computeValue(int n) {
        long long mod = 1e9 + 7;
        
        // We need to calculate (2n)! / (n! * n!) % mod
        long long num = 1; // To store (2n)!
        long long den = 1; // To store (n! * n!)
        
        // Calculate (2n)!
        for (int i = 1; i <= 2 * n; i++) {
            num = (num * i) % mod;
        }
        
        // Calculate n!
        long long factN = 1;
        for (int i = 1; i <= n; i++) {
            factN = (factN * i) % mod;
        }
        
        // den = (n! * n!) % mod
        den = (factN * factN) % mod;
        
        // Result = (num * den^-1) % mod
        long long ans = (num * modInverse(den, mod)) % mod;
        
        return ans;
    }
};