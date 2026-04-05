#include <vector>
#include <algorithm>

using namespace std;

vector<int> reaching_height(int n, int a[]) {
    // Sort the array to easily pick the smallest and largest values
    sort(a, a + n);
    
    vector<int> result(n);
    int left = 0;          // Pointer for smallest elements (Down moves)
    int right = n - 1;     // Pointer for largest elements (Up moves)
    
    for (int i = 0; i < n; i++) {
        // According to 1-based indexing:
        // Odd index (1, 3, 5...) -> Up move (Use largest available)
        // Even index (2, 4, 6...) -> Down move (Use smallest available)
        if (i % 2 == 0) {
            result[i] = a[right--];
        } else {
            result[i] = a[left++];
        }
    }
    
    // Safety check: Ensure the elevator never reaches floor 0 or below
    long long current_floor = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            current_floor += result[i]; // Moving Up
        } else {
            current_floor -= result[i]; // Moving Down
        }
        
        if (current_floor <= 0) {
            return {-1};
        }
    }
    
    return result;
}