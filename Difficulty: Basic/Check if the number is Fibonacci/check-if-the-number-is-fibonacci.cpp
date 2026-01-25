class Solution {
  public:
    // Helper function to check if a number is a perfect square
    bool isPerfectSquare(int x) {
        int s = sqrt(x);
        return (s * s == x);
    }

    string checkFibonacci(int N) {
        // A number is Fibonacci if (5*N*N + 4) or (5*N*N - 4) is a perfect square
        if (isPerfectSquare(5 * N * N + 4) || isPerfectSquare(5 * N * N - 4)) {
            return "Yes";
        } else {
            return "No";
        }
    }
};