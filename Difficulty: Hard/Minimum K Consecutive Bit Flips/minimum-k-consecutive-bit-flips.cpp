class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int flips = 0;           // total flips done
        int currentFlips = 0;    // ongoing flips affecting current index

        vector<int> isFlipped(n, 0);  // marks where flips start

        for (int i = 0; i < n; i++) {
            // Remove the effect of the flip that ended k positions ago
            if (i >= k) {
                currentFlips -= isFlipped[i - k];
            }

            // If the current bit after flips is 0, we need to flip
            if ((arr[i] + currentFlips) % 2 == 0) {
                if (i + k > n) return -1;  // not enough elements to flip
                isFlipped[i] = 1;
                currentFlips++;
                flips++;
            }
        }

        return flips;
    }
};
