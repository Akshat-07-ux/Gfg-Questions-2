class Solution {
  public:
    int myAtoi(string &s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long result = 0;

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Read digits and handle overflow
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Check for overflow/underflow immediately
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        return (int)(result * sign);
    }
};