class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        int low = 1;
        int high = 0;
        
        // The maximum speed needed is the size of the largest pile
        for (int pile : arr) {
            high = max(high, pile);
        }
        
        int result = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canFinish(arr, k, mid)) {
                result = mid; // This speed works, try to find a smaller one
                high = mid - 1;
            } else {
                low = mid + 1; // Too slow, increase speed
            }
        }
        
        return result;
    }

private:
    bool canFinish(const vector<int>& arr, int k, int speed) {
        long long totalHours = 0;
        for (int pile : arr) {
            // Calculate ceil(pile / speed)
            totalHours += (pile + speed - 1) / speed;
            
            // Optimization: if hours exceed k, no need to continue
            if (totalHours > k) return false;
        }
        return totalHours <= k;
    }
};