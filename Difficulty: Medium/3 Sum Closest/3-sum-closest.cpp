class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int closestSum = arr[0] + arr[1] + arr[2];
        
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            
            while (l < r) {
                int currSum = arr[i] + arr[l] + arr[r];
                
                int currDiff = abs(currSum - target);
                int bestDiff = abs(closestSum - target);
                
                // Update if closer OR same distance but larger sum
                if (currDiff < bestDiff || 
                   (currDiff == bestDiff && currSum > closestSum)) {
                    closestSum = currSum;
                }
                
                if (currSum < target) {
                    l++;
                } else if (currSum > target) {
                    r--;
                } else {
                    return currSum; // perfect hit
                }
            }
        }
        
        return closestSum;
    }
};
