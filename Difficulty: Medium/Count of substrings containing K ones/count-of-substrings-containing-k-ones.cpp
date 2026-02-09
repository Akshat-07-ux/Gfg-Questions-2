class Solution {
  public:
    long long int countOfSubstringWithKOnes(string S, int K) {
        long long int count = 0;
        int current_sum = 0;
        int n = S.length();
        
        // frequency array to store occurrences of prefix sums
        // Since max sum is N, size N+1 is sufficient
        vector<int> freq(n + 1, 0);
        
        // Base case: a prefix sum of 0 has been seen once (empty prefix)
        freq[0] = 1;
        
        for (char c : S) {
            // Update current prefix sum of 1s
            current_sum += (c - '0');
            
            // If current_sum >= K, find how many times (current_sum - K) 
            // has appeared as a prefix sum before
            if (current_sum >= K) {
                count += freq[current_sum - K];
            }
            
            // Store the current prefix sum in the frequency map
            freq[current_sum]++;
        }
        
        return count;
    }
};