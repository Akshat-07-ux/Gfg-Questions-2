class Solution {
public:
    int largestPowerOf2(int n) {
        int x = 0;
        while ((1 << (x + 1)) <= n) x++;
        return x;
    }

    int countSetBits(int n) {
        if (n == 0) return 0;

        int x = largestPowerOf2(n);
        int bitsTill2x = x * (1 << (x - 1));      // total bits from 1 to 2^x - 1
        int msbBits = n - (1 << x) + 1;           // MSB contribution
        int rest = n - (1 << x);                  // remaining numbers

        return bitsTill2x + msbBits + countSetBits(rest);
    }
};
