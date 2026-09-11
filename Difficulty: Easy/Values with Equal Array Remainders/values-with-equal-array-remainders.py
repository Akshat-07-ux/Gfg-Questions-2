import math

class Solution:
    def sameMod(self, arr):
        # code here
        if len(set(arr)) == 1:
            return -1
            
        a = 0
        for num in arr:
            a = math.gcd(a, abs(num - arr[0]))
            
        if a == 0:
            return -1
            
        count = 0
        for i in range(1, int(math.isqrt(a)) + 1):
            if a % i == 0:
                count += 1
                if i * i != a:
                    count += 1
                    
        return count
        
