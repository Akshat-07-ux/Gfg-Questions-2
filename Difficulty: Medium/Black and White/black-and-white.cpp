long long numOfWays(int N, int M) {
    const long long MOD = 1000000007;
    long long cells = 1LL * N * M;

    // Total ways to place two knights on different squares
    long long total = (cells % MOD) * ((cells - 1) % MOD) % MOD;

    // Ways where knights attack each other
    long long invalid = 0;

    if (N > 1 && M > 2)
        invalid = (invalid + 4LL * (N - 1) * (M - 2)) % MOD;

    if (N > 2 && M > 1)
        invalid = (invalid + 4LL * (N - 2) * (M - 1)) % MOD;

    long long result = (total - invalid + MOD) % MOD;
    return result;
}
