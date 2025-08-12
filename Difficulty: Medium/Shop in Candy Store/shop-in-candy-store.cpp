class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        int n = prices.size();
        sort(prices.begin(), prices.end());
        
        // Calculate how many candies we must buy
        // Each purchase gives us 1 + k candies total
        int mustBuy = (n + k) / (k + 1); // This is ceil(n/(k+1))
        
        int minCost = 0, maxCost = 0;
        
        // For minimum cost: buy the cheapest 'mustBuy' candies
        for(int i = 0; i < mustBuy; i++) {
            minCost += prices[i];
        }
        
        // For maximum cost: buy the most expensive 'mustBuy' candies
        for(int i = n - mustBuy; i < n; i++) {
            maxCost += prices[i];
        }
        
        return {minCost, maxCost};
    }
};