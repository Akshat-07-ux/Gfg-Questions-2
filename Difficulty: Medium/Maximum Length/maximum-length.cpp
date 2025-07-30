class Solution {
  public:
    int solve(int a, int b, int c) {
        // Find the maximum count among a, b, and c
        int maxCount = max({a, b, c});
        int total = a + b + c;
        
        // Sum of other two
        int sumOtherTwo = total - maxCount;
        
        // If the most frequent character appears more than allowed
        if (maxCount > 2 * sumOtherTwo + 2)
            return -1;
        
        return total;
    }
};
