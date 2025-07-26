class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int threshold = n / 3;  // floor(n/3)
        
        // Phase 1: Find potential candidates using Boyer-Moore algorithm
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        
        for (int num : arr) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Phase 2: Verify candidates by counting their actual frequencies
        count1 = 0;
        count2 = 0;
        
        for (int num : arr) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }
        
        vector<int> result;
        
        if (count1 > threshold) result.push_back(candidate1);
        if (count2 > threshold) result.push_back(candidate2);
        
        // Sort the result as required
        sort(result.begin(), result.end());
        
        return result;
    }
};