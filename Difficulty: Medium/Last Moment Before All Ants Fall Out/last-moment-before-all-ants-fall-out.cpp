class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxTime = 0;

        // For ants moving to the left, the time to fall is just their position
        for (int pos : left) {
            maxTime = max(maxTime, pos);
        }

        // For ants moving to the right, the time to fall is (n - position)
        for (int pos : right) {
            maxTime = max(maxTime, n - pos);
        }

        return maxTime;
    }
};
