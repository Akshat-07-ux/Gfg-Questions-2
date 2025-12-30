class Solution {
  public:
    int minSteps(int d) {
        int steps = 0;
        int sum = 0;

        while (sum < d || (sum - d) % 2 != 0) {
            steps++;
            sum += steps;
        }

        return steps;
    }
};
