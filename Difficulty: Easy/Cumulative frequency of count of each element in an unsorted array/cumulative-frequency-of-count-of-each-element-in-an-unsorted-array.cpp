class Solution {
  public:
    vector<int> countFreq(vector<int>& arr) {
        map<int, int> freq;
        
        // Step 1: Count frequencies
        for (int x : arr) {
            freq[x]++;
        }
        
        vector<int> result;
        int cumulative = 0;
        
        // Step 2: Traverse in sorted order
        for (auto &p : freq) {
            cumulative += p.second;
            result.push_back(cumulative);
        }
        
        return result;
    }
};
