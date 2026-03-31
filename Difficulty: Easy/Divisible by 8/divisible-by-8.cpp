class Solution {
  public:
    int isDivisible8(string S) {
        int n = S.length();

        // Case 1: Single digit
        if (n == 1) {
            return ((S[0] - '0') % 8 == 0);
        }

        // Case 2: Two digits
        if (n == 2) {
            int num1 = stoi(S);
            swap(S[0], S[1]);
            int num2 = stoi(S);
            return (num1 % 8 == 0 || num2 % 8 == 0);
        }

        // Case 3: Three or more digits
        // We look for any combination of 3 indices (i, j, k) 
        // and check all their permutations (6 possible arrangements)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;

                    // Form a 3-digit number from digits at indices i, j, and k
                    int val = (S[i] - '0') * 100 + (S[j] - '0') * 10 + (S[k] - '0');
                    
                    if (val % 8 == 0) {
                        return 1;
                    }
                }
            }
        }

        return 0;
    }
};