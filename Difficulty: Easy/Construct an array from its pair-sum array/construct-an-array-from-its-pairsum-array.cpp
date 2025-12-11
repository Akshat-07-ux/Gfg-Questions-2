class Solution {
public:
    vector<int> constructArr(vector<int>& arr) {
        int m = arr.size();

        // If only one pair, original size is 2: a0 + a1 = arr[0]
        if (m == 1) {
            return {1, arr[0] - 1};
        }

        // Compute n from m = n*(n-1)/2
        long long n = (1 + sqrt(1 + 8LL * m)) / 2;

        vector<long long> res(n);

        long long S01 = arr[0];
        long long S02 = arr[1];
        long long S12 = arr[n - 1];  // correct index for (1,2)

        long long a0 = (S01 + S02 - S12) / 2;
        res[0] = a0;

        // reconstruct all ai from pair (0, i)
        for (int i = 1; i < n; i++) {
            res[i] = arr[i - 1] - a0;
        }

        // convert back to int (problem guarantees it fits)
        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = (int)res[i];
        return ans;
    }
};
