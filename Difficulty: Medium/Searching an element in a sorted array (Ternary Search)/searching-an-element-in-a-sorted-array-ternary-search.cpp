class Solution {
  public:
    // Function to find element in sorted array
    int ternarySearch(int arr[], int N, int K) {
        
        int left = 0, right = N - 1;
        
        while (left <= right) {
            
            // Divide range into 3 parts
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            
            // Check mid1
            if (arr[mid1] == K) 
                return 1;
            
            // Check mid2
            if (arr[mid2] == K) 
                return 1;
            
            // If K is less than mid1 → search left segment
            if (K < arr[mid1]) {
                right = mid1 - 1;
            }
            // If K is greater than mid2 → search right segment
            else if (K > arr[mid2]) {
                left = mid2 + 1;
            }
            // Else search middle segment
            else {
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }
        
        return -1; // not found
    }
};
