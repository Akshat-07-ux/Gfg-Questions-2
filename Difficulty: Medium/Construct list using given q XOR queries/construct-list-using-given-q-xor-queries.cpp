class Solution {
public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        
        vector<int> s;
        s.push_back(0);    // initial list contains 0
        
        int lazyXor = 0;   // global XOR to be applied lazily
        
        for (auto &qr : queries) {
            int type = qr[0];
            int x = qr[1];
            
            if (type == 0) {
                // Insert x, but store it XORed with lazyXor
                s.push_back(x ^ lazyXor);
            }
            else {
                // XOR all elements -> update lazy xor
                lazyXor ^= x;
            }
        }
        
        // Apply final XOR and sort
        for (int &a : s)
            a ^= lazyXor;
        
        sort(s.begin(), s.end());
        
        return s;
    }
};
