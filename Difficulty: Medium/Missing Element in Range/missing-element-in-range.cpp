class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<int> result;
        
        // Use a hash set to store elements of the array
        unordered_set<int> s(arr.begin(), arr.end());
        
        // Check each number in range [low, high]
        for (int i = low; i <= high; i++) {
            if (s.find(i) == s.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
