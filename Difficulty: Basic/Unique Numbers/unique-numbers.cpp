// User function Template for C++
class Solution {
 public:
    vector<int> uniqueNumbers(int L, int R) {
        vector<int> result;
        for (int num = L; num <= R; ++num) {
            if (hasUniqueDigits(num)) {
                result.push_back(num);
            }
        }
        return result;
    }

  private:
    bool hasUniqueDigits(int num) {
        vector<bool> seen(10, false);
        while (num > 0) {
            int digit = num % 10;
            if (seen[digit]) return false;
            seen[digit] = true;
            num /= 10;
        }
        return true;
    }
};