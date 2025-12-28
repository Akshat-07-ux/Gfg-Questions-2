class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        unordered_map<int, int> freq;
        vector<vector<int>> ans;
        vector<int> top;

        for (int i = 0; i < N; i++) {
            int x = arr[i];
            freq[x]++;

            // Remove x if already present
            auto it = find(top.begin(), top.end(), x);
            if (it != top.end()) {
                top.erase(it);
            }

            // Find correct position to insert x
            int pos = 0;
            while (pos < top.size()) {
                if (freq[x] > freq[top[pos]] ||
                   (freq[x] == freq[top[pos]] && x < top[pos])) {
                    break;
                }
                pos++;
            }

            top.insert(top.begin() + pos, x);

            // Keep only top K elements
            if (top.size() > K)
                top.pop_back();

            ans.push_back(top);
        }

        return ans;
    }
};
