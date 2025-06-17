class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        // Prefix sum for coins before i
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        // Suffix sum for coins after i
        vector<long long> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + arr[i];
        }

        long long minCoins = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            int base = arr[i];
            int upper = base + k;

            // Binary search to find the first element > base + k
            int high = upper_bound(arr.begin(), arr.end(), upper) - arr.begin();

            // Coins to remove from all elements before i (remove full piles)
            long long coinsLeft = prefix[i];

            // Coins to remove from all elements after 'high - 1' (trim to upper)
            long long countRight = n - high;
            long long coinsRight = (countRight > 0) ? (suffix[high] - 1LL * countRight * upper) : 0;

            minCoins = min(minCoins, coinsLeft + coinsRight);
        }

        return (int)minCoins;
    }
};