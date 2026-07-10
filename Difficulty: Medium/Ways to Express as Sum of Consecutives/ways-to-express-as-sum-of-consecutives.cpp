class Solution {
  public:
    int getCount(int n) {
        int count = 0;
        
        // k represents the number of consecutive terms, starting from 2
        for (int k = 2; (k * (k - 1)) / 2 < n; k++) {
            // Calculate the numerator for finding 'a'
            int remainder = n - (k * (k - 1)) / 2;
            
            // If the remainder is perfectly divisible by k, we found a valid sequence
            if (remainder % k == 0) {
                count++;
            }
        }
        
        return count;
    }
};