class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] >= x) {
                ans = mid;          // potential ceil
                high = mid - 1;     // look for earlier occurrence
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
