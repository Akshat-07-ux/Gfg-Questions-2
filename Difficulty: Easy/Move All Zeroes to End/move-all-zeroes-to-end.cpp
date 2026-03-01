class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int count = 0; // Index of the next available position for a non-zero element

        for (int i = 0; i < arr.size(); i++) {
            // If the current element is non-zero
            if (arr[i] != 0) {
                // Swap it with the element at 'count' index
                // This moves the non-zero element forward and pushes a zero back
                swap(arr[i], arr[count]);
                count++;
            }
        }
    }
};