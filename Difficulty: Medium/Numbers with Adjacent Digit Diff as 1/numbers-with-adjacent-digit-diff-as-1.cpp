#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<int> absDifOne(int n) {
        vector<int> result;
        queue<long long> q;

        // Push all single-digit numbers from 1 to 9 into the queue
        for (int i = 1; i <= 9; ++i) {
            q.push(i);
        }

        while (!q.empty()) {
            long long curr = q.front();
            q.pop();

            int lastDigit = curr % 10;

            // Option 1: Append (lastDigit - 1) if valid
            if (lastDigit > 0) {
                long long nextNum = curr * 10 + (lastDigit - 1);
                if (nextNum <= n) {
                    result.push_back(nextNum);
                    q.push(nextNum);
                }
            }

            // Option 2: Append (lastDigit + 1) if valid
            if (lastDigit < 9) {
                long long nextNum = curr * 10 + (lastDigit + 1);
                if (nextNum <= n) {
                    result.push_back(nextNum);
                    q.push(nextNum);
                }
            }
        }

        return result;
    }
};