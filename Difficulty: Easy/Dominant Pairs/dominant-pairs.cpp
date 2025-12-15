class Solution {
  public:
    int dominantPairs(int n, vector<int> &arr) {
        int mid = n / 2;
        
        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());
        
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        
        int count = 0;
        int j = 0;
        
        for (int i = 0; i < left.size(); i++) {
            while (j < right.size() && left[i] >= 5LL * right[j]) {
                j++;
            }
            count += j;
        }
        
        return count;
    }
};
