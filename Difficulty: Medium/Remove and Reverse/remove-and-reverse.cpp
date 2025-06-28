#include <deque>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    string removeReverse(string S) {
        vector<int> freq(26, 0);
        for (char ch : S) freq[ch - 'a']++;

        deque<char> dq(S.begin(), S.end());
        bool reversed = false;

        while (true) {
            bool removed = false;
            if (!reversed) {
                // Normal direction
                for (int i = 0; i < dq.size(); ++i) {
                    if (freq[dq[i] - 'a'] > 1) {
                        freq[dq[i] - 'a']--;
                        dq.erase(dq.begin() + i);
                        reversed = true;
                        removed = true;
                        break;
                    }
                }
            } else {
                // Reversed direction
                for (int i = dq.size() - 1; i >= 0; --i) {
                    if (freq[dq[i] - 'a'] > 1) {
                        freq[dq[i] - 'a']--;
                        dq.erase(dq.begin() + i);
                        reversed = false;
                        removed = true;
                        break;
                    }
                }
            }

            if (!removed) break;
        }

        string result = "";
        if (!reversed) {
            for (char ch : dq) result += ch;
        } else {
            for (auto it = dq.rbegin(); it != dq.rend(); ++it)
                result += *it;
        }

        return result;
    }
};
