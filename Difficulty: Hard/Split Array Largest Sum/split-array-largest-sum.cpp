class Solution {
  public:
    bool isValid(vector<int>& arr, int k, int maxSumAllowed) {
        int count = 1, currentSum = 0;
        for (int num : arr) {
            if (currentSum + num > maxSumAllowed) {
                // Need a new subarray
                count++;
                currentSum = num;
                if (count > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(arr, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};
