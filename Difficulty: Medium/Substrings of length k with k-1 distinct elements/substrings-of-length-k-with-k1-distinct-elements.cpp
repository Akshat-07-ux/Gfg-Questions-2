#include <unordered_map>
#include <string>
using namespace std;

class Solution {
  public:
    int substrCount(string &s, int k) {
        if (k > s.length()) return 0;
        
        int count = 0;
        unordered_map<char, int> freq;
        
        // initialize the first window
        for (int i = 0; i < k; ++i) {
            freq[s[i]]++;
        }
        
        // check first window
        if (freq.size() == k - 1) count++;
        
        // slide the window
        for (int i = k; i < s.length(); ++i) {
            char out_char = s[i - k]; // char going out of window
            char in_char = s[i];      // char coming into window
            
            // remove the outgoing character
            freq[out_char]--;
            if (freq[out_char] == 0) freq.erase(out_char);
            
            // add the incoming character
            freq[in_char]++;
            
            // check condition
            if (freq.size() == k - 1) count++;
        }
        
        return count;
    }
};
