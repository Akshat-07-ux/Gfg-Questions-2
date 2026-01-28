class Solution {
public:
    int getSpecialNumber(int N) {
        N = N - 1; // 1-indexed to 0-indexed
        if(N < 0) return 0;

        int result = 0;
        int place = 1;

        while(N > 0) {
            int digit = N % 6;
            result += digit * place;
            N /= 6;
            place *= 10;
        }

        return result;
    }
};
