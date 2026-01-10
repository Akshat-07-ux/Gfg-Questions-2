class Solution {
  public:
    vector<int> reverseSubArray(vector<int> &arr, int l, int r) {
        // convert to 0-based indexing
        l--;
        r--;
        
        while (l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        
        return arr;
    }
};
