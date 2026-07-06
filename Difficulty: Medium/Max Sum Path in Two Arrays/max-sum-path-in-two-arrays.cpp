#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        int m = a.size(), n = b.size();
        
        int total_result = 0;
        int sum_a = 0, sum_b = 0;
        
        // Traverse both arrays
        while (i < m && j < n) {
            if (a[i] < b[j]) {
                sum_a += a[i++];
            } 
            else if (b[j] < a[i]) {
                sum_b += b[j++];
            } 
            else { // a[i] == b[j] (Intersection point)
                total_result += max(sum_a, sum_b) + a[i];
                sum_a = 0;
                sum_b = 0;
                i++;
                j++;
            }
        }
        
        // Add remaining elements of array a[]
        while (i < m) {
            sum_a += a[i++];
        }
        
        // Add remaining elements of array b[]
        while (j < n) {
            sum_b += b[j++];
        }
        
        // Add the maximum of the final remaining paths
        total_result += max(sum_a, sum_b);
        
        return total_result;
    }
};