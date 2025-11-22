class Solution {
  public:
    int leftElement(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        // If n is odd -> middle element remains
        // If n is even -> left middle remains
        if (n % 2 == 1)
            return arr[n / 2];
        else
            return arr[(n / 2) - 1];
    }
};
