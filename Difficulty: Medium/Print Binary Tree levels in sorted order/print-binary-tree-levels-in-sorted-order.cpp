class Solution {
  public:
    vector<vector<int>> binTreeSortedLevels(int arr[], int n) {
        vector<vector<int>> result;
        int i = 0;       // Starting index of the current level
        int levelLen = 1; // Number of nodes expected at the current level

        while (i < n) {
            vector<int> currentLevel;
            
            // Collect nodes for the current level, ensuring we don't go out of bounds
            for (int j = 0; j < levelLen && i < n; j++) {
                currentLevel.push_back(arr[i]);
                i++;
            }
            
            // Sort the nodes of the current level
            sort(currentLevel.begin(), currentLevel.end());
            
            // Store the sorted level in the result
            result.push_back(currentLevel);
            
            // The next level in a complete binary tree has double the nodes
            levelLen *= 2;
        }
        
        return result;
    }
};