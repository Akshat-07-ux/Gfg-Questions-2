class Solution {
public:
    int superPrimes(int n) {
        if (n < 5) return 0; // The smallest super prime is 5 (2 + 3)

        // Sieve of Eratosthenes to find all primes up to n
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p)
                    isPrime[i] = false;
            }
        }

        int count = 0;
        // Check for Super Primes
        // As derived, a prime p is super prime if (p - 2) is also prime.
        // We start from 5 because 5 is the first prime that can be (p - 2) + 2
        for (int i = 5; i <= n; i++) {
            if (isPrime[i] && isPrime[i - 2]) {
                count++;
            }
        }

        return count;
    }
};