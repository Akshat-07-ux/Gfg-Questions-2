#include <iostream>
#include <algorithm> // Required for sort
#include <vector>
#include <string>

using namespace std;

/**
 * Sorts the array of any template type T.
 * Works for int, float/double, and string because they 
 * all support the '<' operator.
 */
template <class T>
void sortArray(T a[], int n) {
    // std::sort uses Introsort (a hybrid of Quicksort, Heapsort, and Insertion Sort)
    // Complexity: O(n log n)
    sort(a, a + n);
}

/**
 * Prints the elements of the array separated by a space.
 */
template <class T>
void printArray(T a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}