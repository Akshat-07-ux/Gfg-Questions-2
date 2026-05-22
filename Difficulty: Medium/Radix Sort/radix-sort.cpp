#include <algorithm>
#include <vector>

using namespace std;

// A utility function to do counting sort of arr[] according to
// the digit represented by exp (e.g., exp is 1, 10, 100, etc.)
void countingSortForRadix(int arr[], int n, int exp) {
    vector<int> output(n); // Output array that will hold sorted elements temporarily
    int count[10] = {0};   // Base 10 digits (0-9)

    // Store count of occurrences of each digit in count[]
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so that count[i] now contains the actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by processing from right to left
    // to maintain the stable sorting property
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main function to implement Radix Sort
void radixSort(int arr[], int n) {
    if (n <= 1) return;

    // Find the maximum number to know the number of digits
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Do counting sort for every digit. Instead of passing digit number, 
    // exp is passed. exp is 10^i where i is current digit number.
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, n, exp);
    }
}