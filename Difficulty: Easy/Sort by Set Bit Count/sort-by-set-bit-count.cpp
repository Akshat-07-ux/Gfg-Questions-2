class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // We use stable_sort to ensure that elements with the same 
        // number of set bits maintain their original relative order.
        stable_sort(arr.begin(), arr.end(), [](int a, int b) {
            // __builtin_popcount is a built-in GCC function that returns 
            // the number of set bits (1s) in an integer.
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            // Sort in descending order of set bit counts
            return countA > countB;
        });
        
        return arr;
    }
};