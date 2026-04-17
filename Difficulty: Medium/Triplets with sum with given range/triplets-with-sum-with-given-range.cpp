#include <algorithm>
#include <vector>

class Solution {
  public:
    // Helper function to count triplets with sum <= target
    int countTripletsLessThanOrEqual(int Arr[], int N, int target) {
        int count = 0;
        
        for (int i = 0; i < N - 2; i++) {
            int left = i + 1;
            int right = N - 1;
            
            while (left < right) {
                int currentSum = Arr[i] + Arr[left] + Arr[right];
                
                if (currentSum <= target) {
                    // If the sum is <= target, then Arr[i] + Arr[left] 
                    // added to any element from left+1 to right is also <= target
                    count += (right - left);
                    left++;
                } else {
                    // Sum is too large, decrease the right pointer
                    right--;
                }
            }
        }
        return count;
    }

    int countTriplets(int Arr[], int N, int L, int R) {
        // Step 1: Sort the array to use two-pointer technique
        std::sort(Arr, Arr + N);
        
        // Step 2: Use the property Count(L, R) = Count(<=R) - Count(<=L-1)
        int countR = countTripletsLessThanOrEqual(Arr, N, R);
        int countLMinus1 = countTripletsLessThanOrEqual(Arr, N, L - 1);
        
        return countR - countLMinus1;
    }
};