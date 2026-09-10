class Solution:
    def countVowels(self, s):
        count = 0
        inthis = set()
        
        for char in s:
            if char in "aeiou" and char not in inthis:
                inthis.add(char)
                count += 1
                
        return count
        