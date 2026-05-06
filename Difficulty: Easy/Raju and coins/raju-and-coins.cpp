#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxNumbers(int n, int k, int a[]) {
        // Sort the array to find missing numbers in sequence
        std::sort(a, a + n);
        
        long long current_k = k;
        int count = 0;
        long long next_expected = 1;

        for (int i = 0; i < n; i++) {
            // Handle duplicates in the input array
            if (a[i] < next_expected) continue;

            if (a[i] > next_expected) {
                // We have a gap of missing numbers: [next_expected, a[i] - 1]
                long long gap_size = a[i] - next_expected;
                
                // Calculate sum of the entire gap using Arithmetic Progression
                // Sum = (n/2) * (first + last)
                long long first = next_expected;
                long long last = a[i] - 1;
                unsigned __int128 gap_sum = (unsigned __int128)gap_size * (first + last) / 2;

                if (gap_sum <= (unsigned __int128)current_k) {
                    current_k -= (long long)gap_sum;
                    count += (int)gap_size;
                } else {
                    // Cannot fit whole gap, find how many we can take from 'first' onwards
                    // Solve for 'm': m*first + m*(m-1)/2 <= current_k
                    // Using a simple loop or binary search is safe here as it's the final step
                    long long low = 0, high = gap_size, best_m = 0;
                    while (low <= high) {
                        long long mid = low + (high - low) / 2;
                        unsigned __int128 mid_sum = (unsigned __int128)mid * first + (unsigned __int128)mid * (mid - 1) / 2;
                        if (mid_sum <= (unsigned __int128)current_k) {
                            best_m = mid;
                            low = mid + 1;
                        } else {
                            high = mid - 1;
                        }
                    }
                    return count + (int)best_m;
                }
            }
            // Move expectation to the number after the one present in array
            next_expected = (long long)a[i] + 1;
        }

        // After checking all elements in 'a', pick remaining smallest numbers
        long long low = 0, high = 1e9, best_m = 0; // Use high = 1e9 as per constraints
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            unsigned __int128 mid_sum = (unsigned __int128)mid * next_expected + (unsigned __int128)mid * (mid - 1) / 2;
            if (mid_sum <= (unsigned __int128)current_k) {
                best_m = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return count + (int)best_m;
    }
};