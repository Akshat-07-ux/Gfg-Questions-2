class Solution:
    def maxStackHeight(self, r, h):
        # code here
       diks = sorted(zip(r, h), key=lambda x: (x[0], -x[1]))
       
       maxih = max(h)
       bit = [0] * (maxih + 1)
       
       def update(i, val):
           while i <= maxih:
               bit[i] = max(bit[i], val)
               i += i & -i
               
       def query(i):
            res = 0
            while i > 0:
                res = max(res, bit[i])
                i -= i & -i
                
            return res
            
            
            
       ans = 0
       for rad, ht in diks:
           cur = query(ht - 1) + ht
           ans = max(ans, cur)
           update(ht, cur)
            
       return ans