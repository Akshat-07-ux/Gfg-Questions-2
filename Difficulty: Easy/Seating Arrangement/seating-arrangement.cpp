#include <vector>

using namespace std;

class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        int n = seats.size();
        
        // Step 1: Validate the initial seating arrangement.
        // If there are already adjacent occupied seats, it's immediately invalid.
        for (int i = 0; i < n - 1; i++) {
            if (seats[i] == 1 && seats[i + 1] == 1) {
                return false;
            }
        }
        
        // Step 2: Try to greedily place the 'k' people.
        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                // Check if the left neighbor is empty or out of bounds
                bool left_empty = (i == 0 || seats[i - 1] == 0);
                // Check if the right neighbor is empty or out of bounds
                bool right_empty = (i == n - 1 || seats[i + 1] == 0);
                
                if (left_empty && right_empty) {
                    seats[i] = 1; // Seat the person
                    k--;          // One less person to seat
                    
                    // Optional optimization: If all people are seated, we can stop early.
                    if (k <= 0) {
                        return true;
                    }
                }
            }
        }
        
        // If k <= 0, we successfully seated everyone.
        return k <= 0;
    }
};