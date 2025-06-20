class Solution {
 public:
    bool validgroup(std::vector<int> &arr, int k) {
        int n = arr.size();
        if (n % k != 0) return false; // Total elements must be divisible by k

        std::map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int start = it->first;
            int count = it->second;

            if (count > 0) {
                // Try to build a group starting from 'start'
                for (int i = 0; i < k; ++i) {
                    int curr = start + i;
                    if (freq[curr] < count) return false;
                    freq[curr] -= count;
                }
            }
        }
        return true;
    }
};