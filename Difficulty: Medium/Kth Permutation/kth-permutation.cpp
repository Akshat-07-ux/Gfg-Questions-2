#include <string>
#include <vector>

class Solution {
  public:
    std::string kthPermutation(int n, int k) {
        int fact = 1;
        std::vector<int> numbers;
        
        // Calculate (n-1)! and populate the list of available digits
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n); // numbers array: [1, 2, ..., n]
        
        std::string ans = "";
        k = k - 1; // Convert to 0-based indexing
        
        while (true) {
            // Find the character index for the current position
            int index = k / fact;
            ans += std::to_string(numbers[index]);
            
            // Remove the used number from the list
            numbers.erase(numbers.begin() + index);
            
            // If no numbers are left, we are done
            if (numbers.size() == 0) {
                break;
            }
            
            // Update k and calculate the new factorial block size
            k = k % fact;
            fact = fact / numbers.size();
        }
        
        return ans;
    }
};