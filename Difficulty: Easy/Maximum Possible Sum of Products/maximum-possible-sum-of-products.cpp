#include <algorithm>

long long MaxSum(long long int A[], long long int B[], long long int N) {
    // Sort both arrays in ascending order
    // Time Complexity: O(N log N)
    std::sort(A, A + N);
    std::sort(B, B + N);
    
    long long totalMaxSum = 0;
    
    // Multiply corresponding elements to maximize the product sum
    for (long long i = 0; i < N; i++) {
        totalMaxSum += (A[i] * B[i]);
    }
    
    return totalMaxSum;
}