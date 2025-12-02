class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();

        // Characters that occur in s
        vector<bool> used(256, false);
        for (char c : s) used[(unsigned char)c] = true;

        // positions of each char
        vector<vector<int>> pos(256);
        for (int i = 0; i < n; i++)
            pos[(unsigned char)s[i]].push_back(i);

        // adjacency list: only valid transitions & only if target char is used in s
        vector<vector<unsigned char>> adj(256);
        for (auto &p : jumps) {
            unsigned char a = p[0], b = p[1];
            if (used[b]) adj[a].push_back(b);
        }

        // same-char jumps allowed
        for (int c = 0; c < 256; c++) {
            if (used[c]) adj[c].push_back(c);
        }

        // prefix ascii sums
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (int)s[i];

        // prefix freq ONLY for used characters
        vector<vector<int>> freq(256);
        for (int c = 0; c < 256; c++) {
            if (used[c]) {
                freq[c].resize(n + 1, 0);
                for (int i = 0; i < n; i++)
                    freq[c][i + 1] = freq[c][i] + (s[i] == char(c));
            }
        }

        vector<long long> dp(n, -1e18);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] < 0) continue;

            unsigned char from = s[i];

            // go through only relevant transitions
            for (unsigned char to : adj[from]) {

                // only the next occurrence
                auto &vec = pos[to];
                auto it = upper_bound(vec.begin(), vec.end(), i);
                if (it == vec.end()) continue;

                int j = *it;

                // compute score
                long long total = pref[j] - pref[i];
                int countTo = freq[to][j] - freq[to][i];
                long long subtract = 1LL * to * countTo;
                long long gain = total - subtract;

                long long newScore = dp[i] + gain;
                if (newScore > dp[j]) dp[j] = newScore;
            }
        }

        long long ans = 0;
        for (auto v : dp) ans = max(ans, v);
        return (int)ans;
    }
};
