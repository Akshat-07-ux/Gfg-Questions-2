class Solution:
    def dominantPairs(self, arr: list[int]) -> int:
        # code here
        middle = len(arr) // 2
        l = sorted(arr[:middle])
        r = sorted(arr[middle:])
        
        win = 0 
        j = 0
        for a in l:
            while j < len(r) and a >= 5 * r[j]:
                j += 1
            win += j
            
        return win
