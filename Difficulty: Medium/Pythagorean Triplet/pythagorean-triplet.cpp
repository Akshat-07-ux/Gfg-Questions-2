class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // Since max value is 1000, max squared value is 1,000,000
        vector<bool> exists(1001, false);
        int max_val = 0;

        // Mark the presence of elements and find the range
        for (int x : arr) {
            exists[x] = true;
            if (x > max_val) max_val = x;
        }

        // Iterate through all possible pairs of a and b
        for (int i = 1; i <= max_val; i++) {
            if (!exists[i]) continue;

            for (int j = i; j <= max_val; j++) {
                if (!exists[j]) continue;

                // Calculate a^2 + b^2
                int val = i * i + j * j;
                int c = sqrt(val);

                // Check if c is an integer, within range, and exists in the array
                if (c * c == val && c <= 1000 && exists[c]) {
                    return true;
                }
            }
        }

        return false;
    }
};