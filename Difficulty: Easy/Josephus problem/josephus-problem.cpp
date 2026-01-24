class Solution {
  public:
    int josephus(int n, int k) {
        int survivor = 0; // Base case: for 1 person, the survivor is at index 0
        
        // Iterate from 2 people up to n people
        for (int i = 2; i <= n; i++) {
            survivor = (survivor + k) % i;
        }
        
        // Convert 0-based index to 1-based index
        return survivor + 1;
    }
};