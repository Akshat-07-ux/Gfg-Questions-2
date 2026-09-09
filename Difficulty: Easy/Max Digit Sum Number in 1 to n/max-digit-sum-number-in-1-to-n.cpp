class Solution {
  public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int findMax(int n) {
        int ans = n;
        int maxSum = digitSum(n);

        int x = n;
        long long b = 1;

        while (x > 0) {
            int candidate = (x - 1) * b + (b - 1);
            if (candidate > 0) {
                int sum = digitSum(candidate);
                if (sum > maxSum || (sum == maxSum && candidate > ans)) {
                    maxSum = sum;
                    ans = candidate;
                }
            }
            b *= 10;
            x /= 10;
        }

        return ans;
    }
};