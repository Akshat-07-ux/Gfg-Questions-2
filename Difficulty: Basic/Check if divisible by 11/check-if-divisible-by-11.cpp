class Solution {
  public:
    int divisibleBy11(string S) {

        long long oddSum = 0, evenSum = 0;

        for (int i = 0; i < S.size(); i++) {
            int digit = S[i] - '0';

            if (i % 2 == 0)
                oddSum += digit;
            else
                evenSum += digit;
        }

        long long diff = abs(oddSum - evenSum);

        return (diff % 11 == 0) ? 1 : 0;
    }
};
