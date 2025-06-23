class Solution {
 public:
    string addStrings(string a, string b) {
        string result;
        int carry = 0;
        int i = a.length() - 1, j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        string num1 = "", num2 = "";

        for (int i = 0; i < arr.size(); ++i) {
            if (i % 2 == 0) num1 += (arr[i] + '0');
            else num2 += (arr[i] + '0');
        }

        string sum = addStrings(num1, num2);

        // Remove leading zeros if any
        int idx = 0;
        while (idx < sum.size() && sum[idx] == '0') ++idx;

        return idx == sum.size() ? "0" : sum.substr(idx);
    }
};