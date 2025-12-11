class Solution {
public:
    long long karatsubaAlgo(string A, string B) {
        long long x = 0, y = 0;

        // Convert A to decimal
        for (char c : A) {
            x = (x << 1) + (c - '0');
        }

        // Convert B to decimal
        for (char c : B) {
            y = (y << 1) + (c - '0');
        }

        return x * y;
    }
};
