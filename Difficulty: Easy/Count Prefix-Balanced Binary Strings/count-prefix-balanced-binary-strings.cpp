class Solution {
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

    long long modInverse(long long n, long long mod) {
        return power(n, mod - 2, mod);
    }

  public:
    int prefixStrings(int n) {
        long long MOD = 1e9 + 7;

        // Calculate (2n)! / (n! * n!) % MOD
        long long num = 1;
        long long den = 1;

        for (int i = 1; i <= n; i++) {
            num = (num * (n + i)) % MOD;
            den = (den * i) % MOD;
        }

        long long nCr = (num * modInverse(den, MOD)) % MOD;

        // Divide by (n + 1) -> multiply by modInverse(n + 1)
        long long ans = (nCr * modInverse(n + 1, MOD)) % MOD;

        return ans;
    }
};