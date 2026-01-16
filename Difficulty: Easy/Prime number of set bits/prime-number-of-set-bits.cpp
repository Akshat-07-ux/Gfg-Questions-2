class Solution {
  public:
    
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int primeSetBits(int L, int R) {
        int count = 0;

        for (int i = L; i <= R; i++) {
            int setBits = __builtin_popcount(i);
            if (isPrime(setBits)) {
                count++;
            }
        }

        return count;
    }
};
