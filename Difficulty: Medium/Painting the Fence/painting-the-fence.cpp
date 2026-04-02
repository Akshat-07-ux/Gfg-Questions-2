class Solution {
  public:
    int countWays(int n, int k) {
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return k;
        
        // Use long long for intermediate calculations to prevent overflow 
        // before the final result (though constraints say result fits in 32-bit)
        long long same = 0;
        long long diff = k;
        long long total = k;
        
        // For n = 2
        same = k; 
        diff = (long long)k * (k - 1);
        total = same + diff;
        
        if (n == 2) return (int)total;

        // DP transition for n > 2
        for (int i = 3; i <= n; i++) {
            // Previous 'diff' becomes the new 'same' because to be same as i-1, 
            // i-1 must have been different from i-2.
            long long prev_diff = diff;
            
            // To be different, current post can be any of (k-1) colors 
            // regardless of whether i-1 was 'same' or 'diff'
            diff = (total * (k - 1));
            same = prev_diff;
            
            total = same + diff;
        }

        return (int)total;
    }
};