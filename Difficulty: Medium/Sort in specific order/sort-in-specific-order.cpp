class Solution {
public:
    void sortIt(vector<int>& arr) {
        vector<int> odd, even;
        
        // Separate odd and even
        for(int x : arr) {
            if(x % 2 != 0) odd.push_back(x);
            else even.push_back(x);
        }
        
        // Sort odd in descending
        sort(odd.begin(), odd.end(), greater<int>());
        
        // Sort even in ascending
        sort(even.begin(), even.end());
        
        // Merge back
        int idx = 0;
        for(int x : odd) arr[idx++] = x;
        for(int x : even) arr[idx++] = x;
    }
};
