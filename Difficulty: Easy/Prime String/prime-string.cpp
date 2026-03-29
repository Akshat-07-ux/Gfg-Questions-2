class Solution {
public:
    bool isPrime(long long n) {
        // Handle base cases for primality
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        // Optimized primality test (checking up to sqrt(n))
        // We use i and i+2 to skip multiples of 2 and 3
        for (long long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    bool isPrimeString(int N, string str) {
        long long asciiSum = 0;

        // Calculate the total ASCII sum of the string
        for (char c : str) {
            asciiSum += (int)c;
        }

        // Return whether the calculated sum is prime
        return isPrime(asciiSum);
    }
};