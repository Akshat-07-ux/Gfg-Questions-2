class Solution {
  public:
    // Helper function to merge two halves and count inversions
    long long mergeAndCount(vector<int> &arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> left(n1), right(n2);
        for (int i = 0; i < n1; i++) left[i] = arr[l + i];
        for (int i = 0; i < n2; i++) right[i] = arr[m + 1 + i];

        long long res = 0;
        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                // If left[i] > right[j], then all elements from left[i] 
                // to left[n1-1] form an inversion with right[j].
                arr[k++] = right[j++];
                res += (n1 - i);
            }
        }

        while (i < n1) arr[k++] = left[i++];
        while (j < n2) arr[k++] = right[j++];

        return res;
    }

    long long countInv(vector<int> &arr, int l, int r) {
        long long res = 0;
        if (l < r) {
            int m = l + (r - l) / 2;
            res += countInv(arr, l, m);
            res += countInv(arr, m + 1, r);
            res += mergeAndCount(arr, l, m, r);
        }
        return res;
    }

    int inversionCount(vector<int> &arr) {
        // We use long long for internal counting to avoid overflow, 
        // then return as int as per function signature.
        return (int)countInv(arr, 0, arr.size() - 1);
    }
};