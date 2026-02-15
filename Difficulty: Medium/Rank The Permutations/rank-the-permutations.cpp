#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    // Helper function to precompute factorials
    long long factorial(int n) {
        if (n <= 1) return 1;
        long long res = 1;
        for (int i = 2; i <= n; i++) res *= i;
        return res;
    }

    long long findRank(string str) {
        int n = str.length();
        long long rank = 1; // Start at 1
        long long fact = factorial(n);

        for (int i = 0; i < n; i++) {
            // Update factorial for the remaining (n - 1 - i) positions
            fact /= (n - i);

            // Count how many characters smaller than str[i] 
            // are present to the right of index i
            int countSmaller = 0;
            for (int j = i + 1; j < n; j++) {
                if (str[j] < str[i]) {
                    countSmaller++;
                }
            }

            // Those countSmaller characters could have been at index i instead,
            // each creating (n - 1 - i)! permutations that come before str
            rank += (long long)countSmaller * fact;
        }

        return rank;
    }
};