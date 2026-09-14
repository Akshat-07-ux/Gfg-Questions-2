class Solution:
    def justifyText(self, words, l):
        # code here
        res = []
        i = 0
        le = len(words)
        
        while i < le:
            j = i
            
            cur_len = len(words[i])
            j += 1
            
            while j < le and cur_len + 1 + len(words[j]) <= l:
                cur_len += 1 + len(words[j])
                j += 1
                
            n_w = j - i
            l_w = words[i:j]
            
            if j == le or n_w == 1:
                line = " ".join(l_w)
                line += " " * (l - len(line))
                res.append(line)
                
            else:
                tot_ch = sum(len(w) for w in l_w)
                tot_sp = l - tot_ch
                n_g = n_w - 1
                s_p_g = tot_sp // n_g
                ex_sp = tot_sp % n_g
                
                line = ""
                for k in range(n_g):
                    line += l_w[k]
                    c_g_s = s_p_g + (
                        1 if k < ex_sp else 0
                    )
                    
                    line += " " * c_g_s
                line += l_w[-1]
                res.append(line)
                
            i = j
        
        return res