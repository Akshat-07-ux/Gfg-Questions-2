#include <vector>

class Solution {
  private:
    // A function to do counting sort of arr[] according to the digit represented by 'exp'
    void countingSort(int arr[], int n, int exp) {
        std::vector<int> output(n);
        std::vector<int> count(n, 0);

        // Store count of occurrences in count[]
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % n;
            count[digit]++;
        }

        // Change count[i] so that count[i] now contains actual
        // position of this digit in output[]
        for (int i = 1; i < n; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array (traverse backwards to maintain stability)
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % n;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // Copy the output array to arr[], so that arr[] now
        // contains sorted numbers according to current digit
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

  public:
    void sort(int arr[], int n) {
        // Step 1: Sort based on the least significant digit: (arr[i] / 1) % n
        countingSort(arr, n, 1);
        
        // Step 2: Sort based on the most significant digit: (arr[i] / n) % n
        countingSort(arr, n, n);
    }
};