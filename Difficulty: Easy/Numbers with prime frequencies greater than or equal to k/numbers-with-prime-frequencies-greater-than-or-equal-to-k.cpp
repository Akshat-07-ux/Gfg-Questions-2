#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // Standard Primality Test: O(sqrt(N))
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i = i + 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    vector<int> primeOccurences(vector<int>& arr, int k) {
        unordered_map<int, int> counts;
        // 1. Map each number to its frequency
        for (int num : arr) {
            counts[num]++;
        }

        vector<int> result;
        // 2. Identify elements that meet both criteria
        for (auto const& [val, freq] : counts) {
            if (freq >= k && isPrime(freq)) {
                result.push_back(val);
            }
        }

        // 3. Sort the result to match the expected output order (37 before 51)
        sort(result.begin(), result.end());

        return result;
    }
};