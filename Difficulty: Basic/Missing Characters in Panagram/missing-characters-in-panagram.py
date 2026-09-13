class Solution:
    def missingPanagram(self, s):
        import string
        # code here
        seen = set(s.lower())
        aph = set(string.ascii_lowercase)
        miss = aph - seen
        
        if not miss:
            return "-1"
            
        return "".join(sorted(miss))
