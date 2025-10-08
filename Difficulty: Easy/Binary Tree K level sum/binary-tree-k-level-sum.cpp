// User function Template for C++
class Solution {
  public:
    int kLevelSum(string s, int k) {
        int level = -1;  // Start before root (since first '(' opens root)
        int sum = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                level++; // going down one level
            }
            else if (s[i] == ')') {
                level--; // coming up
            }
            else if (isdigit(s[i]) || s[i] == '-') {
                // Extract the full number (handle multi-digit and negatives)
                int j = i;
                string num = "";
                if (s[j] == '-') {
                    num += '-';
                    j++;
                }
                while (j < n && isdigit(s[j])) {
                    num += s[j];
                    j++;
                }
                int val = stoi(num);
                // When level matches k, add to sum
                if (level == k)
                    sum += val;

                i = j - 1; // Move pointer ahead
            }
        }
        return sum;
    }
};
