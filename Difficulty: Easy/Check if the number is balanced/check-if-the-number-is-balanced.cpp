// User function template for C++
class Solution {
  public:
    bool balancedNumber(string N) {
        int n = N.size();
        int mid = n / 2;  // middle index (since n is odd)
        
        int leftSum = 0, rightSum = 0;
        
        // sum of digits to the left of mid
        for (int i = 0; i < mid; i++) {
            leftSum += (N[i] - '0');
        }
        
        // sum of digits to the right of mid
        for (int i = mid + 1; i < n; i++) {
            rightSum += (N[i] - '0');
        }
        
        return leftSum == rightSum;
    }
};
