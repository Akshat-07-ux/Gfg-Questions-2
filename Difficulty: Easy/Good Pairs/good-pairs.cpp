class Solution {
  public:
    long long solve(int arr[], int n) {
        // Sort the array to bring identical elements together
        sort(arr, arr + n);
        
        long long totalPairs = 0;
        
        for (int i = 0; i < n; i++) {
            // Find the first element that is strictly greater than arr[i]
            // upper_bound returns an iterator to the first element > arr[i]
            auto it = upper_bound(arr, arr + n, arr[i]);
            
            // The number of elements strictly greater than arr[i] 
            // is the distance from 'it' to the end of the array
            long long countGreater = (arr + n) - it;
            
            totalPairs += countGreater;
        }
        
        return totalPairs;
    }
};