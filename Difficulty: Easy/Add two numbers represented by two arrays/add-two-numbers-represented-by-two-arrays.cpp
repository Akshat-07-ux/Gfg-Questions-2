#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += arr1[i];
                i--;
            }
            if (j >= 0) {
                sum += arr2[j];
                j--;
            }

            result += (sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
