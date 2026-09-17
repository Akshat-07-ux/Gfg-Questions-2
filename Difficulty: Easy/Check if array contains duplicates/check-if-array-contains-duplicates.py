
class Solution:

    def checkDuplicates(self, arr):
        #code here
        seen = set()
        
        for number in arr:
            if number in seen:
                return True
            seen.add(number)
        return False
