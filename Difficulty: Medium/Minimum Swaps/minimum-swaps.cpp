class Solution {
public:
    int minimumSwaps(int pos[], int v[], int n, int k, int b, int t) {
        int swaps = 0;
        int reachableSheep = 0;
        int slowSheepCount = 0;

        // Process sheep from right to left (closest to barn first)
        for (int i = n - 1; i >= 0; i--) {
            // Check if this sheep can naturally reach the barn in time T
            // Distance to cover: (b - pos[i])
            // Distance it can cover: (long long)v[i] * t
            if ((long long)pos[i] + (long long)v[i] * t >= b) {
                // This sheep is "Fast"
                reachableSheep++;
                
                // If there are slow sheep in front of it, 
                // we must swap this fast sheep past all of them.
                swaps += slowSheepCount;
            } else {
                // This sheep is "Slow" and will block any fast sheep behind it
                slowSheepCount++;
            }

            // Once we have secured K sheep reaching the barn
            if (reachableSheep >= k) {
                return swaps;
            }
        }

        // If we exhausted the loop and couldn't get K sheep
        return -1;
    }
};