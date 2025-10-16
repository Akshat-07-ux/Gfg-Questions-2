class Solution {
  public:
    /*You are required to complete this method */
    int remainderWith7(string n) {
        int rem = 0;
        for (char ch : n) {
            int digit = ch - '0';
            rem = (rem * 10 + digit) % 7;
        }
        return rem;
    }
};
