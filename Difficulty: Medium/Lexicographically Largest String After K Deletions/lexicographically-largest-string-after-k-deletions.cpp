class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        int keep = n - k;
        string stack;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            // Pop characters from stack if:
            // - current char is greater than stack top (to improve lex order)
            // - we still have enough characters left to reach 'keep'
            while (!stack.empty() && stack.back() < c && 
                   (stack.size() + (n - i - 1) >= keep)) {
                stack.pop_back();
            }

            // Add current character if we still need more characters
            if (stack.size() < keep) {
                stack.push_back(c);
            }
        }

        return stack;
    }
};
