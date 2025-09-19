class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // Step 1: Check lengths
        if(M != N) return 0;
        
        int i = 0, j = 0;
        
        while(i < M && j < N) {
            // Skip '#' in S
            while(i < M && S[i] == '#') i++;
            // Skip '#' in T
            while(j < N && T[j] == '#') j++;
            
            // If both reached end, break
            if(i == M && j == N) break;
            
            // If only one reached end, impossible
            if((i == M) != (j == N)) return 0;
            
            // Characters must match
            if(S[i] != T[j]) return 0;
            
            // 'A' can only move left: S index >= T index
            if(S[i] == 'A' && i < j) return 0;
            
            // 'B' can only move right: S index <= T index
            if(S[i] == 'B' && i > j) return 0;
            
            i++; j++;
        }
        
        // Skip remaining '#' in S and T
        while(i < M && S[i] == '#') i++;
        while(j < N && T[j] == '#') j++;
        
        // Both must reach end
        return (i == M && j == N) ? 1 : 0;
    }
};
