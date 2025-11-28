class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;

        
        int X = 0;
        for(int i = 1; i <= n; i++) X ^= i;

        
        if (X == n) {
            ans.resize(n);
            iota(ans.begin(), ans.end(), 1);
            return ans;
        }

        
        int k = X ^ n;  
        
        if (1 <= k && k <= n) {
            // include all except k
            for (int i = 1; i <= n; i++)
                if (i != k) ans.push_back(i);
            return ans;
        }

        
        int j = (X ^ n ^ 1);
        for (int i = 1; i <= n; i++)
            if (i != 1 && i != j) ans.push_back(i);

        return ans;
    }
};
