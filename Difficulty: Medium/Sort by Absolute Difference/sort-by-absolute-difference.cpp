class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // Use stable_sort to maintain relative order of elements with equal differences
        stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x);
        });
    }
};