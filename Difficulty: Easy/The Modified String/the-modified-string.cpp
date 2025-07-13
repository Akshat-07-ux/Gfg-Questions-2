class Solution {
  public:
    int modified(string a) {
        int count = 1;  // to count consecutive characters
        int insertions = 0;
        
        for(int i = 1; i < a.length(); i++) {
            if(a[i] == a[i-1]) {
                count++;
                if(count == 3) {
                    insertions++;   // insert a character to break the streak
                    count = 1;      // reset count as if we inserted a different character
                }
            } else {
                count = 1; // reset count if character is different
            }
        }
        return insertions;
    }
};
