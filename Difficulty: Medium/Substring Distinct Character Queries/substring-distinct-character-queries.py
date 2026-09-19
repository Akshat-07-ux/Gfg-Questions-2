class Solution:
    def solveQueries(self, s, queries):
        # code here
        l = len(s)
        
        pre = [[0] * 26 for _ in range(l + 1)]
        
        for i in range(l):
            pre[i + 1] = list(pre[i])
            pre[i + 1][ord(s[i]) - ord('a')] += 1
            
        win = []
        
        for c, r in queries:
            dis_count = 0
            
            for z in range(26):
                if pre[r][z] - pre[c - 1][z] > 0:
                    dis_count += 1
            win.append(dis_count)
            
        return win