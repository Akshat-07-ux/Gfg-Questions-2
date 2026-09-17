from collections import deque

class Solution:
    def minimumEdgeReversal(self, edges: list[list[int]], n: int, src: int, dst: int) -> int:
        # code here
        
        grp = [[] for _ in range(n + 1)]
        
        for a, b in edges:
            grp[a].append((b, 0))
            grp[b].append((a, 1))
            
            
        dis = [float('inf')]*(n + 1)
        
        dis[src] = 0
        dq = deque([src])
        
        while dq:
            cur = dq.popleft()
            
            if cur == dst:
                return dis[dst]
                
            for neig, wgt in grp[cur]:
                if dis[cur] + wgt < dis[neig]:
                    dis[neig] = dis[cur] + wgt
                    if wgt == 0:
                        dq.appendleft(neig)
                    else:
                        dq.append(neig)
                        
        return dis[dst] if dis[dst] != float('inf') else -1
        