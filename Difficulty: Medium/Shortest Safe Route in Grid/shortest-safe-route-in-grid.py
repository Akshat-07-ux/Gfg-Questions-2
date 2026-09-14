from collections import deque

class Solution:
    def shortestPath(self, mat: list[list[int]]) -> int:
        # code here
        a = len(mat)
        b = len(mat[0])
        
        safe = [[True] * b for _ in range(a)]
        
        for i in range(a):
            for j in range(b):
                if mat[i][j] == 0:
                    safe[i][j] = False
                    
                    for rd, cd in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                        ni, nj = i + rd, j + cd
                        if 0 <= ni < a and 0 <= nj < b:
                            safe[ni][nj] = False
                            
        queue = deque()
        visit = [[False] * b for _ in range(a)]
        
        for i in range(a):
            if safe[i][0]:
                queue.append((i, 0, 1))
                visit[i][0] = True
                
        while queue:
            r,c, dis = queue.popleft()
            
            if c == b - 1:
                return dis
                
            for rd, cd in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + rd, c + cd
                if 0 <= nr < a and 0 <= nc < b and safe[nr][nc] and not visit[nr][nc]:
                    visit[nr][nc] = True
                    queue.append((nr, nc, dis + 1))
                    
        return -1
        