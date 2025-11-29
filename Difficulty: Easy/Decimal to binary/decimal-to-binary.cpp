class Solution {
public:
    string decToBinary(int n) {
        if (n == 0) return "0";

        string ans = "";
        while (n > 0) {
            ans.push_back((n % 2) + '0');
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
