#include <string>
#include <unordered_set>

class Solution {
  public:
    int solve(int n, string s) {
        unordered_set<char> in_cafe;   // Tracks customers currently using a computer
        unordered_set<char> rejected;  // Tracks customers who were rejected
        int rejected_count = 0;

        for (char customer : s) {
            // Case 1: Customer is leaving
            if (in_cafe.count(customer)) {
                in_cafe.erase(customer);
                n++; // Free up a computer
            } 
            else if (rejected.count(customer)) {
                // Customer was rejected previously and is now leaving
                rejected.erase(customer);
            } 
            // Case 2: Customer is arriving
            else {
                if (n > 0) {
                    in_cafe.insert(customer);
                    n--; // Occupy a computer
                } else {
                    rejected.insert(customer);
                    rejected_count++;
                }
            }
        }

        return rejected_count;
    }
};