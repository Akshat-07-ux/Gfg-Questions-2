class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        long long ans = 0;
        unordered_map<int, int> freq;
        
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            freq[arr[right]]++;
            
            while (freq.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                left++;
            }
            
            ans += (right - left + 1);
        }
        
        return ans;
    }
};
