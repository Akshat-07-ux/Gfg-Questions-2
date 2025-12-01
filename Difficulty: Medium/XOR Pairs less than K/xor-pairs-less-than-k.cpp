class Solution {
public:
    struct Trie {
        Trie* child[2];
        int count;
        Trie() {
            child[0] = child[1] = nullptr;
            count = 0;
        }
    };
    
    Trie* root = new Trie();
    const int MAX_BIT = 15; // since arr[i], k <= 50000 < 2^16
    
    void insert(int num) {
        Trie* cur = root;
        for (int b = MAX_BIT; b >= 0; b--) {
            int bit = (num >> b) & 1;
            if (!cur->child[bit])
                cur->child[bit] = new Trie();
            cur = cur->child[bit];
            cur->count++;
        }
    }

    int query(int num, int k) {
        Trie* cur = root;
        int res = 0;

        for (int b = MAX_BIT; b >= 0; b--) {
            if (!cur) break;

            int xBit = (num >> b) & 1;
            int kBit = (k >> b) & 1;

            if (kBit == 1) {
                if (cur->child[xBit])  
                    res += cur->child[xBit]->count;
                cur = cur->child[1 - xBit];
            } else {
                cur = cur->child[xBit];
            }
        }

        return res;
    }
    
    int cntPairs(vector<int>& arr, int k) {
        int ans = 0;
        for (int x : arr) {
            ans += query(x, k);
            insert(x);
        }
        return ans;
    }
};
