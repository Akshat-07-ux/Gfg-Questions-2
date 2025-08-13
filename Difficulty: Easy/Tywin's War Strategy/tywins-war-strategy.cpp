class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int required = (n + 1) / 2; // ceil(n / 2)
        
        int luckyCount = 0;
        vector<int> costs;
        
        for (int soldiers : arr) {
            if (soldiers % k == 0) {
                luckyCount++;
            } else {
                costs.push_back(k - (soldiers % k));
            }
        }
        
        if (luckyCount >= required) return 0;
        
        sort(costs.begin(), costs.end());
        
        int soldiersAdded = 0;
        int idx = 0;
        
        while (luckyCount < required && idx < (int)costs.size()) {
            soldiersAdded += costs[idx];
            luckyCount++;
            idx++;
        }
        
        return soldiersAdded;
    }
};