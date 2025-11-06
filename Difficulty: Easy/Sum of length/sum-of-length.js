// User function Template for javascript

class Solution {
    // Function to find the sum of lengths of all subarrays with distinct elements
    sumoflength(arr) {
        const MOD = 1e9 + 7;
        const n = arr.length;
        let seen = new Map();  // stores last index of elements
        let start = 0;
        let ans = 0;

        for (let end = 0; end < n; end++) {
            // If duplicate found, move start pointer
            if (seen.has(arr[end]) && seen.get(arr[end]) >= start) {
                start = seen.get(arr[end]) + 1;
            }

            // Mark last index of arr[end]
            seen.set(arr[end], end);

            // Count of subarrays ending at 'end' = end - start + 1
            let len = end - start + 1;

            // Sum of lengths contributed by these subarrays
            // Formula for sum of first k natural numbers = k*(k+1)/2
            ans = (ans + len) % MOD;
        }

        // The above counts number of subarrays, not sum of their lengths.
        // To get sum of lengths, we need to add sum of lengths for each window size:
        // For each valid subarray ending at end, lengths = 1 + 2 + ... + len = len*(len+1)/2
        // So fix the formula inside the loop:
        ans = 0;
        start = 0;
        seen.clear();

        for (let end = 0; end < n; end++) {
            if (seen.has(arr[end]) && seen.get(arr[end]) >= start) {
                start = seen.get(arr[end]) + 1;
            }
            seen.set(arr[end], end);
            let len = end - start + 1;
            // add sum of lengths of all distinct subarrays ending at 'end'
            ans = (ans + (len * (len + 1)) / 2) % MOD;
        }

        return ans % MOD;
    }
}
