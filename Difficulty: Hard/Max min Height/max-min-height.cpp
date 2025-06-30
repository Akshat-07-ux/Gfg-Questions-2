class Solution {
  public:
    bool canAchieve(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> diff(n + 1, 0);  // difference array for watering effect
        long long waterUsed = 0;
        int current = 0;

        for (int i = 0; i < n; ++i) {
            current += diff[i];  // apply past watering effect
            int height = arr[i] + current;
            if (height < target) {
                int need = target - height;
                waterUsed += need;
                if (waterUsed > k) return false;
                current += need;
                if (i + w < n) {
                    diff[i + w] -= need;
                }
            }
        }
        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAchieve(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
