class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        sort(A, A + N);

        long long start = K1;     // element just after K1-th smallest
        long long end   = K2 - 2; // element just before K2-th smallest
        
        long long sum = 0;
        for(long long i = start; i <= end; i++) {
            sum += A[i];
        }
        
        return sum;
    }
};
