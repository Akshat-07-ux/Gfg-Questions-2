#include <algorithm>

using namespace std;

long long int calculate(int a[], int n) {
    // Sort the array to bring identical elements together.
    // Sorting takes O(N log N) time and O(1) auxiliary space.
    sort(a, a + n);
    
    long long int total_pairs = 0;
    long long int current_frequency = 1;
    
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            // Increment frequency if the element is the same as the previous one
            current_frequency++;
        } else {
            // Calculate pairs formed by the previous group of identical elements
            total_pairs += (current_frequency * (current_frequency - 1)) / 2;
            current_frequency = 1; // Reset frequency for the new element
        }
    }
    
    // Add the pairs for the last group of identical elements
    total_pairs += (current_frequency * (current_frequency - 1)) / 2;
    
    return total_pairs;
}