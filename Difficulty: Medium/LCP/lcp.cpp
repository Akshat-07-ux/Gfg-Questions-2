class Solution {
  public:
    string LCP(string ar[], int n) {
        if (n == 0) return "-1";
        if (n == 1) return ar[0];

        // Sort the array to bring lexicographically smallest and largest to ends
        // Complexity: O(N * max_len * log N)
        sort(ar, ar + n);

        string first = ar[0];
        string last = ar[n - 1];
        string result = "";

        // Compare the first and last strings only
        for (int i = 0; i < first.size(); i++) {
            if (first[i] == last[i]) {
                result += first[i];
            } else {
                break;
            }
        }

        // Return result or -1 if no prefix exists
        return (result.size() > 0) ? result : "-1";
    }
};