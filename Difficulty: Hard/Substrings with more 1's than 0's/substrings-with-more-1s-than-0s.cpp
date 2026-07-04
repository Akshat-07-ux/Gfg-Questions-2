#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    // Fenwick Tree (Binary Indexed Tree) helper functions
    void update(vector<int>& bit, int index, int delta, int size) {
        for (; index < size; index += index & -index) {
            bit[index] += delta;
        }
    }

    int query(vector<int>& bit, int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += bit[index];
        }
        return sum;
    }

public:
    int countSubstring(string& s) {
        int n = s.length();
        
        // The maximum possible prefix sum is n, minimum is -n.
        // We shift everything by + (n + 1) to keep indices positive for the BIT.
        int offset = n + 1;
        int bit_size = 2 * n + 2;
        vector<int> bit(bit_size, 0);
        
        int current_sum = 0;
        int count = 0;
        
        // Initialize the BIT with the initial prefix sum of 0 (at index 0 before any elements)
        update(bit, current_sum + offset, 1, bit_size);
        
        for (char c : s) {
            // 1 contributes +1, 0 contributes -1
            current_sum += (c == '1') ? 1 : -1;
            
            // We need to count all previous prefix sums strictly less than current_sum.
            // With offset, we query up to (current_sum + offset - 1).
            count += query(bit, current_sum + offset - 1);
            
            // Add the current prefix sum to the Fenwick Tree
            update(bit, current_sum + offset, 1, bit_size);
        }
        
        return count;
    }
};