class Solution {
 public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        vector<pair<int, int>> towers(n);
        for (int i = 0; i < n; ++i) {
            towers[i] = {heights[i], cost[i]};
        }

        // Sort by height
        sort(towers.begin(), towers.end());

        // Calculate total cost
        long long totalCost = 0;
        for (int i = 0; i < n; ++i) {
            totalCost += towers[i].second;
        }

        // Find weighted median
        long long cumulativeCost = 0;
        int targetHeight = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeCost += towers[i].second;
            if (cumulativeCost >= (totalCost + 1) / 2) {
                targetHeight = towers[i].first;
                break;
            }
        }

        // Compute final cost using the chosen height
        long long answer = 0;
        for (int i = 0; i < n; ++i) {
            answer += 1LL * abs(towers[i].first - targetHeight) * towers[i].second;
        }

        return answer;
    }
};