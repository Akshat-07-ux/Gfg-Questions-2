class Solution {
  public:
    vector<int> arranged(vector<int>& arr) {
        
        vector<int> pos, neg;
        
        // Separate positives and negatives
        for (int x : arr) {
            if (x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }
        
        vector<int> result;
        int i = 0, j = 0;
        
        // Alternate starting with positive
        while (i < pos.size() && j < neg.size()) {
            result.push_back(pos[i++]);
            result.push_back(neg[j++]);
        }
        
        return result;
    }
};