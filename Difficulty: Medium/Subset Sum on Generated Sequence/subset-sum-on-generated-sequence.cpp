class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        if (x == 0) return true;

        vector<long long> P;
        long long current_sum = s;
        P.push_back(s);

        // Generate elements of the sequence on paper as long as they don't exceed x
        for (int val : arr) {
            if (current_sum > x) break;
            long long p = current_sum + val;
            P.push_back(p);
            current_sum += p;
        }

        // Greedy approach from largest to smallest element
        for (int i = (int)P.size() - 1; i >= 0; --i) {
            if (x >= P[i]) {
                x -= P[i];
            }
        }

        return x == 0;
    }
};