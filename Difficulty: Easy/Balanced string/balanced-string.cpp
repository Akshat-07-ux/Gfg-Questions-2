class Solution {
  public:
    string BalancedString(int N) {
        string result = "";
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        
        auto digitSum = [](int x) {
            int sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };

        int originalN = N; // keep original for sum parity check later

        while (N > 26) {
            result += alpha;
            N -= 26;
        }

        if (N % 2 == 0) {
            int half = N / 2;
            result += alpha.substr(0, half);
            result += alpha.substr(26 - half);
        } else {
            int sum = digitSum(originalN);
            if (sum % 2 == 0) {
                // even sum → (N+1)/2 from start, (N-1)/2 from end
                int left = (N + 1) / 2;
                int right = (N - 1) / 2;
                result += alpha.substr(0, left);
                result += alpha.substr(26 - right);
            } else {
                // odd sum → (N-1)/2 from start, (N+1)/2 from end
                int left = (N - 1) / 2;
                int right = (N + 1) / 2;
                result += alpha.substr(0, left);
                result += alpha.substr(26 - right);
            }
        }

        return result;
    }
};
