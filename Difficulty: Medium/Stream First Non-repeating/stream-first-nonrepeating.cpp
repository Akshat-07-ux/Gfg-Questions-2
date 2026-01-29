class Solution {
  public:
    string firstNonRepeating(string &s) {
        // Frequency array for 26 lowercase English letters
        int freq[26] = {0};
        // Queue to maintain the order of characters
        queue<char> q;
        string result = "";

        for (char c : s) {
            // Increment frequency and add to queue
            freq[c - 'a']++;
            q.push(c);

            // Check the front of the queue
            // If the front character is repeating, it can never be 
            // the first non-repeating character again. Pop it.
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            // If queue is empty, no non-repeating char exists
            if (q.empty()) {
                result += '#';
            } else {
                result += q.front();
            }
        }

        return result;
    }
};