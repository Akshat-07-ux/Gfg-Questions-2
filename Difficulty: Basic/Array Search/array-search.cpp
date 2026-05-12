class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // Iterate through the array starting from the first element
        for (int i = 0; i < arr.size(); i++) {
            // If the current element matches x, return the current index
            if (arr[i] == x) {
                return i;
            }
        }
        
        // If the loop completes, the element was not found
        return -1;
    }
};