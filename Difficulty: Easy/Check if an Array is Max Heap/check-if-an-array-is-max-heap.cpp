class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n = arr.size();
        
        // Iterate through all internal nodes
        for (int i = 0; i <= (n - 2) / 2; i++) {
            
            // Check if left child exists and is greater than parent
            int leftChild = 2 * i + 1;
            if (leftChild < n && arr[leftChild] > arr[i]) {
                return false;
            }
            
            // Check if right child exists and is greater than parent
            int rightChild = 2 * i + 2;
            if (rightChild < n && arr[rightChild] > arr[i]) {
                return false;
            }
        }
        
        return true;
    }
};