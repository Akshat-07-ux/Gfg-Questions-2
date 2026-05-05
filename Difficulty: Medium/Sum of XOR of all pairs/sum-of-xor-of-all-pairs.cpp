class Solution {
public:
    long long sumXOR(vector<int> &arr) {
        long long totalSum = 0;
        int n = arr.size();

        // Iterate through each bit position (0 to 31 for integers)
        for (int i = 0; i < 32; i++) {
            long long countSet = 0;
            long long countUnset = 0;

            // Count numbers with i-th bit set and unset
            for (int j = 0; j < n; j++) {
                if (arr[j] & (1 << i)) {
                    countSet++;
                } else {
                    countUnset++;
                }
            }

            // Total pairs with different i-th bits = countSet * countUnset
            // Contribution to total sum = (pairs) * 2^i
            totalSum += (countSet * countUnset) * (1LL << i);
        }

        return totalSum;
    }
};