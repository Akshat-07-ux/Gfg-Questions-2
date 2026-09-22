class Solution:
    def findLongestWord(self, s: str, d: list) -> str:
        # code here
        good_word = ""
        
        for word in d:
            if len(word) < len(good_word) or (len(word) == len(good_word) and word >= good_word):
                continue
            
            ini = iter(s)
            
            if all(b in ini for b in word):
                good_word = word
                
        return good_word