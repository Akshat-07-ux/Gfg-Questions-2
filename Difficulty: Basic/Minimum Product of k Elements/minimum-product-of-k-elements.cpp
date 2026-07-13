#include <vector>
#include <algorithm>

class Solution {
  public:
    int minProduct(std::vector<int> &arr, int k) {
        // Step 1: Sort the array to bring the smallest positive integers to the front
        std::sort(arr.begin(), arr.end());
        
        long long product = 1;
        long long MOD = 1000000007; // Using exact integer literal
        
        // Safety check: Ensure we don't loop out of bounds if k > arr.size()
        int elements_to_multiply = std::min(k, (int)arr.size());
        
        // Step 2: Multiply the smallest elements
        for (int i = 0; i < elements_to_multiply; i++) {
            product = (product * arr[i]) % MOD;
        }
        
        return product;
    }
};