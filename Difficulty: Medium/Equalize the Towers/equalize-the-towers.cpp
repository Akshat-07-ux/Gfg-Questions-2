class Solution {
public:
    // Helper function to calculate total cost for a specific target height
    long long calculateCost(const vector<int>& heights, const vector<int>& cost, int target) {
        long long total = 0;
        for (int i = 0; i < heights.size(); i++) {
            total += (long long)abs(heights[i] - target) * cost[i];
        }
        return total;
    }

    long long minCost(vector<int>& heights, vector<int>& cost) {
        int low = 1, high = 10000; // Based on constraints 1 <= heights[i] <= 10^4
        
        // Find actual min and max to tighten the search space
        for(int h : heights) {
            low = min(low, h);
            high = max(high, h);
        }

        long long ans = calculateCost(heights, cost, low);

        while (low <= high) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;

            long long cost1 = calculateCost(heights, cost, mid1);
            long long cost2 = calculateCost(heights, cost, mid2);

            ans = min({ans, cost1, cost2});

            if (cost1 < cost2) {
                high = mid2 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        
        return ans;
    }
};