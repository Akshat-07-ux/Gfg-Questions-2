class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.size();
        // record the last occurrence of each digit
        vector<int> last(10, -1);
        
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }
        
        // traverse from left to right
        for (int i = 0; i < n; i++) {
            // try to find a larger digit to swap with (from 9 down to current+1)
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) { // found a candidate later in string
                    swap(s[i], s[last[d]]);
                    return s; // only one swap allowed
                }
            }
        }
        
        return s; // no swap possible, already max
    }
};
