class Solution:
    def diffArray(self, arr, opr):
        # code here
        l = len(arr)
        difference = [0] * (l + 1)
        
        for a,r, v in opr:
            difference[a] += v
            if r + 1 < l:
                difference[r + 1] -= v
                
        current = 0
        for i in range(l):
            current += difference[i]
            arr[i] += current
            
        return arr