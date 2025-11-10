#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int hold = -arr[0];   // We buy the first stock
        int sold = 0;         // Profit after selling
        int cooldown = 0;     // Profit after cooldown

        for (int i = 1; i < n; i++) {
            int prev_hold = hold;
            int prev_sold = sold;
            int prev_cooldown = cooldown;

            // If we hold today, we either already held yesterday or buy today after cooldown
            hold = max(prev_hold, prev_cooldown - arr[i]);

            // If we sold today, we must have held a stock before
            sold = prev_hold + arr[i];

            // If we are in cooldown today, we either were already in cooldown or sold yesterday
            cooldown = max(prev_cooldown, prev_sold);
        }

        // The result is the max profit when not holding a stock (either sold or cooldown)
        return max(sold, cooldown);
    }
};
