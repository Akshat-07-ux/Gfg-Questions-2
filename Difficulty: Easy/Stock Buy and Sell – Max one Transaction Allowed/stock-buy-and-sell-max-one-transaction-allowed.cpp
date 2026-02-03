class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            // Update minimum price so far
            minPrice = min(minPrice, price);

            // Calculate profit if sold today
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
