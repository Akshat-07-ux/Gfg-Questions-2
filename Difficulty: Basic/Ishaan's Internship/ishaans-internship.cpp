int getCandidate(int n, int k) {
    // We start with the first power of k
    long long position = 1;
    
    // While we can still form at least k groups of the current "step" size
    // we multiply by k to simulate the next round of elimination.
    // The smallest remaining position after a round is always the 
    // current cumulative power of k.
    while (position * k <= n) {
        position *= k;
    }
    
    return (int)position;
}