class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        int result = 0;

        for(int i = 0; i < n; i++) {
            long long count = 1LL * (i + 1) * (n - i);
            
            // If count is odd, arr[i] contributes to final XOR
            if(count % 2 == 1) {
                result ^= arr[i];
            }
        }
        
        return result;
    }
};
