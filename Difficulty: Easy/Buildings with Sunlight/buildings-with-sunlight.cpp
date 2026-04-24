class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // Handle empty array case
        if (arr.empty()) return 0;
        
        int count = 0;
        int current_max = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            // A building receives sunlight if it is at least as tall 
            // as the tallest building to its left.
            if (arr[i] >= current_max) {
                count++;
                current_max = arr[i];
            }
        }
        
        return count;
    }
};