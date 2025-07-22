class Solution {
  public:
    vector<int> count(string s) {
        // Initialize counts: uppercase, lowercase, numeric, special
        vector<int> result(4, 0);

        for(char ch : s) {
            if (isupper(ch))
                result[0]++;
            else if (islower(ch))
                result[1]++;
            else if (isdigit(ch))
                result[2]++;
            else
                result[3]++;
        }

        return result;
    }
};
