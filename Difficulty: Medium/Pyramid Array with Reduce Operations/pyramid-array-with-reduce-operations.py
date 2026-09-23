class Solution:
    def formPyramid(self, arr):
        # code here 
        l = len(arr)
        total = sum(arr)
        
        left = [0] * l
        right = [0] * l
        
        left[0] = min(1, arr[0])
        for i in range(1, l):
            left[i] = min(arr[i], left[i - 1] + 1)
            
        right[-1] = min(1, arr[-1])
        for i in range(l - 2, -1, -1):
            right[i] = min(arr[i], right[i + 1] + 1)
            
            
        maxip = 0
        for i in range(l):
            peak = min(left[i], right[i])
            if peak > maxip:
                maxip = peak
                
        pyr_sum = maxip * maxip
        
        return total - pyr_sum