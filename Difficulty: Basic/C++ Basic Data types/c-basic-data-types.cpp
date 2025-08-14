#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int BasicDataType(string s) {
        // If it's a single non-digit → char
        if (s.size() == 1 && !isdigit(s[0])) {
            return sizeof(char);
        }

        // If it contains decimal point
        size_t dotPos = s.find('.');
        if (dotPos != string::npos) {
            int digitsAfterDecimal = s.size() - dotPos - 1;

            // Float if ≤ 5 digits after '.', else double
            if (digitsAfterDecimal <= 5)
                return sizeof(float);
            else
                return sizeof(double);
        }

        // Otherwise integer
        return sizeof(int);
    }
};