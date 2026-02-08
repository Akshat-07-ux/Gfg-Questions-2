class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        long long max_prod = INT_MIN;
        
        long long left_to_right = 1;
        long long right_to_left = 1;

        for (int i = 0; i < n; i++) {
            // If prefix/suffix becomes 0, reset it to 1 for the next segment
            if (left_to_right == 0) left_to_right = 1;
            if (right_to_left == 0) right_to_left = 1;

            // Product from the start
            left_to_right *= arr[i];
            
            // Product from the end
            right_to_left *= arr[n - 1 - i];

            max_prod = max({max_prod, left_to_right, right_to_left});
        }

        return (int)max_prod;
    }
};