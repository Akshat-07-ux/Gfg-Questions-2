class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        bool allNines = true;
        
        for (int i = 0; i < n; i++) {
            if (num[i] != 9) {
                allNines = false;
                break;
            }
        }

        // Case 1: All digits are 9
        if (allNines) {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }

        // Case 2 & 3: Mirror and check
        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2 == 0) ? mid : mid + 1;

        // Find the first point of difference starting from the middle
        int leftSide = i;
        while (leftSide >= 0 && num[leftSide] == num[j]) {
            leftSide--;
            j++;
        }

        bool leftIsSmaller = false;
        if (leftSide < 0 || num[leftSide] < num[j]) {
            leftIsSmaller = true;
        }

        // Mirror left to right
        for (int k = j; k < n; k++) {
            num[k] = num[n - 1 - k];
        }

        // If the left side was smaller or equal, we need to increment the middle
        if (leftIsSmaller) {
            int carry = 1;
            int left = (n % 2 == 0) ? mid - 1 : mid;
            
            while (left >= 0 && carry > 0) {
                num[left] += carry;
                carry = num[left] / 10;
                num[left] %= 10;
                // Reflect change to the right side
                num[n - 1 - left] = num[left];
                left--;
            }
        }

        return num;
    }
};