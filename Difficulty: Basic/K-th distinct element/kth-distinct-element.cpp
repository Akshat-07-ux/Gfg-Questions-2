class Solution {
  public:
    int KthDistinct(vector<int> nums, int k) {
        unordered_map<int,int> freq;
        
        // Count frequency of each number
        for (int x : nums) {
            freq[x]++;
        }
        
        // Now iterate in original order and check distincts
        int count = 0;
        for (int x : nums) {
            if (freq[x] == 1) {  // distinct element
                count++;
                if (count == k) return x;
            }
        }
        
        return -1; // if kth distinct not found
    }
};
