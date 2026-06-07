class Solution {
  public:
    string profession(int level, int pos) {
        // Change to 0-indexed position
        int index = pos - 1;
        
        // Count the number of set bits (1s) in the binary representation of index
        int setBits = __builtin_popcount(index);
        
        // If odd number of 1s -> Doctor, if even -> Engineer
        if (setBits % 2 != 0) {
            return "Doctor";
        } else {
            return "Engineer";
        }
    }
};