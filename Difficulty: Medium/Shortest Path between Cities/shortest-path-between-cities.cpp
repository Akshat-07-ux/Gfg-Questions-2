class Solution {
  public:
    int shortestPath(int x, int y) {
        int steps = 0;
        
        // Move both nodes up until they meet at the Lowest Common Ancestor
        while (x != y) {
            if (x > y) {
                x /= 2; // Move x to its parent
            } else {
                y /= 2; // Move y to its parent
            }
            steps++; // Each move up is one edge in the path
        }
        
        return steps;
    }
};