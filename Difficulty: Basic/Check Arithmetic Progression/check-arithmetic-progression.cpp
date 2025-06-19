class Solution {
    public:
    bool checkIsAP(vector<int> &arr) {
        int n = arr.size();
        if (n <= 2) return true; // 1 or 2 elements always form an AP

        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());

        if ((maxi - mini) % (n - 1) != 0) return false;

        int d = (maxi - mini) / (n - 1);

        unordered_set<int> s(arr.begin(), arr.end());

        for (int i = 0; i < n; ++i) {
            int expected = mini + i * d;
            if (s.find(expected) == s.end()) return false;
        }

        return true;
    }
};