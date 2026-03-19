class Solution {
  public:
    // Function to search x in arr
    // arr: input array
    // n: size of the array
    // x: element to be searched for
    int search(int arr[], int n, int x) {
        
        // Iterate through the array from start to end
        for (int i = 0; i < n; i++) {
            
            // If the current element matches x, return its index
            if (arr[i] == x) {
                return i;
            }
        }
        
        // If the loop finishes without finding x, return -1
        return -1;
    }
};