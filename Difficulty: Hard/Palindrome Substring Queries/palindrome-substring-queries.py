class Solution:
    def palQueries(self, s, queries):
        n = len(s)
        MOD, B = 10**9 + 7, 31
        p, rp, pw = [0], [0], [1] * (n + 1)

        for i in range(1, n + 1): 
            pw[i] = (pw[i - 1] * B) % MOD

        for c, rc in zip(s, s[::-1]):
            p.append((p[-1] * B + (ord(c) - 96)) % MOD)
            rp.append((rp[-1] * B + (ord(rc) - 96)) % MOD)

        get = lambda arr, l, r: (arr[r + 1] - arr[l] * pw[r - l + 1]) % MOD

        return [int(get(p, l, r) == get(rp, n - 1 - r, n - 1 - l)) for l, r in queries]