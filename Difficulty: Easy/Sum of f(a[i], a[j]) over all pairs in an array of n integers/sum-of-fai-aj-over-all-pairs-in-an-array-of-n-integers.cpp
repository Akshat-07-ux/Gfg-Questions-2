class Solution {
public:
    long long sum(vector<int>& arr) {
        const int MAX = 1e6 + 5;
        vector<int> freq(MAX, 0);
        long long ans = 0;
        long long sumAll = 0;  // sum of all previous elements
        long long totalFreq = 0; // count of all previous elements

        for (int a : arr) {
            int excludeFreq = freq[a];
            if (a > 0) excludeFreq += freq[a - 1];
            if (a + 1 < MAX) excludeFreq += freq[a + 1];

            long long excludeSum = 1LL * freq[a] * a;
            if (a > 0) excludeSum += 1LL * freq[a - 1] * (a - 1);
            if (a + 1 < MAX) excludeSum += 1LL * freq[a + 1] * (a + 1);

            ans += 1LL * a * (totalFreq - excludeFreq) - (sumAll - excludeSum);

            // Update freq and sumAll
            freq[a]++;
            totalFreq++;
            sumAll += a;
        }

        return ans;
    }
};
