class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // Sort all three arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        
        int i = 0, j = 0, k = 0;
        int n = a.size();
        
        long long minDiff = LLONG_MAX;
        long long minSum = LLONG_MAX;
        
        vector<int> result(3);
        
        while (i < n && j < n && k < n) {
            int x = a[i];
            int y = b[j];
            int z = c[k];
            
            int currentMax = max({x, y, z});
            int currentMin = min({x, y, z});
            
            long long diff = currentMax - currentMin;
            long long sum = (long long)x + y + z;
            
            if (diff < minDiff || (diff == minDiff && sum < minSum)) {
                minDiff = diff;
                minSum = sum;
                result = {x, y, z};
            }
            
            // Move pointer of the smallest element
            if (currentMin == x) i++;
            else if (currentMin == y) j++;
            else k++;
        }
        
        // Return in decreasing order
        sort(result.begin(), result.end(), greater<int>());
        
        return result;
    }
};
