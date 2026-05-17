#include <vector>

class Solution {
  public:
    std::vector<int> makeBeautiful(std::vector<int> arr) {
        std::vector<int> st; // We can use a vector as a stack to avoid reversing later
        
        for (int num : arr) {
            // If stack is not empty and signs are different
            if (!st.empty() && ((st.back() >= 0 && num < 0) || (st.back() < 0 && num >= 0))) {
                st.pop_back(); // Remove the adjacent opposite sign element
            } else {
                st.push_back(num); // Otherwise, add the current element
            }
        }
        
        return st;
    }
};