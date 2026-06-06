class Solution {
  public:
    long long numOfWays(int n, int m) {
        // Total squares on the board
        long long total_squares = (long long)n * m;
        
        // Total ways to place two distinct knights without restrictions
        long long total_ways = total_squares * (total_squares - 1);
        
        // Count of 2x3 blocks
        long long blocks_2x3 = 0;
        if (n >= 2 && m >= 3) {
            blocks_2x3 = (long long)(n - 1) * (m - 2);
        }
        
        // Count of 3x2 blocks
        long long blocks_3x2 = 0;
        if (n >= 3 && m >= 2) {
            blocks_3x2 = (long long)(n - 2) * (m - 1);
        }
        
        // Total attacking arrangements (4 ways per block)
        long long attacking_ways = 4 * (blocks_2x3 + blocks_3x2);
        
        // Non-attacking ways
        return total_ways - attacking_ways;
    }
};