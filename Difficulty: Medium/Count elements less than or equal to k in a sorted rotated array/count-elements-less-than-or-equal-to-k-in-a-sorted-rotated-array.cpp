class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        if (n == 0) return 0;

        // Step 1: Find pivot (index of minimum element)
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = low;

        // Helper lambda to count <= x in sorted range [l, r]
        auto countInRange = [&](int l, int r) {
            if (l > r) return 0;
            int lo = l, hi = r;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (arr[mid] <= x)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            return hi - l + 1;  // number of elements <= x
        };

        // Step 2: Count in both sorted parts
        int count = 0;
        count += countInRange(pivot, n - 1);
        count += countInRange(0, pivot - 1);

        return count;
    }
};
