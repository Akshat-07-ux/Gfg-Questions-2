class Solution {
public:
    vector<int> calculateZ(string &input) {
        int n = input.size();
        vector<int> Z(n, 0);
        int left = 0, right = 0;
        
        for(int k = 1; k < n; k++) {
            if(k > right) {
                left = right = k;
                while(right < n && input[right] == input[right - left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            } else {
                int k1 = k - left;
                if(Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else {
                    left = k;
                    while(right < n && input[right] == input[right - left]) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }
    
    int getLongestPrefix(string &s) {
        int n = s.size();
        vector<int> z = calculateZ(s);
        
        for(int i = n - 1; i >= 1; i--) {
            if(z[i] == n - i) {
                return i;
            }
        }
        return -1;
    }
};