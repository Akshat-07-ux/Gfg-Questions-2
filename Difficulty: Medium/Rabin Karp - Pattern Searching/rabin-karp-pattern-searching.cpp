// User function Template for C++

// d is the number of characters in the input alphabet
#define d 256

// Function to check if the pattern is present in string or not.
bool search(string pat, string txt, int q) {
    int M = pat.size();
    int N = txt.size();

    if (M > N) return false;

    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1) % q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text
    for (i = 0; i <= N - M; i++) {
        // Check if hash values match
        if (p == t) {
            // Check characters one by one
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }

            if (j == M) return true; // match found
        }

        // Calculate hash value for next window
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // Convert negative hash to positive
            if (t < 0) t = (t + q);
        }
    }

    return false; // not found
}
